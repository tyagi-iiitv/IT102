#include<stdio.h>
#include<string.h>
void main(){
	printf("Program to sort strings in alphabetical order\n");
	printf("Enter the number of strings\n");
	int n;
	scanf("%d",&n);
	struct abc{
		char str[20];
	};
	struct abc arr[n];
	int i,j,k;
	for(i=0;i<n;i++){
		printf("Enter the %dth string without spaces\n",i+1);
		scanf("%s",arr[i].str);
	}
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if (strcmp(arr[j].str,arr[i].str)>0){
				char temp[20];
				strcpy(temp,arr[i].str);
				for(k=i;k>j;k--){
					strcpy(arr[k].str,arr[k-1].str);
				}
				strcpy(arr[j].str,temp);
			}
		}
	}
	printf("Sorted strings are\n");
	for(i=0;i<n;i++){
		printf("%s\n",arr[i].str);
	}
}
		 
