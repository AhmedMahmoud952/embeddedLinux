#include <iostream>
#include <cctype>

class character
{
public:

  character(char member);
  bool isdigit();
  ~character();
private:
  char member = '\0';
};

character::character(char member): member(member)
{
  std::cout << "constructor is called" << std::endl;
}

bool character::isdigit()
{
  if(std::isdigit(this->member)) return true;
  else return false;
}

character::~character()
{
  std::cout << "disconstructor is called" << std::endl;
}

int main() {
  character c1('1');
  character c2('a');
  std::cout << c1.isdigit() << std::endl;
  std::cout << c2.isdigit() << std::endl;
  return 0;
}
