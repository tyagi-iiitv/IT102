#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct str{
	char data;
	struct str *nextPtr;
};
typedef struct str postfix;
typedef postfix *ptr;
void push(ptr *sptr,char data);
char pop(ptr *sptr);
void main(){
	ptr head=malloc(sizeof(postfix));
	head->data='(';
	head->nextPtr=NULL;
	ptr *sptr=&head;
	char operator[7]={'%','/','*','+','-','^','\0'};
	printf("This program will print the postfix notation of the arithmetic expression entered by you\n");
	printf("Enter the expression\n");
	char exp[100];
	scanf("%s",exp);
	int i=0;
	int k,j;
	while(exp[i]!='\0'){
		i++;
	}
	exp[i]=')';
	exp[i+1]='\0';
	int len=strlen(exp);
	char post[len];
	for(i=0;i<len;i++){
		post[i]='\0';
	}
	char last='\0';
	for(i=0;i<len;i++){
		if(exp[i]==')'){
			if(exp[i+1]=='%'||exp[i+1]=='^'||exp[i+1]=='/'||exp[i+1]=='*'||exp[i+1]=='+'||exp[i+1]=='-'){
				if(exp[i+2]=='('){
					last=exp[i+1];
					exp[i+1]='(';
					break;
				}
			}
		}
	}
	for(i=0;i<len;i++){
		if(exp[i]=='('){
			if((*sptr)->data!='%'&&(*sptr)->data!='/'&&(*sptr)->data!='*'&&(*sptr)->data!='+'&&(*sptr)->data!='-'&&(*sptr)->data!='^'){
				push(&head,'(');
			}
		}
		else if(isalnum(exp[i])){
			j=0;
			while(post[j]!='\0'){
				j++;
			}
			post[j]=exp[i];
		}
		else if(exp[i]=='%'||exp[i]=='/'||exp[i]=='*'||exp[i]=='+'||exp[i]=='-'||exp[i]=='^'){
			if((*sptr)->data!='('){
				int op1,op2;
				for(k=0;k<strlen(operator);k++){
					if(operator[k]==exp[i]){
						op1=k;
					}
					if(operator[k]==(*sptr)->data){
						op2=k;
					}
				}
				if(op1>=op2){
					j=0;
					while(post[j]!='\0'){
						j++;
					}
					post[j]=pop(&head);
					push(&head,exp[i]);
				}
				else{
					push(&head,exp[i]);
				}
			}
			else{
				push(&head,exp[i]);
			}
		}
		else if(exp[i]==')'){
			int jump=0;
			for(k=i;k<len;k++){
				if(isalnum(exp[k])){
					jump=1;
				}
			}
			if(jump==0){
			while((*sptr)->data!='('){
				j=0;
				while(post[j]!='\0'){
					j++;
				}
				post[j]=pop(&head);
			}
			}
			else if(jump==1){
				j=0;
				while(post[j]!='\0'){
					j++;
				}
				post[j]=pop(&head);
			}
		}
	}
	printf("The Postfix expression is:\n");
	for(i=0;i<strlen(post);i++){
		printf("%c",post[i]);
	}
	printf("%c",last);
	printf("\n");
}
void push(ptr *sptr,char data){
	ptr temp;
	temp=malloc(sizeof(postfix));
	temp->data=data;
	temp->nextPtr=*sptr;
	*sptr=temp;
}
char pop(ptr *sptr){
	char data=(*sptr)->data;
	*sptr=(*sptr)->nextPtr;
	return data;
}					
			
			
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
