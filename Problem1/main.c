// Manu Redd
// 3105946
// EECS 348
// Lab 05
// Oct 15 2023

#include <stdio.h>

int main () {
    FILE *file;
    char fileName[100];
    int salesNumbers[100];
    int count = 0;

    printf("Enter the name of the file: ");
    scanf("%99", fileName);

    file = fopen(fileName, "r");

    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    while (count < 100 && fscanf(file, "%d", &salesNumbers[count]) == 1) {
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("No numbers found in the file:\n"); 
        return 1;   
    }
    else {
        printf("Numbers from the file:\n");
        for (int i = 0; i < count; i++) {
            printf("%d\n", salesNumbers[i]);
        }

    return 0;
}
