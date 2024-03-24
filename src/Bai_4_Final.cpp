#include <iostream>
#include <random>
#include <vector>
#include "Wards.cpp"
#include <utility>
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
    std::cout<<triple<<' '<<single<<' ';
    int sumInt = 3*triple+single;
    std::vector<int> randomNumbers = generateRandomNumbers(sumInt);
    std::vector<std::pair<Wards,int>> res;
    int i = 0;
    for (int num : randomNumbers) {
        res.push_back(std::make_pair(wards_List[i],num));
        i++;
    }
    
    std::cout << std::endl;
     for (auto p : res) {
        std::cout << (p.first).getName()<<' '<<p.second<<std::endl;

    }
    return 0;
}
