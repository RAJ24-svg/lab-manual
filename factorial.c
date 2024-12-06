#include <stdio.h>

int main() {
    int n, i;
    long long factorial = 1;  // To store the factorial (using long long for larger numbers)

    // Ask the user to input a number
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check if the input is a negative number
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Calculate the factorial using a for loop
        for (i = 1; i <= n; i++) {
            factorial *= i;  // Multiply factorial by i in each iteration
        }

        // Print the result
        printf("Factorial of %d is %lld\n", n, factorial);
    }

    return 0;
}
