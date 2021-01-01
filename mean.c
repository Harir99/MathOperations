/*

Median, mode and Mean by Abdul Mahmoud(1093276) , Bahaa Zuraik(1096463), Austin Varghese (1098759)


*/



#include <stdio.h>

float Mean(float Array[], int n) {
   float mean;
   float sum;
   int i;


   sum = 0;

   for(i = 0; i < n; i++) {
      sum+=Array[i];
   }

   mean = sum/(float)n;

   return mean;

}
