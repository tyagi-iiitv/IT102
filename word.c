#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void ty(int n);
void ty2(int n);
void hu(int n);
void th(int n);
void la(int n);
void cr(int n);
void main(){
	printf("Please enter any amount which occupies atmost 10 spaces along with decimal digits. Limit is 100 crores.\n");
	char amount[11]={'\0'};
	gets(amount);
	char rupee[11]={'\0'};
	char paise[3]={'\0'};
	int i;
	int j=0;
	int check=0;
	for(i=0;i<strlen(amount);i++){
		 if(amount[i]=='.'){
			 check=1;
			 j=0;
		 }
		 if(check==0){
			 rupee[j]=amount[i];
			 j++;
		 }
		 if(check==1){
			 paise[j]=amount[i+1];
			 j++;
		 }
	 }
	 int lenr=strlen(rupee);
	 int lenp=strlen(paise);
	 int ru[lenr];
	 int pa[lenp];
	 int a = atoi(rupee);
	 int b = atoi(paise);
	 for(i=lenr-1;i>=0;i--){
		 ru[i]=a%10;
		 a=a/10;
	 }
	 for(i=lenp-1;i>=0;i--){
		 pa[i]=b%10;
		 b=b/10;
	 }
	 switch(lenr){
		 case 1:
		 ty(atoi(rupee));
		 break;
		 case 2:
		 if(atoi(rupee)<=20){
			 ty(atoi(rupee));
		 }
		 else{
			 ty2(ru[0]);
			 ty(ru[1]);
		 }
		 break; 
		 case 3:
		 hu(ru[0]);
		 int num=10*ru[1]+ru[2];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[1]);
			 ty(ru[2]);
		 }
		 break;
		 case 4:
		 th(ru[0]);
		 hu(ru[1]);
		 num=10*ru[2]+ru[3];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[2]);
			 ty(ru[3]);
		 }
		 break;
		 case 5:
		 num=10*ru[0]+ru[1];
		 if(num<=20){
			 th(num);
		 }
		 else{
			 ty2(ru[0]);
			 ty(ru[1]);
			 th(num);
		 }
		 hu(ru[2]);
		 num=10*ru[3]+ru[4];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[3]);
			 ty(ru[4]);
		 }
		 break;
		 case 6:
		 la(ru[0]);
		 num=10*ru[1]+ru[2];
		 if(num<=20){
			 th(num);
		 }
		 else{
			 ty2(ru[1]);
			 ty(ru[2]);
			 th(num);
		 }
		 hu(ru[3]);
		 num=10*ru[4]+ru[5];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[4]);
			 ty(ru[5]);
		 }
		 break;
		 case 7:
		 num=10*ru[0]+ru[1];
		 if(num<=20){
			 la(num);
		 }
		 else{
			 ty2(ru[0]);
			 ty(ru[1]);
			 la(num);
		 }
		 num=10*ru[2]+ru[3];
		 if(num<=20){
			 th(num);
		 }
		 else{
			 ty2(ru[2]);
			 ty(ru[3]);
			 th(num);
		 }
		 hu(ru[4]);
		 num=10*ru[5]+ru[6];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[5]);
			 ty(ru[6]);
		 }
		 break;
		 case 8:
		 cr(ru[0]);
		 num=10*ru[1]+ru[2];
		 if(num<=20){
			 la(num);
		 }
		 else{
			 ty2(ru[1]);
			 ty(ru[2]);
			 la(num);
		 }
		 num=10*ru[3]+ru[4];
		 if(num<=20){
			 th(num);
		 }
		 else{
			 ty2(ru[3]);
			 ty(ru[4]);
			 th(num);
		 }
		 hu(ru[5]);
		 num=10*ru[6]+ru[7];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[6]);
			 ty(ru[7]);
		 }
		 break;
		 case 9:
		 num=10*ru[0]+ru[1];
		 if(num<=20){
			 cr(num);
		 }
		 else{
			 ty2(ru[0]);
			 ty(ru[1]);
			 cr(num);
		 }
		 num=10*ru[2]+ru[3];
		 if(num<=20){
			 la(num);
		 }
		 else{
			 ty2(ru[2]);
			 ty(ru[3]);
			 la(num);
		 }
		 num=10*ru[4]+ru[5];
		 if(num<=20){
			 th(num);
		 }
		 else{
			 ty2(ru[4]);
			 ty(ru[5]);
			 th(num);
		 }
		 hu(ru[6]);
		 num=10*ru[7]+ru[8];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[7]);
			 ty(ru[8]);
		 }
		 break;
		 case 10:
		 printf("HUNDRED CRORE ");
	 }
	 printf("RUPEES ");
	 switch(lenp){
		 case 1:
		 printf("AND ");
		 ty(atoi(paise));
		 printf("PAISE");
		 break;
		 case 2:
		 printf("AND ");
		 if(atoi(paise)<=20){
			 ty(atoi(paise));
		 }
		 else{
			 ty2(pa[0]);
			 ty(pa[1]);
		 }
		 printf("PAISE");
		 break; 
	 }
	 printf("\n");
}
void ty(int n){
	switch(n){
		case 1: printf("ONE ");
		break;
		case 2: printf("TWO ");
		break;
		case 3: printf("THREE ");
		break;
		case 4: printf("FOUR ");
		break;
		case 5: printf("FIVE ");
		break;
		case 6: printf("SIX ");
		break;
		case 7: printf("SEVEN ");
		break;
		case 8: printf("EIGHT ");
		break;
		case 9: printf("NINE ");
		break;
		case 10: printf("TEN ");
		break;
		case 11: printf("ELEVEN ");
		break;
		case 12: printf("TWELVE ");
		break;
		case 13: printf("THIRTEEN ");
		break;
		case 14: printf("FOURTEEN ");
		break;
		case 15: printf("FIFTEEN ");
		break;
		case 16: printf("SIXTEEN ");
		break;
		case 17: printf("SEVENTEEN ");
		break;
		case 18: printf("EIGHTEEN ");
		break;
		case 19: printf("NINETEEN ");
		break;
		case 20: printf("TWENTY ");
		break;
	}
}
void ty2(int n){
	switch(n){
		case 2: printf("TWENTY ");
		break;
		case 3: printf("THIRTY ");
		break;
		case 4: printf("FOURTY ");
		break;
		case 5: printf("FIFTY ");
		break;
		case 6: printf("SIXTY ");
		break;
		case 7: printf("SEVENTY ");
		break;
		case 8: printf("EIGHTY ");
		break;
		case 9: printf("NINETY ");
		break;
	}
}
void hu(int n){
	switch(n){
		case 1: printf("ONE HUNDRED ");
		break;
		case 2: printf("TWO HUNDRED ");
		break;
		case 3: printf("THREE HUNDRED ");
		break;
		case 4: printf("FOUR HUNDRED ");
		break;
		case 5: printf("FIVE HUNDRED ");
		break;
		case 6: printf("SIX HUNDRED ");
		break;
		case 7: printf("SEVEN HUNDRED ");
		break;
		case 8: printf("EIGHT HUNDRED ");
		break;
		case 9: printf("NINE HUNDRED ");
		break;
	}
}
void th(int n){
	switch(n){
		case 1: printf("ONE THOUSAND ");
		break;
		case 2: printf("TWO THOUSAND ");
		break;
		case 3: printf("THREE THOUSAND ");
		break;
		case 4: printf("FOUR THOUSAND ");
		break;
		case 5: printf("FIVE THOUSAND ");
		break;
		case 6: printf("SIX THOUSAND ");
		break;
		case 7: printf("SEVEN THOUSAND ");
		break;
		case 8: printf("EIGHT THOUSAND ");
		break;
		case 9: printf("NINE THOUSAND ");
		break;
		case 10: printf("TEN THOUSAND ");
		break;
		case 11: printf("ELEVEN THOUSAND ");
		break;
		case 12: printf("TWELVE THOUSAND ");
		break;
		case 13: printf("THIRTEEN THOUSAND ");
		break;
		case 14: printf("FOURTEEN THOUSAND ");
		break;
		case 15: printf("FIFTEEN THOUSAND ");
		break;
		case 16: printf("SIXTEEN THOUSAND ");
		break;
		case 17: printf("SEVENTEEN THOUSAND ");
		break;
		case 18: printf("EIGHTEEN THOUSAND ");
		break;
		case 19: printf("NINETEEN THOUSAND ");
		break;
		case 20: printf("TWENTY THOUSAND ");
		break;
		default: printf("THOUSAND ");
		break;
	}
}
void la(int n){
	switch(n){
		case 1: printf("ONE LAKH ");
		break;
		case 2: printf("TWO LAKH ");
		break;
		case 3: printf("THREE LAKH ");
		break;
		case 4: printf("FOUR LAKH ");
		break;
		case 5: printf("FIVE LAKH ");
		break;
		case 6: printf("SIX LAKH ");
		break;
		case 7: printf("SEVEN LAKH ");
		break;
		case 8: printf("EIGHT LAKH ");
		break;
		case 9: printf("NINE LAKH ");
		break;
		case 10: printf("TEN LAKH ");
		break;
		case 11: printf("ELEVEN LAKH ");
		break;
		case 12: printf("TWELVE LAKH ");
		break;
		case 13: printf("THIRTEEN LAKH ");
		break;
		case 14: printf("FOURTEEN LAKH ");
		break;
		case 15: printf("FIFTEEN LAKH ");
		break;
		case 16: printf("SIXTEEN LAKH ");
		break;
		case 17: printf("SEVENTEEN LAKH ");
		break;
		case 18: printf("EIGHTEEN LAKH ");
		break;
		case 19: printf("NINETEEN LAKH ");
		break;
		case 20: printf("TWENTY LAKH ");
		break;
		default: printf("LAKH ");
	}
}
void cr(int n){
	switch(n){
		case 1: printf("ONE CRORE ");
		break;
		case 2: printf("TWO CRORE ");
		break;
		case 3: printf("THREE CRORE ");
		break;
		case 4: printf("FOUR CRORE ");
		break;
		case 5: printf("FIVE CRORE ");
		break;
		case 6: printf("SIX CRORE ");
		break;
		case 7: printf("SEVEN CRORE ");
		break;
		case 8: printf("EIGHT CRORE ");
		break;
		case 9: printf("NINE CRORE ");
		break;
		case 10: printf("TEN CRORE ");
		break;
		case 11: printf("ELEVEN CRORE ");
		break;
		case 12: printf("TWELVE CRORE ");
		break;
		case 13: printf("THIRTEEN CRORE ");
		break;
		case 14: printf("FOURTEEN CRORE ");
		break;
		case 15: printf("FIFTEEN CRORE ");
		break;
		case 16: printf("SIXTEEN CRORE ");
		break;
		case 17: printf("SEVENTEEN CRORE ");
		break;
		case 18: printf("EIGHTEEN CRORE ");
		break;
		case 19: printf("NINETEEN CRORE ");
		break;
		case 20: printf("TWENTY CRORE ");
		break;
		default: printf("CRORE ");
		break;
	}
}
