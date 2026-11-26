#include <stdio.h>
#include <stdlib.h>

int main() {
    float *prices = NULL;
    int initialItems, extraItems, totalItems;
    float totalBill = 0.0;

    printf("how many products do you want to purchase initially? ");
    scanf("%d", &initialItems);

    if (initialItems <= 0) {
        printf("cart is empty.\n");
        return 0;
    }

    prices = (float *)malloc(initialItems * sizeof(float));
    if (prices == NULL) {
        printf("memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < initialItems; i++) {
        printf("enter price of product %d: ", i + 1);
        scanf("%f", &prices[i]);
    }

    totalItems = initialItems;

    printf("\nhow many additional products do you want to add (0 for none)? ");
    scanf("%d", &extraItems);

    if (extraItems > 0) {
        totalItems = initialItems + extraItems;

        float *temp = (float *)realloc(prices, totalItems * sizeof(float));
        if (temp == NULL) {
            printf("memory reallocation failed\n");
            free(prices);
            return 1;
        }
        prices = temp;

        for (int i = initialItems; i < totalItems; i++) {
            printf("enter price of product %d: ", i + 1);
            scanf("%f", &prices[i]);
        }
    }

    printf("\nshopping cart summary\n");
    for (int i = 0; i < totalItems; i++) {
        printf("product %d: %.2f\n", i + 1, prices[i]);
        totalBill += prices[i];
    }
    printf("total shopping bill: %.2f\n", totalBill);

    free(prices);
    prices = NULL;

    return 0;
}
