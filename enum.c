#include<stdio.h>
enum months{JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};
void main(){
	char *arr[]={"january","february","march","april","may","june","july","august","september","october","november","december"};
	enum months i;
	for(i=JAN;i<=DEC;i++){
		printf("%2d\t%s\n",i+1,arr[i]);
	}
}
