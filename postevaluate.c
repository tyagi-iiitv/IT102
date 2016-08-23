#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
struct str{
	double data;
	struct str *nextPtr;
};
typedef struct str postfix;
typedef postfix *ptr;
void push(ptr *sptr,double data);
double pop(ptr *sptr);
void main(){
	ptr head=NULL;
	printf("This program will evaluate the postfix expression entered by you\n");
	printf("Enter the postfix expression, separate the numbers by a space and number of digits limit in a number is 5\n");
	char post[100];
	char num[6]={'\0'};
	gets(post);
	int i;
	int n = strlen(post);
	post[n]=' ';
	post[n+1]='\0';
	double num1,num2;
	num1=0;
	num2=0;
	int j=0;
	for(i=0;i<strlen(post);i++){
		if(!isspace(post[i])){
			num[j]=post[i];
			j++;
		}
		else{
			j=0;
			if(num[j]=='/'||num[j]=='^'||num[j]=='%'||num[j]=='*'||num[j]=='+'||num[j]=='-'){
				num1 = pop(&head);
				num2 = pop(&head);
				if(num[j]=='/'&&num2!=0){
					push(&head,num2/num1);
				}
				else if(num[j]=='^'){
					push(&head,pow(num2,num1));
				}
				else if(num[j]=='%'){
					double temp =((int)(num2)%(int)(num1));
					push(&head,temp);
				}
				else if(num[j]=='*'){
					push(&head,num1*num2);
				}
				else if(num[j]=='+'){
					push(&head,num1+num2);
				}
				else if(num[j]=='-'){
					push(&head,num2-num1);
				}
			}
			else{
				num1 = atof(num);
				push(&head,num1);
			}
		}
	}
	printf("The solution of the postfix is\n");
	printf("%.2lf\n",pop(&head));
}
void push(ptr *sptr, double data){
	ptr temp;
	temp=malloc(sizeof(postfix));
	temp->data=data;
	temp->nextPtr=*sptr;
	*sptr=temp;
}
double pop(ptr *sptr){
	double data=(*sptr)->data;
	*sptr=(*sptr)->nextPtr;
	return data;
}
	
		
		
	
