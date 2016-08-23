#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main(){
	printf("Enter the text:\n");
	char arr[200]={'\0'};
	gets(arr);
	int s = 0;
	int i,j,k,l,m;
	for(i=0;i<strlen(arr);i++){
		if(isspace(arr[i])){
			s++;
		}
		if(i%20==0&&i!=0){
			if(arr[i]!=' '){
				j=i-1;
				while(arr[j]!=' '){
					j--;
				}
				int count = i-j-1;
				for(k=0;k<=(i-j-1)/(s-1);k++){
					l=i-20;
					while(l<j){
						if(count == 0){
							break;
						}	
						else if(isspace(arr[l])){
							for(m=strlen(arr);m>=l;m--){
								arr[m+1]=arr[m];
							}
							count--;
							l++;
						}
						l++;
					}
				}
				
				s=0;
			}
			else{
				for(m=i;m<=strlen(arr)-1;m++){
					arr[m]=arr[m+1];
				}
				s = 0;
				/*
				for(i=0;i<strlen(arr);i++){
					printf("%c",arr[i]);
				}
				printf("\n");
				*/ 
			}
		}
	}
	for(i=0;i<strlen(arr);i++){
		if(i%20==19){
			if(isspace(arr[i])){
				j=i-1;
				while(arr[j]!=' '){
					j--;
				}
				for(k=i-1;k>=j;k--){
					arr[k+1]=arr[k];
				}
			}
		}
	}
	for(i=0;i<strlen(arr);i++){	
		if(i%20==0){
			printf("\n");
		}
		printf("%c",arr[i]);
	}
	printf("\n");
}
			
