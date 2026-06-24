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
               productList[i].productid, 
               productList[i].productname, 
               productList[i].productcomp,
               productList[i].price, 
               productList[i].Qnt);
    }
    printf("-----------------------------------------------------------------------------------\n");
}