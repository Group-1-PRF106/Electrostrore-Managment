#include <stdio.h>
#include <string.h>
#include "product.h"
#include "search_function.h"
 
/*
 * searchItem()
 * - Menu trung gian cho update.c và delete.c gọi
 * - Cho người dùng chọn: tìm theo ID hoặc theo Tên
 * - Trả về: struct item tìm thấy, hoặc {0} nếu hủy / không tìm thấy
 */
struct item searchItem(void)
{
    struct item empty = {0};
    int choice;
 
    do {
        printf("\n========== CHON SAN PHAM ==========\n");
        printf("  1. Tim theo ID\n");
        printf("  2. Tim theo Ten\n");
        printf("  0. Huy / Quay lai\n");
        printf("=============================================\n");
        printf("Nhap lua chon [0-2]: ");
 
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            choice = -1;
        }
 
        switch (choice)
        {
            case 1: {
                int targetID;
                printf("\nNhap Product ID can tim: ");
                if (scanf("%d", &targetID) != 1)
                {
                    while (getchar() != '\n');
                    printf("[!] ID khong hop le!\n");
                    break;
                }
 
                struct item result = searchProductByID(productList, productCount, targetID);
 
                // Kiem tra co tim thay khong (productid == 0 la struct rong)
                if (result.productid != 0)
                {
                    return result; // TRA VE CHO UPDATE / DELETE
                }
                // Neu khong tim thay, searchProductByID da in thong bao, tiep tuc vong lap
                break;
            }
 
            case 2: {
                char keyword[MAX_NAME];
                printf("\nNhap tu khoa ten san pham: ");
                while (getchar() != '\n');
                if (fgets(keyword, sizeof(keyword), stdin) == NULL)
                    break;
                keyword[strcspn(keyword, "\n")] = '\0';
 
                if (strlen(keyword) == 0)
                {
                    printf("[!] Tu khoa khong duoc de trong!\n");
                    break;
                }
 
                struct item result = searchProductByName(productList, productCount, keyword);
 
                if (result.productid != 0)
                {
                    return result; // TRA VE CHO UPDATE / DELETE
                }
                break;
            }
 
            case 0:
                printf("Da huy tim kiem.\n");
                return empty;
 
            default:
                printf("[!] Lua chon khong hop le!\n");
        }
 
    } while (1);
}