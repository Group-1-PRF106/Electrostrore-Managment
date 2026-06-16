#include "declareFunction.h"
#include <stdio.h>
#include <stdbool.h>

void updateProduct(){
	
	loadData();
	//chọn kiểu tìm kiếm
	//update sản phẩm khác?
	int choice;
	//nhập kiểu tìm kiếm => trả về "Thấy" hoặc "Không thấy" = found
	//temp_name,
	char temp_name[40];
	char temp_brand[40];
	float temp_price;
	int temp_quantity;
	//
	bool editing = true;
	char edit_more;
	//flag out while loops
 	int out_loops;
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
		
	while (editing) {	
		bool found = searchItem(); // tự nhảy qua hàm nhập dữ liệu bên searchiItem()

		if (found == true) {
			printf("--- PRODUCT DETAILS ---\n");
			printf("Product ID: %d\n", productDisplay.product_id);
		   	printf("Product name: %s\n", productDisplay.product_name);
		   	printf("Product brand: %s\n", productDisplay.product_brand);
		  	printf("Product price: %f\n", productDisplay.product_price);
	    	printf("Product quantity: %d\n", productDisplay.product_quantity);
	    	
	    	//update name
    		out_loops = 0;
	    	while (true){
	    		printf("Do you want to update product name?\n");
	    		printf("1. Yes\n");
	    		printf("2. No\n");
	    		printf("3. Back to menu\n");
	    		scanf("%d", &choice);
	    			switch (choice) {
	    				case 2: 
	    					out_loops = 1;
	    					break;
	    				case 1: 
							printf("Enter the new name: \n");
			    			scanf(" %[^\n]", temp_name);
			    			if (checkNameValid(temp_name)){
			    				scanf("[%\n]", updatedProd.product_name);
			    				out_loops = 1;
			    				break;
							}
							break;
						case 3: 
							return;
						default:
							break;
						}
				if (out_loops == 1){
					break;
				}
			}
	
	    	//update brand
    		out_loops = 0;
	    	while (true){
	    		printf("Do you want to update product brand?\n");
	    		printf("1. Yes\n");
	    		printf("2. No\n");
	    		printf("3. Back to menu\n");
	    		scanf("%d", &choice);
	    			switch (choice) {
	    				case 2: 
	    					out_loops = 1;
	    					break;
	    				case 1: 
							printf("Enter the new brand: \n");
			    			scanf(" %[^\n]", temp_brand);
			    			if (checkBrandValid(temp_brand)){
			    				out_loops = 1;
			    				scanf("[%\n]", updatedProd.product_brand);
			    				break;
							}
							break;
						case 3: 
							return;
						default:
							break;
						}
				if (out_loops == 1) {
					break;
				}
			}
	
	    	//update price
    		out_loops = 0;
	    	while (true){
	    		printf("Do you want to update product price?\n");
	    		printf("1. Yes\n");
	    		printf("2. No\n");
	    		printf("3. Back to menu\n");
	    		scanf("%d", &choice);
	    			switch (choice) {
	    				case 2: 
	    					out_loops = 1;
	    					break;
	    				case 1: 
							printf("Enter the new price: \n");
			    			scanf("%f", &temp_price);
			    			if (checkPriceValid(temp_price)){
			    				out_loops = 1;
			    				scanf("%f", updatedProd.product_price);
			    				break;
							}
							break;
						case 3: 
							return;
						default:
							break;
						}
				if (out_loops == 1) {
					break;
				}
			}
	
	    	//update quantity
    		out_loops = 0;
	    	while (true){
	    		printf("Do you want to update product quantity?\n");
	    		printf("1. Yes\n");
	    		printf("2. No\n");
	    		printf("3. Back to menu\n");
	    		scanf("%d", &choice);
	    			switch (choice) {
	    				case 2: 
	    					out_loops = 1;
	    					break;
	    				case 1: 
							printf("Enter the new quantity: \n");
			    			scanf("%d", &temp_quantity);
			    			if (checkQuantityValid(temp_quantity)){
			    				out_loops = 1;
			    				scanf("[%\n]", updatedProd.product_quantity);
			    				break;
							}
							break;
						case 3: 
							return;
						default:
							break;
						}
				if (out_loops == 1) {
					break;
				}
			}
		} else {
			printf("Product is not found!\n");
		}
		
	while (fscanf(fileProductList, "%[^,],%[^,],%f,%d\n", 
            currentProd.product_name, 
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
			
		printf("Do you want to update another product? Y/N?");
		scanf(" %c", &edit_more);
			if (edit_more == 'Y' || edit_more == 'y'){		
			} else {
				edit_more = 'N';
				return;
				break;
			}
	}//ngoặc hàm while lớn editing
} // ngoặc hàm void