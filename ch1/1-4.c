#include <stdio.h>

/* Print Celsius-Fahrenheit table with headers */

main()
{
    float farh, celsius;
    int lower, upper, step;

    lower = -100;          /* Lower limit of temprature table */
    upper = 200;        /* Upper limit of temprature table */
    step = 20;          /* Step size */

    celsius = lower;
    printf("Celsius   Fahr\n");
    while (celsius <= upper) {
        //celsius = (5.0/9.0) * (farh-32.0);
        farh = (9.0/5.0) * celsius + 32.0;
        printf("%6.1f  %6.1f\n", celsius, farh);
        celsius = celsius + step;
    }
}