#include <stdio.h>
#include <string.h>
#include "update.h"


void updateProductBrand(char brand[40]){
	char temp[40];
	int rebrand_loops = 1;
	do {
		//nhập hãng
		printf("Please enter the new brand you want to update: ");
		fgets(temp, sizeof(temp), stdin);

		//Bỏ kí tự xuống dòng
		temp[strcspn(temp, "\n")] = '\0';

		//kiểm tra hãng hợp lệ (0=invalid; 1=valid)
		if (checkValidProductBrand(temp)==1){
			printf("The brand is valid");
			strcpy(brand, temp);
			rebrand_loops = 0;
		} else {
			printf("Please enter another brand: ");
		}
	} while (rebrand_loops == 1);
}
