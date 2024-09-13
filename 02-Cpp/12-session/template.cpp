#include <iostream>
#include <memory>

template <typename T,typename U> class test{
  private:
    T a;
    U b;
  public:
    test(T a, U b) : a(a), b(b) {std::cout << "constructor" << std::endl;}
    auto operator()() { return this->a + this->b; }
    template<typename S> auto add(S K){
      this->a += K;
      this->b += K;
      return this->a + this->b; 
    }
};

template<> class test<float,float>{
  private:
    float a;
    float b;
  public:
    test(float a, float b) : a(a), b(b) {std::cout << "float constructor" << std::endl;}
    float operator()() { return this->a + this->b; }
    template<typename S> float add(S K){
      this->a += K;
      this->b += K;
      return this->a + this->b; 
    }
};



template<typename T> class test<T,T>{
  private:
    T a, b;
  public:
    test(T a, T b) : a(a), b(b) {std::cout << "Partial constructor" << std::endl;}
    T operator()() { return this->a + this->b; }
    template<typename S> auto add(S K){
      this->a += K;
      this->b += K;
      return this->a + this->b; 
    }
};

template<typename T, typename U = int> class test2{
  private:
    T a;
    U b;
  public:
    test2(T a, U b) : a(a), b(b) {std::cout << "Default value constructor" << std::endl;}
    auto operator()() { return this->a + this->b; }
    template<typename S> auto add(S K){
      this->a += K;
      this->b += K;
      return this->a + this->b; 
    }
};

template<typename T, int size> class test3{
  private:
    T data[size];
  public:
    test3(){std::cout << "const value constructor" << std::endl;}
};

template<typename T> void print(T arg){std::cout << arg << " ";}

template<typename T, typename... U> void print(T a,U... b){
  std::cout << a << " ";
  print(b...);
}

int main()
{
  test<int,float> name(3,2.5);
  std::cout << name() << std::endl;
  std::cout << name.add(4.5) << std::endl;
  
  test<float,float> name2(2.5f,2.5f);
  std::cout << name2() << std::endl;
  std::cout << name2.add(4.7f) << std::endl;
  
  test<int,int> name3(3,2);
  std::cout << name2() << std::endl;
  std::cout << name2.add(4.7f) << std::endl;

  test2<float> name4(3.2,2);
  std::cout << name4() << std::endl;
  std::cout << name4.add(4.5) << std::endl;

  test3<int, 5> name5;
  
  print("variadic template : ",2.5f,3,"Hello",5.5);
  return 0;
}