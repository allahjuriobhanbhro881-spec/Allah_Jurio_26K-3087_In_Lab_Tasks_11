#include <stdio.h>
#include <stdlib.h>

int main() {
    int *rollNumbers = NULL;
    float *marks = NULL;
    int n;
    float sum = 0.0, average = 0.0;

    printf("enter total number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("invalid number of students.\n");
        return 1;
    }

    rollNumbers = (int *)calloc(n, sizeof(int));
    marks = (float *)calloc(n, sizeof(float));

    if (rollNumbers == NULL || marks == NULL) {
        printf("memory allocation failed\n");
        free(rollNumbers);
        free(marks);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nstudent %d:\n", i + 1);
        printf("enter roll number: ");
        scanf("%d", &rollNumbers[i]);
        printf("enter marks: ");
        scanf("%f", &marks[i]);
        sum += marks[i];
    }

    average = sum / n;

    printf("\nstudent records\n");
    printf("roll no.\tmarks\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%.2f\n", rollNumbers[i], marks[i]);
    }
    printf("average marks: %.2f\n", average);

    free(rollNumbers);
    free(marks);
    rollNumbers = NULL;
    marks = NULL;

    return 0;
}
