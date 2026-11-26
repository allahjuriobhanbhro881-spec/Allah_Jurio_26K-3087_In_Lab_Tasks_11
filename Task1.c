#include <stdio.h>
#include <stdlib.h>

int main() {
    int *regNumbers = NULL;
    int initialCount, extraCount, totalCount;

    printf("enter initial number of registering students: ");
    scanf("%d", &initialCount);

    if (initialCount <= 0) {
        printf("invalid number of students.\n");
        return 1;
    }

    regNumbers = (int *)malloc(initialCount * sizeof(int));
    if (regNumbers == NULL) {
        printf("memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < initialCount; i++) {
        printf("enter registration number for student %d: ", i + 1);
        scanf("%d", &regNumbers[i]);
    }

    printf("\nregistered students (phase 1)\n");
    for (int i = 0; i < initialCount; i++) {
        printf("student %d: %d\n", i + 1, regNumbers[i]);
    }

    printf("\nenter number of additional students to register: ");
    scanf("%d", &extraCount);

    if (extraCount > 0) {
        totalCount = initialCount + extraCount;

        int *temp = (int *)realloc(regNumbers, totalCount * sizeof(int));
        if (temp == NULL) {
            printf("memory reallocation failed\n");
            free(regNumbers);
            return 1;
        }
        regNumbers = temp;

        for (int i = initialCount; i < totalCount; i++) {
            printf("enter registration number for student %d: ", i + 1);
            scanf("%d", &regNumbers[i]);
        }

        printf("\nall registered students (phase 2)\n");
        for (int i = 0; i < totalCount; i++) {
            printf("student %d: %d\n", i + 1, regNumbers[i]);
        }
    }

    free(regNumbers);
    regNumbers = NULL;

    return 0;
}
