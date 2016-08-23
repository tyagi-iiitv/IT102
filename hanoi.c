#include<stdio.h>
void hanoi(int n,char frompeg,char topeg,char auxpeg){
	if(n==1){
		printf("Move disk 1 from %c to %c\n",frompeg,topeg);
		return;
	}
	hanoi(n-1,frompeg,auxpeg,topeg);
	printf("Move disk %d from %c to %c\n",n,frompeg,topeg);
	hanoi(n-1,auxpeg,topeg,frompeg);
}
void main(){
	printf("Enter the number of disks in the tower of hanoi\n");
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
}
	
	
