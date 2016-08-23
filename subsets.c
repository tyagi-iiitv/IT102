#include<stdio.h>
#include<math.h>
void main(){
	printf("enter the number of elements in the set\n");
	int num,rem;
	scanf("%d",&num);
	int arr[num];
	int len = pow(2,num);
	int i,k;
	printf("{ ");
	for(i=len-1;i>=1;i--){
		int j = 0;
		int jump = i;
		while(j<num){
		rem = i%2;
		arr[j] = rem;
		i = i/2;
		j++;
	}
	printf("{");
	for(k=0;k<num;k++){
		if(arr[k]==1){
			printf("%d ",k+1);
		}
	}
	i = jump;
	printf("} ");
}
printf("{}}\n");
}

