#include "armstrong_numbers.h"
#include <stdint.h>
#include <math.h>

static int get_digit_count(int candidate)
{
   int count = 0;
   while (candidate > 0) {
      candidate /= 10;
      ++count;
   }
   return count;
}

bool is_armstrong_number(int candidate)
{
   bool result = false;
   if (candidate < 10) {
      result = true;
   } 
   else if (candidate >= 100) {
      int count = get_digit_count(candidate);
      int sum = 0, n = candidate;
      while (n > 0 && sum <= candidate) {
         uint16_t r = n % 10;
         sum += pow(r, count);
         n /= 10;
      }
      result = candidate == sum;
   }
   return result;
}