#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<signal.h>
void signalHandler(int signalValue){
	int response;
	printf("\nInterrupt signal (%d) received, Do you wish to continue(1=yes, 2=No)? ",signalValue);
	scanf("%d",&response);
	if(response==1){
		signal(SIGINT,signalHandler);
	}
	else{
		exit(EXIT_SUCCESS);
	}
}
void main(){
	int i;
	int x;
	signal(SIGINT,signalHandler);
	srand(clock());
	for(i=1;i<=100;i++){
		x=1+rand()%50;
		if(x==25){
			raise(SIGINT);
		}
		printf("%4d",i);
		if(i%10==0){
			printf("\n");
		}
	}
}
