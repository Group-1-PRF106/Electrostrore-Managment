#include <stdio.h>
#include <string.h>
#include "search_function.h"
#include "product.h"

void searchProductByName(Product arr[], int n, const char *keyword)
{
    int found = 0;

    for(int i = 0; i < n; i++)
    {
        // strstr tim chuoi con (co phan biet hoa thuong)
        if(strstr(arr[i].productname, keyword) != NULL)
        {
            // Neu day la san pham dau tien hop le duoc tim thay -> Moi in cai Header!
            if (found == 0) {
                printf("\n%-5s %-30s %-15s %-15s %-10s\n", "ID", "TEN SAN PHAM", "HANG", "GIA(VND)", "SO LUONG");
                printf("-----------------------------------------------------------------------------------\n");
            }

            printf("%-5d %-30s %-15s %-15d %-10d\n",
                   arr[i].productid,
                   arr[i].productname,
                   arr[i].productcomp,
                   arr[i].price,
                   arr[i].Qnt);

            found = 1;
        }
    }

    if(!found) {
        printf("\n[!] Khong tim thay san pham nao chua tu khoa: '%s'!\n", keyword);
    } else {
        // Khoa duoi bang lai neu co san pham duoc in ra
        printf("-----------------------------------------------------------------------------------\n");
    }
}