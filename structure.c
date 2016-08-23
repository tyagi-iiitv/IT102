#include<stdio.h>
void main(){
	printf("This program will print the values of three arrays in the structure\n");
	printf("Enter the number of entries in array 1\n");
	int num1;
	scanf("%d",&num1);
	printf("Enter the number of entries in array 1\n");
	int num2,j;
	scanf("%d",&num2);
	printf("Enter the number of entries in array 1\n");
	int num3;
	scanf("%d",&num3);
struct calc{
	int arr1[num1];
	int arr2[num2];
	int arr3[num3];
};

void func(){
	int i;
	struct calc a;
	printf("Fill array 1\n");
	for(i=0;i<num1;i++){
		scanf("%d",&a.arr1[i]);
	}
	printf("Fill array 2\n");
	for(i=0;i<num2;i++){
		scanf("%d",&a.arr2[i]);
	}	
	printf("Fill aray 3\n");
	for(i=0;i<num3;i++){
		scanf("%d",&a.arr3[i]);
	}
	printf("Array 1 is:\n");
for(j=0;j<num1;j++){
	printf("%d ",a.arr1[j]);
}
printf("\n");
printf("Array 2 is:\n");
for(j=0;j<num2;j++){
	printf("%d ",a.arr2[j]);
}
printf("\n");
printf("Array 1 is:\n");
for(j=0;j<num3;j++){
	printf("%d ",a.arr3[j]);
}
printf("\n");
}
struct calc b;
func(b);

}



















