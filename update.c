#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "search_function.h"
#include "update.h"


void updateProduct(){
	
	Product empty_product = {0};//khai báo giá trị so sánh trường hợp k tìm thấy s.phẩm
	
	bool editing = true;
	do {
		Product productChosen = searchItem(); //gán giá trị sản phẩm trả về
		if (memcmp(&productChosen, &empty_product, sizeof(Product)) == 0){
			//so sánh bộ nhớ của struct trống và struct trả về từ searchItem
			//nếu struct trả về rỗng => không tìm thấy
			printf("Product not found!");
				editing = false;
			} else {
				printf("\nProduct ID: %d", productChosen.productid);
				printf("\nProduct name: %s", productChosen.productname);
				printf("\nProduct brand: %s", productChosen.productcomp);
				printf("\nProduct price: %d", productChosen.price);
				printf("\nProduct quantity: %d", productChosen.Qnt);
	
				//Cập nhật tên sản phẩm
				updateProductName(productChosen.productname);
		
				//Cập nhật hãng sản phẩm
				updateProductBrand(productChosen.productcomp);
				
				//Cập nhật giá sản phẩm
				updateProductPrice(&productChosen.price);
		
				//Cập nhật số lượng sản phẩm
				updateProductQuantity(&productChosen.Qnt);	
				
				
// ============================================================
            // 💾 ĐOẠN XỬ LÝ FILE TẠM (ĐÃ TÍCH HỢP ĐỒNG BỘ VÀO ĐÂY)
            // ============================================================
            FILE *fileOld = fopen("NextFile.dat", "r");
            FILE *fileNew = fopen("temp.txt", "w");
            
            if (fileOld != NULL && fileNew != NULL) {
                Product currentProd;
                int isUpdated = 0; // Biến cờ đánh dấu đã tìm thấy để ghi đè chưa
                
                // Đọc từng dòng từ file gốc theo đúng định dạng dữ liệu (%d cho ID)
                while (fscanf(fileOld, "%39s %39s %d %d %d\n", currentProd.productname, currentProd.productcomp, &currentProd.price, &currentProd.productid, &currentProd.Qnt) != EOF) {
                    
                    // So sánh ID kiểu số nguyên (==)
                    if (currentProd.productid == productChosen.productid) {
                        // TRÙNG ID -> Ghi thông tin MỚI (đã sửa) vào file tạm
                        fprintf(fileNew, "%s %s %d %d %d\n", productChosen.productname, productChosen.productcomp, productChosen.price, productChosen.productid, productChosen.Qnt);
                        isUpdated = 1; 
                    } else {
                        // KHÔNG TRÙNG -> Ghi NGUYÊN XI dữ liệu cũ sang file tạm
                        fprintf(fileNew, "%s %s %d %d %d\n", currentProd.productname, currentProd.productcomp, currentProd.price, currentProd.productid, currentProd.Qnt);
                    }
                }
                
                // Đóng cả 2 file để giải phóng quyền kiểm soát của hệ điều hành
                fclose(fileOld);
                fclose(fileNew);
                
                // Thực hiện hoán đổi file để cập nhật hệ thống
                if (isUpdated == 1) {
                    remove("NextFile.dat");              // Xóa file cũ đi
                    rename("temp.txt", "NextFile.dat");  // Đổi tên file tạm thành file chính thức
                    printf("Product updated and saved to file successfully!\n");
                } else {
                    remove("temp.txt"); // Phòng hờ nếu lỗi không tìm thấy ID trong file thì xóa file tạm dư thừa
                    printf("Failed to update product in file!\n");
                }
            } else {
                printf("Error: Could not open files for data saving!\n");
                if (fileOld != NULL) fclose(fileOld);
                if (fileNew != NULL) fclose(fileNew);
            }
            // ============================================================
				
				
					
		}//ngoặc vòng else
		
		
		
		//Kiểm tra muốn cập nhật sản phẩm khác không
		printf("Do you want to update another product? Y/N");
		char update_another;
		scanf(" %c", &update_another);
		if (update_another == 'Y' || update_another == 'y'){
			editing = true;
		} else {
			editing = false;
		}//ngoặc else kiểm tra muốn update s.phẩm khác
	
	} while (editing);	
}//ngoặc hàm void