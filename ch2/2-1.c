/* Date: 12/05/19
   Description: This program print sizes all primitive data type.
                Prints min and max value from symbolic constants from limits.h
                Computes min and max value of basic data types
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>

#define BITS(x) (x*8)

int main()
{
    /* First print bits in each data types */
    printf("-------------------------------------\n");
    printf("Bits in basic data types\n");
    printf("-------------------------------------\n");
    printf("char bits: %ld\n", BITS(sizeof(char)));
    printf("int bits: %ld\n", BITS(sizeof(int)));
    printf("short bits: %ld\n", BITS(sizeof(short)));
    printf("long bits: %ld\n", BITS(sizeof(long)));
    printf("float bits: %ld\n", BITS(sizeof(float)));
    printf("double bits: %ld\n", BITS(sizeof(double)));

    /* Print min and max value from limits.h */
    printf("-------------------------------------\n");
    printf("Printing range of integer types from limit.h\n");
    printf("-------------------------------------\n");
    printf("signed char max = %d\n", SCHAR_MAX);
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("unsigned char max = %u\n", UCHAR_MAX);

    printf("signed int max = %d\n", INT_MAX);
    printf("signed int min = %d\n", INT_MIN);
    printf("unsigned int max = %u\n", UINT_MAX);

    printf("signed short max = %d\n", SHRT_MAX);
    printf("signed char min = %d\n", SHRT_MIN);
    printf("unsigned char max = %u\n", USHRT_MAX);

    printf("signed long max = %ld\n", LONG_MAX);
    printf("signed long min = %ld\n", LONG_MIN);
    printf("unsigned long max = %lu\n", ULONG_MAX);

    printf("-------------------------------------\n");
    printf("Computed value of min max of integer data type\n");
    printf("-------------------------------------\n");
    printf("signed char max = %d\n", (char)((unsigned char) -1 >> 1));
    printf("signed char min = %d\n", (char) ~((unsigned char) -1 >> 1));
    printf("unsigned char max = %u\n", (unsigned char)-1);
    
    printf("signed int max = %d\n", (int)((unsigned int) -1 >> 1));
    printf("signed int min = %d\n", (int) ~((unsigned int) -1 >> 1));
    printf("unsigned int max = %u\n", (unsigned int)-1);
    
    printf("signed short max = %d\n", (short)((unsigned short) -1 >> 1));
    printf("signed short min = %d\n", (short) ~((unsigned short) -1 >> 1));
    printf("unsigned short max = %u\n", (unsigned short)-1);
    
    printf("signed long max = %ld\n", (long)((unsigned long) -1 >> 1));
    printf("signed long min = %ld\n", (long) ~((unsigned long) -1 >> 1));
    printf("unsigned long max = %lu\n", (unsigned long)-1);



    printf("\n-------------------------------------\n");
    printf("Printing range of floating types from float.h\n");
    printf("-------------------------------------\n");
    printf("float max = %.10e\n", FLT_MAX);
    printf("float min = %.10e\n", FLT_MIN);
    
    printf("double max = %.10e\n", DBL_MAX);
    printf("double min = %.10e\n", DBL_MIN);

    printf("\n-------------------------------------\n");
    printf("Printing range of floating types\n");
    printf("-------------------------------------\n");
    /* Bit pattern for max float value 0 11111110 11111111111111111111111 */
    printf("Bit pattern for float max: %x\n", FLT_MAX);
    printf("Bit pattern for float min: %x\n", FLT_MIN);
    printf("float max = %.10e\n", 0x27b82260);
    printf("float min = %.10e\n", 0x27b82260);


}