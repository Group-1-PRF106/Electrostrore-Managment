#include <stdio.h>
#include <string.h>
#include "search_function.h"

// Đổi kiểu trả về từ void sang Product
Product searchItem(Product arr[], int n) {
    int choice;
    int c;
    Product empty_product = {0}; // Sản phẩm rỗng dùng để trả về khi hủy hoặc không tìm thấy
    
    do {
        printf("\n================ TIM KIEM SAN PHAM ================\n");
        printf("1. Tim kiem san pham theo ID\n");
        printf("2. Tim kiem san pham theo Ten\n");
        printf("0. Quay lai menu chinh\n");
        printf("===================================================\n");
        printf("Vui long nhap lua chon cua ban: ");
        
        if (scanf("%d", &choice) != 1) {
            while((c = getchar()) != '\n' && c != EOF);
            choice = -1;
        } else {
            while((c = getchar()) != '\n' && c != EOF);
        }

        switch(choice) {
            case 1: {
                int searchID;
                printf("\nNhap ID san pham can tim: ");
                scanf("%d", &searchID);
                while((c = getchar()) != '\n' && c != EOF); 
                
                // TÌM KIẾM THEO ID VÀ TRẢ VỀ
                for(int i = 0; i < n; i++) {
                    if(arr[i].productid == searchID) {
                        return arr[i]; // Tìm thấy, thoát hàm và trả về struct này luôn
                    }
                }
                // Nếu chạy hết vòng lặp mà không thấy:
                printf("\nKhong tim thay san pham co ID: %d!\n", searchID);
                break;
            }
            case 2: {
                char keyword[100];
                printf("\nNhap ten san pham hoac tu khoa can tim: ");
                fgets(keyword, sizeof(keyword), stdin);
                keyword[strcspn(keyword, "\n")] = 0; 
                
                // Vẫn dùng hàm cũ để in ra màn hình danh sách các sản phẩm khớp tên
                searchProductByName(arr, n, keyword);
                
                // THÊM BƯỚC: Yêu cầu người dùng chọn 1 ID từ danh sách vừa in ra
                int selectID;
                printf("\nNhap ID cua san pham ban muon CHON de cap nhat (hoac nhap 0 de huy): ");
                if (scanf("%d", &selectID) != 1) selectID = 0;
                while((c = getchar()) != '\n' && c != EOF);

                if (selectID == 0) {
                    break; // Quay lại menu tìm kiếm
                }

                // Tìm sản phẩm với ID vừa chọn và trả về
                for(int i = 0; i < n; i++) {
                    if(arr[i].productid == selectID) {
                        return arr[i]; // Trả về struct được chọn
                    }
                }
                printf("\nKhong tim thay san pham co ID: %d!\n", selectID);
                break;
            }
            case 0:
                printf("\nDang huy tim kiem...\n");
                return empty_product; // Trả về struct rỗng nếu người dùng thoát
                
            default:
                printf("\nLua chon khong hop le! Vui long nhap tu 0 den 2.\n");
        }
    } while(choice != 0);

    return empty_product;
}