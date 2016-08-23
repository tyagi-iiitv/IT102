#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
void equivalence(int r, int c, float arr[r][c]){
	int i, j;
	int ref = 0;
	for(i=0; i<r; i++){
		for(j=0; j<r; j++){
		if( i==j){
			if( arr[i][j] == 1){
			ref = 1;
			}
			else{
			ref = 0;
			}
			}
		}
	}
	if(ref == 1){
		printf("The matrix is reflexive\n");
	}
	else{
		printf("The matrix is not reflexive\n");
	}
	int sym = 1;
	for( i=0; i<r; i++){
		for( j=0; j<r; j++){
		if(arr[i][j] != arr[j][i]){
			sym = 0;
			break;
		}
		}
	}
	if(sym == 1){
		printf("The matrix is symmetric\n");
	}
	else{
		printf("The matrix is anti-Symmetric\n");
	}
	int trans = 1;
	int k;
	for( i=0; i<r; i++){
		for( j=0;j<r; j++){ 
			if( arr[i][j] == 1){
				for(k=0; k<r; k++){
				if(arr[j][k] == 1){
					if(arr[i][k] == 1){
					trans = 1;
					}
					else{
					trans = 0;
					break;
					}
				}
				}
			}
		}
	}
	if( trans == 0)
		printf("The matrix is non transitive\n");
	else
		printf("The matrix is transitive\n");
	if((ref == 1)&&(sym == 1)&&(trans == 1))
		printf("The matrix is of an equivalence relation\n");
	else{
		if((ref == 1)&&(sym == 0)&&(trans == 1))
		printf("The matrix is of partial order relation\n");
		else
		printf("The matrix is neither of equivalence relation nor of partial order\n");
	}
}
float average(float arr[],int len){
	float sum=0;
	int i=0;
	while( i<len){
		printf("Enter %dth number\n",i+1);
		scanf("%f", &arr[i]);
		sum = sum+arr[i];
		i++;
	}
	float average = sum/len;
	return average;
}
void bubble(float arr[],int len){
	int i,j;
	for(i=0;i<len;i++){
		for(j=0;j<len-1;j++){
			if(arr[j]>arr[j+1]){
				float c = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = c;
			}
		}
	}
	printf(".......\n");
	printf("The sorted array is:\n");
	for(i=0;i<len;i++){
		printf("%.2f ",arr[i]);
	}
	printf("\n");
}
void chomp(void){
	/*starting print of the chocolate bar*/
	printf("The game of chomp in a 7*4 rectangle\n");
	printf("    1.  2.  3.  4.  5.  6.  7.\n");
	printf("    __  __  __  __  __  __  __\n");
	printf("1. |__||__||__||__||__||__||__|\n");
	printf("    __  __  __  __  __  __  __\n");
	printf("2. |__||__||__||__||__||__||__|\n");
	printf("    __  __  __  __  __  __  __\n");
	printf("3. |__||__||__||__||__||__||__|\n");
	printf("    __  __  __  __  __  __  __\n");
	printf("4. |++||__||__||__||__||__||__|\n");
	/*----------------------------------------------*/
	printf("The bottom left corner of the chocolate is poisonous\n");
	int arr[4][7];
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<7;j++){
			arr[i][j]=1;
		}
	}
	int x,y;
	int p = 1;
	printf("Player 1:Enter the cordinates of the square you want to bite\n");
	scanf("%d%d",&x,&y);
	if((x==4)&&(y==1)){
		printf("You loose\n");
		p=0;
	}
	else{
	/*print of the chocolate bar after entering the cordinates*/
	printf("  1.  2.  3.  4.  5.  6.  7.\n");
	for(i=0;i<x;i++){
		for(j=y-1;j<7;j++){
			arr[i][j]=0;
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<7;j++){
			if (arr[i][j] == 1){
				printf("  __");
			}
		}
		printf("\n");
		printf("%d",i+1);
		for(j=0;j<7;j++){
			if(arr[i][j] == 1){
				if((i==3)&&(j==0)){
					printf("|++|");
				}
				else
				printf("|__|");
			}
		}printf("\n");
	}
	/*--------------------------------------------------*/
}
	int k=2;
	while(p!=0){
		/*Game should close when no box except (4,1) is left*/
		int jump = 0;
		for(i=0;i<4;i++){
			for(j=0;j<7;j++){
				if((i!=3)||(j!=0)){
					if(arr[i][j]==1)
					jump = 1;
				}
			}
		}
		/*----------------------------------------------------*/
		if(jump==1){
		if(k%2==0)
		printf("Player 2:Enter the cordinates of the square you want to bite\n");
		else
		printf("Player 1:Enter the cordinates of the square you want to bite\n");
		scanf("%d%d",&x,&y);
		if((x==4)&&(y==1)){
			printf("You loose\n");
			break;
		}
		else if(arr[x-1][y-1]==0){
		printf("Wrong choice\n");
		continue;
		}
		else{
		/*print of the chocolate bar after entering the cordinates*/
		printf("  1.  2.  3.  4.  5.  6.  7.\n");
		for(i=0;i<x;i++){
			for(j=y-1;j<7;j++){
				arr[i][j]=0;
			}
		}
		for(i=0;i<4;i++){
			for(j=0;j<7;j++){
				if (arr[i][j] == 1){
					printf("  __");
				}
			}
			printf("\n");
			printf("%d",i+1);
			for(j=0;j<7;j++){
				if(arr[i][j] == 1){
					if((i==3)&&(j==0)){
						printf("|++|");
					}
					else
					printf("|__|");
				}
			}printf("\n");
		}	
		/*--------------------------------------------------*/
		}
	}
	else{
		if(k%2==0){
			printf("Player 2 looses\n");
		}
		else
		printf("Player 1 looses\n");
		break;
	}
	k++;
	}
}
void closure(){
	/*Storing the values of elements of the relation*/
	printf("This program will give you the reflexive, symmetric or transitive closure of any relation\n");
	printf("Enter the relation for A*A in the following steps...\n");
	printf("Enter the number of elements in the set A :\n");
	int num1,i,j,k;
	scanf("%d",&num1);
	int arr2[num1];
	printf("Enter the number of elements in the relation A*A \n");
	int num2;
	scanf("%d",&num2);
	int arr[2*num2];
		for(i=0; i<num2; i++){
		printf("For(a,b), enter the value of 'a' and press enter\n");
		int a;
		scanf("%d", &a);
		int b;
		printf("For(a,b) enter the value of b\n");;
		scanf("%d", &b);
		printf("You entered (%d,%d)\n", a, b);
		arr[i] = a;
		arr[2*num2-i-1] = b;
		}
	printf("Your set of ordered pairs is:\n");
	printf("{");
		for(i=0; i<num2; i++){
		printf("(%d,%d)", arr[i], arr[2*num2-i-1]);
		}
	printf("}\n");
	int count = 1;
	int a = 0;
	for(i=0;i<(2*num2);i++){
		for(j=0;j<i;j++){
			if(arr[i] == arr[j]){
				count = 0;
			}	
		}
	if(count != 0){
		arr2[a] = arr[i];
	a++;
	}
	count = 1;
	}
	if(a != num1){
		printf("INCORRECT relation entered...\n");
	}
	/*forming the matrix of the given entries*/
	int mat[num1+1][num1+1];
	for(i=0;i<(num1+1);i++){
		for(j=0;j<(num1+1);j++){
			mat[i][j] = 0;
		}
	}
	for(i=0;i<1;i++){
		for(j=1;j<(num1+1);j++){
			mat[i][j] = arr2[j-1];
			mat[j][i] = arr2[j-1];
		}
	}
	for(i=1;i<(num1+1);i++){
		for(j=0;j<num2;j++){
			if(arr[j] == mat[i][0]){
				for(k=1;k<num1+1;k++){
					if((arr[2*num2-j-1]) == mat[0][k]){
						mat[i][k] = 1;
					}
				}
			}
		}
	}
	/*generating Reflexive closure*/
	printf("Generating reflexive closure\n");
	int matref[num1+1][num1+1];
	for(i=0;i<(num1+1);i++){
		for(j=0;j<(num1+1);j++){
			matref[i][j] = mat[i][j];
		}
	}
	for(i=1;i<(num1+1);i++){
		for(j=1;j<(num1+1);j++){
			if(i==j)
			matref[i][j] = 1;
			else
			matref[i][j] = mat[i][j];
		}
	}
	/*generating symmetric closure*/
	printf("Generating Symmetric closure\n");
	int matsym[num1+1][num1+1];
	for(i=0;i<(num1+1);i++){
		for(j=0;j<(num1+1);j++){
			matsym[i][j] = mat[i][j];
		}
	}
	for(i=1;i<(num1+1);i++){
		for(j=1;j<(num1+1);j++){
			if(mat[i][j] == 1){
				matsym[i][j] = 1;
				matsym[j][i] = 1;
			}
		}
	}
	/*generating transpose closure*/
	printf("Generating transitive closure\n");
	int mattrans[num1+1][num1+1];
	for(i=0;i<(num1+1);i++){
		for(j=0;j<(num1+1);j++){
			mattrans[i][j] = mat[i][j];
		}
	}
	for( i=1; i<(num1+1); i++){
		for( j=1;j<(num1+1); j++){ 
			if( mat[i][j] == 1){
				mattrans[i][j] = 1;
				for(k=1; k<(num1+1); k++){
					if(mat[j][k] == 1){
					mattrans[j][k] = 1;
					mattrans[i][k] = 1;
					}
				}
			}
		}
	}
	printf("The reflexive relation is:\n");
	printf("{");
	for(i=1;i<num1+1;i++){
		for(j=1;j<num1+1;j++){
			if(matref[i][j] == 1){
				printf("(%d,%d)",matref[i][0],matref[0][j]);
			}
		}
	}
	printf("}\n");
	printf("The symmetric relation is:\n");
	printf("{");
	for(i=1;i<num1+1;i++){
		for(j=1;j<num1+1;j++){
			if(matsym[i][j] == 1){
				printf("(%d,%d)",matref[i][0],matref[0][j]);
			}
		}
	}
	printf("}\n");
	printf("The tansitive relation is:\n");
	printf("{");
	for(i=1;i<num1+1;i++){
		for(j=1;j<num1+1;j++){
			if(matref[i][j] == 1){
				printf("(%d,%d)",mattrans[i][0],mattrans[0][j]);
			}
		}
	}
	printf("}\n");
}
void coeff(int n, int m){
	printf("For the first polynomial\n");
	float arr1[n+1];
	int i,j;
	for(i=0;i<=n;i++){
		printf("Enter the coefficient of x^%d \n",i);
		scanf("%f",&arr1[i]);
	}
	printf("For the second polynomial\n");
	float arr2[m+1];
	for(i=0;i<=m;i++){
		printf("Enter the coefficient of x^%d \n",i);
		scanf("%f",&arr2[i]);
	}
	printf("Enter the number k to find coefficient of x^k\n");
	int k;
	scanf("%d",&k);
	float sum=0;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i+j==k){
				sum = sum + (arr1[i]*arr2[j]);
			}
		}
	}
	printf("The coefficient of X^%d is %.2f\n",k,sum);
}
void days(int entry){
	int year, month, days;
	year = entry/360;
	month = (entry%360)/30;
	days = (entry%360)%30;
	printf("The number of days you entered are equivalent to-\n");
	printf("...............................................\n");
	printf("%d years, %d months and %d days\n", year, month, days);
	printf("...............................................\n");	
}
int fact(int num){
	int i;
	int fact = 1;
	scanf("%d", &num);
	for(i=1; i<=num; i++){
		fact = fact*i;
	}
	return fact;
}
void hanoi(int n,char frompeg,char topeg,char auxpeg){
	if(n==1){
		printf("Move disk 1 from %c to %c\n",frompeg,topeg);
		return;
	}
	hanoi(n-1,frompeg,auxpeg,topeg);
	printf("Move disk %d from %c to %c\n",n,frompeg,topeg);
	hanoi(n-1,auxpeg,topeg,frompeg);
}
void transpose(int r, int c, float mat[r][c]){
	int i,j;
	printf("The Transpose of the matrix is:\n");
	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			printf("%5.1f ",mat[j][i]);
		}
		printf("\n");
	}
}
void mat_square(int r, int c, float mat[r][c]){
	int i,j,k;
	if(r==c){
	float mat2[r][r];
	for(i=0;i<r;i++){
		for(j=0;j<r;j++){
			mat2[i][j]=0;
		}
	}
	printf("The square of the matrix is\n");
	for(i=0;i<r;i++){
		for(j=0;j<r;j++){
			for(k=0;k<r;k++){
				mat2[i][j] += mat[i][k]*mat[k][j];
			}
			printf("%5.1f",mat2[i][j]);
		}
		printf("\n");
	}
	}
	else
	printf("Invalid entry\n");
}
void mat_inv(int r, int c, float mat[r][c]){
	int i,j,k;
	if(r==c){
	printf("Inverse of the matrix entered by you is:\n");
	if(r==2){
		printf(" %-5.1f",mat[1][1]);
		printf("-%-5.1f\n",mat[0][1]);
		printf("-%-5.1f",mat[1][0]);
		printf(" %-5.1f\n",mat[0][0]);
	}
	else{	
		float adj[3][3];
		float adj2[3][3];
		float inv[3][3];
		int l,m,n,o,p;
		float a,b,c,d;
		for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			int jump1 = 0;
			int jump2 = 0;
			int jump3 = 0;
			for(k=0;k<3;k++){
				for(l=0;l<3;l++){
					if((k!=i)&&(l!=j)&&(jump1 == 0)){
						a = mat[k][l];
						jump1 = 1;
						for(m=0;m<3;m++){
							for(n=0;n<3;n++){
								if((m!=k)&&(n!=l)&&(jump2 == 0)&&(m!=i)&&(n!=j)){
									b = mat[m][n];
									jump2 = 1;
								}
								else if((m==k)&&(n!=l)&&(jump2 == 0)&&(m!=i)&&(n!=j)){
									c = mat[m][n];
									for(o=0;o<3;o++){
										for(p=0;p<3;p++){
											if((o!=m)&&(o!=i)&&(p!=n)&&(p!=j)&&(jump3 == 0)){
												d = mat[o][p];
												jump3=1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			if((i+j)%2==0){
			adj[i][j] = (a*b)-(c*d);
		}
		else{
			adj[i][j] = (c*d)-(a*b);
		}
		}
		}
		for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			adj2[i][j] = adj[j][i];
		}
		}
		float	det = (mat[0][0]*adj[0][0])+(mat[0][1]*adj[0][1])+(mat[0][2]*adj[0][2]);
		for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			inv[i][j] = adj2[i][j]/det;
			printf("%.2f\t",inv[i][j]);
		}
		printf("\n");
		}
	}
	}
	else
	printf("Invalid entry\n");
}
void pascal(int num){
	int arr[num][2*num-1];
	int i,j;
	for(i=0;i<num;i++){
		for(j=0;j<(2*num-1);j++){
			arr[i][j] = 0;
		}
	}
	arr[0][num-1] = 1;
	arr[1][num-2] = 1;
	arr[1][num] = 1;
	for(i=2;i<num;i++){
		for(j=0;j<(2*num-1);j++){
		if(j != 0)
			arr[i][j] = arr[i-1][j-1] + arr[i-1][j+1];
		else
			arr[i][j] = arr[i-1][j+1];
		}
	}
	for(i=0;i<num;i++){
		for(j=0;j<(2*num-1);j++){
			if(arr[i][j] == 0)
				printf(" ");
			else
				printf("%d",arr[i][j]);
		}
		printf("\n");
	}
}
void print1_d(double arr[],int len){
	int i;
	for(i=0;i<len;i++){
		printf("%.2lf ",arr[i]);
	}
	printf("\n");
}
void print1_f(float arr[],int len){
	int i;
	for(i=0;i<len;i++){
		printf("%.2f ",arr[i]);
	}
	printf("\n");
}
void print1_i(int arr[],int len){
	int i;
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void print2_d(int r, int c, double arr[r][c]){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%.2lf ",arr[i][j]);
		}
		printf("\n");
	}
}
void print2_f(int r, int c, float arr[r][c]){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%.2f ",arr[i][j]);
		}
		printf("\n");
	}
}
void print2_i(int r, int c, int arr[r][c]){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
void compare(char temp[],char arr[],int num[],int i,int pos){
	int j=0;
	int k;
	while(i<strlen(arr)){
		char temp2[20]={'\0'};
		int start=i;
		while(arr[i]!=' '&&arr[i]!='\0'&&arr[i]!='!'&&arr[i]!=';'&&arr[i]!=':'&&arr[i]!='"'&&arr[i]!=','&&arr[i]!='.'&&arr[i]!='?'&&arr[i]!='*'){
			temp2[j]=arr[i];
			i++;
			j++;
		}
		int end=i;
		j=0;
		if(strcmp(temp,temp2)==0){
			num[pos]=num[pos]+1;
			for(k=start;k<end;k++){
				arr[k]='*';
			}
		}
		i++;
	}
}
void word(char arr[]){ //string.h
	int num[100]={0};
	int i,j;
	i=0;
	j=0;
	while(i<strlen(arr)){
		char temp[20]={'\0'};
		int pos=i;
		while(arr[i]!=' '&&arr[i]!='\0'&&arr[i]!='!'&&arr[i]!=';'&&arr[i]!=':'&&arr[i]!='"'&&arr[i]!=','&&arr[i]!='.'&&arr[i]!='?'&&arr[i]!='*'){
			temp[j]=arr[i];
			i++;
			j++;
		}
		j=0;
		compare(temp,arr,num,i+1,pos);
		i++;
	}
	i=0;
	j=0;
	while(i<=strlen(arr)){
		char temp[20]={'\0'};
		int pos=i;
		int count=0;
		while(arr[i]!=' '&&arr[i]!='\0'&&arr[i]!='!'&&arr[i]!=';'&&arr[i]!=':'&&arr[i]!='"'&&arr[i]!=','&&arr[i]!='.'&&arr[i]!='?'&&arr[i]!='*'){
			temp[j]=arr[i];
			i++;
			j++;
			count=1;
		}
		j=0;
		if(count == 1){
			printf("%s occurs %d times\n",temp,num[pos]+1);
		}
		i++;
	}
}
void subsets(int num){ //math.h
	int rem;
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
void swap_i(int *a, int *b){
	*a = (*a)+(*b);
	*b = (*a)-(*b);
	*a = (*a)-(*b);
}
void swap_f(float *a, float *b){
	*a = (*a)+(*b);
	*b = (*a)-(*b);
	*a = (*a)-(*b);
}
void swap_d(double *a, double *b){
	*a = (*a)+(*b);
	*b = (*a)-(*b);
	*a = (*a)-(*b);
}
void xnacci(int x, int num){
	int arr[x+1];
	arr[0] = 0;
	arr[1] = 1;
	printf("The series is\n");
	printf("0 1 ");
	int i,j;
	for(i=2; i<=x; i++){
		int sum = 0;
		for(j=0; j<i; j++){
			sum = sum+arr[j];
		}
	arr[i] = sum;
	printf("%d ", arr[i]);
	}
	int k;
	for(k=0; k<(num-x-1); k++){
	int sum2 = 0;
	for(i=0; i<x; i++){
		arr[i] = arr[i+1];
	}	
	for(j=0; j<=(x-1); j++){
		sum2 = sum2+arr[j];
	}
	arr[x] = sum2;
	printf("%d ",arr[x]);
	}
	printf("\n");
}
void margin(char arr[]){ //string.h, ctype.h
	int s = 0;
	int i,j,k,l,m;
	for(i=0;i<strlen(arr);i++){
		if(isspace(arr[i])){
			s++;
		}
		if(i%20==0&&i!=0){
			if(arr[i]!=' '){
				j=i-1;
				while(arr[j]!=' '){
					j--;
				}
				int count = i-j-1;
				for(k=0;k<=(i-j-1)/(s-1);k++){
					l=i-20;
					while(l<j){
						if(count == 0){
							break;
						}	
						else if(isspace(arr[l])){
							for(m=strlen(arr);m>=l;m--){
								arr[m+1]=arr[m];
							}
							count--;
							l++;
						}
						l++;
					}
				}
				
				s=0;
			}
			else{
				for(m=i;m<=strlen(arr)-1;m++){
					arr[m]=arr[m+1];
				}
				s = 0;
				/*
				for(i=0;i<strlen(arr);i++){
					printf("%c",arr[i]);
				}
				printf("\n");
				*/ 
			}
		}
	}
	for(i=0;i<strlen(arr);i++){
		if(i%20==19){
			if(isspace(arr[i])){
				j=i-1;
				while(arr[j]!=' '){
					j--;
				}
				for(k=i-1;k>=j;k--){
					arr[k+1]=arr[k];
				}
			}
		}
	}
	for(i=0;i<strlen(arr);i++){	
		if(i%20==0){
			printf("\n");
		}
		printf("%c",arr[i]);
	}
	printf("\n");
}
void ty(int n){
	switch(n){
		case 1: printf("ONE ");
		break;
		case 2: printf("TWO ");
		break;
		case 3: printf("THREE ");
		break;
		case 4: printf("FOUR ");
		break;
		case 5: printf("FIVE ");
		break;
		case 6: printf("SIX ");
		break;
		case 7: printf("SEVEN ");
		break;
		case 8: printf("EIGHT ");
		break;
		case 9: printf("NINE ");
		break;
		case 10: printf("TEN ");
		break;
		case 11: printf("ELEVEN ");
		break;
		case 12: printf("TWELVE ");
		break;
		case 13: printf("THIRTEEN ");
		break;
		case 14: printf("FOURTEEN ");
		break;
		case 15: printf("FIFTEEN ");
		break;
		case 16: printf("SIXTEEN ");
		break;
		case 17: printf("SEVENTEEN ");
		break;
		case 18: printf("EIGHTEEN ");
		break;
		case 19: printf("NINETEEN ");
		break;
		case 20: printf("TWENTY ");
		break;
	}
}
void ty2(int n){
	switch(n){
		case 2: printf("TWENTY ");
		break;
		case 3: printf("THIRTY ");
		break;
		case 4: printf("FOURTY ");
		break;
		case 5: printf("FIFTY ");
		break;
		case 6: printf("SIXTY ");
		break;
		case 7: printf("SEVENTY ");
		break;
		case 8: printf("EIGHTY ");
		break;
		case 9: printf("NINETY ");
		break;
	}
}
void hu(int n){
	switch(n){
		case 1: printf("ONE HUNDRED ");
		break;
		case 2: printf("TWO HUNDRED ");
		break;
		case 3: printf("THREE HUNDRED ");
		break;
		case 4: printf("FOUR HUNDRED ");
		break;
		case 5: printf("FIVE HUNDRED ");
		break;
		case 6: printf("SIX HUNDRED ");
		break;
		case 7: printf("SEVEN HUNDRED ");
		break;
		case 8: printf("EIGHT HUNDRED ");
		break;
		case 9: printf("NINE HUNDRED ");
		break;
	}
}
void th(int n){
	switch(n){
		case 1: printf("ONE THOUSAND ");
		break;
		case 2: printf("TWO THOUSAND ");
		break;
		case 3: printf("THREE THOUSAND ");
		break;
		case 4: printf("FOUR THOUSAND ");
		break;
		case 5: printf("FIVE THOUSAND ");
		break;
		case 6: printf("SIX THOUSAND ");
		break;
		case 7: printf("SEVEN THOUSAND ");
		break;
		case 8: printf("EIGHT THOUSAND ");
		break;
		case 9: printf("NINE THOUSAND ");
		break;
		case 10: printf("TEN THOUSAND ");
		break;
		case 11: printf("ELEVEN THOUSAND ");
		break;
		case 12: printf("TWELVE THOUSAND ");
		break;
		case 13: printf("THIRTEEN THOUSAND ");
		break;
		case 14: printf("FOURTEEN THOUSAND ");
		break;
		case 15: printf("FIFTEEN THOUSAND ");
		break;
		case 16: printf("SIXTEEN THOUSAND ");
		break;
		case 17: printf("SEVENTEEN THOUSAND ");
		break;
		case 18: printf("EIGHTEEN THOUSAND ");
		break;
		case 19: printf("NINETEEN THOUSAND ");
		break;
		case 20: printf("TWENTY THOUSAND ");
		break;
		default: printf("THOUSAND ");
		break;
	}
}
void la(int n){
	switch(n){
		case 1: printf("ONE LAKH ");
		break;
		case 2: printf("TWO LAKH ");
		break;
		case 3: printf("THREE LAKH ");
		break;
		case 4: printf("FOUR LAKH ");
		break;
		case 5: printf("FIVE LAKH ");
		break;
		case 6: printf("SIX LAKH ");
		break;
		case 7: printf("SEVEN LAKH ");
		break;
		case 8: printf("EIGHT LAKH ");
		break;
		case 9: printf("NINE LAKH ");
		break;
		case 10: printf("TEN LAKH ");
		break;
		case 11: printf("ELEVEN LAKH ");
		break;
		case 12: printf("TWELVE LAKH ");
		break;
		case 13: printf("THIRTEEN LAKH ");
		break;
		case 14: printf("FOURTEEN LAKH ");
		break;
		case 15: printf("FIFTEEN LAKH ");
		break;
		case 16: printf("SIXTEEN LAKH ");
		break;
		case 17: printf("SEVENTEEN LAKH ");
		break;
		case 18: printf("EIGHTEEN LAKH ");
		break;
		case 19: printf("NINETEEN LAKH ");
		break;
		case 20: printf("TWENTY LAKH ");
		break;
		default: printf("LAKH ");
	}
}
void cr(int n){
	switch(n){
		case 1: printf("ONE CRORE ");
		break;
		case 2: printf("TWO CRORE ");
		break;
		case 3: printf("THREE CRORE ");
		break;
		case 4: printf("FOUR CRORE ");
		break;
		case 5: printf("FIVE CRORE ");
		break;
		case 6: printf("SIX CRORE ");
		break;
		case 7: printf("SEVEN CRORE ");
		break;
		case 8: printf("EIGHT CRORE ");
		break;
		case 9: printf("NINE CRORE ");
		break;
		case 10: printf("TEN CRORE ");
		break;
		case 11: printf("ELEVEN CRORE ");
		break;
		case 12: printf("TWELVE CRORE ");
		break;
		case 13: printf("THIRTEEN CRORE ");
		break;
		case 14: printf("FOURTEEN CRORE ");
		break;
		case 15: printf("FIFTEEN CRORE ");
		break;
		case 16: printf("SIXTEEN CRORE ");
		break;
		case 17: printf("SEVENTEEN CRORE ");
		break;
		case 18: printf("EIGHTEEN CRORE ");
		break;
		case 19: printf("NINETEEN CRORE ");
		break;
		case 20: printf("TWENTY CRORE ");
		break;
		default: printf("CRORE ");
		break;
	}
}
void amount_words(char amount[]){ //stdlib.h, string.h, ctype.h
	char rupee[11]={'\0'};
	char paise[3]={'\0'};
	int i;
	int j=0;
	int check=0;
	for(i=0;i<strlen(amount);i++){
		 if(amount[i]=='.'){
			 check=1;
			 j=0;
		 }
		 if(check==0){
			 rupee[j]=amount[i];
			 j++;
		 }
		 if(check==1){
			 paise[j]=amount[i+1];
			 j++;
		 }
	 }
	 int lenr=strlen(rupee);
	 int lenp=strlen(paise);
	 int ru[lenr];
	 int pa[lenp];
	 int a = atoi(rupee);
	 int b = atoi(paise);
	 for(i=lenr-1;i>=0;i--){
		 ru[i]=a%10;
		 a=a/10;
	 }
	 for(i=lenp-1;i>=0;i--){
		 pa[i]=b%10;
		 b=b/10;
	 }
	 switch(lenr){
		 case 1:
		 ty(atoi(rupee));
		 break;
		 case 2:
		 if(atoi(rupee)<=20){
			 ty(atoi(rupee));
		 }
		 else{
			 ty2(ru[0]);
			 ty(ru[1]);
		 }
		 break; 
		 case 3:
		 hu(ru[0]);
		 int num=10*ru[1]+ru[2];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[1]);
			 ty(ru[2]);
		 }
		 break;
		 case 4:
		 th(ru[0]);
		 hu(ru[1]);
		 num=10*ru[2]+ru[3];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[2]);
			 ty(ru[3]);
		 }
		 break;
		 case 5:
		 num=10*ru[0]+ru[1];
		 if(num<=20){
			 th(num);
		 }
		 else{
			 ty2(ru[0]);
			 ty(ru[1]);
			 th(num);
		 }
		 hu(ru[2]);
		 num=10*ru[3]+ru[4];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[3]);
			 ty(ru[4]);
		 }
		 break;
		 case 6:
		 la(ru[0]);
		 num=10*ru[1]+ru[2];
		 if(num<=20){
			 th(num);
		 }
		 else{
			 ty2(ru[1]);
			 ty(ru[2]);
			 th(num);
		 }
		 hu(ru[3]);
		 num=10*ru[4]+ru[5];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[4]);
			 ty(ru[5]);
		 }
		 break;
		 case 7:
		 num=10*ru[0]+ru[1];
		 if(num<=20){
			 la(num);
		 }
		 else{
			 ty2(ru[0]);
			 ty(ru[1]);
			 la(num);
		 }
		 num=10*ru[2]+ru[3];
		 if(num<=20){
			 th(num);
		 }
		 else{
			 ty2(ru[2]);
			 ty(ru[3]);
			 th(num);
		 }
		 hu(ru[4]);
		 num=10*ru[5]+ru[6];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[5]);
			 ty(ru[6]);
		 }
		 break;
		 case 8:
		 cr(ru[0]);
		 num=10*ru[1]+ru[2];
		 if(num<=20){
			 la(num);
		 }
		 else{
			 ty2(ru[1]);
			 ty(ru[2]);
			 la(num);
		 }
		 num=10*ru[3]+ru[4];
		 if(num<=20){
			 th(num);
		 }
		 else{
			 ty2(ru[3]);
			 ty(ru[4]);
			 th(num);
		 }
		 hu(ru[5]);
		 num=10*ru[6]+ru[7];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[6]);
			 ty(ru[7]);
		 }
		 break;
		 case 9:
		 num=10*ru[0]+ru[1];
		 if(num<=20){
			 cr(num);
		 }
		 else{
			 ty2(ru[0]);
			 ty(ru[1]);
			 cr(num);
		 }
		 num=10*ru[2]+ru[3];
		 if(num<=20){
			 la(num);
		 }
		 else{
			 ty2(ru[2]);
			 ty(ru[3]);
			 la(num);
		 }
		 num=10*ru[4]+ru[5];
		 if(num<=20){
			 th(num);
		 }
		 else{
			 ty2(ru[4]);
			 ty(ru[5]);
			 th(num);
		 }
		 hu(ru[6]);
		 num=10*ru[7]+ru[8];
		 if(num<=20){
			 ty(num);
		 }
		 else{
			 ty2(ru[7]);
			 ty(ru[8]);
		 }
		 break;
		 case 10:
		 printf("HUNDRED CRORE ");
	 }
	 printf("RUPEES ");
	 switch(lenp){
		 case 1:
		 printf("AND ");
		 ty(atoi(paise));
		 printf("PAISE");
		 break;
		 case 2:
		 printf("AND ");
		 if(atoi(paise)<=20){
			 ty(atoi(paise));
		 }
		 else{
			 ty2(pa[0]);
			 ty(pa[1]);
		 }
		 printf("PAISE");
		 break; 
	 }
	 printf("\n");
}
struct tree_i{
	int value;
	int num;
	struct tree_i *leftPtr;
	struct tree_i *rightPtr;
	};
	typedef struct tree_i treei;
	typedef treei *ptr_tree_i;

struct tree_f{
	float value;
	int num;
	struct tree_f *leftPtr;
	struct tree_f *rightPtr;
	};
	typedef struct tree_f treef;
	typedef treef *ptr_tree_f;

struct tree_d{
	double value;
	int num;
	struct tree_d *leftPtr;
	struct tree_d *rightPtr;
	};
	typedef struct tree_d treed;
	typedef treed *ptr_tree_d;


struct tree_c{
	char value;
	int num;
	struct tree_c *leftPtr;
	struct tree_c *rightPtr;
	};
	typedef struct tree_c treec;
	typedef treec *ptr_tree_c;


struct tree_s{
	char value[500];
	int num;
	struct tree_s *leftPtr;
	struct tree_s *rightPtr;
	};
	typedef struct tree_s trees;
	typedef trees *ptr_tree_s;

int H;
ptr_tree_i ROOT_I;
ptr_tree_f ROOT_F;
ptr_tree_d ROOT_D;
ptr_tree_c ROOT_C;
ptr_tree_s ROOT_S;
void input(ptr_tree_i root, int jump,int *height){
	if(root!=NULL){
		ptr_tree_i temp;
		temp=malloc(sizeof(treei));
		temp->leftPtr=NULL;
		if(jump==0){
			printf("Enter the value of left subtree of %d or 0 if NULL\n",root->value);
			scanf("%d",&temp->value);
			if(temp->value==0){
				temp=NULL;
			}
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->leftPtr=temp;
			input(root->leftPtr,0,height);
			input(root,1,height);
		}
		else{
			printf("Enter the value of right subtree of %d or 0 if NULL\n",root->value);
			scanf("%d",&temp->value);
			temp->num=(root->num)+1;
			if(temp->value==0){
				temp=NULL;
			}
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->rightPtr=temp;
			input(root->rightPtr,0,height);
		}
	}
}

void input_tree_i(){
	ptr_tree_i root;
	int h=0;
	int *height=&h;
	root=malloc(sizeof(treei));
	printf("Enter the value of the root\n");
	scanf("%d",&root->value);
	root->leftPtr=NULL;
	root->num=0;
	ROOT_I=root;
	input(root,0,height);
	printf("Tree entry is complete\n");
	H=h;
}
void input_f(ptr_tree_f root, int jump,int *height){
	if(root!=NULL){
		ptr_tree_f temp;
		temp=malloc(sizeof(treef));
		temp->leftPtr=NULL;
		if(jump==0){
			printf("Enter the value of left subtree of %.2f or 0 if NULL\n",root->value);
			scanf("%f",&temp->value);
			if(temp->value==0){
				temp=NULL;
			}
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->leftPtr=temp;
			input_f(root->leftPtr,0,height);
			input_f(root,1,height);
		}
		else{
			printf("Enter the value of right subtree of %.2f or 0 if NULL\n",root->value);
			scanf("%f",&temp->value);
			temp->num=(root->num)+1;
			if(temp->value==0){
				temp=NULL;
			}
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->rightPtr=temp;
			input_f(root->rightPtr,0,height);
		}
	}
}

void input_tree_f(){
	ptr_tree_f root;
	int h=0;
	int *height=&h;
	root=malloc(sizeof(treef));
	printf("Enter the value of the root\n");
	scanf("%f",&root->value);
	root->leftPtr=NULL;
	root->num=0;
	ROOT_F=root;
	input_f(root,0,height);
	printf("Tree entry is complete\n");
	H=h;
}
void input_d(ptr_tree_d root, int jump,int *height){
	if(root!=NULL){
		ptr_tree_d temp;
		temp=malloc(sizeof(treed));
		temp->leftPtr=NULL;
		if(jump==0){
			printf("Enter the value of left subtree of %.2lf or 0 if NULL\n",root->value);
			scanf("%lf",&temp->value);
			if(temp->value==0){
				temp=NULL;
			}
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->leftPtr=temp;
			input_d(root->leftPtr,0,height);
			input_d(root,1,height);
		}
		else{
			printf("Enter the value of right subtree of %.2lf or 0 if NULL\n",root->value);
			scanf("%lf",&temp->value);
			temp->num=(root->num)+1;
			if(temp->value==0){
				temp=NULL;
			}
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->rightPtr=temp;
			input_d(root->rightPtr,0,height);
		}
	}
}

void input_tree_d(){
	ptr_tree_d root;
	int h=0;
	int *height=&h;
	root=malloc(sizeof(treed));
	printf("Enter the value of the root\n");
	scanf("%lf",&root->value);
	root->leftPtr=NULL;
	root->num=0;
	ROOT_D=root;
	input_d(root,0,height);
	printf("Tree entry is complete\n");
	H=h;
}
void input_c(ptr_tree_c root, int jump,int *height){
	if(root!=NULL){
		ptr_tree_c temp;
		temp=malloc(sizeof(treec));
		temp->leftPtr=NULL;
		if(jump==0){
			printf("Enter the value of left subtree of %c or 0 if NULL\n",root->value);
			scanf("%c",&temp->value);
			if(temp->value=='0'){
				temp=NULL;
			}
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->leftPtr=temp;
			input_c(root->leftPtr,0,height);
			input_c(root,1,height);
		}
		else{
			printf("Enter the value of right subtree of %c or 0 if NULL\n",root->value);
			scanf("%c",&temp->value);
			temp->num=(root->num)+1;
			if(temp->value=='0'){
				temp=NULL;
			}
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->rightPtr=temp;
			input_c(root->rightPtr,0,height);
		}
	}
}

void input_tree_c(){
	ptr_tree_c root;
	int h=0;
	int *height=&h;
	root=malloc(sizeof(treec));
	printf("Enter the value of the root\n");
	scanf("%c",&root->value);
	root->leftPtr=NULL;
	root->num=0;
	ROOT_C=root;
	input_c(root,0,height);
	printf("Tree entry is complete\n");
	H=h;
}
void input_s(ptr_tree_s root, int jump,int *height){
	if(root!=NULL){
		ptr_tree_s temp;
		temp=malloc(sizeof(trees));
		temp->leftPtr=NULL;
		if(jump==0){
			printf("Enter the value of left subtree of %s or 0 if NULL\n",root->value);
			gets(temp->value);
			if(temp->value[0]=='0'){
				temp=NULL;
			}
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->leftPtr=temp;
			input_s(root->leftPtr,0,height);
			input_s(root,1,height);
		}
		else{
			printf("Enter the value of right subtree of %s or 0 if NULL\n",root->value);
			gets(temp->value);
			temp->num=(root->num)+1;
			if(temp->value[0]=='0'){
				temp=NULL;
			}
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->rightPtr=temp;
			input_s(root->rightPtr,0,height);
		}
	}
}

void input_tree_s(){
	ptr_tree_s root;
	int h=0;
	int *height=&h;
	root=malloc(sizeof(trees));
	printf("Enter the value of the root\n");
	gets(root->value);
	root->leftPtr=NULL;
	root->num=0;
	ROOT_S=root;
	input_s(root,0,height);
	printf("Tree entry is complete\n");
	H=h;
}
void call_inorder_i(ptr_tree_i root){ //stdlib.h, tree_i()
	if(root!=NULL){
		call_inorder_i(root->leftPtr);
		printf("%d ",root->value);
		call_inorder_i(root->rightPtr);
	}
}

void inorder_i(){
	call_inorder_i(ROOT_I);
	printf("\n");
}
void call_preorder_i(ptr_tree_i root){//stdlib.h, tree_i()
	if(root!=NULL){
	printf("%d ",root->value);
	call_preorder_i(root->leftPtr);
	call_preorder_i(root->rightPtr);
	}
}
void preorder_i(){
	call_preorder_i(ROOT_I);
	printf("\n");
}

void call_postorder_i(ptr_tree_i root){ //stdlib.h, tree_i()
	if(root!=NULL){
	call_postorder_i(root->leftPtr);
	call_postorder_i(root->rightPtr);
	printf("%d ",root->value);
	}
}
void postorder_i(){
	call_postorder_i(ROOT_I);
	printf("\n");
}

void call_inorder_f(ptr_tree_f root){ //stdlib.h, tree_f()
	if(root!=NULL){
		call_inorder_f(root->leftPtr);
		printf("%.2f ",root->value);
		call_inorder_f(root->rightPtr);
	}
}
void inorder_f(){
	call_inorder_f(ROOT_F);
	printf("\n");
}

void call_preorder_f(ptr_tree_f root){ //stdlib.h, tree_f()
	if(root!=NULL){
	printf("%.2f ",root->value);
	call_preorder_f(root->leftPtr);
	call_preorder_f(root->rightPtr);
	}
}
void preorder_f(){
	call_preorder_f(ROOT_F);
	printf("\n");
}

void call_postorder_f(ptr_tree_f root){  //stdlib.h, tree_f()
	if(root!=NULL){
	call_postorder_f(root->leftPtr);
	call_postorder_f(root->rightPtr);
	printf("%.2f ",root->value);
	}
}
void postorder_f(){
	call_postorder_f(ROOT_F);
	printf("\n");
}

void call_inorder_d(ptr_tree_d root){ //stdlib.h, tree_d()
	if(root!=NULL){
		call_inorder_d(root->leftPtr);
		printf("%.2lf ",root->value);
		call_inorder_d(root->rightPtr);
	}
}
void inorder_d(){
	call_inorder_d(ROOT_D);
	printf("\n");
}

void call_preorder_d(ptr_tree_d root){ //stdlib.h, tree_d()
	if(root!=NULL){
	printf("%.2lf ",root->value);
	call_preorder_d(root->leftPtr);
	call_preorder_d(root->rightPtr);
	}
}
void preorder_d(){
	call_preorder_d(ROOT_D);
	printf("\n");
}

void call_postorder_d(ptr_tree_d root){ //stdlib.h, tree_d()
	if(root!=NULL){
	call_postorder_d(root->leftPtr);
	call_postorder_d(root->rightPtr);
	printf("%.2lf ",root->value);
	}
}
void postorder_d(){
	call_postorder_d(ROOT_D);
	printf("\n");
}

void call_inorder_c(ptr_tree_c root){ //stdlib.h, tree_c()
	if(root!=NULL){
		call_inorder_c(root->leftPtr);
		printf("%c ",root->value);
		call_inorder_c(root->rightPtr);
	}
}
void inorder_c(){
	call_inorder_c(ROOT_C);
	printf("\n");
}

void call_preorder_c(ptr_tree_c root){ //stdlib.h, tree_c()
	if(root!=NULL){
	printf("%c ",root->value);
	call_preorder_c(root->leftPtr);
	call_preorder_c(root->rightPtr);
	}
}
void preorder_c(){
	call_preorder_c(ROOT_C);
	printf("\n");
}

void call_postorder_c(ptr_tree_c root){ //stdlib.h, tree_c()
	if(root!=NULL){
	call_postorder_c(root->leftPtr);
	call_postorder_c(root->rightPtr);
	printf("%c ",root->value);
	}
}
void postorder_c(){
	call_postorder_c(ROOT_C);
	printf("\n");
}

void call_inorder_s(ptr_tree_s root){ //stdlib.h, tree_s()
	if(root!=NULL){
		call_inorder_s(root->leftPtr);
		printf("%s ",root->value);
		call_inorder_s(root->rightPtr);
	}
}
void inorder_s(){
	call_inorder_s(ROOT_S);
	printf("\n");
}

void call_preorder_s(ptr_tree_s root){ //stdlib.h, tree_s()
	if(root!=NULL){
	printf("%s ",root->value);
	call_preorder_s(root->leftPtr);
	call_preorder_s(root->rightPtr);
	}
}
void preorder_s(){
	call_preorder_s(ROOT_S);
	printf("\n");
}

void call_postorder_s(ptr_tree_s root){ //stdlib.h, tree_s()
	if(root!=NULL){
	call_postorder_s(root->leftPtr);
	call_postorder_s(root->rightPtr);
	printf("%s ",root->value);
	}
}
void postorder_s(){
	call_postorder_s(ROOT_S);
	printf("\n");
}

struct stack_i{
	int value;
	struct stack_i *nextPtr;
};
typedef struct stack_i stacki;
typedef stacki *ptr_stack_i;

struct stack_f{
	float value;
	struct stack_f *nextPtr;
};
typedef struct stack_f stackf;
typedef stackf *ptr_stack_f;

struct stack_d{
	double value;
	struct stack_d *nextPtr;
};
typedef struct stack_d stackd;
typedef stackd *ptr_stack_d;

struct stack_c{
	char value;
	struct stack_c *nextPtr;
};
typedef struct stack_c stackc;
typedef stackc *ptr_stack_c;

struct stack_s{
	char value[500];
	struct stack_s *nextPtr;
};
typedef struct stack_s stacks;
typedef stacks *ptr_stack_s;

void pop_i(ptr_stack_i *popPtr){ //stdlib.h, stack_?()
	ptr_stack_i temp;
	temp=malloc(sizeof(stacki));
	temp=*popPtr;
	if(temp!=NULL){
	*popPtr=(*popPtr)->nextPtr;
	printf("Value popped out\n");
	}
	else{
		printf("List is empty\n");
	}
}
void pop_f(ptr_stack_f *popPtr){ //stdlib.h, stack_?()
	ptr_stack_f temp;
	temp=malloc(sizeof(stackf));
	temp=*popPtr;
	if(temp!=NULL){
	*popPtr=(*popPtr)->nextPtr;
	printf("Value popped out\n");
	}
	else{
		printf("List is empty\n");
	}
}
void pop_d(ptr_stack_d *popPtr){ //stdlib.h, stack_?()
	ptr_stack_d temp;
	temp=malloc(sizeof(stackd));
	temp=*popPtr;
	if(temp!=NULL){
	*popPtr=(*popPtr)->nextPtr;
	printf("Value popped out\n");
	}
	else{
		printf("List is empty\n");
	}
}
void pop_c(ptr_stack_c *popPtr){ //stdlib.h, stack_?()
	ptr_stack_c temp;
	temp=malloc(sizeof(stackc));
	temp=*popPtr;
	if(temp!=NULL){
	*popPtr=(*popPtr)->nextPtr;
	printf("Value popped out\n");
	}
	else{
		printf("List is empty\n");
	}
}
void pop_s(ptr_stack_s *popPtr){ //stdlib.h, stack_?()
	ptr_stack_s temp;
	temp=malloc(sizeof(stacks));
	temp=*popPtr;
	if(temp!=NULL){
	*popPtr=(*popPtr)->nextPtr;
	printf("Value popped out\n");
	}
	else{
		printf("List is empty\n");
	}
}

void print_ds_i(ptr_stack_i printPtr){ //stdlib.h, stack_i()
	if(printPtr==NULL){
		printf("List is empty\n");
	}
	else{
		while(printPtr!=NULL){
			printf("%d--> ",printPtr->value);
			printPtr=printPtr->nextPtr;
		}
		printf("NULL\n");
	}
}
void print_ds_f(ptr_stack_f printPtr){ //stdlib.h, stack_f()
	if(printPtr==NULL){
		printf("List is empty\n");
	}
	else{
		while(printPtr!=NULL){
			printf("%.2f--> ",printPtr->value);
			printPtr=printPtr->nextPtr;
		}
		printf("NULL\n");
	}
}
void push_f(ptr_stack_f *pushPtr, float value){ //stdlib.h, stack_f()
	ptr_stack_f temp;
	temp=malloc(sizeof(stackf));
	temp->value=value;
	temp->nextPtr=*pushPtr;
	*pushPtr=temp;
	print_ds_f(*pushPtr);
}
void print_ds_d(ptr_stack_d printPtr){ //stdlib.h, stack_d()
	if(printPtr==NULL){
		printf("List is empty\n");
	}
	else{
		while(printPtr!=NULL){
			printf("%.2lf--> ",printPtr->value);
			printPtr=printPtr->nextPtr;
		}
		printf("NULL\n");
	}
}
void push_d(ptr_stack_d *pushPtr, double value){ //stdlib.h, stack_d()
	ptr_stack_d temp;
	temp=malloc(sizeof(stackd));
	temp->value=value;
	temp->nextPtr=*pushPtr;
	*pushPtr=temp;
	print_ds_d(*pushPtr);
}
void print_ds_c(ptr_stack_c printPtr){ //stdlib.h, stack_c()
	if(printPtr==NULL){
		printf("List is empty\n");
	}
	else{
		while(printPtr!=NULL){
			printf("%c--> ",printPtr->value);
			printPtr=printPtr->nextPtr;
		}
		printf("NULL\n");
	}
}
void push_c(ptr_stack_c *pushPtr, char value){ //stdlib.h, stack_c()
	ptr_stack_c temp;
	temp=malloc(sizeof(stackc));
	temp->value=value;
	temp->nextPtr=*pushPtr;
	*pushPtr=temp;
	print_ds_c(*pushPtr);
}
void print_ds_s(ptr_stack_s printPtr){ //stdlib.h, stack_s()
	if(printPtr==NULL){
		printf("List is empty\n");
	}
	else{
		while(printPtr!=NULL){
			printf("%s--> ",printPtr->value);
			printPtr=printPtr->nextPtr;
		}
		printf("NULL\n");
	}
}
void enqueue_i(ptr_stack_i *start,ptr_stack_i *end, int value){
	ptr_stack_i temp,cur;
	temp=malloc(sizeof(stacki));
	temp->value=value;
	temp->nextPtr=NULL;
	cur=*start;
	if(*start==NULL){
		*start=temp;
		*end=temp;
		print_ds_i(*start);
	}
	else{
		while(cur->nextPtr!=NULL){
			cur=cur->nextPtr;
		}
		cur->nextPtr=temp;
		*end=temp;
		print_ds_i(*start);
	}
}
void dequeue_i(ptr_stack_i *start){
	ptr_stack_i temp;
	temp=malloc(sizeof(stacki));
	temp=*start;
	if(temp!=NULL){
	*start=temp->nextPtr;
	printf("Value successfully dequed\n");
	free(temp);
	}
	else{
		printf("List is empty\n");
	}
}
void dequeue_d(ptr_stack_d *start){
	ptr_stack_d temp;
	temp=malloc(sizeof(stackd));
	temp=*start;
	if(temp!=NULL){
	*start=temp->nextPtr;
	printf("Value successfully dequed\n");
	free(temp);
	}
	else{
		printf("List is empty\n");
	}
}
void dequeue_f(ptr_stack_f *start){
	ptr_stack_f temp;
	temp=malloc(sizeof(stackf));
	temp=*start;
	if(temp!=NULL){
	*start=temp->nextPtr;
	printf("Value successfully dequed\n");
	free(temp);
	}
	else{
		printf("List is empty\n");
	}
}
void dequeue_c(ptr_stack_c *start){
	ptr_stack_c temp;
	temp=malloc(sizeof(stackc));
	temp=*start;
	if(temp!=NULL){
	*start=temp->nextPtr;
	printf("Value successfully dequed\n");
	free(temp);
	}
	else{
		printf("List is empty\n");
	}
}
void dequeue_s(ptr_stack_s *start){
	ptr_stack_s temp;
	temp=malloc(sizeof(stacks));
	temp=*start;
	if(temp!=NULL){
	*start=temp->nextPtr;
	printf("Value successfully dequed\n");
	free(temp);
	}
	else{
		printf("List is empty\n");
	}
}

void enqueue_f(ptr_stack_f *start,ptr_stack_f *end, float value){
	ptr_stack_f temp,cur;
	temp=malloc(sizeof(stackf));
	temp->value=value;
	temp->nextPtr=NULL;
	cur=*start;
	if(*start==NULL){
		*start=temp;
		*end=temp;
		print_ds_f(*start);
	}
	else{
		while(cur->nextPtr!=NULL){
			cur=cur->nextPtr;
		}
		cur->nextPtr=temp;
		*end=temp;
		print_ds_f(*start);
	}
}		
void enqueue_d(ptr_stack_d *start,ptr_stack_d *end, double value){
	ptr_stack_d temp,cur;
	temp=malloc(sizeof(stackd));
	temp->value=value;
	temp->nextPtr=NULL;
	cur=*start;
	if(*start==NULL){
		*start=temp;
		*end=temp;
		print_ds_d(*start);
	}
	else{
		while(cur->nextPtr!=NULL){
			cur=cur->nextPtr;
		}
		cur->nextPtr=temp;
		*end=temp;
		print_ds_d(*start);
	}
}
void enqueue_c(ptr_stack_c *start,ptr_stack_c *end, char value){
	ptr_stack_c temp,cur;
	temp=malloc(sizeof(stackc));
	temp->value=value;
	temp->nextPtr=NULL;
	cur=*start;
	if(*start==NULL){
		*start=temp;
		*end=temp;
		print_ds_c(*start);
	}
	else{
		while(cur->nextPtr!=NULL){
			cur=cur->nextPtr;
		}
		cur->nextPtr=temp;
		*end=temp;
		print_ds_c(*start);
	}
}			
void enqueue_s(ptr_stack_s *start,ptr_stack_s *end, char value[]){
	ptr_stack_s temp,cur;
	temp=malloc(sizeof(stacks));
	int len=strlen(value);
	int i;
	for(i=0;i<=len;i++){
		temp->value[i]=value[i];
	}
	temp->nextPtr=NULL;
	cur=*start;
	if(*start==NULL){
		*start=temp;
		*end=temp;
		print_ds_s(*start);
	}
	else{
		while(cur->nextPtr!=NULL){
			cur=cur->nextPtr;
		}
		cur->nextPtr=temp;
		*end=temp;
		print_ds_s(*start);
	}
}	
void push_i(ptr_stack_i *pushPtr, int value){ //stdlib.h, stack_i()
	ptr_stack_i temp;
	temp=malloc(sizeof(stacki));
	temp->value=value;
	temp->nextPtr=*pushPtr;
	*pushPtr=temp;
	print_ds_i(*pushPtr);
}	
void push_s(ptr_stack_s *pushPtr, char value[]){ //stdlib.h, stack_s()
	ptr_stack_s temp;
	temp=malloc(sizeof(stacks));
	int len=strlen(value);
	int i;
	for(i=0;i<=len;i++){
		temp->value[i]=value[i];
	}
	
	temp->nextPtr=*pushPtr;
	*pushPtr=temp;
	print_ds_s(*pushPtr);
}

void push(ptr_stack_c *sptr,char data){ 
	ptr_stack_c temp;
	temp=malloc(sizeof(stackc));
	temp->value=data;
	temp->nextPtr=*sptr;
	*sptr=temp;
}
char pop_return(ptr_stack_c *sptr){ 
	char data=(*sptr)->value;
	*sptr=(*sptr)->nextPtr;
	return data;
}					
void post_exp(char exp[]){ // post_structure(), string.h, ctype.h, stdlib.h
	ptr_stack_c head=malloc(sizeof(stackc));
	head->value='(';
	head->nextPtr=NULL;
	ptr_stack_c *sptr=&head;
	char operator[7]={'%','/','*','+','-','^','\0'};
	int i=0;
	int k,j;
	while(exp[i]!='\0'){
		i++;
	}
	exp[i]=')';
	exp[i+1]='\0';
	int len=strlen(exp);
	char post[len];
	for(i=0;i<len;i++){
		post[i]='\0';
	}
	char last='\0';
	for(i=0;i<len;i++){
		if(exp[i]==')'){
			if(exp[i+1]=='%'||exp[i+1]=='^'||exp[i+1]=='/'||exp[i+1]=='*'||exp[i+1]=='+'||exp[i+1]=='-'){
				if(exp[i+2]=='('){
					last=exp[i+1];
					exp[i+1]='(';
					break;
				}
			}
		}
	}
	for(i=0;i<len;i++){
		if(exp[i]=='('){
			if((*sptr)->value!='%'&&(*sptr)->value!='/'&&(*sptr)->value!='*'&&(*sptr)->value!='+'&&(*sptr)->value!='-'&&(*sptr)->value!='^'){
				push(&head,'(');
			}
		}
		else if(isalnum(exp[i])){
			j=0;
			while(post[j]!='\0'){
				j++;
			}
			post[j]=exp[i];
		}
		else if(exp[i]=='%'||exp[i]=='/'||exp[i]=='*'||exp[i]=='+'||exp[i]=='-'||exp[i]=='^'){
			if((*sptr)->value!='('){
				int op1,op2;
				for(k=0;k<strlen(operator);k++){
					if(operator[k]==exp[i]){
						op1=k;
					}
					if(operator[k]==(*sptr)->value){
						op2=k;
					}
				}
				if(op1>=op2){
					j=0;
					while(post[j]!='\0'){
						j++;
					}
					post[j]=pop_return(&head);
					push(&head,exp[i]);
				}
				else{
					push(&head,exp[i]);
				}
			}
			else{
				push(&head,exp[i]);
			}
		}
		else if(exp[i]==')'){
			int jump=0;
			for(k=i;k<len;k++){
				if(isalnum(exp[k])){
					jump=1;
				}
			}
			if(jump==0){
			while((*sptr)->value!='('){
				j=0;
				while(post[j]!='\0'){
					j++;
				}
				post[j]=pop_return(&head);
			}
			}
			else if(jump==1){
				j=0;
				while(post[j]!='\0'){
					j++;
				}
				post[j]=pop_return(&head);
			}
		}
	}
	printf("The Postfix expression is:\n");
	for(i=0;i<strlen(post);i++){
		printf("%c",post[i]);
	}
	printf("%c",last);
	printf("\n");
}
void push_post(ptr_stack_d *sptr, double data){
	ptr_stack_d temp;
	temp=malloc(sizeof(stackd));
	temp->value=data;
	temp->nextPtr=*sptr;
	*sptr=temp;
}
double pop_red(ptr_stack_d *sptr){
	double data=(*sptr)->value;
	*sptr=(*sptr)->nextPtr;
	return data;
}
void post_evaluate(char post[]){ //string.h, ctype.h, math.h, stdlib.h, post_structure(), numbers in the char array should be separated by space
	ptr_stack_d head=NULL;
	char num[6]={'\0'};
	int i;
	int n = strlen(post);
	post[n]=' ';
	post[n+1]='\0';
	double num1,num2;
	num1=0;
	num2=0;
	int j=0;
	for(i=0;i<strlen(post);i++){
if(!isspace(post[i])){
			num[j]=post[i];
			j++;
		}
		else{
			j=0;
			if(num[j]=='/'||num[j]=='^'||num[j]=='%'||num[j]=='*'||num[j]=='+'||num[j]=='-'){
				num1 = pop_red(&head);
				num2 = pop_red(&head);
				if(num[j]=='/'&&num2!=0){
					push_post(&head,num2/num1);
				}
				else if(num[j]=='^'){
					push_post(&head,pow(num2,num1));
				}
				else if(num[j]=='%'){
					double temp =((int)(num2)%(int)(num1));
					push_post(&head,temp);
				}
				else if(num[j]=='*'){
					push_post(&head,num1*num2);
				}
				else if(num[j]=='+'){
					push_post(&head,num1+num2);
				}
				else if(num[j]=='-'){
					push_post(&head,num2-num1);
				}
			}
			else{
				num1 = atof(num);
				push_post(&head,num1);
			}
		}
	}
	printf("The solution of the postfix is\n");
	printf("%.2lf\n",pop_red(&head));
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
void merge_i(int arr[], int len){	
	mergeSort(arr,0,len-1);
}
void sortSubArray_f(float arr[], int start, int end){
	int i;
	int j;
	int mid1, mid2;
	float temp;
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
			float tarr[mid1-start];
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
void mergeSort_f(float arr[], int start, int end){
	int mid=(start+end)/2;
	if(end>=start+2){
		mergeSort_f(arr,start,mid);
		mergeSort_f(arr,mid+1,end);
	}
	if(start!=end){
		sortSubArray_f(arr,start,end);
	}
}
void merge_f(float arr[], int len){	
	mergeSort_f(arr,0,len-1);
}
void sortSubArray_d(double arr[], int start, int end){
	int i;
	int j;
	int mid1, mid2;
	double temp;
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
			double tarr[mid1-start];
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
void mergeSort_d(double arr[], int start, int end){
	int mid=(start+end)/2;
	if(end>=start+2){
		mergeSort_d(arr,start,mid);
		mergeSort_d(arr,mid+1,end);
	}
	if(start!=end){
		sortSubArray_d(arr,start,end);
	}
}
void merge_d(double arr[], int len){	
	mergeSort_d(arr,0,len-1);
}	
void call_tree_print_i(int h, ptr_tree_i root){ //tree_i, math.h, stdlib.h
	int i,j,k;
	int r=h+1;
	int c=(int)(pow(2,h));
	int arr[h+1][(int)(pow(2,h))];
	int arr_space[r][c];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			arr[i][j]=0;
			arr_space[i][j]=0;
		}
	}
	int space = 0;
	void inorder(ptr_tree_i root){
		if(root!=NULL){
			inorder(root->leftPtr);
			int k;
			for(k=0;k<c;k++){
				if(arr[root->num][k]==0){
					arr[root->num][k]=root->value;
					break;
				}
			}
			space = space + 1;
			arr_space[root->num][k]=space;
			inorder(root->rightPtr);
		}
	}
	inorder(root);
	int pre;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(arr[i][j]!=0){
				if(j==0){
					for(k=0;k<2*arr_space[i][j];k++){
					printf(" ");
					}
					pre=2*arr_space[i][j]+2;
				}
				else{
					for(k=0;k<(2*arr_space[i][j])-pre;k++){
					printf(" ");
					}
					pre=2*arr_space[i][j]+2;
				}
				printf("%d",arr[i][j]);
			}
		}
		printf("\n\n");
		pre=0;
	}		
}
void tree_print_i(){
	call_tree_print_i(H,ROOT_I);
}
void height(){ //tree_?(), stdlib.h
	printf("Height of the tree is: %d\n",H);
}
void call_tree_print_f(int h, ptr_tree_f root){ //tree_i, math.h, stdlib.h
	int i,j,k;
	int r=h+1;
	int c=(int)(pow(2,h));
	float arr[h+1][(int)(pow(2,h))];
	int arr_space[r][c];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			arr[i][j]=0;
			arr_space[i][j]=0;
		}
	}
	int space = 0;
	void inorder(ptr_tree_f root){
		if(root!=NULL){
			inorder(root->leftPtr);
			int k;
			for(k=0;k<c;k++){
				if(arr[root->num][k]==0){
					arr[root->num][k]=root->value;
					break;
				}
			}
			space = space + 1;
			arr_space[root->num][k]=space;
			inorder(root->rightPtr);
		}
	}
	inorder(root);
	int pre;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(arr[i][j]!=0){
				if(j==0){
					for(k=0;k<2*arr_space[i][j];k++){
					printf(" ");
					}
					pre=2*arr_space[i][j]+2;
				}
				else{
					for(k=0;k<(2*arr_space[i][j])-pre;k++){
					printf(" ");
					}
					pre=2*arr_space[i][j]+2;
				}
				printf("%-.2f",arr[i][j]);
			}
		}
		printf("\n\n");
		pre=0;
	}		
}
void tree_print_f(){
	call_tree_print_f(H,ROOT_F);
}
void call_tree_print_d(int h, ptr_tree_d root){ //tree_i, math.h, stdlib.h
	int i,j,k;
	int r=h+1;
	int c=(int)(pow(2,h));
	double arr[h+1][(int)(pow(2,h))];
	int arr_space[r][c];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			arr[i][j]=0;
			arr_space[i][j]=0;
		}
	}
	int space = 0;
	void inorder(ptr_tree_d root){
		if(root!=NULL){
			inorder(root->leftPtr);
			int k;
			for(k=0;k<c;k++){
				if(arr[root->num][k]==0){
					arr[root->num][k]=root->value;
					break;
				}
			}
			space = space + 1;
			arr_space[root->num][k]=space;
			inorder(root->rightPtr);
		}
	}
	inorder(root);
	int pre;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(arr[i][j]!=0){
				if(j==0){
					for(k=0;k<2*arr_space[i][j];k++){
					printf(" ");
					}
					pre=2*arr_space[i][j]+2;
				}
				else{
					for(k=0;k<(2*arr_space[i][j])-pre;k++){
					printf(" ");
					}
					pre=2*arr_space[i][j]+2;
				}
				printf("%-.2lf",arr[i][j]);
			}
		}
		printf("\n\n");
		pre=0;
	}		
}
void tree_print_d(){
	call_tree_print_d(H,ROOT_D);
}
void call_tree_print_c(int h, ptr_tree_c root){ //tree_i, math.h, stdlib.h
	int i,j,k;
	int r=h+1;
	int c=(int)(pow(2,h));
	char arr[h+1][(int)(pow(2,h))];
	int arr_space[r][c];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			arr[i][j]='0';
			arr_space[i][j]=0;
		}
	}
	int space = 0;
	void inorder(ptr_tree_c root){
		if(root!=NULL){
			inorder(root->leftPtr);
			int k;
			for(k=0;k<c;k++){
				if(arr[root->num][k]=='0'){
					arr[root->num][k]=root->value;
					break;
				}
			}
			space = space + 1;
			arr_space[root->num][k]=space;
			inorder(root->rightPtr);
		}
	}
	inorder(root);
	int pre;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(arr[i][j]!='0'){
				if(j==0){
					for(k=0;k<2*arr_space[i][j];k++){
					printf(" ");
					}
					pre=2*arr_space[i][j]+2;
				}
				else{
					for(k=0;k<(2*arr_space[i][j])-pre;k++){
					printf(" ");
					}
					pre=2*arr_space[i][j]+2;
				}
				printf("%c",arr[i][j]);
			}
		}
		printf("\n\n");
		pre=0;
	}		
}
void tree_print_c(){
	call_tree_print_c(H,ROOT_C);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
					
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		


	
	

	
	















			

				
		

