#include <stdio.h>


// Hàm kiểm tra tính hợp lệ của giá sản phẩm
// Trả về 1 nếu hợp lệ, trả về 0 nếu không hợp lệ
int checkValidProductPrice(int price) {
	if (10000<=price && price<=500000 ){
		return 1;
	} else {
		return 0;
	}
}