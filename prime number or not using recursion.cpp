#include <stdio.h>
#include <stdbool.h>
bool isPrimeRecursive(int n, int divisor) {
    if (divisor == 1)
        return true;
    if (n % divisor == 0)
        return false;
    return isPrimeRecursive(n, divisor - 1);
}
bool isPrime(int n) {
    if (n <= 1)
        return false;
    return isPrimeRecursive(n, n - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isPrime(num))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);
    
    return 0;
}

