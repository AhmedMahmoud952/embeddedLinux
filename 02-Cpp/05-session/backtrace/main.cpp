#include <iostream>
#include "backtrace.hpp"

void fun1();
void fun2();
void fun3();

void fun1(){
  EnterFn;  
  fun2();
}

void fun2(){
  EnterFn;  
  fun3();
}

void fun3(){
  EnterFn;  
  PrintBT;  
}

int main() {
    EnterFn;
    fun1();  
    return 0;
}
