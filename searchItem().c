#include "product.h"
#include "search_function.h"
#include "data.h"

// ====================================================================
// HÀM 1: DÙNG CHO MENU CHÍNH (Tra cứu để XEM)
// ====================================================================
void search_item(void) {
	int choice;
	do {
		printf("\n========== SEARCH MENU ==========\n");
		printf("  1. Search Product by ID\n");
		printf("  2. Search Product by Name\n");
		printf("  0. Back to Main Menu\n");
		printf("=================================\n");
		printf("Enter your choice [0-2]: ");
		
		if (scanf("%d", &choice) != 1) {
			while(getchar() != '\n'); // Dọn rác buffer nếu người dùng nhập chữ
			choice = -1;
		}

		switch(choice) {
			case 1: {
				int id;
				printf("\nEnter Product ID to search: ");
				if (scanf("%d", &id) == 1) {
					// Gọi hàm searchProductByID bên file searchProductByID().c
					searchProductByID(productList, productCount, id); 
				} else {
					while(getchar() != '\n');
					printf("\n[!] Invalid ID format!\n");
				}
				break;
			}
			case 2: {
				char keyword[MAX_NAME];
				printf("\nEnter keyword for Product Name: ");
				
				// Khắc phục lỗi trôi lệnh kinh điển của C khi dùng fgets liền sau scanf
				while(getchar() != '\n'); 
				
				fgets(keyword, sizeof(keyword), stdin);
				keyword[strcspn(keyword, "\n")] = '\0'; 

				if (strlen(keyword) > 0) {
					// Gọi hàm searchProductByName bên file searchProductByName().c
					searchProductByName(productList, productCount, keyword);
				} else {
					printf("\n[!] Keyword cannot be empty!\n");
				}
				break;
			}
			case 0:
				return; // Quay lại Menu Admin/User
			default:
				printf("\n[!] Invalid choice! Please select 0, 1, or 2.\n");
		}
	} while(1);
}


// ====================================================================
// HÀM 2: DÙNG CHO HÀM UPDATE / DELETE (Tra cứu để TRẢ VỀ ĐỐI TƯỢNG)
// ====================================================================
struct item searchItem(void) {
    struct item empty_item = {0}; // tạo 1 struct rỗng
    int targetID;

    printf("\n[System] Enter the Product ID you want to select: ");
    if (scanf("%d", &targetID) != 1) {
        while(getchar() != '\n');
        return empty_item; //Nhập sai -> Trả về struct rỗng
    }

    
    for(int i = 0; i < productCount; i++) {
        if(productList[i].productid == targetID) {
            return productList[i]; // tìm thấy -> Trả về nguyên bản sao của struct đó
        }
    }

    return empty_item; 
}