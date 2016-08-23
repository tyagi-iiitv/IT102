#include<stdio.h>
void main(){
	printf("Enter the number of dates you want to store\n");
	int n;
	scanf("%d",&n);
	struct date{
		int day;
		int month;
		int year;
	};
	struct date arr[n];
	int i;
	for(i=0;i<n;i++){
		printf("Enter the date number %d\nEnter the day\n",i+1);
		scanf("%d",&arr[i].day);
		printf("Enter the month\n");
		scanf("%d",&arr[i].month);
		printf("Enter the year\n");
		scanf("%d",&arr[i].year);
		int leap=0;
		if(arr[i].year%400==0){
			leap=1;
		}
		else if(arr[i].year%100==0){
			leap=0;
		}
		else if(arr[i].year%4==0){
			leap=1;
		}
		if(arr[i].month>12){
			printf("Invalid entry\n");
			continue;
		}
		else if(arr[i].month==1||arr[i].month==3||arr[i].month==5||arr[i].month==7||arr[i].month==8||arr[i].month==10||arr[i].month==12){
			if(arr[i].day>31){
				printf("Invalid entry\n");
				continue;
			}
		}
		else if(arr[i].month==2&&leap==1){
			if(arr[i].day>29){
				printf("Invalid Entry\n");
				continue;
			}
		}
		else if(arr[i].month==2&&leap==0){
			if(arr[i].day>28){
				printf("Invalid entry\n");
				continue;
			}
		}
		else{
			if(arr[i].day>30){
				printf("Invalid entry\n");
				continue;
			}
		}
	}
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			
