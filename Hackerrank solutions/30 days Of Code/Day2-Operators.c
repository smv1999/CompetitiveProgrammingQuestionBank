/* Task
Given the meal price (base cost of a meal), tip percent (the percentage of the meal price being added as tip), and tax percent (the percentage of the meal price being added as tax) for a meal, find and print the meal's total cost. Round the result to the nearest integer.

Example



A tip of 15% * 100 = 15, and the taxes are 8% * 100 = 8. Print the value  and return from the function.

Function Description
Complete the solve function in the editor below.

solve has the following parameters:

int meal_cost: the cost of food before tip and tax
int tip_percent: the tip percentage
int tax_percent: the tax percentage
Returns The function returns nothing. Print the calculated value, rounded to the nearest integer.

Note: Be sure to use precise values for your calculations, or you may end up with an incorrectly rounded result.

Sample Input

12.00
20
8
Sample Output

15    */

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the solve function below.
void solve(double meal_cost, int tip_percent, int tax_percent)  {
     double tip = meal_cost * tip_percent / 100;
     double tax = meal_cost * tax_percent / 100;
      int total =(int)round(meal_cost + tip + tax);
printf("%d",total);
}
int main()
{
    double mo;
    int tp,tp1;
    scanf("%lf",&mo);
    scanf("%d",&tp);
    scanf("%d",&tp1);
    solve(mo,tp,tp1);
}
