#include "isogram.h"
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>

bool is_isogram(const char phrase[])
{
   int used_letters = 0;

   if (phrase == NULL)
      return false;

   for (int i = 0; phrase[i] != '\0'; ++i) {
      if (isalpha(phrase[i])) {
         int bit_number = toupper(phrase[i]) - 'A';
         int bit_mask = 1 << bit_number;
         if ((used_letters & bit_mask) > 0)
            return false;
         else
            used_letters |= bit_mask;
      }
   }
   return true;
}