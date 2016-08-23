#include<stdio.h>
void main(){
	printf("This is the program for printing n^m without using maths library\n");
	printf("Please enter the value of 'n'\n");
	int n,m,i,swap;
	scanf("%d", &n);
	printf("Please enter the value of 'm'\n");
	scanf("%d", &m);
	swap = n;
	for(i=1; i<m; i++){
		n = n*swap;
	}
	printf("The value of n^m is %d\n", n);
}
	
	
