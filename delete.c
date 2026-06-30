#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "search_function.h"

void deleteProduct(){
    Product empty_product = {0}; // Khai báo giá trị so sánh trường hợp không tìm thấy sản phẩm
    bool deleting = true;
    
    do {
        Product productChosen = searchItem(); // Gán giá trị sản phẩm trả về từ hàm tìm kiếm
        
        if (memcmp(&productChosen, &empty_product, sizeof(Product)) == 0){
            // So sánh bộ nhớ của struct trống và struct trả về từ searchItem
            // Nếu struct trả về rỗng => không tìm thấy
            printf("Product not found!\n");
            deleting = false;
        } else {
            // Hiển thị thông tin sản phẩm trước khi xác nhận xóa
            printf("\n--- PRODUCT TO DELETE ---");
            printf("\nProduct ID: %d", productChosen.productid);
            printf("\nProduct name: %s", productChosen.productname);
            printf("\nProduct brand: %s", productChosen.productcomp);
            printf("\nProduct price: %d", productChosen.price);
            printf("\nProduct quantity: %d\n", productChosen.Qnt);
            
            // Hỏi xác nhận xóa từ người dùng
            printf("Are you sure you want to delete this product? Y/N: ");
            char confirm;
            scanf(" %c", &confirm);
            
            if (confirm == 'Y' || confirm == 'y') {
                // ============================================================
                // 💾 ĐOẠN XỬ LÝ FILE TẠM (BỎ QUA SẢN PHẨM CẦN XÓA)
                // ============================================================
                FILE *fileOld = fopen("NextFile.dat", "r");
                FILE *fileNew = fopen("temp.txt", "w");
                
                if (fileOld != NULL && fileNew != NULL) {
                    Product currentProd;
                    int isDeleted = 0; // Biến cờ đánh dấu đã tìm thấy để xóa (bỏ qua không ghi) chưa
                    
                    // Đọc từng dòng từ file gốc theo đúng định dạng dữ liệu
                    while (fscanf(fileOld, "%39s %39s %d %d %d\n", currentProd.productname, currentProd.productcomp, &currentProd.price, &currentProd.productid, &currentProd.Qnt) != EOF) {
                        
                        // So sánh ID kiểu số nguyên
                        if (currentProd.productid == productChosen.productid) {
                            // TRÙNG ID -> Bỏ qua không ghi vào file tạm (hành động xóa)
                            isDeleted = 1; 
                        } else {
                            // KHÔNG TRÙNG -> Ghi NGUYÊN XI dữ liệu cũ sang file tạm
                            fprintf(fileNew, "%s %s %d %d %d\n", currentProd.productname, currentProd.productcomp, currentProd.price, currentProd.productid, currentProd.Qnt);
                        }
                    }
                    
                    // Đóng cả 2 file để giải phóng quyền kiểm soát của hệ điều hành
                    fclose(fileOld);
                    fclose(fileNew);
                    
                    // Thực hiện hoán đổi file để cập nhật hệ thống
                    if (isDeleted == 1) {
                        remove("NextFile.dat");              // Xóa file cũ đi
                        rename("temp.txt", "NextFile.dat");  // Đổi tên file tạm thành file chính thức
                        printf("Product deleted and system saved successfully!\n");
                    } else {
                        remove("temp.txt"); // Phòng hờ nếu có lỗi phát sinh không tìm thấy ID trong file
                        printf("Failed to delete product from file!\n");
                    }
                } else {
                    printf("Error: Could not open files for data saving!\n");
                    if (fileOld != NULL) fclose(fileOld);
                    if (fileNew != NULL) fclose(fileNew);
                }
                // ============================================================
            } else {
                printf("Deletion canceled.\n");
            }
            
        } // Ngoặc vòng else ngoài cùng
        
        // Kiểm tra muốn xóa sản phẩm khác không
        printf("Do you want to delete another product? Y/N: ");
        char delete_another;
        scanf(" %c", &delete_another);
        if (delete_another == 'Y' || delete_another == 'y'){
            deleting = true;
        } else {
            deleting = false;
        } // Ngoặc else kiểm tra muốn delete s.phẩm khác
        
    } while (deleting);
} // Ngoặc hàm void