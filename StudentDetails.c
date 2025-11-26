//Entering Student Details 

#include <stdio.h>
struct Student {
    char name[50];
    int rollNumber;
    char branch[30];
    float cgpa;
    char contact[15];
    char email[50];
};
int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name); 
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Branch: ");
        scanf(" %[^\n]s", students[i].branch);

        printf("CGPA: ");
        scanf("%f", &students[i].cgpa);

        printf("Contact Number: ");
        scanf(" %[^\n]s", students[i].contact);

        printf("Email ID: ");
        scanf(" %[^\n]s", students[i].email);
    }
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name         : %s\n", students[i].name);
        printf("Roll Number  : %d\n", students[i].rollNumber);
        printf("Branch       : %s\n", students[i].branch);
        printf("CGPA         : %.2f\n", students[i].cgpa);
        printf("Contact No.  : %s\n", students[i].contact);
        printf("Email ID     : %s\n", students[i].email);
    }

    return 0;
}
