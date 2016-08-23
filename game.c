#include<stdio.h>

int i=1;
int match=22; 
int pick;


void turn_comp();
void turn_user();


void main()
{
char turn;
printf("\nWelcome to Match Game\n");
printf("You have been given 22 matches and you have to pick 1/2/3/4 match(es).\nThe one to Pick the last match will be the winner\n");
printf("Let us Start\n");
printf("Enter who will start (U-User, C-Computer): ");
scanf("%c",&turn);
if((turn=='C')||(turn=='c')) 
turn_comp();
else 
turn_user();
}



void turn_comp()
{
printf("\nYou have chosen Computer to start\n");
while(i<=5)
{
	if(i==1)
	{
	  printf("Computer picked up 2 Sticks\n");
	  match=match-2;
	  printf("Remaining Sticks: %d\n",match);
	  X:
	  printf("Enter the no. of Sticks You want to pick: ");
	  scanf("%d",&pick);
          if((pick==0)||(pick>4))
	  { printf("\nDon't try to be OVERSMART..!!\n"); goto X; }	
	  ++i;	
	}

	else if((i!=1)&&(i<5))
	{
	printf("\nYou picked up %d match(es)\n",pick);
	match=match-pick;
	printf("Remaining matches : %d\n",match);
		switch(pick)
		{
		case 1:
		printf("Computer picked up 4 matches\n");
		match=match-4;
		printf("Remaining matches : %d\n",match);
		break;

		case 2:
		printf("Computer picked up 3 matches\n");
		match=match-3;
		printf("Remaining matches : %d\n",match);
		break;

		case 3:
		printf("Computer picked up 2 matches\n");
		match=match-2;
		printf("Remaining matches : %d\n",match);
		break;

		case 4:
		printf("Computer picked up 1 match\n");
		match=match-1;
		printf("Remaining matches : %d\n",match);
		break;
		}
	
	  Y:
	  printf("Enter the no. of Sticks You want to pick: ");
	  scanf("%d",&pick);
          if((pick<=0)||(pick>4))
	  { printf("\nDon't try to be OVERSMART..!!\n"); goto X; }	
	  ++i;
}	

else
{
if((match-pick)<5)
{
printf("Remaining Matches :%d\n",match-pick);
printf("Now to win Computer can pick all the match very easily\n"); 
printf("And this is How computer won the game..!! Better Luck Next time..!!\n");
break;
}
}
}
}




void turn_user()
{
printf("\nYou have chosen yourself to start\n");
while(i<=5)
{

printf("\nEnter the number of matches you want to pick: ");
scanf("%d",&pick);
match=match-pick;
printf("Remaining Matches: %d\n",match);


if((pick==1)&&(i==1))
{
printf("\nComputer picked up 1 match\n");
match=match-1;
printf("Remaining Matches: %d\n",match);
++i;
}

else if (match>5)
{
switch(pick)
{
case 1:
		printf("Computer picked up 4 matches\n");
		match=match-4;
		printf("Remaining matches : %d\n",match);
		break;
case 2:
		printf("Computer picked up 3 matches\n");
		match=match-3;
		printf("Remaining matches : %d\n",match);
		break;
case 3:
		printf("Computer picked up 2 matches\n");
		match=match-2;
		printf("Remaining matches : %d\n",match);
		break;
case 4:
		printf("Computer picked up 1 matches\n");
		match=match-1;
		printf("Remaining matches : %d\n",match);
		break;
}
++i;
}

else 
{
if(match==5)
{
printf("To win Computer have to Pick all the 5 matches which is not according to the rules\n");
printf("Anyway Congratulations..!!\n");
break;
}
else if(match<5)
{
printf("Now to win Computer can pick all the match very easily\n"); 
printf("As usual it is proved who is the winner..!!\n");
printf("Congratulations to Computer..!! Better Luck next time\n");
break;
}
}
}
}
