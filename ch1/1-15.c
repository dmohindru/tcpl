/* Date: 05/04/19
   Description: Temperature converion program using function
*/

#include <stdio.h>

float celsius(float farh)
{
    return (5.0/9.0) * (farh-32.0);
}
main()
{
    float farh;
    int lower, upper, step;

    lower = 0;          /* Lower limit of temprature table */
    upper = 300;        /* Upper limit of temprature table */
    step = 20;          /* Step size */

    farh = lower;
    printf("Fahr Celsius\n");
    while (farh <= upper) {
        printf("%3.0f  %6.1f\n", farh, celsius(farh));
        farh = farh + step;
    }
}