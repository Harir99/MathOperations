/*

FindArea by Shayan Mohammed(1097825) and Harir Al Rubaye (1108085) 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float FindArea(int x, int* success) {

/* This function will check which option the user selected, and return the area*/

		*success = '\0';

		/* Area of each shape declared */
		float areaCircle = 0;
		float radius=0;
		float areaSquare = 0;
		float length=0;
		float width=0;
		float areaTriangle = 0;
		float base =0;
		float height=0;

	if (x == 1) {

		printf("Enter Radius: \n");
		scanf("%f", &radius);

		/* Formula of area of circle */
		areaCircle = (3.141) * (radius) * (radius);
		printf("The area of the CIRCLE is: %f\n",areaCircle);



	} else if (x == 2) {

		printf("Enter Length: \n");
		scanf("%f", &length);
		printf("Enter Width: \n");
		scanf("%f", &width);

		/* Formula of area of square  */
		areaSquare = (length) * (width);
		printf("The area of the SQAURE is: %f\n",areaSquare);



	} else if (x == 3) {

		printf("Enter Base: \n");
		scanf("%f", &base);
		printf("Enter Height: \n");
		scanf("%f", &height);

		/* Formula of area of triangle*/
		areaTriangle = ( (base *height) /2);
		printf("The area of the TRIANGLE is: %f\n",areaTriangle);



	}

	return areaCircle;
	return areaSquare;
	return areaTriangle;
}
