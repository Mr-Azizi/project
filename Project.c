#include <stdio.h>
#include <string.h>

char Students [200][100];
double Scores [200];
int Student_count = 0;

//----------------------------------------
void addStudent();
void displayStudents();
void calculateAverage();
void findStudent();
//----------------------------------------
int main()
{
    int choice;
    do {
        printf("\n----------- Menu -----------\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Calculate Average\n");
        printf("4. Find Student\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            calculateAverage();
            break;
        case 4:
            findStudent();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}

//------------------------------------------------

void addStudent()
{
    printf("\n-----------(NEW STUDENT)-----------\n");

    char name[100];
    double score;

    printf("Eneter student's name: \n");
    scanf(" %[^\n]", name);

    printf("Enter student's score: \n");
    scanf("%lf", &score);

    strcpy(Students[Student_count], name);
    Scores[Student_count] = score;
    Student_count++;
}

void displayStudents()
{
    printf("\n-----------(List)-----------\n");
    for (int i = 0; i < Student_count; i++)
    {
        printf("number(%d) Name: %s Score: %.2lf\n ", i+1, Students[i], Scores[i]);
    }
}

void calculateAverage()
{
    printf("\n-----------(Average Scores)-----------\n");
    double sum;
    for (int i = 0; i < Student_count; i++)
    {
        sum += Scores[i];
    }
    double average = sum / Student_count;
    printf("Average: %.2f", average);
}

void findStudent()
{
    char serchStudet[100];
    double Student_score;
    int find=0;
    printf("Enter Student's name: ");
    scanf("%s", &serchStudet);
    
    for (int i = 0; i < Student_count; i++)
    {
        if (strcmp(Students[i], serchStudet) == 0)
        {
            find = 1;
            Student_score = Scores[i];
            break;
        }
    }
    if (find == 1)
    {
        printf("Name: %s / Score: %.2lf",serchStudet , Student_score);
    }else
    {
        printf("The Student Not found!");
    }
}