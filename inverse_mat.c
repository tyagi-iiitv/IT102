#include<stdio.h>
void main(){
	printf("To find the inverse of a 3*3 matrix\n");
	float arr[3][3];
	float adj[3][3];
	float adj2[3][3];
	float inv[3][3];
	int i,j,k,l,m,n,o,p;
	float a,b,c,d;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("Enter the value of [%d][%d] element\n",i+1,j+1);
			scanf("%f",&arr[i][j]);
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			int jump1 = 0;
			int jump2 = 0;
			int jump3 = 0;
			for(k=0;k<3;k++){
				for(l=0;l<3;l++){
					if((k!=i)&&(l!=j)&&(jump1 == 0)){
						a = arr[k][l];
						jump1 = 1;
						for(m=0;m<3;m++){
							for(n=0;n<3;n++){
								if((m!=k)&&(n!=l)&&(jump2 == 0)&&(m!=i)&&(n!=j)){
									b = arr[m][n];
									jump2 = 1;
								}
								else if((m==k)&&(n!=l)&&(jump2 == 0)&&(m!=i)&&(n!=j)){
									c = arr[m][n];
									for(o=0;o<3;o++){
										for(p=0;p<3;p++){
											if((o!=m)&&(o!=i)&&(p!=n)&&(p!=j)&&(jump3 == 0)){
												d = arr[o][p];
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
	float	det = (arr[0][0]*adj[0][0])+(arr[0][1]*adj[0][1])+(arr[0][2]*adj[0][2]);
	printf("You entered the matrix:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%.2f\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("The inverse of the matrix is:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			inv[i][j] = adj2[i][j]/det;
			printf("%.2f\t",inv[i][j]);
		}
		printf("\n");
	}
}


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
					
