#include<stdio.h>
#include<string.h>
void compare(char temp[],char arr[],int num[],int i,int pos);
void main(){
	printf("Enter the text you want to enter\n");
	char arr[500];
	int num[100]={0};
	gets(arr);
	int i,j;
	i=0;
	j=0;
	while(i<strlen(arr)){
		char temp[20]={'\0'};
		int pos=i;
		while(arr[i]!=' '&&arr[i]!='\0'&&arr[i]!='!'&&arr[i]!=';'&&arr[i]!=':'&&arr[i]!='"'&&arr[i]!=','&&arr[i]!='.'&&arr[i]!='?'&&arr[i]!='*'){
			temp[j]=arr[i];
			i++;
			j++;
		}
		j=0;
		compare(temp,arr,num,i+1,pos);
		i++;
	}
	i=0;
	j=0;
	while(i<=strlen(arr)){
		char temp[20]={'\0'};
		int pos=i;
		int count=0;
		while(arr[i]!=' '&&arr[i]!='\0'&&arr[i]!='!'&&arr[i]!=';'&&arr[i]!=':'&&arr[i]!='"'&&arr[i]!=','&&arr[i]!='.'&&arr[i]!='?'&&arr[i]!='*'){
			temp[j]=arr[i];
			i++;
			j++;
			count=1;
		}
		j=0;
		if(count == 1){
			printf("%s occurs %d times\n",temp,num[pos]+1);
		}
		i++;
	}
}

void compare(char temp[],char arr[],int num[],int i,int pos){
	int j=0;
	int k;
	while(i<strlen(arr)){
		char temp2[20]={'\0'};
		int start=i;
		while(arr[i]!=' '&&arr[i]!='\0'&&arr[i]!='!'&&arr[i]!=';'&&arr[i]!=':'&&arr[i]!='"'&&arr[i]!=','&&arr[i]!='.'&&arr[i]!='?'&&arr[i]!='*'){
			temp2[j]=arr[i];
			i++;
			j++;
		}
		int end=i;
		j=0;
		if(strcmp(temp,temp2)==0){
			num[pos]=num[pos]+1;
			for(k=start;k<end;k++){
				arr[k]='*';
			}
		}
		i++;
	}
}
			
	
