#include<stdio.h>
void main(){
	printf("This is the program to print the average marks in the class\n");
	printf("Please Enter the number of students in the class\n");
	int number;
	float sum=0;
	float marks;
	scanf("%d", &number);
	int j=1;
	while( j<=number){
		printf("Enter marks of %dth student\n",j);
		scanf("%f", &marks);
		sum = sum+marks;j++;
	}
	float average = sum/number;
	printf("The Average marks of the class are\n");
	printf("%f\n", average);
}
		
