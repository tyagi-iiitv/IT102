#include<stdio.h>
void main(){
	printf("program to find time for simultaneous downloads\n");
	printf("Enter the number of downloads\n");
	int n;
	scanf("%d",&n);
	float tl[n];
	float speed[n];
	int i,j,k;
	for(i=0;i<n;i++){
		printf("Enter the time left of %dth download\n",i+1);
		scanf("%f",&tl[i]);
		printf("Enter the speed of %dth download\n",i+1);
		scanf("%f",&speed[i]);
		}
	/*Performing insertion sort*/
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(tl[j]>tl[i]){
				float temp = tl[i];
				float temp2 = speed[i];
				for(k=i;k>j;k--){
					tl[k]=tl[k-1];
					speed[k]=speed[k-1];
				}
				tl[j]=temp;
				speed[j]=temp2;
			}
		}
	}
	/*Insertion sort completed*/
	float tempt=0;
	float temps=0;
	float t=0;
	for(i=0;i<n;i++){
		tempt=tl[i]-t;
		t=t+(tempt*speed[i]/(temps+speed[i]));
		temps=speed[i]+temps;
	}
	printf("The time required is: %.1f\n",t);
}
