#ifndef HEADER_UPDATE_DANG
#define HEADER_UPDATE_DANG

void updateProduct();

int updateProductName(char name[40]);
int checkValidProductName();

int updateProductBrand(char name[40]);
void checkValidProductBrand();

int updateProductPrice();
void checkValidProductPrice();

int updateProductQuantity();
void checkValidProductQuantity();

#endif