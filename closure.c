#include<stdio.h>
void main(){
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
	printf("The given matrix is\n");
	for(i=0;i<(num1+1);i++){
		for(j=0;j<(num1+1);j++){
			printf("%d",mat[i][j]);
		}printf("\n");
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
	printf("Generating transpose closure\n");
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
	printf("The reflexive closure matrix is:\n");
	for(i=0;i<(num1+1);i++){
		for(j=0;j<(num1+1);j++){
			if((i==0)&&(j==0))
				printf(" ");
			else
			printf("%d",matref[i][j]);
		}printf("\n");
	}
	printf("The symmetric closure is:\n");
	for(i=0;i<(num1+1);i++){
		for(j=0;j<(num1+1);j++){
			if((i==0)&&(j==0))
				printf(" ");
			else
			printf("%d",matsym[i][j]);
		}printf("\n");
	}
	printf("The transitive closure matrix is:\n");
	for(i=0;i<(num1+1);i++){
		for(j=0;j<(num1+1);j++){
			if((i==0)&&(j==0))
				printf(" ");
			else
			printf("%d",mattrans[i][j]);
		}printf("\n");
	}
	printf("The reflexive relation is:\n");
	printf("{(");
	for(i=1;i<num1+1;i++){
		for(j=1;j<num1+1;j++){
			if(matref[i][j] == 1){
				printf("%d,%d)",matref[i][0],matref[0][j]);
			}
		}
	}
	printf("}\n");
	printf("The symmetric relation is:\n");
	printf("{(");
	for(i=1;i<num1+1;i++){
		for(j=1;j<num1+1;j++){
			if(matsym[i][j] == 1){
				printf("%d,%d)",matref[i][0],matref[0][j]);
			}
		}
	}
	printf("}\n");
	printf("The tansitive relation is:\n");
	printf("{(");
	for(i=1;i<num1+1;i++){
		for(j=1;j<num1+1;j++){
			if(matref[i][j] == 1){
				printf("%d,%d)",mattrans[i][0],mattrans[0][j]);
			}
		}
	}
	printf("}\n");
}












