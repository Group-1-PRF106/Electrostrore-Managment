#include <stdio.h>

void updateProductQuantity(int *quantity){
	int temp;
	int requantity_loops = 1;
	do {
		//nhập giá
		printf("Please enter the new quantity you want to update: ");
		scanf("%d", &temp);

		//kiểm tra giá hợp lệ (0=invalid; 1=valid)
		if (checkValidProductQuantity(temp)==1){
			printf("The quantity is valid");
			*quantity = temp;
			requantity_loops = 0;
		} else {
			printf("Please enter another quantity: ");
		}
	} while (requantity_loops == 1);
}