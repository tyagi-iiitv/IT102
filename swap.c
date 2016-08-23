#include<stdio.h>
void main(){
	int a,b,c;
	printf("Please enter the value of first number 'a'\n");
	scanf("%d", &a);
	printf("Please enter the value of second number 'b'\n");
	scanf("%d", &b);
	printf("--------------------------------------------------------\n");
	printf("Now swapping of two numbers will occur\n");
	printf("-------------------------------------------------------\n");
	c = a;
	a = b;
	b = c;
	printf("The value of first number 'a' is %d\n", a);
	printf("The value of second number 'b' is %d\n", b);
}
	
