/**
 * Demonstrates `|=` (pipe equal) used to add flag value
 * and use `&` to check if a specified flag value set.
 *
 * This code snippet widely appears in Linux kernel and Db2
 *
 * Explanation:
 * https://github.com/xxks-kkk/shuati/pull/153
 *
 * Compile:
 * clang++ -std=c++11 -stdlib=libc++ pipe-equal-set-flags.cc
 *
 * Output:
 * $./a.out
 * Is DEFAULT_VIBRATE set ? Ans: true
 * Is DEFAULT_LIGHTS set ? Ans: false
 * Is DEFAULT_LIGHTS set ? Ans: true
 */
#include <stdio.h>

int main() {
  bool hasVibrate, hasLights;
  const int DEFAULT_SOUND = 1;
  const int DEFAULT_VIBRATE = 1<<1; // is the same as 2 or 010 in binary
  const int DEFAULT_LIGHTS = 1<<2;  // is the same as 4 or 100 in binary

  int myFlags = DEFAULT_SOUND | DEFAULT_VIBRATE; // same as 001 | 010, producing 011

  hasVibrate = (DEFAULT_VIBRATE & myFlags) != 0;
  hasLights = (DEFAULT_LIGHTS & myFlags) != 0;
  printf("Is DEFAULT_VIBRATE set ? Ans: %s\n", hasVibrate? "true": "false");
  printf("Is DEFAULT_LIGHTS set ? Ans: %s\n", hasLights? "true": "false");
  
  myFlags |= DEFAULT_LIGHTS; // we add a "DEFAULT_LIGHTS" flag
  hasLights = (DEFAULT_LIGHTS & myFlags) != 0;
  printf("Is DEFAULT_LIGHTS set ? Ans: %s\n", hasLights? "true": "false");  
}
