#include <iostream>

class Integar{
  private:
    int value;
  public:
  // constructor Note: there is no point implementing rule 5 here i just did it for practice
  // default constructor 
  Integar():value(0){}
  // parameterized constructor
  explicit Integar(int val) : value(val) {}
  // copy constructor
  Integar(const Integar& other): value(other.value){}
  // move constructor
  Integar(Integar&& other) noexcept : value(std::move(other.value)) {}
  // destructor
  ~Integar(){this->value = 0;}

  // copy assignment operator
  Integar& operator=(const Integar& other){
    if(this != &other){
      this->value = other.value;
    }
    return *this;
  }
  // move assignment operator
  Integar& operator=(Integar&& other) noexcept {
    if(this != &other){
      this->value = std::move(other.value);
    }
    return *this;
  }

  // operator overloading {+,-,*,/} on Integer
  Integar operator+(const Integar& other) const {return Integar(this->value + other.value);}
  Integar operator-(const Integar& other) const {return Integar(this->value - other.value);}
  Integar operator*(const Integar& other) const {return Integar(this->value * other.value);}
  Integar operator/(const Integar& other) const {return Integar(this->value / other.value);}
  
  // operator overloading {+,-,*,/} on double
  Integar operator+(const double& other) const {return Integar(this->value + other);}
  Integar operator-(const double& other) const {return Integar(this->value - other);}
  Integar operator*(const double& other) const {return Integar(this->value * other);}
  Integar operator/(const double& other) const {return Integar(this->value / other);}

  // operator overloading {+,-,*,/} on float
  Integar operator+(const float& other) const {return Integar(this->value + other);}
  Integar operator-(const float& other) const {return Integar(this->value - other);}
  Integar operator*(const float& other) const {return Integar(this->value * other);}
  Integar operator/(const float& other) const {return Integar(this->value / other);}
  
  // operator overloading {+,-,*,/} on long
  Integar operator+(const long& other) const {return Integar(this->value + other);}
  Integar operator-(const long& other) const {return Integar(this->value - other);}
  Integar operator*(const long& other) const {return Integar(this->value * other);}
  Integar operator/(const long& other) const {return Integar(this->value / other);}

  // operator overloading {+,-,*,/} on int
  Integar operator+(const int& other) const {return Integar(this->value + other);}
  Integar operator-(const int& other) const {return Integar(this->value - other);}
  Integar operator*(const int& other) const {return Integar(this->value * other);}
  Integar operator/(const int& other) const {return Integar(this->value / other);}

  // lhs varibale overloading operators
  template<typename T>
  friend T operator+(const T& lhs, const Integar& rhs){return lhs + rhs.value;}
  template<typename T>
  friend T operator-(const T& lhs, const Integar& rhs){return lhs - rhs.value;}
  template<typename T>
  friend T operator*(const T& lhs, const Integar& rhs){return lhs * rhs.value;}
  template<typename T>
  friend T operator/(const T& lhs, const Integar& rhs){return lhs / rhs.value;}

  // comparison operators
  bool operator==(const Integar& other) const {return this->value == other.value;}
  bool operator!=(const Integar& other) const {return this->value != other.value;}
  bool operator<=(const Integar& other) const {return this->value <= other.value;}
  bool operator>=(const Integar& other) const {return this->value >= other.value;}
  bool operator<(const Integar& other) const {return this->value < other.value;}
  bool operator>(const Integar& other) const {return this->value > other.value;}
  
  // pre increment and decrement operators
  Integar& operator++(){ ++this->value; return *this;}
  Integar& operator--(){ --this->value; return *this;}
  
  // post increment and decrement operators
  Integar operator++(int x){
    Integar temp = *this;
    ++this->value;
    return temp;
  }
  Integar operator--(int x){
    Integar temp = *this;
    --this->value;
    return temp;
  }
  
  // printing the value
  friend std::ostream& operator<<(std::ostream& os,const Integar temp){
    os << temp.value;
    return os;
  }

};

int main()
{
  Integar a(5);
  Integar b(7);
  Integar  c = a + b;
  auto d = 5.3 - b;
  std::cout << a << std::endl;

  return 0;
}