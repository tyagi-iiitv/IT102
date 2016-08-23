#include<stdio.h>
void main(){
	printf("This is the program to print the grade of the student\n");
	printf("Please enter your percentage\n");
	float per;
	scanf("%f", &per);
	if( per>=90)
		printf("Grade is A\n");
	else
	if( per>=80)
		printf("Grade is B\n");
	else
	if( per>=70)
		printf("Grade is C\n");
	else
	if( per>=60)
		printf("Grade is D\n");
	else
	if( per<60)
		printf("You are failed\n");
	else
		printf("Incorrect Percentage\n");
}
