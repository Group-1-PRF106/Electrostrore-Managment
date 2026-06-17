#include "product.h"
#include "add_functions.h"
#include "data.h"
#include "search_function.h"
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

/* HIỂN THỊ DANH SÁCH */
void displayAllProduct(Product arr[], int n, int showPrice)
{
    if(showPrice)
    {
        printf("\n%-5s %-35s %-15s\n",
               "ID", "TEN SAN PHAM", "GIA(VND)");

        for(int i = 0; i < n; i++)
        {
            printf("%-5d %-35s %-15.2f\n",
                   arr[i].id,
                   arr[i].name,
                   arr[i].price);
        }
    }
    else
    {
        printf("\n%-5s %-35s\n",
               "ID", "TEN SAN PHAM");

        for(int i = 0; i < n; i++)
        {
            printf("%-5d %-35s\n",
                   arr[i].id,
                   arr[i].name);
        }
    }
}


/* TÌM THEO ID */
void searchProductByID(Product arr[], int n, int searchID)
{
    int found = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i].id == searchID)
        {
            printf("\nID : %d", arr[i].id);
            printf("\nTen: %s", arr[i].name);
            printf("\nGia: %.2f\n", arr[i].price);

            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("\nKhong tim thay san pham!\n");
    }
}


/* TÌM THEO TÊN */
void searchProductByName(Product arr[], int n, const char *keyword)
{
    int found = 0;

    printf("\n%-5s %-35s %-15s\n",
           "ID", "TEN SAN PHAM", "GIA");

    for(int i = 0; i < n; i++)
    {
        if(strstr(arr[i].name, keyword))
        {
            printf("%-5d %-35s %-15.2f\n",
                   arr[i].id,
                   arr[i].name,
                   arr[i].price);

            found = 1;
        }
    }

    if(!found)
    {
        printf("\nKhong tim thay san pham!\n");
    }
}


/* SẮP XẾP THEO GIÁ */
void sortProductsByPrice(Product arr[], int n)
{
    Product temp;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j].price > arr[j + 1].price)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nDa sap xep thanh cong!\n");
}