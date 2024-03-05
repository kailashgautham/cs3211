#include<chrono> //include file just pastes the reference file into your code.
#include<iostream>
#include<thread>
#include<string>

std::string hello = "Hello";

void print_hello() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << hello << std::endl;
}

int main() {
  std::string world{"World"};
  std::thread thread1(print_hello);
  std::thread thread2([](std::string name){
      std::this_thread::sleep_for(std::chrono::seconds(2));
      name += "!";
      std::cout << name << std::endl;
      },
      world);
  thread1.join();
  thread2.join();
  return 0;
}

