# ElectroStore Manager 🛒⚡
### E-Commerce Electronics & Bundle Management System
*Báo cáo Dự án Học phần: PRF192 - Programming Fundamentals*
*Trường Đại học FPT - Lớp SE2101*
*Thành phố Hồ Chí Minh, Tháng 05 - 2026*

---

## 📋 1. Giới thiệu Dự án (Introduction)

### 1.1. Mô tả dự án (Project Description)
Trong bối cảnh thương mại điện tử phát triển không ngừng, việc quản lý sản phẩm và kho hàng một cách chính xác là vô cùng thiết yếu cho sự vận hành ổn định và trải nghiệm tốt của khách hàng. Dự án với tên gọi **“ElectroStore Manager”** là một ứng dụng giao diện dòng lệnh (Console-based Application) được phát triển bằng ngôn ngữ C nhằm đơn giản hóa và tối ưu hóa quy trình quản lý các sản phẩm điện tử cũng như các gói combo khuyến mãi (Promotional Bundles). Được thiết kế như một phần sản phẩm thực hành cho khóa học PRF192, hệ thống giải quyết bài toán quản lý dữ liệu có cấu trúc, được kiểm định nghiêm ngặt và lưu trữ tệp bền vững cho các cửa hàng bán lẻ điện tử quy mô vừa và nhỏ.

Ứng dụng áp dụng nhuần nhuyễn các nguyên lý lập trình nền tảng, bao gồm cấu trúc kiến trúc mô-đun, cấp phát bộ nhớ động (`malloc`/`realloc`/`free`), chuẩn hóa và ràng buộc dữ liệu đầu vào chặt chẽ, cùng hệ thống File I/O an toàn để duy trì tính toàn vẹn dữ liệu. Hệ thống hỗ trợ đầy đủ các thao tác CRUD cơ bản, các thuật toán tìm kiếm và sắp xếp nâng cao, cùng logic nghiệp vụ chuyên biệt để tính toán chiết khấu gói combo và tổng giá trị đơn hàng. Sự kết hợp giữa giao diện dòng lệnh trực quan và xử lý logic phía sau mạnh mẽ giúp dự án trở thành một công cụ quản lý kho và đơn hàng có tính thực tiễn và khả năng mở rộng cao.

### 1.2. Đội ngũ phát triển & Phân công nhiệm vụ (Project Team)
Dự án được hoàn thiện với sự đóng góp 100% công suất từ tất cả các thành viên trong nhóm, dưới sự hướng dẫn của giảng viên **Lê Thị Hồng Nga**:

| STT | Mã Sinh Viên | Họ và Tên | Tỷ lệ hoàn thành | Nhiệm vụ đảm nhiệm |
| :---: | :---: | :--- | :---: | :--- |
| **1** | SE203117 | **Trần Minh Khang** | 100% | Khởi tạo hệ thống & Điều hướng: Thiết lập luồng xác thực (Authentication Flow), Thiết kế Menu điều hướng, Xây dựng màn hình Chào mừng (Welcome Screen). |
| **2** | SE194104 | **Đặng Hải Đăng** | 100% | Phát triển các mô-đun cập nhật thông tin sản phẩm (`updateProduct`) và nghiệp vụ xóa bản ghi khỏi hệ thống (`deleteProduct`). |
| **3** | SE171614 | **Lê Thanh Huy** | 100% | Nghiên cứu và hiện thực hóa các tính năng thêm mới dữ liệu (`Add New Operations`: addProduct, addBundle, addCustomer, addOrder). |
| **4** | SE204270 | **Nguyễn Huy Trọng** | 100% | Thiết kế và tối ưu hóa các thuật toán hiển thị danh sách dạng cột định dạng (`displayAllProduct`) và các bộ lọc tìm kiếm (`Search Operations`). |

---

## 🔍 2. Phân tích Yêu cầu & Phân rã Hệ thống (Requirement Analysis)

### 2.1. Cấu trúc Dữ liệu thành phần (Data Structures)
Hệ thống quản lý dữ liệu thông qua 3 cấu trúc (`struct`) chính:

#### I. Cấu trúc Sản phẩm (`Product`)
Lưu trữ thông tin chi tiết về từng mặt hàng điện tử trong kho:
* `product_id` (`int`): Mã định danh duy nhất của sản phẩm.
* `product_name` (`char[40]`): Tên sản phẩm (Chuỗi ký tự, chỉ chấp nhận chữ cái alphabetic).
* `product_brand` (`char[40]`): Thương hiệu/Hãng sản xuất sản phẩm.
* `product_price` (`float`): Giá bán lẻ mặt hàng (Giới hạn hợp lệ: `10.000` - `5.000.000` VND).
* `product_quantity` (`int`): Số lượng hàng tồn kho (Giới hạn hợp lệ: `1` - `500`).

#### II. Cấu trúc Người dùng & Khách hàng (`User`)
Quản lý thông tin đăng nhập hệ thống và thông tin chi tiết của khách hàng mua hàng:
* `user_name` (`char[10]`): Tên tài khoản đăng nhập hệ thống.
* `password` (`char[10]`): Mật khẩu truy cập hệ thống (Đã được mã hóa).
* `user_id` (`string`): Mã định danh duy nhất của khách hàng.
* `customer_name` (`char[50]`): Họ và tên đầy đủ của khách hàng.
* `user_phone` (`char[15]`): Số điện thoại liên hệ (Kiểm định dữ liệu: Phải là số, độ dài 10-11 ký tự).
* `user_email` (`char[50]`): Địa chỉ email khách hàng (Kiểm định dữ liệu: Phải chứa các ký tự `@` và `.`).
* `user_address` (`char[100]`): Địa chỉ nhận và giao hàng.
* `order_id` (`string`): Mã định danh đơn hàng liên kết gần nhất.

#### III. Cấu trúc Tìm kiếm (`SearchQuery`)
Cấu trúc bổ trợ chứa tiêu chí tìm kiếm động:
* `target` (`char[40]`): Từ khóa tìm kiếm theo tên hoặc thương hiệu sản phẩm.
* `id` (`int`): Mã số ID dùng cho việc đối sánh chính xác tuyệt đối.

### 2.2. Phân rã Chức năng (System Functions)

#### I. Giao diện & Xác thực (User Interface & Authentication)
* `welcome()`: Hiển thị màn hình chào mừng của cửa hàng với mốc thời gian và thông tin hệ thống hiện tại.
* `login()`: Xử lý đăng nhập của người dùng (Xác thực tài khoản/mật khẩu, giới hạn tối đa 3 lần thử).
* `menu()`: Hiển thị menu điều hướng chính và chuyển tiếp người dùng đến các chức năng tương ứng (Thêm/Xóa/Sửa/Tìm kiếm/Hiển thị/Thoát).

#### II. Quản lý Sản phẩm - Thao tác Cập nhật (Update Operations)
* `updateProduct()`: Tìm kiếm sản phẩm theo ID -> Hiển thị bản ghi hiện tại -> Cho phép người dùng nhập giá trị mới (Tên, Hãng, Giá, Số lượng) -> Kiểm tra tính hợp lệ dữ liệu đầu vào -> Sử dụng mô hình Tệp tạm thời (*Temporary File Pattern*): Đọc file gốc → Ghi file tạm → Ghi đè thay thế file gốc -> Trả về trạng thái thành công/thất bại.
* `deleteProduct()`: Tìm kiếm theo ID -> Sử dụng tệp tạm thời sao chép toàn bộ các sản phẩm trừ sản phẩm bị xóa -> Xóa file gốc và đổi tên file tạm thời -> Xử lý trường hợp không tìm thấy mã sản phẩm.

#### III. Lưu trữ Dữ liệu Bền vững (Data Persistence)
* `loadData()`: Nạp toàn bộ dữ liệu sản phẩm từ tệp `NextFile.dat` vào bộ nhớ RAM khi khởi động chương trình bằng hàm `fscanf()` hoặc `fgets()` + `sscanf()`.
* `saveData()`: Ghi lại toàn bộ dữ liệu sản phẩm trong bộ nhớ xuống tệp `NextFile.dat` khi thoát chương trình bằng hàm `fprintf()`.
* `addProduct()`: Thêm sản phẩm mới kèm kiểm định chặt chẽ toàn bộ thuộc tính nhập vào.
* `addBundle()`: Tạo gói combo khuyến mãi mới bằng cách kết hợp nhiều sản phẩm điện tử lại với nhau đi kèm chính sách giảm giá riêng biệt.
* `addCustomer()`: Thêm tài khoản khách hàng mới (ID, tên đầy đủ, SĐT, email, địa chỉ).
* `addOrder()`: Khởi tạo đơn hàng mới chứa các sản phẩm được chọn, số lượng mua, tính toán tổng tiền và cập nhật trạng thái thanh toán.

#### IV. Tìm kiếm & Sắp xếp Phân tích (Search & Analysis)
* `searchItem()`: Đọc file tuần tự, sử dụng hàm `strcmp()` để đối sánh dữ liệu và hiển thị kết quả tương ứng.
* `displayAllProduct()`: Xuất danh sách toàn bộ sản phẩm hiện có ra màn hình dưới dạng bảng cột được định dạng chuyên nghiệp.
* `searchProductByID()`: Tìm kiếm và trả về sản phẩm trùng khớp chính xác mã ID.
* `searchProductByName()`: Tìm kiếm và lọc ra các sản phẩm có tên chứa từ khóa mà người dùng nhập vào.
* `sortProductsByPrice()`: Sắp xếp tập dữ liệu sản phẩm theo tiêu chí giá cả theo thứ tự tăng dần hoặc giảm dần dựa trên cấu hình tuyển chọn.

#### V. Quản lý Gói & Giảm giá (Bundle & Discount Management)
* `calculateDiscount()`: Áp dụng mức giảm giá theo tỷ lệ phần trăm hoặc cố định, kiểm tra quy tắc giảm giá (giá trị tối thiểu/tối đa) và trả về giá cuối cùng sau chiết khấu.
* `calculateTotalOrderValue()`: Tính toán tổng giá trị đơn hàng, tự động cộng gộp thuế giá trị gia tăng (VAT).
* `calculateTotalQtyPerProduct()`: Thống kê và tổng hợp số lượng tích lũy đã bán được đối với từng mặt hàng cụ thể.

---

## 🛠️ 3. Thiết kế Thuật toán & Sơ đồ Luồng (Algorithm Design)

Mã nguồn được vận hành dựa trên các sơ đồ khối giải thuật chuẩn hóa sau:

1. **Luồng Chào mừng & Đăng nhập (`welcome` & `login`)**: Hệ thống nạp dữ liệu nền tảng ngay khi bật. Tiếp đến, hàm đăng nhập xác thực thông tin, nếu nhập sai quá 3 lần, chương trình tự động ngắt (`exit()`). Nếu đúng, hệ thống kiểm tra quyền hạn tài khoản để chuyển hướng sang giao diện quản trị viên (`admin_menu()`) hoặc khách hàng (`user_menu()`).
2. **Luồng Quản trị viên (`admin_menu`)**: Phân tách thành 2 nhánh lớn:
   * **Quản lý sản phẩm (`Product Management`)**: Liên kết trực tiếp tới các hàm con `displayAllProduct()`, `searchProduct()`, `addProduct()`, `updateProduct()`, `deleteProduct()`, và `addBundle()`.
   * **Hệ thống dữ liệu (`Data System`)**: Liên kết điều phối hàm `addVoucher()` và `addCustomer()`.
3. **Luồng Khách hàng (`user_menu` & `display_menu_user`)**: Cho phép người dùng phổ thông tiếp cận các tính năng phi quản trị bao gồm: Tìm kiếm sản phẩm, xem toàn bộ kho hàng, và tiến hành đặt hàng (`addOrder()`).
4. **Mô hình Tệp tạm thời (`Temporary File Pattern`)**: Được áp dụng triệt để trong các tác vụ `updateProduct()` và `deleteProduct()`. Luồng xử lý tiến hành tạo một file trung gian `TempFile.dat`, đọc quét tuần tự file gốc, sửa đổi dữ liệu hoặc bỏ qua bản ghi cần xóa tại bộ nhớ đệm, ghi dữ liệu mới sang file tạm, sau đó tiến hành đồng bộ ghi đè file cũ để tránh xung đột hệ thống khi gặp sự cố bất ngờ.

---

## 📂 4. Kiến trúc Thiết kế & Tính mô-đun (Architectural Design)

Để đảm bảo nguyên lý tách biệt mã nguồn rõ ràng (**Separation of Concerns**), cấu trúc mã nguồn được phân bổ thành 4 lớp thành phần chính mô phỏng các kiến trúc phần mềm hiện đại:
* 📦 **`Product` (Data Transfer Object - DTO):** Đóng gói thực thể dữ liệu thô của sản phẩm để luân chuyển giữa các tầng xử lý.
* 🎮 **`ProductManager` (Controller):** Đảm nhận vai trò xử lý toàn bộ logic nghiệp vụ cốt lõi, quản lý danh sách mảng và tính toán các thuật toán sắp xếp, chiết khấu.
* 💾 **`FileHelper` (Utility):** Thành phần tiện ích chuyên biệt chịu trách nhiệm thao tác trực tiếp với phần cứng, quản lý tệp tin `NextFile.dat` và `accounts.txt`.
* 🖥️ **`ConsoleIO` (View):** Chịu trách nhiệm render giao diện đồ họa text, xử lý định dạng vị trí hiển thị bảng cột trên Console thông qua hàm định vị tọa độ `gotoxy()`.

---

## 🚀 5. Hướng dẫn Cài đặt & Sử dụng (Installation & Guide)

### Yêu cầu Môi trường
* Trình biên dịch C (Ví dụ: GCC, Clang, hoặc MSVC).
* Hệ điều hành hỗ trợ thư viện hiển thị màn hình tiêu chuẩn (Khuyến khích chạy trên hệ điều hành Windows để tối ưu hóa hiển thị hàm `gotoxy` và thư viện `<conio.h>`).

### Các bước Thực thi trên GitHub
1. Sao chép kho lưu trữ về máy cá nhân:
   ```bash
   git clone https://github.com/your-username/ElectroStore-Manager.git
   cd ElectroStore-Manager
   ```
2. Thực hiện biên dịch mã nguồn chương trình bằng GCC:
   ```bash
   gcc main.c -o ElectroStoreManager
   ```
3. Khởi chạy ứng dụng:
   ```bash
   ./ElectroStoreManager
   ```

*Lưu ý: Để chương trình vận hành chính xác, hãy đảm bảo các tệp tin cơ sở dữ liệu nền tảng gồm `NextFile.dat` và `accounts.txt` luôn nằm chung một thư mục với tệp tin thực thi sau khi biên dịch.*
