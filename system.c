#include "system.h"
#include "data.h"
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

// Ham don dep bo nho dem ban phim, thay the cho fflush(stdin);
void clear_buffer(void){
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void safe_gets(char *buffer, int size){
	if (fgets(buffer, size, stdin) != NULL) {
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len-1] == '\n')
			buffer[len-1] = '\0';
	}
}

// Ham welcome
void welcome(void){
	time_t t;
	time(&t);
	system("cls");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t%s", ctime(&t));
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("|\t\t\t\t==================================\t\t\t\t|\n");
	printf("|\t\t\t\t|\t  WELCOME TO PRODUCT MGMT  \t|\t\t\t\t\n");
	printf("|\t\t\t\t ===============================\t\t\t\t|\n");
	printf("|\t\t\t\t    WE BELIEVE IN QUALITY   \t\t\t\t|\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	printf("Press any key to continue......................\n");
	getch();
	system("cls"); // Xoa man hinh truoc khi login
}

int checkLoginFromFile(char *uname, char *pword){
	FILE *fp = fopen("accounts.txt", "r");
	if (fp == NULL) {
		printf("[System] Loi: Khong tim thay file accounts.txt!\n");
		return 0;
	}
	char fileUser[64], filePass[64];
	int role = 0;
	// Read lines: username password role
	while (fscanf(fp, "%63s %63s %d", fileUser, filePass, &role) == 3) {
		if (strcmp(uname, fileUser) == 0 && strcmp(pword, filePass) == 0) {
			fclose(fp);
			return role;
		}
	}
	fclose(fp);
	return 0;
}

int login(void){
	int attempt = 0, i = 0;
	char uname[64], pword[64];

	do{
		system("cls");
		printf("\n=================Login==================\n");
		printf("Username: ");
		scanf("%63s", uname);
		printf("Password: ");

		i = 0;
		while(i < (int)sizeof(pword)-1){
			char c = getch();
			if (c == '\r' || c == '\n') break;
			pword[i++] = c;
			printf("*");
		}
		pword[i] = '\0';
		clear_buffer();

		// Check hard-coded credentials first
		if(strcmp(uname,"admin") == 0 && strcmp(pword,"admin123") == 0){
			printf("\n\n WELCOME ADMIN! LOGIN SUCCESSFUL\n");
			getch();
			return 1;
		}
		else if(strcmp(uname,"user") == 0 && strcmp(pword,"user123") == 0){
			printf("\n\n WELCOME USER! LOGIN SUCCESSFUL\n");
			getch();
			return 2;
		}

		// Check accounts file
		int role = checkLoginFromFile(uname, pword);
		if (role == 1 || role == 2) return role;

		printf("\n\n SORRY! INVALID CREDENTIALS\n");
		attempt++;
		getch();
	} while (attempt < 3);

	printf("\nToo many attempts! Exiting..\n");
	return 0; // Login failed
}

void admin_menu(void) {
	int choice;
	do {
		system("cls");
		printf("\n========== ADMIN MENU ==========");
		printf("\n  1. Add Product\n");
		printf("  2. Delete Product\n");
		printf("  3. Edit Product\n");
		printf("  4. Search Product\n");
		printf("  5. Display All Products\n");
		printf("  6. Add Bundle\n");
		printf("  7. Add Customer\n");
		printf("  8. Add Order\n");
		printf("  9. Logout\n");
		printf("================================\n");
		printf("  Enter choice [1-9]: ");
		if (scanf("%d", &choice) != 1) { clear_buffer(); choice = -1; }

		switch(choice) {
			case 1:
				add_item();
				break;
			case 2:
				delete_product();
				break;
			case 3:
				edit_item();
				break;
			case 4:
				search_item();
				break;
			case 5:
				displayAllProduct();
				break;
			case 6:
				addBundle(bundleList, &bundleCount, productList, productCount);
				saveBundles();
				getch();
				break;
			case 7:
				addCustomer(customerList, &customerCount);
				saveCustomers();
				getch();
				break;
			case 8:
				addOrder(orderList, &orderCount, customerList, customerCount,
						productList, productCount, bundleList, bundleCount);
				saveOrders();
				getch();
				break;
			case 9:
				printf("Logging out...\n");
				getch();
				return; // Quay về login
			default:
				printf("Invalid choice!\n");
				getch();
		}
	} while(1);
}

void user_menu(void) {
	int choice;
	do {
		system("cls");
		printf("\n========== USER MENU ==========");
		printf("\n  1. Search Product\n");
		printf("  2. Display All Products\n");
		printf("  3. View My Orders\n");
		printf("  4. Add to Cart\n");
		printf("  5. Logout\n");
		printf("================================\n");
		printf("  Enter choice [1-5]: ");
		if (scanf("%d", &choice) != 1) { clear_buffer(); choice = -1; }

		switch(choice) {
			case 1:
				search_item();
				break;
			case 2:
				displayAllProduct();
				break;
			case 3:
				printf("View My Orders: feature not implemented yet.\n");
				getch();
				break;
			case 4:
				printf("Add to Cart: feature not implemented yet.\n");
				getch();
				break;
			case 5:
				printf("Logging out...\n");
				getch();
				return; // Quay về login
			default:
				printf("Invalid choice!\n");
				getch();
		}
	} while(1);
}