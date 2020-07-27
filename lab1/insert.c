/*
* Write a program to input n elements in an array and then insert m elements
* one by one at specifed position and display the array elements after overall 
* insertion.
*created by- Abhas  Kumar
* Date- 27/07/2020
*/


#include<stdio.h>
int main(){
	int n;
	int m;
	printf("Enter no of initial elements and no of insertions\n");
	scanf("%d%d",&n, &m);
	int arr[7];
	int *p;
	p=arr;
	int j=1;
	printf("Enter initial elements\n");
	for(int i=0;i<n;++i){
		scanf("%d",(p+i));
	}
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

