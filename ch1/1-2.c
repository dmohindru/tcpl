#include <stdio.h>

/* With this example compiler give warning of unknown escape sequence
   and when program is executed it prints the character.
*/
main()
{
    printf("Hello World\l");
    printf("Hello World\7");
    printf("Hello World\8");

}