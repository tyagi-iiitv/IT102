#include<stdio.h>
int main(){
	printf("This program shows the use of escape sequences\n");
	printf("Press 1 for using \\n \n");
	printf("press 2 for using \\t \n");
	printf("press 3 for using \\a \n");
	printf("press 4 for using \\ \n");
	printf("press 5 for using \" \n");
	printf("press 0 to exit \n");
	int num, num2;
	scanf("%d",&num);
	do{
		switch(num){
			case 1: printf("\n");
			break;
			case 2: printf("\t \n");
			break;
			case 3: printf("\a \n");
			break;
			case 4: printf("\\ \n");
			break;
			case 5: printf("\" \n");
			break;
		}
	printf("Press 1 for using \\n \n");
	printf("press 2 for using \\t \n");
	printf("press 3 for using \\a \n");
	printf("press 4 for using \\ \n");
	printf("press 5 for using \" \n");
	printf("press 0 to exit \n");
	scanf("%d",&num2);
	}while(num2 != 0);
	return 0;
}		
