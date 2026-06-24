include <stdio.h>
#include "search_function.h"
#include "product.h" // Lấy productList và productCount
#include "data.h"    // Để xài lệnh saveData()

void sortProductsByPrice(void)
{
    if (productCount < 2) {
        printf("\n[!] Kho co it hon 2 san pham, khong can sap xep!\n");
        return;
    }

    struct item temp;

    // Sắp xếp nổi bọt mảng productList trên RAM theo giá tăng dần
    for(int i = 0; i < productCount - 1; i++)
    {
        for(int j = 0; j < productCount - i - 1; j++)
        {
            if(productList[j].price > productList[j+1].price)
            {
                temp = productList[j];
                productList[j] = productList[j+1];
                productList[j+1] = temp;
            }
        }
    }

    printf("\n[Sap xep] Da sap xep thanh cong theo GIA TANG DAN!\n");

    // Gọi saveData() để ghi mảng vừa sắp xếp xuống NextFile.dat theo ĐÚNG CHUẨN
    saveData(); 
}