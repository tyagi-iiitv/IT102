#include<stdio.h>
void main(){
	/*starting print of the chocolate bar*/
	printf("The game of chomp in a 7*4 rectangle\n");
	printf("    1.  2.  3.  4.  5.  6.  7.\n");
	printf("    __  __  __  __  __  __  __\n");
	printf("1. |__||__||__||__||__||__||__|\n");
	printf("    __  __  __  __  __  __  __\n");
	printf("2. |__||__||__||__||__||__||__|\n");
	printf("    __  __  __  __  __  __  __\n");
	printf("3. |__||__||__||__||__||__||__|\n");
	printf("    __  __  __  __  __  __  __\n");
	printf("4. |++||__||__||__||__||__||__|\n");
	/*----------------------------------------------*/
	printf("The bottom left corner of the chocolate is poisonous\n");
	int arr[4][7];
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<7;j++){
			arr[i][j]=1;
		}
	}
	int x,y;
	int p = 1;
	printf("Player 1:Enter the cordinates of the square you want to bite\n");
	scanf("%d%d",&x,&y);
	if((x==4)&&(y==1)){
		printf("You loose\n");
		p=0;
	}
	else{
	/*print of the chocolate bar after entering the cordinates*/
	printf("  1.  2.  3.  4.  5.  6.  7.\n");
	for(i=0;i<x;i++){
		for(j=y-1;j<7;j++){
			arr[i][j]=0;
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<7;j++){
			if (arr[i][j] == 1){
				printf("  __");
			}
		}
		printf("\n");
		printf("%d",i+1);
		for(j=0;j<7;j++){
			if(arr[i][j] == 1){
				if((i==3)&&(j==0)){
					printf("|++|");
				}
				else
				printf("|__|");
			}
		}printf("\n");
	}
	/*--------------------------------------------------*/
}
	int k=2;
	while(p!=0){
		/*Game should close when no box except (4,1) is left*/
		int jump = 0;
		for(i=0;i<4;i++){
			for(j=0;j<7;j++){
				if((i!=3)||(j!=0)){
					if(arr[i][j]==1)
					jump = 1;
				}
			}
		}
		/*----------------------------------------------------*/
		if(jump==1){
		if(k%2==0)
		printf("Player 2:Enter the cordinates of the square you want to bite\n");
		else
		printf("Player 1:Enter the cordinates of the square you want to bite\n");
		scanf("%d%d",&x,&y);
		if((x==4)&&(y==1)){
			printf("You loose\n");
			break;
		}
		else if(arr[x-1][y-1]==0){
		printf("Wrong choice\n");
		continue;
		}
		else{
		/*print of the chocolate bar after entering the cordinates*/
		printf("  1.  2.  3.  4.  5.  6.  7.\n");
		for(i=0;i<x;i++){
			for(j=y-1;j<7;j++){
				arr[i][j]=0;
			}
		}
		for(i=0;i<4;i++){
			for(j=0;j<7;j++){
				if (arr[i][j] == 1){
					printf("  __");
				}
			}
			printf("\n");
			printf("%d",i+1);
			for(j=0;j<7;j++){
				if(arr[i][j] == 1){
					if((i==3)&&(j==0)){
						printf("|++|");
					}
					else
					printf("|__|");
				}
			}printf("\n");
		}	
		/*--------------------------------------------------*/
		}
	}
	else{
		if(k%2==0){
			printf("Player 2 looses\n");
		}
		else
		printf("Player 1 looses\n");
		break;
	}
	k++;
	}
}
			