#include <stdio.h>
#include "search_function.h"

void searchProductByID(Product arr[], int n, int searchID)
{
    int found = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i].productid == searchID)
        {
            // 1. In tiêu đề cột giống hệt hàm tìm theo tên
            printf("\n%-5s %-30s %-15s %-15s %-10s\n", "ID", "TEN SAN PHAM", "HANG", "GIA(VND)", "SO LUONG");
            
            // 2. In dữ liệu của sản phẩm trên cùng một hàng ngang
            printf("%-5d %-30s %-15s %-15d %-10d\n",
                   arr[i].productid,
                   arr[i].productname,
                   arr[i].productcomp,
                   arr[i].price,
                   arr[i].Qnt);

            found = 1;
            break; // Tìm thấy ID là dừng luôn vì ID là duy nhất
        }
    }

    if(!found)
    {
        printf("\nKhong tim thay san pham co ID: %d!\n", searchID);
    }
}