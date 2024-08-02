#include <iostream>
#include "backtrace.hpp"

std::vector<std::string> tracer::functionNames = {"Back Trace as follows: "};

  tracer::tracer(std::string funcName): functionName(funcName){
    functionNames.push_back(funcName);
    std::cout << "Entering : " << functionName << std::endl;
  }

  void tracer::printBackTrace(){
    for(auto function : functionNames)
    {
      std::cout << function << std::endl;
    }
  }

  tracer::~tracer(){
    std::cout << "Exiting : " << functionName << std::endl;
  }




