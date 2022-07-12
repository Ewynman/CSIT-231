/*
 * This code works using a comandline with a space inbetween inputws
 * if not enough inputs are entered then you are to enter them one by one
 * as it asks.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
// PI is the ratio of diameter to the circumfrence of a circle
#define PI 3.14159
//Regular Variables
double weight, volume, batchWeight, innerA, outerA, area;
double innerD, outerD, density, thickness;
int quantity;

//Declaring pointers and double pointers for weight
double *weightP = &weight;
double **weightPP = &weightP;

//Declaring pointers and double pointers for volume
double *volumeP = &volume;
double **volumePP = &volumeP;

//Declaring pointers and double pointers for batchWeight
double *batchWeightP = &batchWeight;
double **batchWeightPP = &batchWeightP;

//Declaring pointers and double pointers for innerA
double *innerAP = &innerA;
double **innerAPP = &innerAP;

//Declaring pointers and double pointers for outerA
double *outerAP = &outerA;
double **outerAPP = &outerAP;

//Declaring pointers and double pointers for area
double *areaP = &area;
double **areaPP = &areaP;

//Declaring pointers and double pointers for innerD
double *innerDP = &innerD;
double **innerDPP = &innerDP;

//Declaring pointers and double pointers for outerD
double *outerDP = &outerD;
double **outerDPP = &outerDP;

//Declaring pointers and double pointers for density
double *densityP = &density;
double **densityPP = &densityP;

//Declaring pointers and double pointers for thickness
double *thickP= &thickness;
double **thickPP = &thickP;

//Declaring pointers and double pointers for quantity
int *quantityP = &quantity;
int **quantityPP = &quantityP;

//declare variables so we can use the pow functions
double innerDP2;
double *innerDP22 = &innerDP2;
double **innerDP222 = &innerDP22;

double outerDP2;
double *outerDP22 = &outerDP2;
double **outerDP222 = &outerDP22;

//if statement to see if there is enough items on the comand line if not default 
//back to asking users for inputs one by one
if(argc != 6)
{
  printf("You did not enter enough numbers, Enter all the numbers now\n");
        //Enter the Inner Diameter
        printf("\nPlease enter the Inner Diameter of the Washer in cm: ");
        scanf("%lf", &innerD);
        //Enter the Outer Diameter
        printf("Please enter the Outer Diameter of the Washer in cm: ");
        scanf("%lf", &outerD);
        //Enter the thickness
        printf("Please enter the thickness of the Washer in cm: ");
        scanf("%lf", &thickness);
        //Enter the density
        printf("Please enter the density of the material of the Washer in g/cm2: ");
        scanf("%lf",&density);
        //Enter the number of washers
        printf("Please enter the number of washers ordered: ");
        scanf("%d", &quantity);
           
} else{
        //Input on the comand line in a set order
        //inner diameter
        innerD = atof(argv[1]);
        //outer diameter
        outerD = atof(argv[2]);
        //thickness
        thickness = atof(argv[3]);
        //density
        density = atof(argv[4]);
        //quantity
        quantity = atoi(argv[5]);
    }
    //Calculations
    *innerDP22 = pow(*innerDP/2.0,2.0);
    *innerAP = PI * *innerDP22;
    *outerDP22 = pow(*outerDP/2.0,2.0);
    *outerAP = PI * *outerDP22;
    *areaP = *outerAP - *innerAP;
    *volumeP = *areaP * *thickP;
    *weightP = *volumeP * *densityP;
    batchWeight = *quantityP * *weightP;
    //Print out the ansers with double pointers
    printf("--------------------Answers---------------------\n");
    printf("The Rim Area of the washer is          %10.5lf\n", **areaPP);
    printf("The weight of one washer is            %10.5lf\n", **weightPP);
    printf("The weight of the batch of washers is  %10.5lf\n", **batchWeightPP);
    printf("-------------------Memory Positions-------------\n");
    //Print the memory slot for every variable, pointer, and double pointer with spaces inbetween
    printf("The memory slot for weight is:         %p \n", weight);
    printf("The memory slot for *weightP is:       %p \n", *weightP);
    printf("The memroy slot for **weightPP is      %p \n", **weightPP);
    printf("\n");
    printf("The memory slot for volume is:         %p \n", volume);
    printf("The memory slot for *volumeP is:       %p \n", *volumeP);
    printf("The memroy slot for **volumePP is      %p \n", **volumePP);
    printf("\n");
    printf("The memory slot for batchWight  is:    %p \n", batchWeight);
    printf("The memory slot for *batchWeightP is:  %p \n", *batchWeightP);
    printf("The memroy slot for **batchWeightPP is %p \n", **batchWeightPP);
    printf("\n");
    printf("The memory slot for innerA  is:        %p \n", innerA);
    printf("The memory slot for *innerAP is:       %p \n", *innerAP);
    printf("The memroy slot for **innerAPP is      %p \n", **innerAPP);
    printf("\n");
    printf("The memory slot for outerA  is:        %p \n", outerA);
    printf("The memory slot for *outerAP is:       %p \n", *outerAP);
    printf("The memroy slot for **outerAPP is      %p \n", **outerAPP);
    printf("\n");
    printf("The memory slot for area  is:          %p \n", area);
    printf("The memory slot for *areaAP is:        %p \n", *areaP);
    printf("The memroy slot for **areaPP is        %p \n", **areaPP);
    printf("\n");
    printf("The memory slot for innerD  is:        %p \n", innerD);
    printf("The memory slot for *innerDP is:       %p \n", *innerDP);
    printf("The memroy slot for **innerDPP is      %p \n", **innerDPP);
    printf("\n");
    printf("The memory slot for outerD  is:        %p \n", outerD);
    printf("The memory slot for *outerDP is:       %p \n", *outerDP);
    printf("The memroy slot for **outerDPP is      %p \n", **outerDPP);
    printf("\n");
    printf("The memory slot for density  is:       %p \n", density);
    printf("The memory slot for *densityP is:      %p \n", *densityP);
    printf("The memroy slot for **densityPP is     %p \n", **densityPP);
    printf("\n");
    printf("The memory slot for thickness  is:     %p \n", thickness);
    printf("The memory slot for *thicknessP is:    %p \n", *thickP);
    printf("The memroy slot for **thicknessPP is:  %p \n", **thickPP);
    printf("\n");
    printf("The memory slot for quantity  is:      %p \n", quantity);
    printf("The memory slot for *quantityP is:     %p \n", *quantityP);
    printf("The memroy slot for **quantityPP is:   %p \n", **quantityPP);
    printf("\n");
    printf("The memory slot for innerDP is:        %p \n", innerDP);
    printf("The memory slot for *innerDP22 is:     %p \n", *innerDP22);
    printf("The memroy slot for **innerDP222 is:   %p \n", **innerDP222);
    printf("\n");
    printf("The memory slot for outerDP is:        %p \n", outerDP);
    printf("The memory slot for *outerDP22 is:     %p \n", *outerDP22);
    printf("The memroy slot for **outerDP222 is:   %p \n", **outerDP222);
    printf("---------------------------------------------------\n");
}
