#include <stdio.h>

int main() {
    // Declare three variables to store the numbers
    float num1, num2, num3;

    // Ask the user to input three numbers
    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    // Compare the numbers to find the largest
    if (num1 >= num2 && num1 >= num3) {
        printf("The largest number is: %.2f\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("The largest number is: %.2f\n", num2);
    } else {
        printf("The largest number is: %.2f\n", num3);
    }

    return 0;
}
