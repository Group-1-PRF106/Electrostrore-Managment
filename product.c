#include "product.h"
#include "add_functions.h"
#include "data.h"
#include <conio.h>

// vieets phaanf add_item, edit, delete,
// ví dụ
void add_item(void){
	// Call addItem() from add_functions
	addItem(productList, &productCount);
	// Save to file after adding
	saveData();
}

void delete_product(void){
	// Delete product by ID
	int id;
	int found = 0;
	printf("Enter Product ID to delete: ");
	scanf("%d", &id);
	
	// Find and delete
	for(int i = 0; i < productCount; i++){
		if(productList[i].productid == id){
			found = 1;
			// Shift elements after deletion
			for(int j = i; j < productCount - 1; j++){
				productList[j] = productList[j+1];
			}
			productCount--;
			printf("Product deleted successfully!\n");
			saveData();
			getch();
			return;
		}
	}
	
	if(!found){
		printf("Product ID not found!\n");
		getch();
	}
}

void edit_item(void){
	// Placeholder implementation
	printf("edit_item(): feature not fully implemented yet.\n");
	getch();
}

void search_item(void){
	// Search product by ID or name
	int choice;
	printf("\n1. Search by ID\n2. Search by Name\nEnter choice: ");
	scanf("%d", &choice);
	
	if(choice == 1){
		int id;
		printf("Enter Product ID: ");
		scanf("%d", &id);
		
		for(int i = 0; i < productCount; i++){
			if(productList[i].productid == id){
				printf("Found: ID=%d, Name=%s, Company=%s, Price=%d, Qty=%d\n",
					productList[i].productid, productList[i].productname,
					productList[i].productcomp, productList[i].price,
					productList[i].Qnt);
				getch();
				return;
			}
		}
		printf("Product ID not found!\n");
		getch();
	}
	else if(choice == 2){
		char name[40];
		printf("Enter Product Name: ");
		scanf("%39s", name);
		
		int found = 0;
		for(int i = 0; i < productCount; i++){
			if(strstr(productList[i].productname, name) != NULL){
				printf("Found: ID=%d, Name=%s, Company=%s, Price=%d, Qty=%d\n",
					productList[i].productid, productList[i].productname,
					productList[i].productcomp, productList[i].price,
					productList[i].Qnt);
				found = 1;
			}
		}
		if(!found){
			printf("No products found with that name!\n");
		}
		getch();
	}
	else{
		printf("Invalid choice!\n");
		getch();
	}
}

void displayAllProduct(void){
	// Display all products from productList
	if(productCount == 0){
		printf("No products in database!\n");
		getch();
		return;
	}
	
	printf("\n===== ALL PRODUCTS =====\n");
	for(int i = 0; i < productCount; i++){
		printf("%d: ID=%d, Name=%s, Company=%s, Price=%d, Qty=%d\n",
			i+1, productList[i].productid, productList[i].productname,
			productList[i].productcomp, productList[i].price, productList[i].Qnt);
	}
	getch();
}