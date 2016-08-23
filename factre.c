#include<stdio.h>
void main(){
printf("This program will print the factorial of the number using recursion\n");
printf("Enter the number whose factorial you want to find?\n");
int num;
scanf("%d", &num);
int fact(int n){
	if(n == 0){
	return 1;
	}
	if(n == 1){
	return 1;
	}
	else
	return n*fact(n-1);
	}
printf("The factorial is = %d\n", fact(num));
}
