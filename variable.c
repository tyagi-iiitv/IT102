#include<stdio.h>
#include<stdarg.h>
double average(int i,...);
void main(){
	double a=5;
	double b=10;
	double c=15;
	double d=20;
	printf("a=%.2lf\nb=%.2lf\nc=%.2lf\nd=%.2lf\n",a,b,c,d);
	printf("Average of a and b is: %.2lf\n",average(2,a,b)); 
	printf("Average of a,b and c is: %.2lf\n",average(3,a,b,c));
	printf("Average of a,b,c and d is: %.2lf\n",average(4,a,b,c,d));
}
double average(int i,...){
	double total = 0;
	int j;
	va_list ap;//object created of name ap
	va_start(ap,i);
	for(j=0;j<i;j++){
		total+=va_arg(ap,double);//double defines the data type of object ap
	}
	va_end(ap);
	return total/i;
}
