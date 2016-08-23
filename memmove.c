#include<stdio.h>
#include<string.h>
void main(){
	char str1[] = "Home sweet home";
	char str2[10];
	memmove(str2,&str1[5],10);
	printf("%s\n",str2);
}
