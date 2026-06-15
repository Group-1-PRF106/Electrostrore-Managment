#include "data.h"

//Bien toan cuc
struct item productList[MAX_PRODUCTS];
int productCount = 0;
// Ham nap du lieu tu file len Raw
void loadData(){
	FILE *fp=fopen ("NextFile.dat","r");
	if(fp == NULL){
		printf("[System] Khoong tim thay file NextFile.dat. Bat dau voi 0 san pham.\n");
		productCount=0;
		return ;	
	}
	printf("[System] Da nap %d san pham tu file vao bo nho.\n",productCount);
	//Ham luu du lieu tu Ram xuong file
	void saveData(){
		FILE *fp = fopen ("NextFile.dat","w");
		if(fp==NULL){
			printf("[System]Loi: Khong the luu file NExtFile.dat!\n");
			return;
		}
	}
	for (int i=0; i< productCount; i++){
		fprintf(fp, "%s %s %d %d %d\n",
				productList[i].productname,
				productList[i].productcomp,
				productList[i].price,
				productList[i].productid,
				productList[i].Qnt) != EOF;{
			productCount++;
			if(productCount >= MAX_PRODUCTS)break;
			}
				
	}
	fclose(fp);
	printf(" [System] Da luu %d san pham xuong file thanh cong.\n",productCount);
	
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