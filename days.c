#include<stdio.h>
void main(){
	printf("This is the program for printing number of days, months and years from the given days\n");
	printf("Please enter the number of days\n");
	int entry;
	scanf("%d", &entry);
	int year, month, days;
	year = entry/360;
	month = (entry%360)/30;
	days = (entry%360)%30;
	printf("The number of days you entered are equivalent to-\n");
	printf("...............................................\n");
	printf("%d years, %d months and %d days\n", year, month, days);
	printf("...............................................\n");	
}
	
