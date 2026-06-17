#include "search.h"

void sortProductsByPrice(int ascending) {
    struct item temp; // Bien tam cung kieu struct item

    // Thuat toan Bubble Sort
    for(int i = 0; i < productCount - 1; i++) {
        for(int j = 0; j < productCount - i - 1; j++) {
            
            // Xac dinh dieu kien hoan vi dua tren bien ascending
            int condition = ascending ? (productList[j].price > productList[j + 1].price) 
                                      : (productList[j].price < productList[j + 1].price);
            
            if(condition) {
                temp = productList[j];
                productList[j] = productList[j + 1];
                productList[j + 1] = temp;
            }
        }
    }

    if(ascending) {
        printf("\nDa sap xep danh sach san pham theo gia TANG DAN!\n");
    } else {
        printf("\nDa sap xep danh sach san pham theo gia GIAM DAN!\n");
    }
}
