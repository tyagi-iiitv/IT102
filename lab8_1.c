#include<stdio.h>
void main(){
	printf("This program will print the amount of time required for the given number of parallel downloads\n");
	printf("Enter the number of downloads\n");
	int n;
	scanf("%d",&n);
	float speed[n];
	float size[n];
	int i;
	float min = 0;
	for(i=0;i<n;i++){
		printf("Enter the size of %dth download\n",i+1);
		scanf("%f",&size[i]);
		printf("Enter the speed of %dth download\n",i+1);
		scanf("%f",&speed[i]);
		if(min<size[i]/speed[i]){
			min = size[i]/speed[i];
		}
	}
	printf("The time required for downloads is: %.1f seconds\n",min);
}
	
