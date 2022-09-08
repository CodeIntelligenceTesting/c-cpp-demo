#include "heap_buffer_overflow.h"
#include <base64.h>
#include <cstring>
#include <cstdio>

const char* SECRET = "RlVaWklORw=="; // base64("FUZZING")

void heap_buffer_overflow(int a, int b, std::string c) {
  if (a > 100 && b < 100 && c == SECRET) {
          // Trigger a heap buffer overflow
          char *s = (char *)malloc(1);
          strcpy(s, "too long");
          printf("%s\n", s);
  }
}
