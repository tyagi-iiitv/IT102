#include<stdio.h>
int main(){
	printf("This program finds the elements of a relation b/w A(n)*A(n) sets \n");
	printf("Enter the number of elements in the set \n");
	int num,i;
	scanf("%d",&num);
	int arr[num];
	for(i=0; i<num; i++){ /*entering data in the array*/
		arr[i] = i+1;
	}
	return 0;
}
int step1(int n){ /*end to end array initialisation*/
	int arr1[2*n];
	if(n == 3){
		int i;
		for(i=0; i<n; i++){
			arr1[i] = i+1;
			arr1[2*n-i-1] = i+1;
		}
	}
	else{
		arr1[n-1] = n;
		arr1[2*n-1] = n;
		return step1(n-1);
	}
}
int step2(int n){ /*one after another array initialisation*/
	int arr2[n*(n-1)];
	if(n == 3){
		arr2[0] = 1;
		arr2[1] = 2;
		arr2[2] = 2;
		arr2[3] = 3;
		arr2[4] = 1;
		arr2[5] = 3;
	}
	else{
		int arr1[n-1];int i;
		for(i = 0; i<n-1; i++){
			arr1[i] = i+1;
		}
		for(i=
		
		
