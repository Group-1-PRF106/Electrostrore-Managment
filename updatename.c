#include <stdio.h>
#include <string.h>
int checkValidProductName(char name[]);

void updateProductName(char name[40]){
	char temp[40];
	int rename_loops = 1;
	do {
		//nhập tên
		printf("Please enter the new name you want to update: ");
		fgets(temp, sizeof(temp), stdin);

		//Bỏ kí tự xuống dòng
		temp[strcspn(temp, "\n")] = '\0';

		//kiểm tra tên hợp lệ (0=invalid; 1=valid)
		if (checkValidProductName(temp)==1){
			printf("The name is valid");
			strcpy(name, temp);
			rename_loops = 0;
		} else {
			printf("Please enter another name: ");
		}
	} while (rename_loops == 1);
}
