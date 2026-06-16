#include "declareFunction.h"
#include <stdbool.h>
#include <stdio.h>

void deleteProduct(){
	// Giữ nguyên khai báo struct bên trong hàm theo yêu cầu của bạn
	struct ProductDetails {
		int product_id;
		char product_name[40];
		char product_brand[40];
		float product_price;
		int product_quantity;
	};
	
	loadData();
	int choice;
	bool deleting = true;
	char delete_more;
	int out_delete_loops;
	struct ProductDetails productDisplay;
	
	//Khai báo 2 con trỏ FILE
	FILE *fileProductList = fopen("NextFile.dat", "r");
	FILE *fileTemp = fopen("temp.txt", "w");
	//Kiểm tra mở được hay không
	if (fileGoc == NULL || fileTam == NULL) {
    	if (fileProductList) fclose(fileProductList);
    	if (fileTemp) fclose(fileTemp);
    	printf("Error!!!");
    	return;
	
	while (deleting) {	
		bool found = searchItem(); // Tự nhảy qua hàm nhập dữ liệu và tìm kiếm bên searchItem()

		if (found == true) {
			struct ProductDetails currentProd; // Biến tạm hứng dữ liệu cũ từng dòng
			printf("--- PRODUCT DETAILS ---\n");
			printf("Product ID: %d\n", productDisplay.product_id);
			printf("Product name: %s\n", productDisplay.product_name);
			printf("Product brand: %s\n", productDisplay.product_brand);
			printf("Product price: %f\n", productDisplay.product_price);
			printf("Product quantity: %d\n", productDisplay.product_quantity);
			
			out_delete_loops = 0;
			while (true) {
				printf("Do you want to delete this product?\n");
				printf("1. Yes\n");
				printf("2. No\n");
				printf("3. Back to menu\n");
				if (scanf("%d", &choice) != 1) {
					printf("Invalid input! Please enter a number.\n");
					while (getchar() != '\n'); // Tránh lặp vô hạn khi nhập lỗi
					continue;
				}
				
				switch (choice) {
					case 1: 
						
			  			}
						saveData(); 
						printf("Output: Delete successful\n");
						out_delete_loops = 1;
						break;
						
					case 2: // Chọn No -> xuống Xóa sảb phẩm khác
						out_delete_loops = 1;
						break;
						
					case 3: // Chọn Back to menu
						return;
						
					default:
						printf("Invalid choice! Please select 1, 2, or 3.\n");
						break;
				}
				
				if (out_delete_loops == 1) {
					break;
				}
			}
				while (fscanf(fileProductList, "%d,%[^,],%[^,],%f,%d\n", 
			            &currentProd.product_id, currentProd.product_name, 
			              currentProd.product_brand, &currentProd.product_price, 
			            &currentProd.product_quantity) != EOF){
			        if (currentProd.product_id == updatedProd.product_id) {
						// Nếu TRÙNG ID -> Ghi dữ liệu MỚI (đã sửa) vào file tạm
						fprintf(fileTemp, "%d,%s,%s,%.2f,%d\n", 
								updatedProd.product_id, updatedProd.product_name, 
								updatedProd.product_brand, updatedProd.product_price, 
								updatedProd.product_quantity);
					}else {
						// Nếu KHÔNG TRÙNG -> Ghi lại dữ liệu CŨ (giữ nguyên) vào file tạm
						fprintf(fileTemp, "%d,%s,%s,%.2f,%d\n", 
						currentProd.product_id, currentProd.product_name, 
						currentProd.product_brand, currentProd.product_price, 
						currentProd.product_quantity);
					}
				}
				//đóng 2 file lại
				fclose(fileProductList);
				fclose(fileTemp);	
				//xóa file gốc, đổi file temp thành file gốc
				remove("NextFile.dat");
				rename("temp.txt", "NextFile.dat");	
		} else {
			printf("Product is not found!\n");
		}
		
		
		printf("Do you want to delete another product? Y/N? ");
		scanf(" %c", &delete_more);
		if (delete_more == 'Y' || delete_more == 'y') {		
		} else {
			delete_more = 'N';
			return;
		}
		
	}
}