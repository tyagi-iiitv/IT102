#include<stdio.h>
typedef struct card{
	unsigned face: 4;//store values from 0-15 i.e. 2^4-1.
	unsigned :0;
	unsigned suit: 2;//store values from 0-3.
	unsigned :0;
	unsigned color:1;//store either 0 or 1.
}acard;
void filldeck(acard wdeck[]);
void deal(acard wdeck[]);
void main(){
	acard deck[52];
	filldeck(deck);
	deal(deck);
}
void filldeck(acard wdeck[]){
	int i;
	for(i=0;i<52;i++){
		wdeck[i].face=i%13;
		wdeck[i].suit=i/13;
		wdeck[i].color=i/26;
	}
}

void deal(acard wdeck[]){
	int k1,k2;
	for(k1=0,k2=k1+26;k1<26;k1++,k2++){
		printf("Card:%3d, Suit:%2d, Color:%2d\t",wdeck[k1].face,wdeck[k1].suit,wdeck[k1].color);
		printf("Card:%3d, Suit:%2d, Color:%2d\n ",wdeck[k2].face,wdeck[k2].suit,wdeck[k2].color);
	}
}	

