#include<stdio.h>
#include<stdlib.h>

void insert(int *,int);
void del(int *,int);
void sort(int *,int);
void search(int *,int);
void reverse(int *,int);
void read(int *, int );
void output(int *,int);

int main(){
    int n; int k;
    printf("Enter size off array\n");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    printf("Enter elements\n");
    read(a,n);
    int c;
    printf("Enter your choice: 1.insertion 2.deletion 3.searching 4.sorting 5.reverse\n");
    scanf("%d",&c);
    switch(c){
        case 1:
            insert(a,n);
            break;
        case 2:
            del(a,n);
            break;
        case 3:
            search(a,n);
            break;
        case 4:
            sort(a,n);
            printf("Sorted order:\n");
            output(a,n);
            break;
        case 5:
            reverse(a,n);
            printf("Reversed order:\n");
            output(a,n);
            break;
    }
}

void insert(int *arr, int n){
	int m;
	printf("Maximum size is 7\nEnter no of insertions\n");

	scanf("%d",&m);
	if(n>=7){
        printf("invalid size of array\n");
	}
	int *p;
	p=arr;
	int j=1;
	for(j;j<=m;++j){

		if(j+n>7){
			printf("outOfBound\n");
			break;
		}
		printf("Enter element to be inserted and the position at which to be entered\n");
		int k;
		int pos;
		scanf("%d%d",&k,&pos);
		//int *ptr=arr+j+n-1;
		int i=n-1+j;
		for(i;i>pos;--i)
		{
			arr[i]=arr[i-1];
		}
		arr[i]=k;
	}
	for(int i=0;i<n+j-1;++i){
		printf("%d ",*(p+i));
	}
}


void sort(int *a, int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n-i-1;++j){
            if(*(a+j)>*(a+j+1)){
                int t=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=t;
            }
        }
    }
}

void reverse(int *p, int n){
    int t;
    for(int i=0;i<n/2;++i){
        t=*(p+i);
        *(p+i)=*(p-i+n-1);
        *(p+n-i-1)=t;
    }
}

void output(int *ptr, int n){
    for(int i=0;i<n;++i){
        printf("%d ",*(ptr+i));
    }
    printf("\n");
}

void del(int *arr, int n){
	printf("Enter no of elements to be deleted:\n");
	int m;
	scanf("%d", &m);
	int a=n;
	for(int j=0;j<m;++j){
		if(n==0){
			printf("No more element left to delete\n");
			break;
		}
		int pos;
		scanf("%d",&pos);
		if(pos>n){
			printf("OutOfBound\nSelect below %d\n",n+1);
			j--;
			continue;
		}
		for(int i=pos;i<n-1;++i){
			arr[i]=arr[i+1];
		}
		n--;
	}
	printf("The array after delete operation(s):\n");
	for(int i=0;i<n;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}


void search(int *arr,int n){
	int k;
	printf("Enter element to be searched\n");
	scanf("%d",&k);
	int a=0;
	printf("position=\t");
	for(int i=0;i<n;++i)
	{
		if(arr[i]==k){
			a=1;
			printf("%d",i);
		}
	}
	if(a==0){
		printf("notFound");
	}
}

void read(int *a, int n){
    for(int i=0;i<n;++i){
        scanf("%d", (a+i));
    }
}
