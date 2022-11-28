#include <stdbool.h>
#include <stdio.h>

bool is_prime(unsigned long long int n) {
    int divisor;
    if (n <= 1) return false;
    if (n == 2) return true;
    if (((n % 10) % 2 ) == 0) return false;
    for (divisor = 2; divisor * divisor <= n; divisor++) {
        if (n % divisor == 0) return false;
    }
    return true;
}

int main(void) {
    unsigned long long int n;
    printf("Enter a number: ");
    scanf(" %llu", &n);
    if (is_prime(n))
        printf("Prime\n");
    else
        printf("Not prime\n");
    return 0;
}
    