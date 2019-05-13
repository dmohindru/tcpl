/* Date: 13/05/2019
   Description: This program is used to test compile time string
   concatenation
*/
#include <stdio.h>
#define HELLO "hello, "
int main()
{
    printf(HELLO "world\n");
    return 0;
}