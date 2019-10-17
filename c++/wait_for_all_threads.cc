#include<thread>
#include<iostream>
#include<vector>

using namespace std;

void message(int i) {
  cout << "thread " << i << endl << std::flush;
}

int main() {
  int NUM_THREADS = 5;
  vector<thread> threads;
  for(int i = 0; i < NUM_THREADS; ++i) {
    threads.emplace_back(thread(message, i));
  }
  for(auto&& th: threads) {
    th.join();
  }
}
