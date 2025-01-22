#include <stdio.h>

double PSum_1(int n) {
    double S = 0.0;
    int i = 1;
    while (i <= n) {
        S += i;
        i++;
    }
    return S;
}

int main() {
    int n;
    printf("Enter a natural number n (n >= 1): ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Error: n must be greater than or equal to 1.\n");
        return 1;
    }

    double result = PSum_1(n);
    printf("The sum of the first %d natural numbers is: %.0f\n", n, result);

    return 0;
}
