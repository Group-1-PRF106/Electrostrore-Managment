#include <stdio.h>
#include <string.h>
#include "search_function.h"

void searchProductByName(Product arr[], int n, const char *keyword)
{
    int found = 0;

    // Cập nhật tiêu đề bảng: Thêm cột HANG và SO LUONG, căn lề cho phù hợp
    printf("\n%-5s %-30s %-15s %-15s %-10s\n", "ID", "TEN SAN PHAM", "HANG", "GIA(VND)", "SO LUONG");

    for(int i = 0; i < n; i++)
    {
        // strstr de tim chuoi con, phan biet hoa thuong
        if(strstr(arr[i].productname, keyword) != NULL)
        {
            // In thêm mảng productcomp (Hãng) và biến Qnt (Số lượng)
            printf("%-5d %-30s %-15s %-15d %-10d\n",
                   arr[i].productid,
                   arr[i].productname,
                   arr[i].productcomp,
                   arr[i].price,
                   arr[i].Qnt);

            found = 1;
        }
    }

    if(!found)
    {
        printf("\nKhong tim thay san pham nao chua tu khoa: '%s'!\n", keyword);
    }
}