#include<stdio.h>
#include<stdlib.h>

void read(int *, int );
int check(int *, int );
void merge(int *, int *, int *, int );
void output(int *, int);

int main(){
    int n;
    printf("Enter size of arrays:\n");
    scanf("%d",&n);
    printf("Enter elements of arrays:\n");
    int *a=(int*)malloc(n*sizeof(int));
    int *b=(int*)malloc(n*sizeof(int));
    int *p=(int*)malloc(2*n*sizeof(int));
    read(a,n);
    read(b,n);

    if(check(a,n)==0){
        printf("Invalid: not sorted");
        return 0;
    }
    if(check(b,n)==0){
        printf("Invalid: not sorted");
        return 0;
    }

    printf("After merging\n");
    merge(a,b,p,n);
    output(p,2*n);

}

void read(int *a, int n){
    for(int i=0;i<n;++i){
        scanf("%d", (a+i));
    }
}

int check(int *a, int n){
    for(int i=0;i<n-1;++i){
        if(*(a+i)>*(a+i+1)){
            return 0;
        }
    }
    return 1;
}

void merge(int *a, int *b, int *p, int n){
    int i=0;
    int j=0;
    int k=0;
    while(i<n && j<n){
        if(*(a+i)<*(b+j)){
            *(p+k)=*(a+i);
            i++;
            k++;
        }
        else{
           *(p+k)=*(b+j);
            j++;
            k++;
        }
    }
    while(i<n){
        *(p+k)=*(a+i);
        i++;
        k++;
    }
    while(j<n){
        *(p+k)=*(b+j);
        j++;
        k++;
    }
    return;
}

void output(int *ptr, int n){
    for(int i=0;i<n;++i){
        printf("%d ",*(ptr+i));
    }
    printf("\n");
}
