#include <stdio.h>
#include <string.h>
#include "search_function.h"
#include "product.h"
 
/*
 * searchProductByName()
 * - In danh sách sản phẩm khớp từ khóa (kèm số thứ tự)
 * - Hỏi người dùng nhập số thứ tự để chọn
 * - Trả về: struct item được chọn, hoặc {0} nếu hủy / không tìm thấy
 */
struct item searchProductByName(struct item arr[], int n, const char *keyword)
{
    struct item empty = {0};
    int matchIndex[MAX_PRODUCTS]; // Lưu vị trí các sản phẩm khớp
    int matchCount = 0;
 
    // Tìm và in danh sách khớp từ khóa
    for (int i = 0; i < n; i++)
    {
        if (strstr(arr[i].productname, keyword) != NULL)
        {
            if (matchCount == 0)
            {
                printf("\n%-5s %-30s %-15s %-15s %-10s\n",
                       "STT", "TEN SAN PHAM", "HANG", "GIA(VND)", "SO LUONG");
                printf("-----------------------------------------------------------------------------------\n");
            }
            printf("%-5d %-30s %-15s %-15d %-10d\n",
                   matchCount + 1,          // So thu tu (1, 2, 3...)
                   arr[i].productname,
                   arr[i].productcomp,
                   arr[i].price,
                   arr[i].Qnt);
            matchIndex[matchCount] = i;     // Luu vi tri trong mang goc
            matchCount++;
        }
    }
 
    if (matchCount == 0)
    {
        printf("\n[!] Khong tim thay san pham nao chua tu khoa: '%s'!\n", keyword);
        return empty;
    }
 
    printf("-----------------------------------------------------------------------------------\n");
 
    // Neu chi co 1 ket qua, tra ve luon khoi can chon
    if (matchCount == 1)
    {
        printf("[*] Chi co 1 ket qua, tu dong chon san pham nay.\n");
        return arr[matchIndex[0]];
    }
 
    // Nhieu ket qua -> hoi chon so thu tu
    int pick;
    printf("\n[?] Nhap so thu tu san pham muon chon (1-%d), nhap 0 de huy: ", matchCount);
    if (scanf("%d", &pick) != 1 || pick == 0)
    {
        while (getchar() != '\n');
        return empty;
    }
 
    if (pick < 1 || pick > matchCount)
    {
        printf("[!] So thu tu khong hop le!\n");
        return empty;
    }
 
    return arr[matchIndex[pick - 1]]; // Tra ve struct da chon
}