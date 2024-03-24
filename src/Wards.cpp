#include "Point.cpp"
#include <vector>
#include<utility>
class Wards
{
private:
    /* data */
    char name_ward;
    Point entry_ward;
    Point exit_ward;
    std::vector<Point> walls_ward;
public:
    Wards(/* args */);
    ~Wards();

  void setName(char name_ward){
    this->name_ward = name_ward;
  }
  char getName(){
    return name_ward;
  }
};

Wards::Wards(/* args */)
{
}

Wards::~Wards()
{
}
