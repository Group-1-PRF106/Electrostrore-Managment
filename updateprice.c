#include <stdio.h>

#include "update.h"

void updateProductPrice(int *price){
	int temp;
	int reprice_loops = 1;
	do {
		//nhập giá
		printf("Please enter the new price you want to update: ");
		scanf("%d", &temp);

		//kiểm tra giá hợp lệ (0=invalid; 1=valid)
		if (checkValidProductPrice(temp)==1){
			printf("The price is valid");
			*price = temp;
			reprice_loops = 0;
		} else {
			printf("Please enter another price: ");
		}
			
	} while (reprice_loops == 1);
}