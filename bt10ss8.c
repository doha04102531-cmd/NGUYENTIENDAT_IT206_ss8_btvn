#include <stdio.h>
#include <string.h>

#define MAX 100

// ===== STRUCT =====
typedef struct {
    int id;
    char name[20];
    int age;
    float gpa;
} Student;

// ===== FUNCTION DECLARATIONS =====
void inputStudents(Student students[], int *n);
void printStudents(Student students[], int n);
void saveToFile(Student students[], int n);
int loadFromFile(Student students[]);
int findStudentById(Student students[], int n, int id);
void sortByGPA(Student students[], int n);
void addStudent(Student students[], int *n);
void deleteStudent(Student students[], int *n);

// ===== FUNCTIONS =====

/**
 * @brief Nhập danh sách sinh viên
 */
void inputStudents(Student students[], int *n) {
    printf("Nhap so sinh vien: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("Sinh vien %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Ten: ");
        scanf("%s", students[i].name);
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }
}

/**
 * @brief In danh sách sinh viên
 */
void printStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %.1f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

/**
 * @brief Ghi danh sách sinh viên ra file
 */
void saveToFile(Student students[], int n) {
    FILE *f = fopen("students.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %s %d %.1f\n",
                students[i].id,
                students[i].name,
                students[i].age,
                students[i].gpa);
    }
    fclose(f);
}

/**
 * @brief Đọc danh sách sinh viên từ file
 */
int loadFromFile(Student students[]) {
    FILE *f = fopen("students.txt", "r");
    if (f == NULL) return 0;

    int n = 0;
    while (fscanf(f, "%d %s %d %f",
                  &students[n].id,
                  students[n].name,
                  &students[n].age,
                  &students[n].gpa) == 4) {
        n++;
    }
    fclose(f);
    return n;
}

/**
 * @brief Tìm sinh viên theo ID
 */
int findStudentById(Student students[], int n, int id) {
    for (int i = 0; i < n; i++)
        if (students[i].id == id)
            return i;
    return -1;
}

/**
 * @brief Sắp xếp sinh viên theo GPA giảm dần
 */
void sortByGPA(Student students[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (students[j].gpa < students[j + 1].gpa) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
}

/**
 * @brief Thêm sinh viên mới
 */
void addStudent(Student students[], int *n) {
    Student s;
    printf("Nhap ID: ");
    scanf("%d", &s.id);

    if (findStudentById(students, *n, s.id) != -1) {
        printf("ID da ton tai!\n");
        return;
    }

    printf("Ten: ");
    scanf("%s", s.name);
    printf("Tuoi: ");
    scanf("%d", &s.age);
    printf("GPA: ");
    scanf("%f", &s.gpa);

    students[*n] = s;
    (*n)++;
}

/**
 * @brief Xoa sinh vien theo ID
 */
void deleteStudent(Student students[], int *n) {
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);

    int index = findStudentById(students, *n, id);
    if (index == -1) {
        printf("Khong tim thay sinh vien!\n");
        return;
    }

    for (int i = index; i < *n - 1; i++)
        students[i] = students[i + 1];

    (*n)--;
}

// ===== MAIN =====
int main() {
    Student students[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n===== Student Manager =====\n");
        printf("1. Nhap sinh vien\n");
        printf("2. In danh sach\n");
        printf("3. Ghi file\n");
        printf("4. Doc file\n");
        printf("5. Tim kiem\n");
        printf("6. Sap xep\n");
        printf("7. Them sinh vien\n");
        printf("8. Xoa sinh vien\n");
        printf("0. Thoat\n");
        printf("===========================\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputStudents(students, &n);
                break;
            case 2:
                printStudents(students, n);
                break;
            case 3:
                saveToFile(students, n);
                break;
            case 4:
                n = loadFromFile(students);
                break;
            case 5: {
                int id;
                printf("Nhap ID can tim: ");
                scanf("%d", &id);
                int idx = findStudentById(students, n, id);
                if (idx != -1)
                    printf("%d %s %d %.1f\n",
                           students[idx].id,
                           students[idx].name,
                           students[idx].age,
                           students[idx].gpa);
                else
                    printf("Khong tim thay!\n");
                break;
            }
            case 6:
                sortByGPA(students, n);
                break;
            case 7:
                addStudent(students, &n);
                break;
            case 8:
                deleteStudent(students, &n);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 0);

    return 0;
}