#include<stdio.h>
float expo(float a, float b);
void main(){
	printf("Enter the first number i.e a of a^b\n");
	float a;
	scanf("%f",&a);
	printf("Enter the second number i.e a of a^b\n");
	float b;
	scanf("%f",&b);
	float res=expo(a,b);
	printf("The answer is: %.2f\n",res);
	
}
float expo(float a, float b){
	if(b<0){
		return expo(1/a,-b);
	}
	else if(b==0){
		return 1;
	}
	else if(b==1){
		return a;
	}
	else if(b>0 && (int)b%2==0){
		 return expo(a*a,b/2);
	}
	else if(b>0 && (int)b%2!=0){
		return a*expo(a*a,(b-1)/2);
	}
}
		
