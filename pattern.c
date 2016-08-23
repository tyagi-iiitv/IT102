
#include<stdio.h>
void main(){
	printf("This program will print the triangle in decreasing order of the number given by You\n");
	printf("Please enter the integral number\n");
	int num;
	scanf("%d", &num);
	int i,j,k,l;
	for(i=num; i>=1; i--){
		for(k=i; k>=1; k--){
		printf("%d",k);
		}
			for(j=2; j<=i; j++){
			printf("%d",j);
			}
			printf("\n");
				for(l=0; l<=num-i; l++){
				printf(" ");
				}
	}
}
