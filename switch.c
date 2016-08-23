#include<stdio.h>
int main(){
	printf("Enter the grade from a-f to calculate number of students with same grade\n");
	printf("Enter EOF i.e. ^d for ubuntu and ^z for windows if you have finished\n");
	char grade;
	int acount = 0;
	int bcount = 0;
	int ccount = 0;
	int dcount = 0;
	int ecount = 0;
	int fcount = 0;
	while((grade = getchar()) != EOF){
		switch(grade){
			case 'A':
			case 'a': acount++;
			break;
			case 'B':
			case 'b': bcount++;
			break;
			case 'C':
			case 'c': ccount++;
			break;
			case 'D':
			case 'd': dcount++;
			break;
			case 'E':
			case 'e': ecount++;
			break;
			case 'F':
			case 'f': fcount++;
			break;
			default: 
			printf("Wrong choice\n");
			break;
		}
	}
	printf("Number of a's are : %d\n", acount);
	printf("Number of b's are : %d\n", bcount);
	printf("Number of c's are : %d\n", ccount);
	printf("Number of d's are : %d\n", dcount);
	printf("Number of e's are : %d\n", ecount);
	printf("Number of f's are : %d\n", fcount);
	return 0;
}
