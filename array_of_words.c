#include<stdio.h>
#include<stdlib.h>
void main(){
	printf("Enter the number of words\n");
	int n,n1;
	scanf("%d",&n);
	char *arr[n];
	int i;
	for(i=0;i<n;i++){
		printf("Enter the %dth word\n",i+1);
		arr[i]=malloc(sizeof(int));
		scanf("%s",arr[i]);
	}
	printf("Type the number of the word you want to alter\n");
	scanf("%d",&n1);
	char str[20];
	printf("Enter new string to copy to that string\n");
	scanf("%s",str);
	char *ptr=str;
	char *ptr2=arr[n1-1];
	while(*ptr!='\0'){
		*ptr2=*ptr;
		ptr++;
		ptr2++;
	}
	printf("The new array is\n");
	for(i=0;i<n;i++){
		printf("%s\n",arr[i]);
	}
}
