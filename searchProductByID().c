#include <stdio.h>
#include "search_function.h"
#include "product.h"

void searchProductByID(Product arr[], int n, int searchID)
{
    int found = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i].productid == searchID)
        {
            printf("\n%-5s %-30s %-15s %-15s %-10s\n", "ID", "TEN SAN PHAM", "HANG", "GIA(VND)", "SO LUONG");
            printf("-----------------------------------------------------------------------------------\n");
            
            printf("%-5d %-30s %-15s %-15d %-10d\n",
                   arr[i].productid,
                   arr[i].productname,
                   arr[i].productcomp,
                   arr[i].price,
                   arr[i].Qnt);

            printf("-----------------------------------------------------------------------------------\n");
            found = 1;
            break; 
        }
    }

    if(!found) {
        printf("\n[!] Khong tim thay san pham co ID: %d!\n", searchID);
    }
}