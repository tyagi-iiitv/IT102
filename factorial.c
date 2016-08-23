#include<stdio.h>
void main(){
	printf("This is the program for calculating the factorial of the given number\n");
	printf("Plase enter the number\n");
	int num,i;
	int fact = 1;
	scanf("%d", &num);
	for(i=1; i<=num; i++){
		fact = fact*i;
	}
	printf("The factorial of %d is %d\n", num, fact);
}
	
