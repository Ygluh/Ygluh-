#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>

typedef struct Student {
    int record_book_number;
    char full_name[50];
    char group[10];
    float midterm_score;
} Student;

Student* students = NULL;
int num_students = 0;//переменная для хранения колва студентов

void add_student(int record_book_number, char* full_name, char* group, float midterm_score) {
    students = realloc(students, (num_students + 1) * sizeof(Student));//добавление памаяти к уже существующей
    students[num_students].record_book_number = record_book_number;
    strcpy(students[num_students].full_name, full_name);//копируем имя в поле имени стедента
    strcpy(students[num_students].group, group);
    students[num_students].midterm_score = midterm_score;
    num_students++;
}

void remove_students_with_low_scores() {
    int i = 0;
    while (i < num_students) 
    {
        if (students[i].midterm_score < 3)
        {
            for (int j = i; j < num_students - 1; j++) 
            {
                students[j] = students[j + 1];
            }
            num_students--;
        }
        else 
        {
            i++;
        }
    }
}

void print_students() {
    for (int i = 0; i < num_students; i++)
    {
        printf("%d) %d %s %s %.2f\n", i+1, students[i].record_book_number, students[i].full_name, students[i].group, students[i].midterm_score);
    }
}


int main() {
    srand(time(NULL)); //генератор случайных чисел
    add_student(rand()%899999+100000, "Lareonov Vadim Olegovich", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Lev Nikolaevich Tolstoy", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Popova Alisa Sergeevna", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Yakovlev Gleb Konstantinovich", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Kopylov Mikhail Egorovich", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Evdakimov Yaroslav Mikhailovich", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Blinov Lev Kirillovich", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Evdokimova Sofia Miroslavovna", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Gorelova Maria Kirillovna", "IA-23",rand()%5+1);
    add_student(rand()%899999+100000, "Nikolaeva Sofia Maksimovna", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Rodionov Mark Mironovich", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Rusanova Varvara Dmitrievna", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Samsonov Grigory Alekseevich", "IA-23",rand()%5+1);
    add_student(rand()%899999+100000, "Lavrov Artyom Mironovich", "IA-23", rand()%5+1);
    add_student(rand()%899999+100000, "Serova Kristina Egorovna", "IA-23", rand()%5+1);

    printf("all the students:\n");
    print_students();

    int d; //переменная для хранения ответа пользователя
    while (1)//бесконечный цикл для добавления новых студентов
    {    
    printf("\n Want to add a student? [1/0]\n");
    scanf("%d",&d);
    if(d == 0)
    {
        break;
    }
    char name[50], group[10];
    int h, b;
    
    printf("Record number: ");
    scanf("%d", h);

    printf("Full name: ");
    scanf("%c", name);

    printf("group: ");
    scanf("%c", group);

    printf("point: ");
    scanf("%d", b);

    add_student(h,name,group,b);//вызов функции для добавления нового студента в массив
    }

    printf("all the students:\n");
    print_students();


    printf("\n\nStudents with good scores:\n");
    remove_students_with_low_scores();
    print_students();

    return 0;
}
