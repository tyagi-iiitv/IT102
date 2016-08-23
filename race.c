#include<stdio.h>
#include<stdlib.h>
void main(){
	printf("This is the race between two players from 1 to 109\n");
	printf("The position of the two players is depicited by following figure\n");
	int i,j;
	for(i=0;i<=10;i++){
		for(j=0;j<=9;j++){
			if(i==0 && j==0){
				printf("P1P2");
			}
			else
			printf("____ ");
		}
		printf("\n");
		for(j=0;j<=9;j++){
			printf("%2d%d  ",i,j);
		}
		printf("\n\n");
	}
	int num,dig1,dig10,pig1,pig10;
	int sum1 = 0;
	int sum2 = 0;
	int k=1;
	while(k!=0){
		if(k%2==0){
			printf("Player 2: press 1 to roll the dice\n");
		}
		else
		printf("Player 1: press 1 to roll the dice\n");
		scanf("%d",&num);
		if(num!=1){
			printf("Wrong choice\n");
			continue;
		}
		else{
			int ans = (rand()%6)+1;
			printf("You got %d\n",ans);
			if(k%2==0){
				if(sum2+ans > 109){
					printf("Better Luck next time\n");
					k++;
					continue;
				}
				else if(sum2+ans == 109){
					printf("Congrats! You win\n");
					break;
				}
				sum2 = sum2+ans;
				while(ans==6){
					printf("Player 2: press 1 to roll the dice\n");
					scanf("%d",&num);
					if(num!=1){
						printf("Wrong choice\n");
						continue;
					}
					else{
						ans = (rand()%6)+1;
						printf("You got %d\n",ans);
						sum2 = sum2+ans;
						if(sum2+ans > 109){
							printf("Better Luck next time\n");
							k++;
							break;
						}
						else if(sum2+ans == 109){
							printf("Congrats! You win\n");
							break;
						}
					}
				}
				printf("Your new position chart is\n");
				dig1 = sum2%10;
				dig10 = sum2/10;
				pig1 = sum1%10;
				pig10 = sum1/10;
				for(i=0;i<=10;i++){
					for(j=0;j<=9;j++){
						if(sum1 == sum2 && i==dig10 && j==dig1){
							printf("P1P2 ");
						}
						else if(i==dig10 && j==dig1){
							printf(" P2  ");
						}
						else if(i==pig10 && j==pig1){
							printf(" P1  ");
						}
						else
						printf("____ ");
					}
					printf("\n");
					for(j=0;j<=9;j++){
						printf("%2d%d  ",i,j);
					}
					printf("\n\n");
				}
			}
			else{
				if(sum1+ans > 109){
					printf("Better Luck next time\n");
					k++;
					continue;
				}
				else if(sum1+ans == 109){
					printf("Congrats! You win\n");
					break;
				}
				sum1 = sum1+ans;
				while(ans==6){
					printf("Player 1: press 1 to roll the dice\n");
					scanf("%d",&num);
					if(num!=1){
						printf("Wrong choice\n");
						continue;
					}
					else{
						ans = (rand()%6)+1;
						printf("You got %d\n",ans);
						sum1 = sum1+ans;
						if(sum2+ans > 109){
							printf("Better Luck next time\n");
							k++;
							break;
						}
						else if(sum2+ans == 109){
							printf("Congrats! You win\n");
							break;
						}
					}
				}
				printf("Your new position chart is\n");
				dig1 = sum1%10;
				dig10 = sum1/10;
				pig1 = sum2%10;
				pig10 = sum2/10;
				for(i=0;i<=10;i++){
					for(j=0;j<=9;j++){
						if(sum1 == sum2 && i==dig10 && j==dig1){
							printf("P1P2 ");
						}
						else if(i==dig10 && j==dig1){
							printf(" P1  ");
						}
						else if(i==pig10 && j==pig1){
							printf(" P2  ");
						}
						else
						printf("____ ");
					}
					printf("\n");
					for(j=0;j<=9;j++){
						printf("%2d%d  ",i,j);
					}
					printf("\n\n");
				}
			}
		}
		k++;	
	}
}
