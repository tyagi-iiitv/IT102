#include<stdio.h>
void main(){
	printf("This program will try to find a straight line equation by the given set of points\n");
	printf("Enter the number of points you want to enter\n");
	int n;
	scanf("%d",&n);
	float s1=0;
	float s2=0;
	float s3=0;
	float s4=0;
	int i,j,k;
	for(i=0;i<n;i++){
		printf("Enter (x%d,y%d)\n",i+1,i+1);
		float x,y;
		scanf("%f%f",&x,&y);
		s1=s1+x;
		s2=s2+(x*x);
		s3=s3+y;
		s4=s4+(x*y);
	}
	float arr1[2][1];
	for(i=0;i<2;i++){
		for(j=0;j<1;j++){
			arr1[i][j]=0;
		}
	}
	float arr2[2][2];
	float arr3[2][1];
	arr2[0][0]=s2/(n*s2-s1*s1);
	arr2[0][1]=-s1/(n*s2-s1*s1);
	arr2[1][0]=-s1/(n*s2-s1*s1);
	arr2[1][1]=n/(n*s2-s1*s1);
	arr3[0][0]=s3;
	arr3[1][0]=s4;
	for(i=0;i<2;i++){
		for(j=0;j<1;j++){
			for(k=0;k<2;k++){
				arr1[i][j] += (arr2[i][k]*arr3[k][j]);
			}
		}
	}
	printf("Value of 'c' is %.1f\n",arr1[0][0]);
	printf("Value of 'm' is %.1f\n",arr1[1][0]);
}
