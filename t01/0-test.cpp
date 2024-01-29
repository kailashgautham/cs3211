#include <iostream>
#include <thread>

int counter;

int main() {
  auto t0 = std::thread{[]{++counter;}};
  auto t1 = std::thread{[]{++counter;}};
  t0.join();
  t1.join();
  std::cout << counter << std::endl;
  return 0;
}
