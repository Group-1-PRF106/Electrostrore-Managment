#ifndef SEARCH_FUNCTION_H
#define SEARCH_FUNCTION_H
 
#include <stdio.h>
#include <string.h>
#include "product.h"
 
// Đồng bộ kiểu: Product là bí danh của struct item
typedef struct item Product;
 
// ==================================================
// searchItem()
// - Hàm TRUNG GIAN dùng cho update.c và delete.c
// - Hiện mini-menu, gọi searchByID hoặc searchByName
// - Trả về: struct item tìm thấy, hoặc {0} nếu không có / hủy
// ==================================================
struct item searchItem(void);
 
// ==================================================
// searchProductByID()
// - Tìm sản phẩm theo ID trong mảng
// - In kết quả ra màn hình
// - Trả về: struct item tìm thấy, hoặc {0} nếu không có
// ==================================================
struct item searchProductByID(struct item arr[], int n, int searchID);
 
// ==================================================
// searchProductByName()
// - Tìm theo từ khóa tên, in danh sách khớp
// - Hỏi người dùng chọn ID từ danh sách
// - Trả về: struct item được chọn, hoặc {0} nếu hủy
// ==================================================
struct item searchProductByName(struct item arr[], int n, const char *keyword);
 
// ==================================================
// displayAllProduct()
// - Hiển thị toàn bộ danh sách sản phẩm
// ==================================================
void displayAllProduct(void);
 
// ==================================================
// sortProductsByPrice()
// - Sắp xếp productList theo giá tăng dần, lưu file
// ==================================================
void sortProductsByPrice(void);
 
#endif