#include<stdio.h>
int main(){
	printf("Enter the first  integer number\n");
	double num1, num2;
	scanf("%lf",&num1);
	printf("Eter the second number in integer\n");
	scanf("%lf",&num2);
	float average;
	average = (double)(num1 + num2)/2;
	printf("The average is %f\n",average);
	return 0;
}
	
