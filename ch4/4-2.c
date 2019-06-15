/* Date: 14/06/19
   Description: atof convert string s to double (also handle scentific notation)
*/

#include <ctype.h>
#include <stdio.h>

/* atof: convert string s to double my version*/
double atof(char s[])
{
    double val, power, exp_power;
    int i, sign, exp_sign, exponent;

    for (i = 0; isspace(s[i]); i++); /* skip white space */

    sign = (s[i] == '-')? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    /* extention starts here */
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    exp_sign = (s[i] == '-')? -1 : 1;
    if (s[i] == '-')
        i++;
    for (exponent = 0; isdigit(s[i]); i++)
        exponent = exponent * 10 + (s[i] - '0');
    for (exp_power = 1.0; exponent > 0; exponent--)
        exp_power *= 10.0;
    
    if (exp_sign < 0)
        return sign * val  / (power * exp_power);
    else
        return sign * val * exp_power / power;
}

int main()
{
    char num[] = "123.45";
    char num1[] = "123.45e-6";
    char num2[] = "123.45e-2";

    printf("%s = %g\n", num, atof(num));
    printf("%s = %g\n", num1, atof(num1));
    printf("%s = %g\n", num2, atof(num2));
    return 0;

}