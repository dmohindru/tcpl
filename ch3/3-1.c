/* Date: 20/05/19
   Description: binary search program
*/
#include <stdio.h>

/* binsearch: find x in v */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n -1;
    mid = (low+high) / 2;
    while (low <= high && v[mid] != x) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low+high) / 2;
    }
    if (v[mid] == x)
        return mid;
    else
        return -1;
}

int main()
{
    int index, n = 10;
    int v[] = {1, 3, 4, 5, 7, 9, 12, 13, 15, 21};
    (index = binsearch(6, v, n)) > -1 ? printf("Found 6 at index %d\n", index) : printf("6 not found\n");
    //index = binsearch(9, v, n) > -1 ? printf("Found 9 at index %d\n", index) : printf("9 not found\n");
    //index = binsearch(10, v, n) > -1 ? printf("Found 10 at index %d\n", index) : printf("10 not found. index: %d\n", index);


}