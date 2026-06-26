#include <stdio.h>
#include "search_function.h"
#include "product.h"
 
/*
 * searchProductByID()
 * - In thông tin sản phẩm tìm được ra màn hình
 * - Trả về: struct item tìm thấy, hoặc {0} nếu không có
 */
struct item searchProductByID(struct item arr[], int n, int searchID)
{
    struct item empty = {0};
 
    for (int i = 0; i < n; i++)
    {
        if (arr[i].productid == searchID)
        {
            printf("\n%-5s %-30s %-15s %-15s %-10s\n",
                   "ID", "TEN SAN PHAM", "HANG", "GIA(VND)", "SO LUONG");
            printf("-----------------------------------------------------------------------------------\n");
            printf("%-5d %-30s %-15s %-15d %-10d\n",
                   arr[i].productid,
                   arr[i].productname,
                   arr[i].productcomp,
                   arr[i].price,
                   arr[i].Qnt);
            printf("-----------------------------------------------------------------------------------\n");
 
            return arr[i]; // TIM THAY -> tra ve struct
        }
    }
 
    printf("\n[!] Khong tim thay san pham co ID: %d!\n", searchID);
    return empty; // KHONG TIM THAY -> tra ve struct rong
}