#include<stdio.h>
void main(){
	printf("Use of pointers to change the value of an integer\n");
	int a = 10;
	int *p=&a;
	*p=20;
	printf("New value of a is: %d\n",a);
}
