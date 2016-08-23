#include<stdio.h>
void main(){
	printf("To print the top three and bottom three from an array of marks\n");
	printf("enter the number of students whose marks you want to enter\n");
	int n;
	scanf("%d",&n);
	int i,j,k;
	float marks[n];
	for(i=0;i<n;i++){
		printf("Enter the marks of %dth student\n",i+1);
		scanf("%f",&marks[i]);
	}
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(marks[j]>marks[i]){
				float temp = marks[i];
				for(k=i;k>j;k--){
					marks[k]=marks[k-1];
				}
				marks[j]=temp;
			}
		}
	}
	printf("Bottom 3 marks are\n");
	for(i=0;i<3;i++){
		printf("%.1f ",marks[i]);
	}
	printf("\n");
	printf("Top 3 marks are\n");
	for(i=n-1;i>n-4;i--){
		printf("%.1f ",marks[i]);
	}
	printf("\n");
}
	
