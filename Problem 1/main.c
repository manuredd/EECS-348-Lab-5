// Manu Redd
// 3105946
// EECS 348
// Lab 05
// Oct 15 2023

#include <stdio.h>

int compareSales(const void *a, const void *b) {
    return (*(float *)b - *(float *)a);
}

int main() {
    FILE *file;
    char fileName[100];
    float salesNumbers[100];
    int count = 0;

    printf("Enter the name of the file: ");
    scanf("%99s", fileName);

    file = fopen(fileName, "r");

    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    while (count < 100 && fscanf(file, "%f", &salesNumbers[count]) == 1) {
        count++;
    }

    fclose(file);

    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    if (count == 0) {
        printf("No numbers found in the file:\n");
        return 1;
    } else {
        printf("\nMonthly sales report for 2022:\n");

        for (int i = 0; i < count; i++) {
            printf("%-10s %s %-10.2f\n", months[i], "$", salesNumbers[i]);
        }

        printf("\nSales Summary: \n");

        float smallest = salesNumbers[0];
        int smallestMonth = 0;
        float largest = salesNumbers[0];
        int largestMonth = 0;
        float sum = 0;

        for (int i = 1; i < count; i++) {
            if (salesNumbers[i] < smallest) {
                smallest = salesNumbers[i];
                smallestMonth = i;
            }
            if (salesNumbers[i] > largest) {
                largest = salesNumbers[i];
                largestMonth = i;
            }
            sum += salesNumbers[i];
        }

        float average = sum / count;

        printf("%s %s%.2f (%s)\n", "Minimum Sales:", "$", smallest, months[smallestMonth]);
        printf("%s %s%.2f (%s)\n", "Maximum Sales:", "$", largest, months[largestMonth]);
        printf("%s %s%.2f\n", "Average Sales:", "$", average);

        printf("\n6-Month Moving Average Report:\n");
        for (int i = 0; i < 7; i++) {
            float movingAverage = 0;
            for (int j = 0; j < 6; j++) {
                movingAverage += salesNumbers[i + j];
            }
            movingAverage /= 6;
            printf("%s - %s   $%.2f\n", months[i], months[i + 5], movingAverage);
        }

        // Sort sales data in descending order
        qsort(salesNumbers, count, sizeof(float), compareSales);

        printf("\nSales Report (Highest to Lowest)\n");
        printf("%-12s %s\n", "Month", "Sales");
        for (int i = 0; i < count; i++) {
            printf("%-12s $%.2f\n", months[i], salesNumbers[i]);
    }

        
    }

    return 0;
}
