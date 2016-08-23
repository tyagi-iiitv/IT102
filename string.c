#include<stdio.h>
#include<string.h>
void main(){
	printf("Enter the number of entries of names you want to enter\n");
	int num;
	scanf("%d",&num);
	struct entry{
		char name[20];
		char dob[11];
	};
    struct entry arr[num];
	int i,j;
	struct entry jump[num];
	for(i=0;i<num;i++)
	{
		printf("Enter The name, upto 20 characters\n");
		gets(arr[i-1].name);
		printf("enter the D.O.B as DD-MM-YYYY\n");
		gets(arr[i].dob);
	}
	for(i=0;i<num;i++){
		for(j=0;j<num-1;j++){
			if(strcmp(arr[j].name,arr[j+1].name) > 0){
				jump[j] = arr[j];
				arr[j+1] = arr[j];
				jump[j] = arr[j+1];
			}
		}
	}
	printf("The new sorted format is\n");
	for(i=0;i<num;i++){
		printf("Name: %s\nD.O.B: %s",arr[i].name,arr[i].dob);
	}printf("\n");
}
