#ifndef ADD_FUNCTIONS_H
#define ADD_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "product.h"  // Reuse struct item from product.h

// --- ĐỊNH NGHĨA CÁC CẤU TRÚC DỮ LIỆU CỦA NHÁNH B ---

// Reuse struct item from product.h (instead of Item typedef)
// struct item { productname, productcomp, price, productid, Qnt }

// Struct Customer (Đã sửa từ int id sang chuỗi ký tự theo addCustomer.c)
typedef struct {
    char customerID[20];
    char name[50];
    char email[50];
    char phone[15];
} Customer;

// Struct Bundle (Đã sửa đổi theo cấu trúc mảng itemIDs trong addBundle.c)
typedef struct {
    char bundleID[20];
    char bundleName[50];
    int itemCount;
    char itemIDs[10][20]; // Lưu tối đa 10 mã sản phẩm trong 1 gói
    float discountPercent;
} Bundle;

// Struct Order (Đã sửa đổi và bổ sung các trường tính toán theo addOrder.c)
typedef struct {
    char orderID[20];
    char customerID[20];
    int itemCount;
    char itemIDs[20][20]; // Lưu tối đa 20 sản phẩm trong đơn hàng
    int quantities[20];
    float subtotal;
    char bundleID[20];
    float discount;
    float total;
    char paymentStatus[20];
} Order;


// --- KHAI BÁO CÁC PROTOTYPE HÀM (INTERFACE CHO ADMIN GỌI) ---

void addItem(struct item items[], int *n);

void addCustomer(Customer customers[], int *n);

void addBundle(Bundle bundles[], int *bundleCount, struct item items[], int itemCount);

void addOrder(Order orders[], int *orderCount, Customer customers[], int customerCount, struct item items[], int itemCount, Bundle bundles[], int bundleCount);

#endif