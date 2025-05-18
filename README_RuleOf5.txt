
# 📘 Tổng hợp các hàm đặc biệt trong C++ (Rule of 5)

## ✅ Tình huống sử dụng và hàm được gọi tương ứng:

| Tình huống sử dụng                      | Hàm được gọi           |
|----------------------------------------|------------------------|
| `ClassName a(...);`                    | ✅ Constructor          |
| `ClassName b = a;`                     | ✅ Copy Constructor     |
| `b = a;`                               | ✅ Copy Assignment      |
| `ClassName c = ClassName(...);`       | ✅ Move Constructor     |
| `c = std::move(a);`                    | ✅ Move Assignment      |
| Hết vòng đời hoặc `delete` đối tượng   | ✅ Destructor           |

---

## 🧠 Ghi nhớ nhanh:

- **Constructor**: Khởi tạo đối tượng mới từ đầu.
- **Copy Constructor**: Tạo đối tượng mới bằng cách sao chép từ đối tượng khác.
- **Copy Assignment**: Gán giá trị của một đối tượng cho đối tượng đã tồn tại.
- **Move Constructor**: Tạo đối tượng mới bằng cách "chiếm" tài nguyên từ đối tượng tạm thời.
- **Move Assignment**: Gán đối tượng bằng cách chuyển tài nguyên (không sao chép).
- **Destructor**: Tự động gọi khi đối tượng bị huỷ để giải phóng tài nguyên.

---

## 📌 Khi nào cần tự viết các hàm này?

| Trường hợp                               | Cần viết? |
|------------------------------------------|-----------|
| Lớp có con trỏ, `new/delete`             | ✅ Cần     |
| Lớp đơn giản (int, double, string...)    | ❌ Không cần |
| Dùng `std::unique_ptr`, `std::vector`... | ❌ Không cần |

---

## 📦 Khuyến nghị

- Với lớp quản lý tài nguyên thủ công → nên viết đầy đủ "Rule of 5":
  - Constructor
  - Copy constructor
  - Copy assignment
  - Move constructor
  - Move assignment
  - Destructor

- Nếu dùng smart pointer (`std::unique_ptr`, `std::shared_ptr`) thì compiler sẽ tự lo phần move.

---
