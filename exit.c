#include<stdio.h>
#include<stdlib.h>
void print();
void main(){
	int answer;
	atexit(print);
	printf("Press 1 to exit program with function exit\n");
	printf("Press 2 to terminate program normally\n");
	scanf("%d",&answer);
	if(answer==1){
		printf("Terminating program with function exit\n");
		exit(EXIT_FAILURE);
	}
	printf("Terminating program by reaching the end of main\n");
}
void print(){
	printf("Program terminated suucessfully with exit\n");
}

