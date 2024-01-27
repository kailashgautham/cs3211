#include<thread>
#include<iostream>

int raced;
int result;

int main(int argc, char** argv) {
  for (int i = 0; i < std::stoi(argv[1]); i++) {
    std::thread t0 {[]{raced = 0;}};
    std::thread t1{[]{raced = 1;}};
    std::thread t2{[]{result=raced;}};
    t0.join();
    t1.join();
    t2.join();
    std::cout << result << std::endl;
  }
  return 0;
}
