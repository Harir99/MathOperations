/*

Median, mode and Mean by Abdul Mahmoud(1093276) , Bahaa Zuraik(1096463), Austin Varghese (1098759)


*/
#include <stdio.h>



int mode(int a[],int n) {
   int maxValue = 0;
   int maxCount = 0;
   int i;
   int j;

   for (i = 0; i < n; ++i) {
      int count = 0;

      for (j = 0; j < n; ++j) {
         if (a[j] == a[i])
         ++count;
      }

      if (count > maxCount) {
         maxCount = count;
         maxValue = a[i];
      }
   }

   return maxValue;
}
