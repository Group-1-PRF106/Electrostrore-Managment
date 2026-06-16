#include "system.h" // Include file header de goi duoc cac ham he thong
#include "data.h"   // Include file header de goi duoc loadData/saveData

// Khai bao prototype (Neu chua co trong system.h thi phai co o day)
void welcome(void);
int login(void);        // login() phai tra ve int (1: Admin, 2: User, 0: Fail)
void admin_menu(void);
void user_menu(void);


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
    int role;
    // Vong lap vo han cho phep nguoi dung Logout va Login lai
    while (1) {
        welcome();      
        role = login();
        // Kiem tra dang nhap thanh cong
        if (role == 1 || role == 2) {
            // ? NAP DU LIEU TU FILE LEN RAM (Chi goi 1 lan sau khi login ok)
            loadData(); 
            // Dieu huong
            if (role == 1) {
                admin_menu(); // Vao menu Admin
            } 
            else if (role == 2) {
                user_menu();  // Vao menu User
            }
        } 
        else {
            // Dang nhap sai qua 3 lan
            printf("\n System Exit. Goodbye!\n");
            break; // Thoat khoi
        }
    }
    
    return 0;
}