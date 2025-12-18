#include <stdio.h>
#include <string.h>

// Định nghĩa struct Student
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Hàm lưu danh sách sinh viên vào file
void saveToFile(Student students[], int n) {
    FILE *f = fopen("students.txt", "w");

    if (f == NULL) {
        printf("Khong the mo file students.txt\n");
        return;
    }

    fprintf(f, "========================================\n");
    fprintf(f, "      DANH SACH SINH VIEN\n");
    fprintf(f, "========================================\n");
    fprintf(f, "%-5s %-30s %-5s %-10s\n", "ID", "Ten", "Tuoi", "GPA");
    fprintf(f, "-----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        fprintf(f, "%-5d %-30s %-5d %-10.2f\n",
                students[i].id,
                students[i].name,
                students[i].age,
                students[i].gpa);
    }

    fprintf(f, "========================================\n");

    fclose(f);
}

int main() {
    Student students[5];
    int n;

    // Nhập số sinh viên
    do {
        printf("Nhap so sinh vien (1-5): ");
        if (scanf("%d", &n) != 1) {
            printf("Du lieu nhap khong hop le.\n");
            return 1;
        }
    } while (n < 1 || n > 5);

    // Nhập thông tin sinh viên
    for (int i = 0; i < n; i++) {
        printf("---- Sinh vien %d ----\n", i + 1);

        printf("Nhap ID: ");
        scanf("%d", &students[i].id);

        printf("Nhap Ten: ");
        scanf(" %49[^\n]", students[i].name);

        printf("Nhap Tuoi: ");
        scanf("%d", &students[i].age);

        printf("Nhap GPA: ");
        scanf("%f", &students[i].gpa);
    }

    // In danh sách sinh viên
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

    // Lưu vào file
    saveToFile(students, n);
    printf("Da luu danh sach sinh vien vao students.txt\n");

    return 0;
}
123