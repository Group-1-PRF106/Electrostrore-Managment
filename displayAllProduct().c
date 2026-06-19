#include <stdio.h>
#include "search_function.h"

void displayAllProduct(Product arr[], int n, int showPrice, const char* filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("\nLoi: Khong the mo file %s de ghi!\n", filename);
        return; 
    }

    if(showPrice)
    {
        printf("\n%-5s %-35s %-15s\n", "ID", "TEN SAN PHAM", "GIA(VND)");
        fprintf(file, "%-5s %-35s %-15s\n", "ID", "TEN SAN PHAM", "GIA(VND)");

        for(int i = 0; i < n; i++)
        {
            printf("%-5d %-35s %-15d\n", arr[i].productid, arr[i].productname, arr[i].price);
            fprintf(file, "%-5d %-35s %-15d\n", arr[i].productid, arr[i].productname, arr[i].price);
        }
    }
    else
    {
        printf("\n%-5s %-35s\n", "ID", "TEN SAN PHAM");
        fprintf(file, "%-5s %-35s\n", "ID", "TEN SAN PHAM");

        for(int i = 0; i < n; i++)
        {
            printf("%-5d %-35s\n", arr[i].productid, arr[i].productname);
            fprintf(file, "%-5d %-35s\n", arr[i].productid, arr[i].productname);
        }
    }

    // Chỉ đóng file, KHÔNG in thông báo gì thêm
    fclose(file);
}