#include <stdio.h>
#include <stdbool.h>
//A Narcissistic Number (or Armstrong Number) is a positive number which is the sum of its own digits,
//each raised to the power of the number of digits in a given base.
//In this Kata, we will restrict ourselves to decimal (base 10).
bool main()
{
    int num = 153; // Example number
    if (num < 0) {
        return false;
    }

    if (num <= 9 && num >= 0) {
        return true;
    }

    int digits = 1;
    int buffer_num = num;
    while (buffer_num > 10) {
        buffer_num = buffer_num / 10;
        digits++;
    }

    buffer_num = num;
    int sum = 0;
    int digit = 0;
    while (buffer_num > 0) {
        digit = buffer_num % 10;
        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= digit;
        }
        sum += power;
        buffer_num = buffer_num / 10;
    }
    return sum == num ? true : false;
}