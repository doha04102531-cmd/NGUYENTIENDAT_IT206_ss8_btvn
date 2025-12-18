#include <stdio.h>
#include <string.h>

#define MAX 5

// ================= STRUCT =================
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// ================= FUNCTION PROTOTYPES =================
void inputStudents(Student students[], int n);
void printStudents(Student students[], int n);
void saveToFile(Student students[], int n);
int loadFromFile(Student students[]);
int findStudentById(Student students[], int n, int id);

// ================= FUNCTIONS =================

void inputStudents(Student students[], int n) {
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
}

void printStudents(Student students[], int n) {
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
}

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

int loadFromFile(Student students[]) {
    FILE *f = fopen("students.txt", "r");
    if (f == NULL) {
        return 0;
    }

    char line[200];
    int count = 0;

    // Bỏ qua phần tiêu đề
    for (int i = 0; i < 5; i++) {
        fgets(line, sizeof(line), f);
    }

    while (fscanf(f, "%d %49[^\n] %d %f",
                  &students[count].id,
                  students[count].name,
                  &students[count].age,
                  &students[count].gpa) == 4) {
        count++;
        if (count >= MAX) break;
    }

    fclose(f);
    return count;
}

/**
 * @brief Tìm kiếm sinh viên theo ID
 *
 * Duyệt qua mảng sinh viên để tìm sinh viên có ID trùng khớp.
 *
 * @param students  Mảng sinh viên
 * @param n         Số lượng sinh viên
 * @param id        ID cần tìm
 *
 * @return int
 *  - Trả về index sinh viên nếu tìm thấy
 *  - Trả về -1 nếu không tìm thấy hoặc ID < 0
 */
int findStudentById(Student students[], int n, int id) {
    if (id < 0) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

// ================= MAIN =================
int main() {
    Student students[MAX];
    int n;

    // Nhập số sinh viên
    do {
        printf("Nhap so sinh vien (1-5): ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    // Nhập + in + lưu
    inputStudents(students, n);
    printStudents(students, n);
    saveToFile(students, n);

    // Đọc lại từ file
    printf("\nDOC DU LIEU TU FILE:\n");
    n = loadFromFile(students);
    printStudents(students, n);

    // ===== TEST TÌM KIẾM =====
    int searchId;
    printf("\nNhap ID can tim: ");
    scanf("%d", &searchId);

    int index = findStudentById(students, n, searchId);

    if (index != -1) {
        printf("Tim thay sinh vien:\n");
        printf("ID: %d\n", students[index].id);
        printf("Ten: %s\n", students[index].name);
        printf("Tuoi: %d\n", students[index].age);
        printf("GPA: %.2f\n", students[index].gpa);
    } else {
        printf("Khong tim thay sinh vien co ID = %d\n", searchId);
    }

    return 0;
}
