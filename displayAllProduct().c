#include "search.h"

void displayAllProduct(int showPrice) {
    // Kiem tra neu mang rong
    if (productCount == 0) {
        printf("Danh sach san pham hien dang trong!\n");
        return;
    }

    if(showPrice) {
        printf("\n%-5s %-30s %-20s %-15s %-10s\n", "ID", "TEN SAN PHAM", "HANG SAN XUAT", "GIA(VND)", "SO LUONG");
        printf("------------------------------------------------------------------------------------\n");
        for(int i = 0; i < productCount; i++) {
            printf("%-5d %-30s %-20s %-15d %-10d\n",
                   productList[i].productid,
                   productList[i].productname,
                   productList[i].productcomp,
                   productList[i].price,
                   productList[i].Qnt);
<<<<<<< HEAD
        }
    } else {
        printf("\n%-5s %-30s %-20s %-10s\n", "ID", "TEN SAN PHAM", "HANG SAN XUAT", "SO LUONG");
        printf("----------------------------------------------------------------------\n");
        for(int i = 0; i < productCount; i++) {
            printf("%-5d %-30s %-20s %-10d\n",
                   productList[i].productid,
                   productList[i].productname,
                   productList[i].productcomp,
                   productList[i].Qnt);
        }
    }
    printf("------------------------------------------------------------------------------------\n");
}
=======
        }
    } else {
        printf("\n%-5s %-30s %-20s %-10s\n", "ID", "TEN SAN PHAM", "HANG SAN XUAT", "SO LUONG");
        printf("----------------------------------------------------------------------\n");
        for(int i = 0; i < productCount; i++) {
            printf("%-5d %-30s %-20s %-10d\n",
                   productList[i].productid,
                   productList[i].productname,
                   productList[i].productcomp,
                   productList[i].Qnt);
        }
    }
    printf("------------------------------------------------------------------------------------\n");
}
>>>>>>> 8b2e0fc3a8ada0779f5970a2b6ec7c776c311b46
