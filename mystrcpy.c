#include<stdio.h>
void main(){
	char str1[20];
	char str2[20];
	printf("Enter string 1\n");
	scanf("%s",str1);
	printf("Enter string 2\n");
	scanf("%s",str2);
	char *c1=str1;
	char *c2=str2;
	printf("String one after copying to string 2 is :\n");
	while(*c1!='\0'){
		*c2=*c1;
		c2++;
		c1++;
	}
	printf("%s\n",str2);
}
