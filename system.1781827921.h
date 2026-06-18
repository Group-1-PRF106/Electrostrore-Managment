#ifndef SYSTEM_H
#define SYSTEM_H
#include "product.h"
#include "add_functions.h"

// Extern declarations for Nhánh B data (Customer, Bundle, Order)
#define MAX_CUSTOMERS 100
#define MAX_BUNDLES 50
#define MAX_ORDERS 100

extern Customer customerList[MAX_CUSTOMERS];
extern int customerCount;

extern Bundle bundleList[MAX_BUNDLES];
extern int bundleCount;

extern Order orderList[MAX_ORDERS];
extern int orderCount;

// Function prototypes cho Systems Flow
void welcome(void);
int login(void);
void admin_menu(void);
void user_menu(void);
#endif