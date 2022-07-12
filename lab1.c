#include <stdio.h>
// PI is the ratio of diameter to the circumfrence of a circle
#define PI 3.14159
/*
I'm now going to declare my variables
alculated variables on one line input vriables on another
*/
double weight, volume, batchWeight, innerA, outerA, area;
double innerD, outerD, density, thickness;
int quantity;

void main()
{
  printf("Please enter the Inner Diameter of the Washer in cm: ");
  scanf("%lf", &innerD);
  printf("Please enter the Outer Diameter of the Washer in cm: ");
  scanf("%lf", &outerD);
  printf("Please enter the density of the material of the Washer in g/cm2: ");
  scanf("%lf", &density);
  printf("Please enter the thickness of the Washer in cm: ");
  scanf("%lf", &thickness);
  printf("Please enter the number of washewrs ordered: ");
  scanf("%d", &quantity);
  /*Hello I am Eddie */
  innerA = PI*innerD/2*innerD/2;
  outerA = PI*outerD/2*outerD/2;
  area = outerA - innerA;
  volume = area * thickness;
  weight = volume * density;
  batchWeight = quantity*weight; 
  //You can Call me Eddie
  printf("The Rim Area of the washer is %10.5lf\n", area);
  printf("The weight of one washer is %10.5lf\n", weight);
  printf("The weight of the batch of washers is %10.5lf\n", batchWeight);
  //Have a good one
}