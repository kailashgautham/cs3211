void reader(int* foo) {
  std::cout << *foo;
  delete foo;
}

void writer(int* foo) {
  (*foo)++;
  delete foo;
}

void schedule_unsafe() {
  int* foo = new int;

  std::thread { reader, foo }.detach();
  std::thread { writer, foo }.detach();
}

/*
 * There are multiple problems here.
 * 1) we do not know who is using the resource, and so we don't know when to free the resource.
 * 2) each function believes that it is responsible for deleting the resource, which can become messy. 
 */

// Besides data races
// - double free (both threads delete foo without knowing if the other has done so)
// - use after free (one may delete before the other accesses)
// - uninitialised variable (foo's value is undefined!)
