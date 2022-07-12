#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct coord
{       
        char Label[20];
        float xCoordinate;
        float yCoordinate;
}plot;
 
float lengthCalc(char Label1[20], char Label2[20], float xCord1, float yCord1, float xCord2, float yCord2)
{
        float calculation = sqrt(pow((xCord1-xCord2),2) + pow((yCord1-yCord2),2));

        printf("Length between plot: %s and %s is:\t%.2f", Label1, Label2, calculation);
        return calculation;
}
int main()
{
        char *cLabel1, *cLabel2;
        float xCor11, yCor11, xCor22, yCor22;
        char enterStr[50];
        int enter;
 
        scanf("%s", enterStr);
        enter = atoi(enterStr);

        if (enter <= 1)
        {
                printf("You do not have enoght info in your input.txt file, update it please");
                exit(1);
        }else
        {
                struct coord coordinates[enter];

                for(int i = 0; i < enter; i++)
                {
                        char *CLabel = coordinates[i].Label;
                        scanf("%s", CLabel);
                        scanf("%f", &coordinates[i].xCoordinate);
                        scanf("%f", &coordinates[i].yCoordinate);
                }              
                float closestCord = INFINITY;
                float furthestCord = 0.0;
                float calculation2;
                int nearestPointA, nearestPointB, furthestPointA, furthestPointB;
 
                for(int count = 0; count <= enter-1; count++)
                {
                for(int count2 = 0; count2 <= enter-1; count2++)
                        { 
                                cLabel1 = coordinates[count].Label;
                                xCor11= coordinates[count].xCoordinate;
                                yCor11 = coordinates[count].yCoordinate;
                                cLabel2 = coordinates[count2].Label;
                                xCor22 = coordinates[count2].xCoordinate;
                                yCor22 = coordinates[count2].yCoordinate;

                                if(count!=count2)
                                {
					printf("\n----------------------------------------------------\n");
                                        printf("\n%s - (x:%f, y:%f) \n%s - (x:%f, y:%f)\n", cLabel1, xCor11, yCor11, cLabel2, xCor22, yCor22);
 					printf("\n----------------------------------------------------\n");
                                        calculation2 = lengthCalc(cLabel1, cLabel2, xCor11, yCor11, xCor22, yCor22);
 
                                        if(calculation2 < closestCord)
                                        {
                                                nearestPointA = count;
                                                nearestPointB = count2;
                                                closestCord = calculation2;
                                        }
                                        if(calculation2 > furthestCord)
                                        {
                                                furthestPointA = count;
                                                furthestPointB = count2;
                                                furthestCord = calculation2;
                                        } 
                                }
                                else
                                {
                                        continue;
                                }
                        }
                }
       printf("\n----------------------------------------------------\n");
       printf("\nClosest points: %s and %s for a length of \t%f", coordinates[nearestPointA].Label, coordinates[nearestPointB].Label, closestCord);
       printf("\nFurthest points: %s and %s for a length of \t%f", coordinates[furthestPointB].Label, coordinates[furthestPointA].Label, furthestCord);
       printf("\n----------------------------------------------------\n");
       return(0);
        }       
}
