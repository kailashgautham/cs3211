#include <iostream>
#include <thread>
#include <chrono>

int flag = 0;
int a = 0;
int b = 0;

void test1() {
  a = 1;
  b = 1;
  flag = 1;
}

void test2() {
  std::cout << "init a: " << a << std::endl;
  std::cout << "init b: " << b << std::endl;

  while (flag == 0) {
  }

  std::cout << "final a: " << a << std::endl;
  std::cout << "final b: " << b << std::endl;

}

int main() {
  auto t2 = std::thread {test2};
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  auto t1 = std::thread {test1};

  t1.join();
  t2.join();
}


