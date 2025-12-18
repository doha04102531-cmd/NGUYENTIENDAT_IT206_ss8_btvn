#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
    float gpa;
} Student;

/**
 * @brief Sắp xếp danh sách sinh viên theo GPA giảm dần
 *
 * @param students Mảng sinh viên
 * @param n        Số lượng sinh viên
 */
void sortByGPA(Student students[], int n) {
    Student temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].gpa < students[j + 1].gpa) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void printStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %.1f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

int main() {
    Student students[] = {
        {1, "An", 20, 8.0},
        {2, "Binh", 21, 7.5},
        {3, "Chi", 19, 9.0}
    };

    int n = 3;

    sortByGPA(students, n);

    printf("Danh sach sau khi sap xep:\n");
    printStudents(students, n);

    return 0;
}
