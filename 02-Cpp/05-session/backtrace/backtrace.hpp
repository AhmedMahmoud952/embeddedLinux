#ifndef __BACKTRACE_H__
#define __BACKTRACE_H__

#include <string>
#include <vector>

#define EnterFn tracer name(__func__)
#define PrintBT tracer::printBackTrace()

class tracer
{
public:
  tracer(std::string funcName);
  static void printBackTrace();
  ~tracer();

private:
  std::string functionName = "";
  static std::vector<std::string> functionNames;
};
#endif // __BACKTRACE_H__