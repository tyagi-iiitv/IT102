#include<stdio.h>
	void bubble(int work[],int size,int (*compare)(int a,int b));
	int ascending(int a,int b);
	int descending(int a,int b);
	void main(){
		int order;
		int counter;
		int a[10]={2,6,4,8,10,12,89,68,45,37};
		printf("Enter 1 to sort ascending\nEnter 2 to sort descending\n");
		scanf("%d",&order);
		printf("Data items in original order\n");
		for(counter=0;counter<10;counter++){
			printf("%5d",a[counter]);
		}
		if(order==1){
			bubble(a,10,ascending);
			printf("Data items in ascending order\n");
		}
		else{
			bubble(a,10,descending);
			printf("Data items in descending order\n");
		}
		for(counter=0;counter<10;counter++){
			printf("%5d",a[counter]);
		}
		printf("\n");
	}
	void bubble(int work[],int size,int (*compare)(int a,int b)){
		int pass;
		int count;
		void swap(int *ptr1, int *ptr2);
		for(pass=1;pass<size;pass++){
			for(count=0;count<size-1;count++){
				if((*compare)(work[count],work[count+1])){
					swap(&work[count],&work[count+1]);
				}
			}
		}
	}
	void swap(int *ptr1,int *ptr2){
		int hold;
		hold=*ptr1;
		*ptr1=*ptr2;
		*ptr2=hold;
	}
	int ascending(int a,int b){
		return b<a;
	}
	int descending(int a,int b){
		return b>a;
	}
					
	
		
		
		
		
		
		
		
		
		
		
		
		
		
