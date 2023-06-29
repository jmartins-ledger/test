#include <stdint.h>
#include <stdlib.h>
#include <parser.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
  pp_vector((uint8_t *)data, (uint32_t)size);

  return 0; // Values other than 0 and -1 are reserved for future use.
}
