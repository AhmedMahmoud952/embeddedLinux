#include <iostream>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signal){
  std::cout << "Ctrl+C is pressed exiting program" << std::endl;

  exit(signal);
}

int main()
{
  signal(SIGINT, signalHandler);
  while (true)
  {
    std::cout << "Processing..." << std::endl;
    sleep(1);
  }
  return 0;
}