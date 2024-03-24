#include <iostream>
#include <random>
#include <vector>
#include "Wards.cpp"
#include <utility>
#include <map>
#include <algorithm> 
#include<typeinfo>
// Hàm tạo ngẫu nhiên 8 số nguyên dương tuân theo phân phối chuẩn
std::vector<int> generateRandomNumbers(int tong) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> distribution(tong/10, 100); // Trung bình và độ lệch chuẩn

    std::vector<int> numbers;
    int sum = 0;

    for (int i = 0; i < 10; ++i) {
        int num = static_cast<int>(distribution(gen));
        if (num > 0) {
            numbers.push_back(num);
            sum += num;
        }
    }

    // Đảm bảo tổng là tong
    while (sum != tong) {
        int diff = tong - sum;
        int idx = std::uniform_int_distribution<>(0, 9)(gen);
        numbers[idx] += diff;
        sum = tong;
    }

    return numbers;
}
int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
std::vector<int> create_Array(int vis,int pes,int pat){
    std::vector<int> res;
    for (int i = 1;i<=vis;i++) res.push_back(1);
    for (int i = 1;i<=pes;i++) res.push_back(2);
    for (int i = 1;i<=pat;i++) res.push_back(3);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(res.begin(), res.end(), g);
    return res;
}
std::pair<char,int> max_map(std::map<char,int> &a){
    int max = 0;
    char s;
    for (auto x: a){
        if (x.second>max) 
        {
            max = x.second;
            s = x.first;
    }
    
}
    return std::make_pair(s,max);
}
int main() {
    Wards A,B,E,F,G,L,M,N,K,W;
    A.setName('A');
    B.setName('B');
    E.setName('E');
    F.setName('F');
    G.setName('G');
    L.setName('L');
    M.setName('M');
    N.setName('N');
    K.setName('K');
    W.setName('W');

    std::vector<Wards> wards_List={A,B,E,F,G,L,M,N,K,W};
    int triple;
    int single;
    triple = GetRandom(0,30000);
    single = 30000-triple;
    int vis,per,pat;
    vis = single;
    per = GetRandom(0,triple);
    pat = triple - per;
    std:: cout <<"visitor: "<<vis<<" "<<"Personel: "<<per<<" "<<"Patient: "<<pat<<std::endl;
    std::cout<<triple<<' '<<single<<' ';
    int sumInt = 3*triple+single;
    std::vector<int> randomNumbers = generateRandomNumbers(sumInt);
    std::vector<std::pair<Wards,int>> res;
    int i = 0;
    for (int num : randomNumbers) {
        res.push_back(std::make_pair(wards_List[i],num));
        i++;
    }
    
    std::map<char,int> mp;
    for (auto p:res){
        std::cout<<p.first.getName()<<" "<<p.second<<std::endl;
    }
    for (auto p:res){
        mp[p.first.getName()] = p.second;
    }
    for (auto it:mp){
        std::cout<<it.first<<" "<<it.second<<std::endl;
    }
    std::vector<int> Pedestrian = create_Array(vis,per,pat);
    std::vector<char> journey[30000];
    int jor = 0;
    for (auto x:Pedestrian){
        if (x == 1){
            std::pair<char,int> max_vis = max_map(mp);
            journey[jor].push_back(max_vis.first);
            mp[max_vis.first]--;
        }
        else{
            std::pair<char,int> max_vis = max_map(mp);
            journey[jor].push_back(max_vis.first);
            mp[max_vis.first]--; 

            max_vis = max_map(mp);
            journey[jor].push_back(max_vis.first);
            mp[max_vis.first]--;

            max_vis = max_map(mp);
            journey[jor].push_back(max_vis.first);
            mp[max_vis.first]--;
        }
        jor ++;
    }
int count =0;
    for (int k = 0 ;k<30000;k++){
        for (auto h : journey[k]){
            std::cout<<h<<" ";
        }
        std::cout<<std::endl;
        count++;
    }
    std::cout<<count;
    return 0;
}
