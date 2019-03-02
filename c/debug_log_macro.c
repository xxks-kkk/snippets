#include <stdlib.h>
#include <stdio.h>

// run: gcc -DDEBUG debug_log_macro.c

#if defined(DEBUG) || defined(_DEBUG)
#define LOG(M, ...)                                                            \
  do {                                                                         \
    fprintf(stderr, "[%s (%s:%d)]  " M "\n", __func__, __FILE__, __LINE__,     \
            ##__VA_ARGS__);                                                    \
  } while (0)
#else
#define LOG(M, ...)                                                            \
  do {                                                                         \
  } while (0)
#endif

#define CHECK(EXPR, M, ...)                                                    \
  do {                                                                         \
    if (!(EXPR)) {                                                             \
      fprintf(stderr, "[%s (%s:%d)] ERROR  " M "\n", __func__, __FILE__,       \
              __LINE__, ##__VA_ARGS__);                                        \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0)

int main() {
  LOG("Enter the main function");
  CHECK(1==0, "one is not equal to zero");    
}
