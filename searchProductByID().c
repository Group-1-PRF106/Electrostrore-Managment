#include <stdio.h>
#include "search.h"

void searchProductByID(Product arr[], int n, int searchID)
{
    int found = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i].id == searchID)
        {
            printf("\nID : %d", arr[i].id);
            printf("\nTen: %s", arr[i].name);
            printf("\nGia: %.2f\n", arr[i].price);

            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("\nKhong tim thay san pham!\n");
    }
}