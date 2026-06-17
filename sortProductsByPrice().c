#include <stdio.h>
#include "search.h"

void sortProductsByPrice(Product arr[], int n)
{
    Product temp;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j].price > arr[j+1].price)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nDa sap xep thanh cong!\n");
}