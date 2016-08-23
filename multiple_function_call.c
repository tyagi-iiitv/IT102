#include<stdio.h>
void child(int a);
void adult(int b);
void senior(int c);
void main(){
	void (*call[3])(int )={child,adult,senior};
	printf("press 1 if you are a child, 2 if you are an adult, 3 for senior citizen\n");
	int n;
	scanf("%d",&n);
	(*call[n-1])(n-1);
}
void child(int a){
	printf("You are a child\n");
}
void adult(int b){
	printf("You are a child\n");
}	
void senior(int c){
	printf("You are a child\n");
}
