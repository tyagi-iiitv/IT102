#include<stdio.h>
#include<stdlib.h>
void main(){
	printf("Showing the use of some stdlib functions\n");
	printf("First we will convert a string value to double\n");
	printf("Enter the string value\n");
	char str1[20];
	gets(str1);
	double a;
	a = atof(str1);
	printf("The converted value is: %lf\n",a);
	printf("NOW we will convert a separate the numeric and string portion of the string\n");
	printf("Enter the string\n");
	char str2[20];
	gets(str2);
	double b;
	char *str3;
	b = strtod(str2,&str3);
	printf("The numeric value is: %lf\n",b);
	printf("The string is: %s\n",str3);
	printf("NOW we will convert a separate the numeric and string portion of the string with a base\n");
	printf("Enter the string\n");
	char str4[20];
	gets(str4);
	long c;
	char *str5;
	c = strtol(str4,&str5,2);
	printf("The numeric value is: %lf\n",b);
	printf("The string is: %s\n",str5);
}
