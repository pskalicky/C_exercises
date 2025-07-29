#include <stdbool.h>
#include <math.h>

bool narcissistic(int num)
{
    int p = log10(num) + 1; // can be off
    int n = num;
    do
        num -= pow(n % 10, p);
    while (n /= 10);
    return !num;
}