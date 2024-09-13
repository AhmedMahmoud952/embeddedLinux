#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

int calc(int x, int y) {return x+y;}

int main()
{
  std::packaged_task<int(int,int)> task(calc);
  std::future<int> future = task.get_future();
  std::thread t(std::move(task),2,3);
  t.join();
  std::cout << "sum : " << future.get() << std::endl;
  // std::promise<int> promiseObj;
  // std::future<int> futureObj = promiseObj.get_future();
  // std::thread sumThread([&promiseObj]{
  //   int result = calc(10, 20);
  //   promiseObj.set_value(result);
  // });
  // int result = futureObj.get();
  // std::cout << "sum = " << result << std::endl;
  // sumThread.join();
  // return 0;
}


// static int count = 0;
// std::condition_variable cv;
// std::mutex mtx;
// bool ready = false;

// void worker(){
//   std::unique_lock<std::mutex> lock(mtx);
//   cv.wait(lock,[]{return ready;});
//   std::cout << "worker thread." << std::endl;
// }

// void giver(){
//   std::unique_lock<std::mutex> lock(mtx);
//   std::cout << "giver thread." << std::endl;
//   ready = true;
//   cv.notify_one();
//   ready = true;
// }

// int main()
// {
//   std::thread w(worker);
//   std::thread g(giver);
//   g.join();
//   w.join();
//   return 0;
// }



// void updateCount(){
//   std::unique_lock<std::mutex> lock(mtx);
//   for (int  i = 0; i < 10000; i++)
//   {
//     /* code */
//     count++;
//   }
  
// }

// int main()
// {
// //   std::thread t(test(),41);
// //   t.join(); // Wait for the thread to finish execution
// //   std::cout << "in main" << std::endl;
// //   std::thread t2([](int num){std::cout << "in lambda thread: " << num << std::endl;},235);
// //   t2.join(); // Wait for the lambda thread to finish execution

//   // std::chrono::system_clock::time_point wait_time = std::chrono::system_clock::now() + std::chrono::seconds(5);
//   // std::cout << "slepping until" << std::endl;
//   // std::this_thread::sleep_until(wait_time); // Sleep until the specified time
//   // std::cout << "woke up" << std::endl;

//   // std::thread t1(updateCount);
//   // std::thread t2(updateCount);
//   // std::cout << "i am here" << std::endl;
//   // t1.join();
//   // std::cout << "i am there" << std::endl;
//   // t2.join();
  
//   // std::cout << "final value: " <<  count << std::endl;
//   return 0;
// }
