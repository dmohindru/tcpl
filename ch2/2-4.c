/* Date: 15/05/19
   Desription: Alternate version of squeeze that deletes each character in
               s1 that matches any character in s2
*/
#include <stdio.h>
enum condition {NO, YES};


void squeeze(char s1[], char s2[]) {
    int i, j, k;
    enum condition ispresent = NO;
    
    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k = 0, ispresent = NO; s2[k] != '\0' && !ispresent; k++)
            if (s2[k] == s1[i])
                ispresent = YES;
        if (!ispresent)
            s1[j++] = s1[i];
    }   
        s1[j] = '\0';
}

int main()
{
    char s[] = "dhruv mohindru";
    printf("Before squeeze: %s\n", s);
    squeeze(s, "vr");
    printf("After squeeze: %s\n", s);
}