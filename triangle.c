#include <stdio.h>
void main(){
	int i,j,k,l;
	printf("Enter the value of n\n");
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=(n-i);j++){
			printf(" ");
		}
		for(k=1;k<=(n-(n-i));k++){
			if(k==1){
				printf("*");
			}
			else{
				printf(" *");
			}
		}
		printf("\n");
	}
}


