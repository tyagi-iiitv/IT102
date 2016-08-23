#include<stdio.h>
void main(){
	printf("Enter the order of the matrix you want to enter\n");
	int len;
	scanf("%d", &len);
	int arr[len][len];
	int i, j;
	for(i=0; i<len; i++){
		for(j=0; j<len; j++){
		printf("Enter the [%d][%d] element\n", (i+1), (j+1));
		scanf("%d", &arr[i][j]);
		}
	}
	printf("Your entered matrix is\n");
	for(i=0; i<len; i++){
		for(j=0; j<len; j++){
		printf("%d", arr[i][j]);
		}
	printf("\n");
	}
	int ref = 0;
	for(i=0; i<len; i++){
		for(j=0; j<len; j++){
		if( i=j){
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
	for( i=0; i<len; i++){
		for( j=0; j<len; j++){
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
	for( i=0; i<len; i++){
		for( j=0;j<len; j++){ 
			if( arr[i][j] == 1){
				for(k=0; k<len; k++){
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
