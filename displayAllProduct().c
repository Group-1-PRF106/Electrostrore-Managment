#include <stdio.h>
#include "search_function.h"
#include "product.h" // Để bốc mảng productList và biến productCount ra xài

void displayAllProduct(void)
{
    
    if (productCount == 0) {
        printf("\n[!] Danh sach san pham \n");
        return; 
    }

    printf("\n%-5s %-30s %-15s %-15s %-10s\n", "ID", "TEN SAN PHAM", "HANG", "GIA(VND)", "SO LUONG");
    printf("-----------------------------------------------------------------------------------\n");

    for(int i = 0; i < productCount; i++)
    {
        printf("%-5d %-30s %-15s %-15d %-10d\n", 
               productList[i].product_id, 
               productList[i].product_name, 
               productList[i].product_brand,
               productList[i].product_price, 
               productList[i].product_quantity);
    }
    printf("-----------------------------------------------------------------------------------\n");
}