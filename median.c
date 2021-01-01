/*

Median, mode and Mean by Abdul Mahmoud(1093276) , Bahaa Zuraik(1096463), Austin Varghese (1098759)


*/
#include <stdio.h>


float median(int Array[], int n) {
    int temp;
    int i;
    int j;
    // the following two loops sort the array x in ascending order
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(Array[j] < Array[i]) {
                // swap elements
                temp = Array[i];
                Array[i] = Array[j];
                Array[j] = temp;
            }
        }
    }

    if(n%2==0) {
        // if there is an even number of elements, return mean of the two elements in the middle
        return((Array[n/2] + Array[n/2 - 1]) / 2.0);
    } else {
        // else return the element in the middle
        return Array[n/2];
    }
}
