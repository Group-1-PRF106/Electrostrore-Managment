#ifndef SEARCH_FUNCTION_H
#define SEARCH_FUNCTION_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "product.h"


// Đồng bộ kiểu dữ liệu: Gán 'Product' làm bí danh cho 'struct item'
typedef struct item Product;

// ==================================================
// SEARCH & DISPLAY FUNCTIONS
// ==================================================

/*
 * Hiển thị toàn bộ danh sách sản phẩm
 * showPrice = 1: hiển thị giá
 * showPrice = 0: không hiển thị giá
 */
Product searchItem(Product arr[], int n);

/*
 * Hiển thị toàn bộ danh sách sản phẩm
 * showPrice = 1: hiển thị giá
 * showPrice = 0: không hiển thị giá
 */
void displayAllProduct(Product arr[], int n, int showPrice, const char* filename);

/*
 * Tìm kiếm sản phẩm theo ID
 */
void searchProductByID(Product arr[], int n, int searchID);

/*
 * Tìm kiếm sản phẩm theo tên
 */
void searchProductByName(Product arr[], int n, const char *keyword);

/*
 * Sắp xếp sản phẩm theo giá tăng dần
 */
void sortProductsByPrice(Product arr[], int n, const char* filename);

#endif