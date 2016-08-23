#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main(){
	srand(time(0));
	int pos[70]={0};//1 for turtle, 2 for hare, 3 for both 
	pos[0]=3;
	int i;
	int t=0;
	int h=0;
	int nt,nh;
	int jump;
	printf("Enter any number from 0-9 to start:\n");
	scanf("%d",&jump);
	printf("The game starts as:\n");
	for(i=0;i<70;i++){
		if(i%10==0){
			printf("\n");
		}
		if(pos[i]==1){
			printf("[T]");
		}
		else if(pos[i]==2){
			printf("[H]");
		}
		else if(pos[i]==3){
			printf("[HT]");
		}
		else{
			printf("[ ]");
		}
	}
	printf("\n");
	printf("BANG! THEY ARE OFF\n");
	while(t!=69&&h!=69){
		for(i=0;i<70;i++){
			pos[i]=0;
		}
		nt=rand()%10;
		nh=rand()%10;
		if(nt>=0&&nt<=3){
			printf("OH YEAH! TURTLE SPEEDS UP\n");
			t=t+3;
		}
		else if(nt>=4&&nt<=6){
			printf("NO! TURTLE SLIPS\n");
			t=t-6;
		}
		else if(nt>=7&&nt<=9){
			printf("OH YEAH! TURTLE CONTINUES SLOWLY\n");
			t=t+1;
		}
		if(nh>=0&&nh<=1){
			printf("HUH! ENJOY YOUR SLEEP MR. HARE\n");
			h=h;
		}
		else if(nh>=2&&nh<=3){
			printf("O SHIT! HARE IS SPEEDING UP\n");
			h=h+9;
		}
		else if(nh>=4&&nh<=5){
			printf("OH YEAH! HARE SLIPPED BADLY\n");
			h=h-12;
		}
		else if(nh>=6&&nh<=7){
			printf("Hare is continuing with its race\n");
			h=h+1;
		}
		else if(nh>=8&&nh<=9){
			printf("WATCH IT! MR. HARE, YOU JUST SLIPPED\n");
			h=h-2;
		}
		if(h<0){
			printf("SHIT MAN! BAD LUCk!\n");
			h=0;
		}
		if(t<0){
			printf("SHIT MAN! BAD LUCk!\n");
			t=0;
		}
		if(h>69){
			h=69;
		}
		if(t>69){
			t=69;
		}
		if(t==h){
			pos[t]=3;
		}
		else{
			pos[t]=1;
			pos[h]=2;
		}
		if(h==69){
			printf("FU*k! Hare has won\n");
		}
		if(t==69){
			printf("YEAH! ONCE AGAIN, TURTLE HAS WON\n");
		}
		if(t==69&&h==69){
			printf("ITS A TIE\n");
		}
		printf("Enter any number from 0-9 to see their current location:\n");
		scanf("%d",&jump);
		for(i=0;i<70;i++){
			if(i%10==0){
				printf("\n");
			}
			if(pos[i]==1){
				printf("[T]");
			}
			else if(pos[i]==2){
				printf("[H]");
			}
			else if(pos[i]==3){
				printf("[HT]");
			}
			else{
				printf("[ ]");
			}
		}
		printf("\n");
	}
}
