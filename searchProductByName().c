#include "search.h"

void searchProductByName(const char *keyword) {
    int found = 0;

    printf("\nKET QUA TIM KIEM TU KHOA \"%s\"\n", keyword);
    printf("\n%-5s %-30s %-20s %-15s %-10s\n", "ID", "TEN SAN PHAM", "HANG SAN XUAT", "GIA(VND)", "SO LUONG");
    printf("------------------------------------------------------------------------------------\n");

    for(int i = 0; i < productCount; i++) {
        // strstr tim chuoi con, neu khac NULL tuc la ten co chua keyword
        if(strstr(productList[i].productname, keyword) != NULL) {
            printf("%-5d %-30s %-20s %-15d %-10d\n",
                   productList[i].productid,
                   productList[i].productname,
                   productList[i].productcomp,
                   productList[i].price,
                   productList[i].Qnt);
            found = 1;
        }
    }

    if(!found) {
        printf("Khong tim thay san pham nao!\n");
    }
    printf("------------------------------------------------------------------------------------\n");
}