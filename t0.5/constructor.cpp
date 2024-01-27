#include<iostream>
class A {
  public:
    char x;
    int y;
    std::string saga;
    A() : x{'1'}, y{}, saga{"default constructed"} {

      std::cout << "Default constructor called" << std::endl;

    }

    ~A() {
      std::cout << "Destructor called, object was " << saga << std::endl;
    }
};

struct B {
  public:
    char x;
    std::string y;
    std::string saga;
    B() : x{'1'}, y{}, saga{"default constructed"} {
      std::cout << saga << std::endl;
    }
    B(int i) : x{'1' + (char)i}, y{}, saga{"custom constructed with int"} {
      std::cout << saga << std::endl;
    }
    ~B() {
      std::cout << "Destructor called, object was " << saga << std::endl;
    }
    B(const B& other) : x{other.x}, y{other.y}, saga("copy constructed from object that was " + other.saga) {
      std::cout << "Copy constructor called" << std::endl;
    }
    B& operator=(const B& other) {
      std::cout << "Copy assignment called" << std::endl;
      x = other.x;
      y = other.y;
      saga = "(" + saga + ") then set to object that was (" + other.saga + ")";
      return *this;
    }
    B(B&& other) : x{std::move(other.x)}, y{std::move(other.y)}, saga{"move constructed from object that was " + other.saga} {
      std::cout << "Move constructor called" << std::endl;
    }
    B& operator=(B&& other) {
      std::cout << "Move assignment called" << std::endl;
      x = std::move(other.x);
      y = std::move(other.y);
      saga = "(" + saga + ")" + " then set to object that was (" + other.saga + ")";
      other.saga = "(" + other.saga + ") then moved from";
      return *this;
    }
};

void demo1() {
  A a; //start of lifetime of a
  {
    A b; //start of lifetime of b
  } //end of lifetime of b

  A c;
  //end of lifetime of c
  //end of lifetime of a
}

void change_x_bad(A a) { a.x = 'C'; }
void change_x_good(A& a) { a.x = 'C'; }

void demo2() {
  A a;
  change_x_bad(a);
  std::cout << "mutate pass by value " << a.x << std::endl;
  {
    A a_copy = a;
    a_copy.x = 'C';
    std::cout << "mutate copy " << a.x << std::endl;
    a = a_copy;
    std::cout << "Copy mutated back to a: " << a.x << std::endl;
  }
  A b;
  change_x_good(b);
  std::cout << "mutate pass by reference " << b.x << std::endl;

  A c;
  A& c_ref = c;
  c_ref.x = 'C';
  std::cout << "mutate reference " << c.x << std::endl;
}

  void demo3() {
    B a;
    B a_copy = a;
    B b{1};
    b = a;
  }

  void demo4() {
    B c1;
    std::cout << "c1: " << c1.x << ":" << c1.y << std::endl;
    B c2{1};
    std::cout << "c2: " << c2.x << ":" << c2.y << std::endl;
    B c3 = c2;
    std::cout << "c3: " << c3.x << ":" << c3.y << std::endl;
    c3 = c1;
    std::cout << "c3: " << c3.x << ":" << c3.y << std::endl;
    c3 = std::move(c2);
    std::cout << "c2: " << c2.x << ":" << c2.y << std::endl;
    std::cout << "c3: " << c3.x << ":" << c3.y << std::endl;
  }

  int main() {
    demo1();
    std::cout << std::endl;
    demo2();
    std::cout << std::endl;
    demo3();
    std::cout << std::endl;
    demo4();
    return 0;
  }
