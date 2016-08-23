#include<stdio.h>
void main(){
	printf("This program will find the transpose, square or inverse of a given matrix\n");
	printf("Press 1 for finding transpose\nPress 2 for finding square\nPress 3 for finding inverse\n");
	int choice;
	scanf("%d",&choice);
	printf("Enter the rown in your matrix\n");
	int r;
	scanf("%d",&r);
	printf("Enter the columns in your matrix\n");
	int c;
	scanf("%d",&c);
	float mat[r][c];
	int i,j,k;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("Enter the value of [%d][%d]\n",i+1,j+1);
			scanf("%f",&mat[i][j]);
		}
	}
	printf("You entered the following matrix\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%2.1f",mat[i][j]);
		}
		printf("\n");
	}
	switch(choice){
		case 1:
		printf("The Transpose of the matrix is:\n");
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				printf("%2.1f",mat[j][i]);
			}
			printf("\n");
		}
		break;
		case 2:
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
				printf("%2.1f",mat2[i][j]);
			}
			printf("\n");
		}
	}
	else
	printf("Invalid entry\n");
		break;
		case 3:
		if(r==c){
		printf("Inverse of the matrix entered by you is:\n");
		if(r==2){
			printf("%2.1f",mat[1][1]);
			printf("-%2.1f\n",mat[0][1]);
			printf("-%2.1f",mat[1][0]);
			printf("%2.1f\n",mat[0][0]);
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
	break;
	default:
	printf("Wrong choice\n");
	break;
}
}



	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
					
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
