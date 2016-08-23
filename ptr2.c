#include<stdio.h>
void copyarr(char *s1, int num1, char *s2);
void copyptr(char *s3, int num3, char *s4);
void main(){
	char *str1 = "Hello";
	char str2[10];
	char *str3 = "Good bye";
	char str4[10];
	printf("First string is: %s\n",str1);
	copyarr(str1,6,str2);
	printf("Third string is: %s\n",str3);
	copyptr(str3,9,str4);
	printf("Fourth string is: %s\n",str4);
}
void copyarr(char *s1, int num1, char *s2){
	int i;
	for(i=0;i<num1;i++){
		s2[i]=s1[i];
	}
	printf("Second string is: %s\n", s2);
}
void copyptr(char *s3, int num3, char *s4){
	while(*s3 != '\0'){
		*s4 = *s3;
		s3++;
		s4++;
	}
}

	
		
		
