#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int product_id;
	char product_name[40];
	char product_brand[40];
	float product_price;
	int product_quantity;
	} Product;//khai báo kiểu dữ liệu Product

void updateProduct(){
	loadData();
	Product empty_product = {0};//khai báo giá trị so sánh trường hợp k tìm thấy s.phẩm
	
	bool editing = true;
	do {
		Product productChosen = searchItem(); //gán giá trị sản phẩm trả về
		while (true){
			if (memcmp(&productChosen, &empty_product, sizeof(Product)) == 0){
					//so sánh bộ nhớ của struct trống và struct trả về từ searchItem
					//nếu struct trả về rỗng => không tìm thấy
					printf("Product not found!");
					editing = false;
					break;//break dòng while (true)
				} else {
					printf("\nProduct ID: %d", productChosen.product_id);
					printf("\nProduct name: %s", productChosen.product_name);
					printf("\nProduct brand: %s", productChosen.product_brand);
					printf("\nProduct price: %.2f", productChosen.product_price);
					printf("\nProduct quantity: %d", productChosen.product_quantity);
				}
		
		//Cập nhật tên sản phẩm
		updateProductName(productChosen.product_name);
		
		//Cập nhật hãng sản phẩm
		updateProductBrand(productChosen.product_brand);
		
		//Cập nhật giá sản phẩm
		updateProductPrice(&productChosen.product_price);

		//Cập nhật số lượng sản phẩm
		updateProductQuantity(&productChosen.product_quantity);
		
		break;
		
		}//ngoặc vòng while (true)
		
		
		
		//Kiểm tra muốn cập nhật sản phẩm khác không
		while (getchar() != '\n' && getchar() != EOF);
		printf("Do you want to update another product? Y/N");
		char update_another = getchar();
		if (update_another == 'Y' || update_another == 'y'){
			editing = true;
		} else {
			editing = false;
		}//ngoặc else kiểm tra muốn update s.phẩm khác
	
	} while (editing);
	
}//ngoặc hàm void