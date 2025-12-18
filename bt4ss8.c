#include <stdio.h>
#include <string.h>

// Định nghĩa struct Student
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Hàm đọc danh sách sinh viên từ file
int loadFromFile(Student students[]) {
    FILE *f = fopen("students.txt", "r");
    if (f == NULL) {
        printf("Khong the mo file students.txt\n");
        return 0;
    }

    char line[200];
    int count = 0;

    // Bỏ qua 5 dòng đầu (tiêu đề + đường kẻ)
    for (int i = 0; i < 5; i++) {
        if (fgets(line, sizeof(line), f) == NULL) {
            fclose(f);
            return 0;
        }
    }

    // Đọc từng sinh viên
    while (fscanf(f, "%d %49[^\n] %d %f",
                  &students[count].id,
                  students[count].name,
                  &students[count].age,
                  &students[count].gpa) == 4) {
        count++;
        if (count >= 5) break;
    }

    fclose(f);
    return count;
}

// Hàm in danh sách sinh viên
void printStudents(Student students[], int n) {
    printf("========================================\n");
    printf("      DANH SACH SINH VIEN (TU FILE)\n");
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
}

int main() {
    Student students[5];
    int n;

    // Đọc dữ liệu từ file
    n = loadFromFile(students);

    if (n == 0) {
        printf("Khong co du lieu de hien thi.\n");
        return 0;
    }

    // In ra màn hình
    printStudents(students, n);

    return 0;
}
