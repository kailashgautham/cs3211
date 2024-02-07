#include<mutex>
#include <iostream>
#include <thread>

int counter;
std::mutex m;
int main() {
  auto t0 = std::thread{[]{m.lock(); ++counter; m.unlock();}};
  auto t1 = std::thread{[]{m.lock(); ++counter; m.unlock();}};
  t0.join();
  t1.join();
  std::cout << counter << std::endl;
  return 0;
}
