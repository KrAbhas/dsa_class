#include<stdio.h>
#include<stdlib.h>

struct form{
    char name[10];
    int rn;
    int marks[5];
    int tm;
    float av;
};
typedef struct form student;

void read(student*, int );
void total_marks(student*, int);
void print(student*, int);
void avg(student*, int);

int main(){
    int n;
    printf("Enter no of students\n");
    scanf("%d",&n);
    student* std = (student*)malloc(n*sizeof(student));
    read(std, n);
    total_marks(std, n);
    avg(std,n);
    print(std, n);
}

void read(student* std, int n){
    for(int i=0;i<n;++i){
        printf("enter details of student %d\n", i+1);
        scanf("%s",(std+i)->name);
        scanf("%d",&(std+i)->rn);
        for(int j=0;j<5;++j){
            scanf("%d",&(std+i)->marks[j]);
        }
        (std+i)->tm=0;
    }
}


void total_marks(student* std, int n){
   for(int i=0;i<n;++i){
        for(int j=0;j<5;++j){
            (std+i)->tm+=(std+i)->marks[j];
        }
    }
}

void avg(student* std, int n){
   for(int i=0;i<n;++i){
        (std+i)->av=((std+i)->tm)/5.0;
    }
}

void print(student* std, int n){
    printf("details of students in sorted order\n");
    for(int i=0;i<n;++i){
        printf("%s\t",(std+i)->name);
        printf("%d\t",(std+i)->rn);
        printf("%d\t",(std+i)->tm);
        printf("%.2f\n",(std+i)->av);
    }
}

