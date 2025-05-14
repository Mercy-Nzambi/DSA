#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char courseName[30];
    int courseCode;
} Course;

typedef struct {
    int mark;
    char the_grade;
    bool gradeCalculated;
} Grade;

char gradeStudent(int mark) {
    if (mark >= 0 && mark <= 100) {
        if (mark > 69) {
            return 'A';
        } else if (mark > 59) {
            return 'B';
        } else if (mark > 49) {
            return 'C';
        } else if (mark > 39) {
            return 'D';
        } else {
            return 'E';
        }
    }
}

typedef struct {
    char studentName[50];
    char regNo[20];
    int age;
    Course course;
    Grade grades;
} Student;

void createStudent(Student* student, const char* studentName, const char* regNo, int age, Course course, Grade grades) {
    for(int i=0; i<40; i++){
    student->studentName[i] = studentName[i];
    student->regNo[i] = regNo[i];
    student->age = age;
    student->course = course;
    student->grades = grades;
    }
}

void editStudentDetails(Student* student) {
    int choice;
    printf("\nEdit Student Details:\n");
    printf("1. Edit Name\n");
    printf("2. Edit Registration Number\n");
    printf("3. Edit Age\n");
    printf("4. Edit Course\n");
    printf("5. Edit Marks\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter new name: ");
            scanf("%49s", student->studentName);
            break;
        case 2:
            printf("Enter new registration number: ");
            scanf("%s", student->regNo);
            break;
        case 3:
            printf("Enter new age: ");
            scanf("%d", &student->age);
            break;
        case 4:
            printf("Enter new course name: ");
            scanf("%s", student->course.courseName);
            printf("Enter new course code: ");
            scanf("%d", &student->course.courseCode);
            break;
        case 5:
            if (student->grades.gradeCalculated) {
                printf("Grades already calculated and cannot be changed!\n");
            } else {
                printf("Enter new mark (0-100): ");
                scanf("%d", &student->grades.mark);
                student->grades.the_grade = gradeStudent(student->grades.mark);
                student->grades.gradeCalculated = true;
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}


int main() {
    Course CT = {"Computer Technology", 212};
    Student students[40];
    int studentCount = 0;

    for (int i = 0; i < 5; i++) {
        char studentName[50];
        char regNo[20];
        int age;
        int mark;
        int choice;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Edit Student Details\n");
        printf("3. Add Marks and Calculate Grades\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (studentCount >= 40 ) {
                    printf("Maximum student capacity reached!\n");
                    break;
                }
                char studentName[50];
                char regNo[20];
                int age;
                int mark;

                printf("Enter Your Name: ");
                scanf("%s", studentName);

                printf("Enter your Registration Number: ");
                scanf("%s", regNo);

                printf("Enter your age: ");
                scanf("%d", &age);

                Grade grades;
                grades.mark = 0;
                grades.the_grade = gradeStudent(mark);
                grades.gradeCalculated = false;

                createStudent(&students[studentCount], studentName, regNo, age, CT, grades);
                studentCount++;
                printf("Student added successfully!\n");
                break;
            }
            case 2: {
    if (studentCount == 0) {
        printf("No students available to edit.\n");
        break;
    }
    int index;
    printf("Enter student number to edit (1-%d): ", studentCount);
    scanf("%d", &index);
    if (index < 1 || index > studentCount) {
        printf("Invalid student number!\n");
        break;
    }
    editStudentDetails(&students[index-1]);
    break;
}
            case 3: {
                if (studentCount == 0) {
                    printf("No students available.\n");
                    break;
                }
                int index;
                printf("Enter student number to add marks (1-%d): ", studentCount);
                scanf("%d", &index);
                if (index < 1 || index > studentCount) {
                    printf("Invalid student number!\n");
                    break;
                }
                if (students[index-1].grades.gradeCalculated) {
                    printf("Grades already calculated for this student!\n");
                    break;
                }
                printf("Enter the student's mark (0-100): ");
                scanf("%d", &students[index-1].grades.mark);
                students[index-1].grades.the_grade = gradeStudent(students[index-1].grades.mark);
                students[index-1].grades.gradeCalculated = true;
                printf("Grade calculated: %c\n", students[index-1].grades.the_grade);
                break;
            }
            case 4: {
                if (studentCount == 0) {
                    printf("No students to display.\n");
                    break;
                }
                printf("\nStudents Information:\n");
                for (int i = 0; i < studentCount; i++) {
                    printf("Student %d:\n", i+1);
                    printf("Name: %s\n", students[i].studentName);
                    printf("Registration Number: %s\n", students[i].regNo);
                    printf("Age: %d\n", students[i].age);
                    printf("Course Name: %s\n", students[i].course.courseName);
                    printf("Course Code: %d\n", students[i].course.courseCode);
                    if (students[i].grades.gradeCalculated) {
                        printf("Marks: %d\n", students[i].grades.mark);
                        printf("Grade: %c\n", students[i].grades.the_grade);
                    } else {
                        printf("Marks: Not entered\n");
                        printf("Grade: Not calculated\n");
                    }
                    printf("\n");
                }
                break;
            }
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    printf("Press Enter to exit...");
    return 0;
}

}
