#include<stdio.h>
void main(){
	printf("This is the program for swapping two numbers with using only two variables\n");
	float a,b;
	printf("Please enter the first number 'a'\n");
	scanf("%f", &a);
	printf("Enter the second number 'b'\n");
	scanf("%f", &b);
	printf("------------------------------------------------------\n");
	printf("The swapped numbers are\n");
	printf("------------------------------------------------------\n");
	a = a+b;
	b = a-b;
	a = a-b;
	printf("The value of 'a' is %5.2f\n", a);
	printf("The valus of 'b' is %5.2f\n", b);
}
