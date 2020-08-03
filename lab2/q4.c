#include<stdio.h>
#include<stdlib.h>

void input(int **, int, int);
void output(int **, int, int);
void add(int **, int **, int**, int, int);
void initialize(int **, int , int);

int main(){
    int n, m;
    printf("Enter the row size and the column size:");
    scanf("%d%d",&n,&m);

    int **a=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;++i){
        *(a+i)=(int*)malloc(m*sizeof(int));
    }

    int **b=(int **)malloc(n*sizeof(int*));
    for(int i=0;i<n;++i){
        *(b+i)=(int*)malloc(m*sizeof(int));
    }

    int **c=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;++i){
        *(c+i)=(int*)malloc(m*sizeof(int));
    }

    initialize(c, n, m);
    printf("Enter the elements\n");
    input(a, n, m);
    input(b, n, m);
    add(a, b, c, n, m);
    printf("sum:\n");
    output(c, n, m);
}

void input(int **p, int n, int m){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",(*(p+i)+j));
        }
    }
}

void add(int **a, int** b, int** c, int n, int m){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            *(*(c+i)+j)=*(*(a+i)+j) + *(*(b+i)+j);
        }
    }
}

void output(int **c, int n, int m){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            printf("%d ",*(*(c+i)+j));
        }
        printf("\n");
    }
}

void initialize(int **p, int n,int m){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            *(*(p+i)+j)=0;
        }
    }
}

