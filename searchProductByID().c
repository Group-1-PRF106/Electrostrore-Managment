#include "search.h"

void searchProductByID(int searchID) {
    int found = 0;
    
    printf("\nKET QUA TIM KIEM ID %d\n", searchID);
    printf("--------------------------------------------------------------\n");

    for(int i = 0; i < productCount; i++) {
        if(productList[i].productid == searchID) {
            printf("ID        : %d\n", productList[i].productid);
            printf("Ten       : %s\n", productList[i].productname);
            printf("Hang      : %s\n", productList[i].productcomp);
            printf("Gia       : %d VND\n", productList[i].price);
            printf("So luong  : %d\n", productList[i].Qnt);
            
            found = 1;
            break; // Tim thay thi dung vong lap luon
        }
    }

    if(!found) {
        printf("Khong tim thay san pham co ID %d!\n", searchID);
    }
    printf("--------------------------------------------------------------\n");
<<<<<<< HEAD
}
=======
}
>>>>>>> 8b2e0fc3a8ada0779f5970a2b6ec7c776c311b46
