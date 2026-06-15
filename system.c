#include "system.h"
#include "data.h"
#include <conio.h>
#include <windows.h>
#include <time.h>
//Ham don dep bo nho dem ban phim, thay the cho fflush(stdin);
void clear_buffer(){
	int c;
	while ((c=getchar()) != '\n'&& c!=EOF);
}
void safe_gets(char *buffer, int size){
	if (fgets(buffer, size, stdin)!=NULL){
		size_t len = strlen(buffer);
		if (len>0 && buffer[len-1]=='\n');
		{
			buffer[len=1]='\0';
		}
	}
}
//Ham welcome
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
	system("cls");//Xoa man hinh truoc khi login
	
}
int checkLoginFromFile(char *uname, char *pword){
	FILE *fp = fopen ("accounts.txt","r");
	if(fp=NULL){
		printf("[System] Loi: Khong tim thay file accounts.txt!\n");
		return 0;
	}
	char fileUser[20],filePass[20];
	int role =0;
	// Doc tung dong trong file
	while (fscanf(fp,"%s %s %s",fileUser, filePass, &role)!=EOF){
		if(strcmp(uname,fileUser)==0 && strcmp(pword,filePass)==0){
			fclose(fp);
			return role;
		}
	}
	fclose(fp);
	return 0;
}
int login(void){
	int attempt = 0, i=0;
	char uname[20],pword[20];
	do{
		system("cls");
		printf("\n=================Login==================\n");
		printf("Username:");
		scanf("%s",uname);
		printf("Password:");
		char c;
		i = 0;
		while(i<20){
			c=getch();
			if(c==13)break;
			pword[i]=c;
			printf("*");
			i++;
		}
		pword[i]='\0';
		clear_buffer();
		int role=checkLoginFromFile(uname,pword);		
		//Kiem tra admin
		if(strcmp(uname,"admin")==0 && strcmp(pword,"admin123")==0){
			printf("\n\n WELCOME ADMIN! LOGIN SUCCESSFUL");
			getch();
			return 1;
		}
		//Kiem tra user
		else if(strcmp(uname,"user")==0 && strcmp(pword,"user123")==0){
			printf("\n\n WELCOME USER! LOGIN SUCCESSFUL");
			getch();
			return 2;
		}
		else{
			printf("\n\n SORRY! INVALID CREDENTIALS");
			attempt++;
			getch();
		}
	}while (attempt<3);
printf("\nToo many attempts! Exiting..");
return 0; //Luc nay la False
//ADmin
}
void admin_menu() {
    int choice;
    do {
        system("cls");
        printf("\n========== ADMIN MENU ==========\n");
        printf("  1. Add Product\n");
        printf("  2. Delete Product\n");
        printf("  3. Edit Product\n");
        printf("  4. Search Product\n");
        printf("  5. Display All Products\n");
        printf("  6. Add Voucher\n");
        printf("  7. Add Customer\n");
        printf("  8. Logout\n");
        printf("================================\n");
        printf("  Enter choice [1-8]: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: add_item(); break;
            case 2: 
                printf("Logging out...");
                getch();
                return; // Quay về login
            default:
                printf("Invalid choice!");
                getch();
        }
    } while(1);
}
//User
void user_menu() {
    int choice;
    do {
        system("cls");
        printf("\n========== USER MENU ==========\n");
        printf("  1. Search Product\n");
        printf("  2. Display All Products\n");
        printf("  3. View My Orders\n");
        printf("  4. Add to Cart\n");
        printf("  5. Logout\n");
        printf("================================\n");
        printf("  Enter choice [1-5]: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Logging out...");
                getch();
                return; // Quay về login
            default:
                printf("Invalid choice!");
                getch();
        }
    } while(1);
}