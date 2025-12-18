#include <stdio.h>

typedef struct {
    int id;
    float gpa;
} Student;

/**
 * @brief Tính GPA trung bình của lớp
 *
 * @param students Mảng sinh viên
 * @param n        Số lượng sinh viên
 * @return float
 *  - GPA trung bình nếu n > 0
 *  - 0.0 nếu danh sách rỗng
 */
float calculateAverageGPA(Student students[], int n) {
    if (n <= 0) {
        return 0.0;
    }

    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += students[i].gpa;
    }

    return sum / n;
}

int main() {
    // ===== DỮ LIỆU GIẢ LẬP (AI GENERATED) =====
    Student students[10] = {
        {1, 7.5},
        {2, 8.0},
        {3, 8.5},
        {4, 9.0},
        {5, 7.0},
        {6, 8.2},
        {7, 8.8},
        {8, 9.1},
        {9, 7.9},
        {10, 8.5}
    };

    int n = 10;

    float avgGPA = calculateAverageGPA(students, n);
    printf("GPA trung binh cua lop la: %.2f\n", avgGPA);

    // ===== TEST CASE: DANH SÁCH RỖNG =====
    Student emptyList[1];
    float emptyAvg = calculateAverageGPA(emptyList, 0);
    printf("GPA trung binh (danh sach rong): %.2f\n", emptyAvg);

    return 0;
}
