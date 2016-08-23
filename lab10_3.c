#include<stdio.h>
void swap(float a, float b);
void main(){
	printf("Enter the first number\n");
	float n1;
	scanf("%f",&n1);
	float n2;
	printf("Enter the second number\n");
	scanf("%f",&n2);
	swap(n1,n2);
}
void swap(float a, float b){
	float c=a;
	a=b;
	b=c;
	printf("Value of first number is: %.1f\n",a);
	printf("value of second number is: %.1f\n",b);
}
	
