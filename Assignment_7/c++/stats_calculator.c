#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Compare function for qsort to implement sorting of the integers in ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to calculate the mean of the array of integers
double calculate_mean(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];          // running sum of all elements from the array
    }
    return (double)sum / size;  // return mean as a double
}

// Function to calculate the median of the array of integers
double calculate_median(int *arr, int size) {
    if (size == 0) return -INFINITY;    // Handle empty array case, return negative infinty if no elements

    // sort the array (in ascending order) to find the median -- using qsort
    qsort(arr, size, sizeof(int), compare);

    // If the size of array is even, return the average of the two middle elements
    if (size % 2 == 0) {
        return (arr[size/2 - 1] + arr[size/2]) / 2.0;
    }  // If the size is odd, return the middle element
    else {
        return arr[size/2];
    }
}

// Function to calculate the mode(s) of an array of integers
void calculate_mode(int *arr, int size, int *mode_arr, int *mode_count) {
    int max_value = INT_MIN, min_value = INT_MAX;

    // Find the range of the array (min and max values)
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_value) max_value = arr[i];
        if (arr[i] < min_value) min_value = arr[i];
    }

    int range = max_value - min_value + 1;
    // an array to store the frequency of each number in the original array
    // indexed from 0 to range - 1 (so each index represents [the number in the original array - min_value])
    // for example, if min_value is 10 and max_value is 35, then the array is indexed from 0 to 25
    // and index 0 represents the number 10, index 1 represents the number 11, ..., and index 25 represents number 35
    int *frequency = calloc(range, sizeof(int));

    // Count the frequency of each number
    for (int i = 0; i < size; i++) {
        frequency[arr[i] - min_value]++;
    }

    // Find the maximum frequency
    int max_count = 0;
    for (int i = 0; i < range; i++) {
        if (frequency[i] > max_count) {
            max_count = frequency[i];
        }
    }

    // Identify the mode(s)
    *mode_count = 0;
    for (int i = 0; i < range; i++) {
        if (frequency[i] == max_count && max_count > 1) {
            // as per the explanation and example from above,
            // the mode will be the index value in the frequency array + min_value (= 10 for our example)
            mode_arr[*mode_count] = i + min_value;
            (*mode_count)++;
        }
    }

    free(frequency); // Free the allocated memory
}

// Main function with an example
int main() {
    // Input data array
    int data[] = {10, 13, 22, 34, 22, 35, 13, 13};
    int size = sizeof(data) / sizeof(data[0]);

    // Printing the original input data array
    printf("Data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n");

    // Calculate and print the mean
    double mean = calculate_mean(data, size);
    printf("Mean: %.2f\n", mean);

    // Copy array for median computation to avoid modifying the original array
    int *copy = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) copy[i] = data[i];

    // Calculate and print the median
    double median = calculate_median(copy, size);
    printf("Median: %.2f\n", median);

    // Free the copied array
    free(copy);

    // Calculate and print the mode(s)
    int mode_arr[size];
    int mode_count;
    calculate_mode(data, size, mode_arr, &mode_count);

    if (mode_count == 0) {
        printf("Mode: No mode (all numbers occur only once)\n");
    } else {
        printf("Mode: ");
        for (int i = 0; i < mode_count; i++) {
            printf("%d ", mode_arr[i]);
        }
        printf("\n");
    }

    return 0;
}
