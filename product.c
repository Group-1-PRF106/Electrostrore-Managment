#include "product.h"
#include "add_functions.h"
#include "data.h"
#include <stdio.h>
#include <string.h>
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
}
void displayAllProduct(v){
}


