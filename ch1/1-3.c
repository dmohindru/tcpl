#include <stdio.h>

/* Print Fahrenheit-Celsius table with headers */

main()
{
    float farh, celsius;
    int lower, upper, step;

    lower = 0;          /* Lower limit of temprature table */
    upper = 300;        /* Upper limit of temprature table */
    step = 20;          /* Step size */

    farh = lower;
    printf("Fahr Celsius\n");
    while (farh <= upper) {
        celsius = (5.0/9.0) * (farh-32.0);
        printf("%3.0f  %6.1f\n", farh, celsius);
        farh = farh + step;
    }
}