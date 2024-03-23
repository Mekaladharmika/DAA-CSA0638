#include <stdio.h>
#include <math.h>
int countDigits(int num) {
    if (num == 0)
        return 0;
    return 1 + countDigits(num / 10);
}
int power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    return base * power(base, exponent - 1);
}
int isArmstrong(int num, int n) {
    if (num == 0)
        return 0;
    return power(num % 10, n) + isArmstrong(num / 10, n);
}
int main() {
    int number, digits, result;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    digits = countDigits(number);
    result = isArmstrong(number, digits);
    
    if (result == number)
        printf("%d is an Armstrong number.\n", number);
    else
        printf("%d is not an Armstrong number.\n", number);
    
    return 0;
}
