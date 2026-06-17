#include <stdio.h>
#include <string.h>
#include "search.h"

void searchProductByName(Product arr[], int n, const char *keyword)
{
    int found = 0;

    printf("\n%-5s %-35s %-15s\n",
           "ID","TEN SAN PHAM","GIA");

    for(int i=0;i<n;i++)
    {
        if(strstr(arr[i].name, keyword))
        {
            printf("%-5d %-35s %-15.2f\n",
                   arr[i].id,
                   arr[i].name,
                   arr[i].price);

            found = 1;
        }
    }

    if(!found)
    {
        printf("\nKhong tim thay san pham!\n");
    }
}