#include <stdio.h>


// Hàm kiểm tra tính hợp lệ của giá sản phẩm
// Trả về 1 nếu hợp lệ, trả về 0 nếu không hợp lệ
int checkValidProductQuantity(int quantity) {
	if (1<=quantity && quantity<=500 ){
		return 1;
	} else {
		return 0;
	}
}