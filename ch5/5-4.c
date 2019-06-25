/* Date: 25/06/19
   Description: strend function checks if t is present at end of s */
#include <stdio.h>

int strend(char *s, char *t)
{
    char *s_temp, *t_temp;
    int s_len, t_len;
    s_len = t_len = 0;
    s_temp = s;
    t_temp = t;
    
    /* Find length of both strings */
    while (*s_temp) {
        s_temp++;
        s_len++;
    }

    while (*t_temp) {
        t_temp++;
        t_len++;
    }
    if (s_len < t_len)
        return 0;
    
    /* Point s to start of t */
    s += s_len - t_len;

    /* Start comparision */
    while (*s == *t) {
        s++;
        t++;
    }
    
    if (*s == '\0')
        return 1;
    else
        return 0;
}

int main()
{
    char str1[] = "Dhruv Mohindru";
    char str2[] = "Mohindru";
    char str3[] = "Mahindra";
    
    printf("%d\n", strend(str1, str2));
    printf("%d\n", strend(str1, str3));
    return 0;
}