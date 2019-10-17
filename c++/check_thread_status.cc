#include <future>
#include <thread>
#include <chrono>
#include <iostream>

// This program offers an example of checking thread status
//
// Compile: clang++ -std=c++14 -stdlib=libc++ check_thread_status.cc

int main() {
  using namespace std::chrono_literals;
  /* Run some task on new thread. The launch policy std::launch::async
     makes sure that the task is run asynchronously on a new thread. */
  auto future = std::async(std::launch::async,
                           [] {
                             std::this_thread::sleep_for(3s);
                             return 8;
  });

  std::future_status status;
  do
  {
    // Use wait_for() with zero milliseconds to check thread status.    
    status = future.wait_for(0ms);

    // Print status.
    if (status == std::future_status::ready) {
        std::cout << "Thread finished" << std::endl;
    } else {
        std::cout << "Thread still running" << std::endl;
    }
  } while (status != std::future_status::ready);

  auto result = future.get(); // Get result.

  std::cout << "result: " << result << std::endl;
}
