/*strstr*/
#include<stdio.h>
#include<string.h>
void main(){
	char *str1 = "abcdefabcdef";
	char *str2 = "def";
	printf("the portion of: %s beginning with: %s is %s\n",str1,str2,strstr(str1,str2)); 
}

	
	
