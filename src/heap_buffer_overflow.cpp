#include "heap_buffer_overflow.h"
#include <cstring>
#include <cstdio>

void heap_buffer_overflow(int a, int b, std::string c) {
  if (a > 100 && b < 100 && c == "FUZZING") {
          // Trigger a heap buffer overflow
          char *s = (char *)malloc(1);
          strcpy(s, "too long");
          printf("%s\n", s);
  }
}
