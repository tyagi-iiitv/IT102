#include<stdio.h>
#include<string.h>
void main(){
	char *str1 = "This is a string with 7 tokens";
	char *ptr;
	printf("The tokens are:\n");
	ptr = strtok(str1," ");
	while(ptr != '\0'){
		printf("%s\n",ptr);
		ptr = strtok('\0'," ");
	}
}
	
	
