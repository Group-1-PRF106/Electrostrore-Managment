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
// Khai bao prototype các hàm de main.c goi duoc
void add_item(void);
void edit_item(void);
void delete_product(void);
void search_item(void);
void read_item(void);

#endif

