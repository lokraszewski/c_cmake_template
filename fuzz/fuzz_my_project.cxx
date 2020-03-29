#include "my_project/my_project.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  const int a = atoi((const char *)data);

  return my_project_add(a, 0);
}