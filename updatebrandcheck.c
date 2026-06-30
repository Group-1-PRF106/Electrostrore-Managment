#include <stdio.h>
#include <ctype.h>   // Để dùng hàm isalnum hoặc isalpha, isdigit
#include <string.h>  // Để dùng hàm strlen

//AI hỗ trợ

// Hàm kiểm tra tính hợp lệ của tên sản phẩm
// Trả về 1 nếu hợp lệ (chỉ chứa chữ cái, số, và khoảng trắng), trả về 0 nếu không hợp lệ
int checkValidProductBrand(const char *temp) {
    // Trường hợp chuỗi rỗng hoặc con trỏ NULL
    if (temp == NULL || strlen(temp) == 0) {
        return 0; 
    }

    // Duyệt qua từng ký tự của chuỗi
    for (int i = 0; temp[i] != '\0'; i++) {
        unsigned char c = (unsigned char)temp[i];

        // ĐIỀU KIỆN MỚI: 
        // Nếu ký tự KHÔNG phải là chữ-số (isalnum) VÀ KHÔNG phải là khoảng trắng (' ')
        if (!isalnum(c) && c != ' ') {
            return 0; // Trả về 0 (không hợp lệ) ngay khi gặp ký tự đặc biệt (như !, @, #, -, ...)
        }
    }
    return 1; // Hợp lệ nếu đi qua hết vòng lặp
}