#include<unique_ptr>

int main() {
  //unique ptr declaration
  std::unique_ptr<int> foo = std::make_unique<int>(0);

  //lambda function to close a file f
  auto deleter = [](FILE* f) {
    fclose(f);
  };

  //a unique pointer that points to a FILE and uses deleter as  Deleter
  auto bar = std::unique_ptr<FILE, decltype(deleter)> {
   fopen("file.txt", "w"), deleter 
  };

  use_foo(foo.get());
  use_bar(bar.get());
} //foo and bar are both deleted here
