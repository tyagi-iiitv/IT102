#include<stdio.h>
void func1(int a);
void func2(int a);
void func3(int a);
void func4(int a);
void main(){
	printf("Program to call different functions with reference\n");
	printf("We have three functions..\nPress 1 to call func.1, 2 for calling func.2 and 3 for calling func.3\n");
	printf("Press 4 to quit\n");
	int choice=1;
	void (*ptr[4])(int)={func1, func2, func3, func4};
	while(choice <= 4){
	scanf("%d",&choice);
	(*ptr[choice-1])(choice);
	if(choice == 4)
	break;
}
}
void func1(int a){
	printf("You have selected the %d function\n",a);
}
void func2(int a){
	printf("You have selected the %d function\n",a);
} 
void func3(int a){
	printf("You have selected the %d function\n",a);
}
void func4(int a){
	printf("Program will exit\n");
}	
	
