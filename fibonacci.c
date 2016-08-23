#include<stdio.h>
void main(){
	printf("This is the program to print fibonacci series\n");
	printf("Please enter the amount of time you want to run the seies\n");
	int number;
	scanf("%d", &number);
	int a=0;
	printf("0 ");
	int b=1;
	int i=1;
	int c;
	while( i<number){
		c =a+b;
		printf("%d ", c);
		a =b;
		b =c;
		i++;
	}
	printf("\n");
}
