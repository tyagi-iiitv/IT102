#include<stdio.h>
int forward(int a, int b, int arr[a][b], int i, int j);
void main(){
	/*-----------------------------------------------------------------------------*/
	//Entering of values and storing them in an array
	printf("Enter the expression in form of 1's and zeroes\n");
	printf("Say you have to enter ABCD: then enter 1111 and so on\n");
	printf("Fine: To begin with, tell me how many bits are  consumed by each of your value\n");
	printf("i.e.if your expression is ABCD+BCD'A and so on....then enter 4 as the input\n");
	int bit;
	scanf("%d",&bit);
	printf("Thank you so much: You are just there\n");
	printf("Just tell me how many child expression your total expression contains\n");
	printf("That is in above case: The expression contained 2 child expressions of 4 bit each\n");
	int num;
	scanf("%d",&num);
	int len=bit*num;
	int arr[len];//Array in which original entries are stored
	char arr2[bit];//For printing ABCD type result entries
	int first[len];//For storing values varying with one bit in first level 
	int x1[len];//For storing 00X1 type values in first level result with replacing X by 2m  
	char arr1[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	printf("WARNING! You each child expression should contain exactly %d bits\n",bit);
	int count = 0;
	int i,j;
	while(count < len){
		printf("Enter your expression in form of 0 and 1\n");
		for(i=count;i<count+bit;i++){
			scanf("%d",&arr[i]);
			if(arr[i]==1){
				if(i<bit){
					arr2[i]=arr1[i];
				}
				else{
					arr2[(i)%bit]=arr1[(i)%bit];
				}
			}
			else if(arr[i]==0){
				if(i<bit){
					arr2[i]='!';
				}
				else{
					arr2[(i)%bit]='!';
				}
			}	
		}
		count = count+bit;
		printf("You entered\n");
		for(i=0;i<bit;i++){
			if(arr2[i]!='!')
			printf("%c",arr2[i]);
			else
			printf("%c'",arr1[(i)%bit]);
		}
		printf("\n");
	}
	/*------------------------------------------------------------------------------------*/
	//By the above method, I've already selected all the minterms of the first step (*Tested OK)
	/*------------------------------------------------------------------------------------*/
	//Starting the first level
	/*-------------------------------------------------------------------*/
	//creating the change matrix
	count = 0;
	int change[num][num];
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
		change[i][j]=0;
		}
	}
	int k,l;
	l=0;
	int countj=0;
	while(count<len){
		for(i=count;i<count+bit;i++){
			countj=l+1;
			for(j=bit+i;j<len;j=j+bit){
				if(arr[i]!=arr[j]){
				change[l][countj]=change[l][countj]+1;
				}
				countj++;
			}
		}
		l++;
		count = count+bit;
	}
	//Ending creation of the change matrix (*Tested OK)
	/*-----------------------------------------------------------*/
	//Entering 00X1 type data into x1[len]
	/*-----------------------------------------------------------*/
	int pos=0;
	for(i=0;i<len;i++){
		x1[i]=3;
	}//Initialising array so that no garbage value creeps in if some places are left unused		
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			if(change[i][j]==1){
				for(k=(i*bit),l=(j*bit);k<(i*bit)+bit,l<(j*bit)+bit;k++,l++){
					if(arr[k]==arr[l]){
						x1[pos]=arr[k];
					}
					else{
					x1[pos]=2;//2 used in place of X
					}
					pos++;
				}
			}
		}
	}
	//Initialising of x1[len] is complete (*Tested OK)
	/*-----------------------------------------------------------------------*/
	//now we have to store the unused values for later calculations
	/*------------------------------------------------------------------------*/
	count = 0;
	pos=0;
	int store[len];
	for(i=0;i<len;i++){
		store[i]=3;
	}//Initialising array so that no garbage value creeps in if some places are left unused	
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			if(change[i][j]==1||change[j][i]==1){
				count = 1;
			}
		}
		if(count == 0){
			for(k=i*bit;k<(i*bit)+bit;k++){
				store[pos]=arr[k];
				pos++;
			}
		}
			count=0;
	}
	/*-----------------------------------------------------------------------------------------*/
	//Stored the unused value(*Tested OK)
	/*--------------------------------------------------------------------------------------------*/
	//Writing the XX01 type of data into x2[len] by using change matrix again
	int len2;
	count = 0;
	for(i=0;i<len;i++){
		if(x1[i]==3){
		len2 = i;
		break;
		}
	}
	int x2[len2];
	int change2[len2/bit][len2/bit];
	for(i=0;i<len2/bit;i++){
		for(j=0;j<len2/bit;j++){
		change2[i][j]=0;
		}
	}
	l=0;
	countj=0;
	while(count<len2){
		for(i=count;i<count+bit;i++){
			countj=l+1;
			for(j=bit+i;j<len2;j=j+bit){
				if(x1[i]!=x1[j]){
				change2[l][countj]=change2[l][countj]+1;
				}
				countj++;
			}
		}
		l++;
		count = count+bit;
	}
	/*---------------------------------------------------------------------*/
	//change2 matrix initialized(*Tested OK)
	/*------------------------------------------------------------------------*/
	//Entering 0XX1 type data into x2[len]
	/*-----------------------------------------------------------*/
	pos=0;
	for(i=0;i<len2;i++){
		x2[i]=3;
	}//Initialising array so that no garbage value creeps in if some places are left unused		
	for(i=0;i<len2/bit;i++){
		for(j=0;j<len2/bit;j++){
			if(change2[i][j]==1){
				for(k=(i*bit),l=(j*bit);k<(i*bit)+bit,l<(j*bit)+bit;k++,l++){
					if(x1[k]==x1[l]){
						x2[pos]=x1[k];
					}
					else{
					x2[pos]=2;//2 used in place of X
					}
					pos++;
				}
			}
		}
	}
	/*-------------------------------------------------------------------*/
	//Initialisation of x2[len2] completed
	/*-------------------------------------------------------------------*/
	//Now we have to store the unused values into store[len]
	for(i=0;i<len;i++){
		if(store[i]==3){
			pos=i;
			break;
		}
	}
	count = 0;
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			if(change2[i][j]==1||change2[j][i]==1){
				count = 1;
			}
		}
		if(count == 0){
			for(k=i*bit;k<(i*bit)+bit;k++){
				store[pos]=x1[k];
				pos++;
			}
		}
			count=0;
	}
	/*------------------------------------------------*/
	//Store Initialised(*Tested OK)
	/*---------------------------------------------------*/
	int final[len];
	for(i=0;i<len;i++){
		final[i]=3;
	}
	pos=0;
	for(i=0;i<len2;i++){
		if(x2[i]!=3){
			final[i]=x2[i];
		}
		else{
			pos=i;
			break;
		}
	}
	for(i=0;i<len;i++){
		if(store[i]!=3){
			final[pos]=store[i];
			pos++;
		}
		else{
			break;
		}
	}
	/*-------------------------------------------------------------*/
	//Initialisation of final[len] is completed(*Tested OK)
	/*-------------------------------------------------------------*/
	int len3;
	count=0;
	for(i=0;i<len;i++){
		if(final[i]==3){
			len3 = i;
			break;
		}
	}
	int result[len3/bit][num];
	for(i=0;i<len3/bit;i++){
		for(j=0;j<num;j++){
			result[i][j]=0;
		}
	}
	for(i=0;i<len3/bit;i++){
		for(j=0;j<num;j++){
			for(k=i*bit,l=j*bit;k<(i*bit)+bit,l<(j*bit)+bit;k++,l++){
				if(final[k]!=arr[l]&&final[k]<=1){
					count = 1;
				}
			}
			if(count==0){
				result[i][j]=1;
			}
			count = 0;
		}
	}
	/*--------------------------------------------------------*/
	//result matrix initialised successfully(*Tested OK)
	/*-----------------------------------------------------------*/
	//Calculating the result
	count = 0;
	for(i=0;i<len3/bit;i++){
		for(j=0;j<num;j++){
			if(result[i][j]==1){
				for(k=0;k<len3/bit;k++){
					if(i!=k&&result[i][j]==result[k][j]){
						count = forward(len3/bit,num,result,i,j);
					}
					else
					count = 0;
				}
			}
		}
		if(count!=0){
			for(j=0;j<num;j++){
				result[i][j]=0;
			}
		}
	}
								
	for(i=0;i<len3/bit;i++){
		for(j=0;j<num;j++){
			printf("%d",result[i][j]);
		}printf("\n");
	}
}
int forward(int a, int b, int arr[a][b],  int i, int j){
	int ans=0;
	int k,l;
	int end;
	for(k=0;k<b;k++){
		if(arr[i][k]==1)
		end = k;
	}
	for(k=j;k<b;k++){
		if(arr[i][k]==1){
			for(l=0;l<a;l++){
				if(i!=l&&arr[i][k]==arr[l][k]){
					if(k==end){
						ans = 1;
					}
					else { 
						forward(a,b,arr,i,k);
					}
				}
			}
			if(ans==0){
				break;
			}
		}
	}
	return ans;
}
				
				
						
	
		
			

























































