#include <stdio.h>
#include "search_function.h"

void sortProductsByPrice(Product arr[], int n, const char* filename)
{
    Product temp;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
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

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("\nLoi: Khong the mo file %s de luu du lieu!\n", filename);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        fprintf(file, "%d,%s,%d\n", arr[i].productid, arr[i].productname, arr[i].price);
    }

    // Chỉ đóng file, KHÔNG in thông báo gì thêm
    fclose(file);
}