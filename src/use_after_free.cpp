#include "use_after_free.h"

int use_after_free(int a, int b, const std::string& c) {
  if (a > 100 && b < 100 && c == "Awesome Fuzzing!") {
    // Trigger a use after free bug by allocating an int array on the heap, delete it,
    // and then try to access the buffer. Referencing memory after it has been freed
    // can cause a program to crash, use unexpected values, or execute code.
    int *array = new int[100];
    delete [] array;
    return array[0];  // BOOM
  }
  return 0;
}
