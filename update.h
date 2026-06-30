#ifndef HEADER_UPDATE_DANG
#define HEADER_UPDATE_DANG

void updateProduct();

void updateProductName(char name[40]);
int checkValidProductName(const char *temp);

void updateProductBrand(char name[40]);
int checkValidProductBrand(const char *temp);

void updateProductPrice(int *price);
int checkValidProductPrice(int price);

void updateProductQuantity(int *quantity);
int checkValidProductQuantity(int quantity);

#endif