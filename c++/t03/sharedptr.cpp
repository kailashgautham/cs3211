/* shared pointer
 * when shared pointer is copied, references increases by 1.
 * when shared ptr copy is destructed, references dec by 1.
 *
 * when references = 0, shared ptr calls destructor on the object it is pointing to.
 */

#include<cstdio>
#include<memory>

void rc(const char* s, const std::shared_ptr<int>& x) {
  auto refs = x.use_count();
  printf("%s: %zu ref%s\n", s, refs, refs == 1 ? "" : "s");
}

void foo(std::shared_ptr<int> arg) {
  rc("foo 1", arg); //prints 5
  auto z = arg; //6 refs
  rc("foo 2", arg); //prints 6
}

int main() {
  auto x = std::make_shared<int>(100);
  rc("initial", x); //1 ref

  {
    auto a = x; //2 refs
    auto b = x; //3 refs
    auto c = a; //4 refs
    foo(x); //5 refs
  }

  rc("E", x); //print 1
}
