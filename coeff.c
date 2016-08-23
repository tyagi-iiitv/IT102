#include<stdio.h>
void main(){
	printf("Enter the two polynomials to find coefficient of X^n\n");
	printf("Enter the highest degree of x in first polynomial\n");
	int n;
	scanf("%d",&n);
	float arr1[n+1];
	int i,j;
	for(i=0;i<=n;i++){
		printf("Enter the coefficient of x^%d \n",i);
		scanf("%f",&arr1[i]);
	}
	printf("Now enter the highest degree of x in second polynomial\n");
	int m;
	scanf("%d",&m);
	float arr2[m+1];
	for(i=0;i<=m;i++){
		printf("Enter the coefficient of x^%d \n",i);
		scanf("%f",&arr2[i]);
	}
	printf("Enter the number k to find coefficient of x^k\n");
	int k;
	scanf("%d",&k);
	float sum=0;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i+j==k){
				sum = sum + (arr1[i]*arr2[j]);
			}
		}
	}
	printf("The coefficient of X^%d is %.2f\n",k,sum);
}
