#include<stdio.h>
#include<string.h>

struct student{
    char name[100];
    int id;
    float marks;
};
  int main(){
    struct student s1;
    s1.id = 32;
    s1.marks = 9.5;
    strcpy(s1.name, "hello");

    printf("student name : %s \n" , s1.name);
    printf("student roll no.: %d \n", s1.id);
    printf("student cgpa : %f \n" , s1.marks);

    return 0;
  }

