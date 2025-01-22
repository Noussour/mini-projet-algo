#include <stdio.h>
#include <time.h>

double PSum_2(long long int n) {
    double S = 0.0;
    long long int i = 1;
    while (i <= n) {
        S += i;
        i++;
    }
    return S;
}

int main() {
    double n_values[] = {1e6, 2e6, 1e7, 2e7, 1e8, 2e8, 1e9, 2e9, 1e10, 2e10, 1e11, 2e11, 1e12, 2e12};
    int num_values = sizeof(n_values) / sizeof(n_values[0]);

    // Open a CSV file for writing
    FILE *file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the header to the CSV file
    fprintf(file, "n,Execution Time (seconds)\n");

    printf("n\t\tExecution Time (seconds)\n");
    printf("---------------------------------\n");

    for (int i = 0; i < num_values; i++) {
        long long int n = (long long int)n_values[i]; // Cast to long long int
        clock_t start = clock(); // Start time
        double result = PSum_2(n); // Call the function
        clock_t end = clock(); // End time

        double execution_time = (double)(end - start) / CLOCKS_PER_SEC;

        // Print to console
        printf("%lld\t\t%.6f\n", n, execution_time);

        // Write to CSV file
        fprintf(file, "%lld,%.6f\n", n, execution_time);
    }

    // Close the CSV file
    fclose(file);

    return 0;
}