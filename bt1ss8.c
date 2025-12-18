#include <stdio.h>
#include <string.h>

// Định nghĩa struct Student
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Luu danh sach sinh vien vao file text
int saveToFile(const char *filename, Student students[], int n) {
    FILE *f = fopen(filename, "w");
    if (!f) return 0;
    fprintf(f, "ID,Name,Age,GPA\n");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d,%s,%d,%.2f\n",
                students[i].id,
                students[i].name,
                students[i].age,
                students[i].gpa);
    }
    fclose(f);
    return 1;
}

int main() {
    // Mảng chứa tối đa 5 sinh viên
    Student students[5];
    int n;

    // Nhập số sinh viên (1..5)
    do {
        printf("Nhap so sinh vien (1-5): ");
        if (scanf("%d", &n) != 1) {
            printf("Du lieu nhap khong hop le. Thoat.\n");
            return 1;
        }
        if (n < 1 || n > 5) printf("Vui long nhap so tu 1 den 5.\n");
    } while (n < 1 || n > 5);

    // Nhập thông tin từng sinh viên
    for (int i = 0; i < n; i++) {
        printf("---- Sinh vien %d ----\n", i + 1);
        printf("Nhap ID: ");
        scanf("%d", &students[i].id);
        printf("Nhap Ten: ");
        scanf(" %49[^\\n]", students[i].name);
        printf("Nhap Tuoi: ");
        scanf("%d", &students[i].age);
        printf("Nhap GPA: ");
        scanf("%f", &students[i].gpa);
    }

    // In danh sách sinh viên dưới dạng bảng
    printf("========================================\n");
    printf("      DANH SACH SINH VIEN\n");
    printf("========================================\n");
    printf("%-5s %-30s %-5s %-10s\n", "ID", "Ten", "Tuoi", "GPA");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-5d %-30s %-5d %-10.2f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }

    printf("========================================\n");

    // Lưu danh sách vào file
    if (saveToFile("students.txt", students, n)) {
        printf("Da luu danh sach vao file students.txt\n");
    } else {
        printf("Loi: Khong the luu file students.txt\n");
    }

    return 0;
}
