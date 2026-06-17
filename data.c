#include "data.h"
#include "add_functions.h"

//Bien toan cuc
struct item productList[MAX_PRODUCTS];
int productCount = 0;

// Nhánh B: Customer, Bundle, Order globals
#define MAX_CUSTOMERS 100
#define MAX_BUNDLES 50
#define MAX_ORDERS 100

Customer customerList[MAX_CUSTOMERS];
int customerCount = 0;

Bundle bundleList[MAX_BUNDLES];
int bundleCount = 0;

Order orderList[MAX_ORDERS];
int orderCount = 0;
// Ham nap du lieu tu file len Raw
void loadData(void){
	FILE *fp = fopen("NextFile.dat", "r");
	if (fp != NULL) {
		productCount = 0;
		while (productCount < MAX_PRODUCTS) {
			char name[MAX_NAME];
			char comp[MAX_COMP];
			int price, id, qnt;
			int read = fscanf(fp, "%39s %39s %d %d %d\n", name, comp, &price, &id, &qnt);
			if (read != 5) break;
			strncpy(productList[productCount].productname, name, MAX_NAME-1);
			productList[productCount].productname[MAX_NAME-1] = '\0';
			strncpy(productList[productCount].productcomp, comp, MAX_COMP-1);
			productList[productCount].productcomp[MAX_COMP-1] = '\0';
			productList[productCount].price = price;
			productList[productCount].productid = id;
			productList[productCount].Qnt = qnt;
			productCount++;
		}
		fclose(fp);
		printf("[System] Da nap %d san pham tu file vao bo nho.\n", productCount);
	} else {
		printf("[System] Khong tim thay file NextFile.dat. Bat dau voi 0 san pham.\n");
		productCount = 0;
	}

	loadCustomers();
	loadBundles();
	loadOrders();
}
void saveData(){
    FILE *fp = fopen("NextFile.dat", "w");
    
    if(fp == NULL){
        printf("[System] Loi: Khong the luu file NextFile.dat!\n");
        return;
    }
    
    for(int i = 0; i < productCount; i++){
        fprintf(fp, "%s %s %d %d %d\n",
                productList[i].productname,    // ? S?a productName ? productname
                productList[i].productcomp,
                productList[i].price,          // ? S?a prince ? price
                productList[i].productid,
                productList[i].Qnt);           // ? B? d?u < > th?a
    }
    
    fclose(fp);
    printf("[System] Da luu %d san pham xuong file thanh cong.\n", productCount);
}

void saveCustomers(void) {
    FILE *fp = fopen("customers.txt", "w");
    if (fp == NULL) {
        printf("[System] Loi: Khong the luu file customers.txt!\n");
        return;
    }
    for (int i = 0; i < customerCount; i++) {
        fprintf(fp, "%s|%s|%s|%s\n",
                customerList[i].customerID,
                customerList[i].name,
                customerList[i].email,
                customerList[i].phone);
    }
    fclose(fp);
    printf("[System] Da luu %d khach hang xuong file.\n", customerCount);
}

void loadCustomers(void) {
    FILE *fp = fopen("customers.txt", "r");
    if (fp == NULL) {
        customerCount = 0;
        return;
    }
    customerCount = 0;
    char line[256];
    while (fgets(line, sizeof(line), fp) && customerCount < MAX_CUSTOMERS) {
        line[strcspn(line, "\r\n")] = '\0';
        char *token = strtok(line, "|");
        if (!token) continue;
        strcpy(customerList[customerCount].customerID, token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        strcpy(customerList[customerCount].name, token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        strcpy(customerList[customerCount].email, token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        strcpy(customerList[customerCount].phone, token);
        
        customerCount++;
    }
    fclose(fp);
    printf("[System] Da nap %d khach hang tu file.\n", customerCount);
}

void saveBundles(void) {
    FILE *fp = fopen("bundles.txt", "w");
    if (fp == NULL) {
        printf("[System] Loi: Khong the luu file bundles.txt!\n");
        return;
    }
    for (int i = 0; i < bundleCount; i++) {
        fprintf(fp, "%s|%s|%f|%d",
                bundleList[i].bundleID,
                bundleList[i].bundleName,
                bundleList[i].discountPercent,
                bundleList[i].itemCount);
        for (int j = 0; j < bundleList[i].itemCount; j++) {
            fprintf(fp, "|%s", bundleList[i].itemIDs[j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("[System] Da luu %d combo/bundle xuong file.\n", bundleCount);
}

void loadBundles(void) {
    FILE *fp = fopen("bundles.txt", "r");
    if (fp == NULL) {
        bundleCount = 0;
        return;
    }
    bundleCount = 0;
    char line[256];
    while (fgets(line, sizeof(line), fp) && bundleCount < MAX_BUNDLES) {
        line[strcspn(line, "\r\n")] = '\0';
        char *token = strtok(line, "|");
        if (!token) continue;
        strcpy(bundleList[bundleCount].bundleID, token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        strcpy(bundleList[bundleCount].bundleName, token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        bundleList[bundleCount].discountPercent = atof(token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        bundleList[bundleCount].itemCount = atoi(token);
        
        for (int j = 0; j < bundleList[bundleCount].itemCount; j++) {
            token = strtok(NULL, "|");
            if (token) {
                strcpy(bundleList[bundleCount].itemIDs[j], token);
            }
        }
        bundleCount++;
    }
    fclose(fp);
    printf("[System] Da nap %d combo/bundle tu file.\n", bundleCount);
}

void saveOrders(void) {
    FILE *fp = fopen("orders.txt", "w");
    if (fp == NULL) {
        printf("[System] Loi: Khong the luu file orders.txt!\n");
        return;
    }
    for (int i = 0; i < orderCount; i++) {
        fprintf(fp, "%s|%s|%d|%f|%s|%f|%f|%s",
                orderList[i].orderID,
                orderList[i].customerID,
                orderList[i].itemCount,
                orderList[i].subtotal,
                orderList[i].bundleID,
                orderList[i].discount,
                orderList[i].total,
                orderList[i].paymentStatus);
        for (int j = 0; j < orderList[i].itemCount; j++) {
            fprintf(fp, "|%s,%d", orderList[i].itemIDs[j], orderList[i].quantities[j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("[System] Da luu %d don hang xuong file.\n", orderCount);
}

void loadOrders(void) {
    FILE *fp = fopen("orders.txt", "r");
    if (fp == NULL) {
        orderCount = 0;
        return;
    }
    orderCount = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp) && orderCount < MAX_ORDERS) {
        line[strcspn(line, "\r\n")] = '\0';
        char *token = strtok(line, "|");
        if (!token) continue;
        strcpy(orderList[orderCount].orderID, token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        strcpy(orderList[orderCount].customerID, token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        orderList[orderCount].itemCount = atoi(token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        orderList[orderCount].subtotal = atof(token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        strcpy(orderList[orderCount].bundleID, token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        orderList[orderCount].discount = atof(token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        orderList[orderCount].total = atof(token);
        
        token = strtok(NULL, "|");
        if (!token) continue;
        strcpy(orderList[orderCount].paymentStatus, token);
        
        for (int j = 0; j < orderList[orderCount].itemCount; j++) {
            token = strtok(NULL, "|");
            if (token) {
                char *comma = strchr(token, ',');
                if (comma) {
                    *comma = '\0';
                    strcpy(orderList[orderCount].itemIDs[j], token);
                    orderList[orderCount].quantities[j] = atoi(comma + 1);
                }
            }
        }
        orderCount++;
    }
    fclose(fp);
    printf("[System] Da nap %d don hang tu file.\n", orderCount);
}