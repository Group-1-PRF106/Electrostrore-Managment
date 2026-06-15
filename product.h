#ifndef PRODUCT_H
#define PRODUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 40
#define MAX_COMP 40
#define MAX_PRODUCTS 100

//khai báo struct dùng chung
struct item{
	char productname[MAX_NAME];
	char productcomp[MAX_COMP];
	int productid;
	int price;
	int Qnt;
};
//Bien toan cuc chua du lieu
extern struct item productList[MAX_PRODUCTS];
extern int productCount;
// Khai baso prototype các hàm để main.c gọi được
void add_item(void);
void edit_item(void);
void deleteproduct(void);
void search_item(void);
void read_item();
void read_item();
void displayAllProduct();
void searchProdcutByID(int id);
void searchProductByName(char* name);
void sortProductsByPrice(int asscending);

#endif

