#define _CRT_SECURE_NO_WARNINGS    //这一行不用加上，防止编译器报错的
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// compare
int compare(const void* a, const void* b) {
    double f = *(double*)a - *(double*)b;
    if (f > 0) return 1;
    if (f < 0) return -1;
    return 0;
}
// findMedian func
double findMedian(double arr[], int n) {
    qsort(arr, n, sizeof(double), compare);
 
    return (double)arr[n/2];
}

int main(void) {
#define N 201
#define M 3
    double data[N][M];

#define MAXCHAR 100
    char buffer[MAXCHAR];
    int row = 0;
    int column = 0;
    char* ptr;

    char fn[] = "data.csv";
    FILE* fptr;
    fptr = fopen(fn, "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }
    while (fgets(buffer, MAXCHAR, fptr)) {
        column = 0;
        row++;
        if (row == 1) {
            continue;
        }
        char* value = strtok(buffer, ",");
        while (value) {
            data[row - 2][column] = strtod(value, &ptr);
            value = strtok(NULL, ",");
            column++;
        }
    }
    fclose(fptr);
    fptr = NULL;
    //===========================================================
   /* for (int i = 0; i < 201; i++) {
        printf("%d,%f\n", i, data[i][2]);
    }*/
    double column0[201];
    double column1[201];
    double column2[201];
    for (int i = 0; i < 201; i++) {
        column0[i] = data[i][0];
        column1[i] = data[i][1];
        column2[i] = data[i][2];
    }

    // caucalte middlen
    double median0 = findMedian(column0, 201);
    double median1 = findMedian(column1, 201);
    double median2 = findMedian(column2, 201);

    // print result
    printf("%.2f,%.2f,%.2f", median0, median1,median2);

    return EXIT_SUCCESS;
}