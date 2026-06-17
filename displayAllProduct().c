#include <stdio.h>
#include "search.h"

void displayAllProduct(Product arr[], int n, int showPrice)
{
    if(showPrice)
    {
        printf("\n%-5s %-35s %-15s\n",
               "ID", "TEN SAN PHAM", "GIA(VND)");

        for(int i=0;i<n;i++)
        {
            printf("%-5d %-35s %-15.2f\n",
                   arr[i].id,
                   arr[i].name,
                   arr[i].price);
        }
    }
    else
    {
        printf("\n%-5s %-35s\n",
               "ID", "TEN SAN PHAM");

        for(int i=0;i<n;i++)
        {
            printf("%-5d %-35s\n",
                   arr[i].id,
                   arr[i].name);
        }
    }
}