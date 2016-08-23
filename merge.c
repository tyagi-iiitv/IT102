#include<stdio.h>
void mergeSort(int arr[], int start, int end);
void sortSubArray(int arr[], int start, int end);
void main(){
	printf("Merge sorting the array\n");
	printf("Enter the length of the integer array\n");
	int len,i;
	scanf("%d",&len);
	int arr[len];
	for(i=0;i<len;i++){
		printf("Enter the %dth element\n",i+1);
		scanf("%d",&arr[i]);
	}
	printf("You entered the following array\n");
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	mergeSort(arr,0,len-1);
	printf("The sorted array is\n");
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void mergeSort(int arr[], int start, int end){
	int mid=(start+end)/2;
	if(end>=start+2){
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
	}
	if(start!=end){
		sortSubArray(arr,start,end);
	}
}
void sortSubArray(int arr[], int start, int end){
	int i;
	int j;
	int mid1, mid2, temp;
	if(start+1==end){
		if(arr[start]>arr[end]){
			temp=arr[start];
			arr[start]=arr[end];
			arr[end]=temp;
		}
	}
	else{
			mid1=(start+end)/2;
			mid2=mid1+1;
		if(arr[start]>arr[end]){
			int tarr[mid1-start];
			for(i=start,j=0;i<=mid1;i++,j++){
				tarr[j]=arr[i];
			}
			for(i=mid2,j=0;i<=end;i++,j++){
				arr[j]=arr[i];
			}
			for(i=start+(end-mid2)+1,j=0;j<=(mid1-start);i++,j++){
				arr[i]=tarr[j];
			}
		}
		else if(arr[mid1]<arr[mid2]){
		}
		else{
			i=mid2;
			int pos=start;
			while(i<=end){
				while(arr[pos]<arr[i]){
					pos++;
				}
				temp=arr[i];
				for(j=mid1;j>=pos;j--){
					arr[j+1]=arr[j];
				}
				mid1++;
				arr[pos]=temp;
				i++;
				pos++;
			}
		}
	}
}




















