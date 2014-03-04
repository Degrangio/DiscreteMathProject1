#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

struct player{
	int handvalue;
	int typevalue;
	int hand [5];
	char handc [5][20];
	int handnumeric[5];
};

typedef struct player poker_player;

int shuffledeck(int decktoshuffle[52]){
	int i, j, k, card1, card2;
	srand (time(NULL));
	k = 0;
	for(k;k<5000;k++){
		i = rand() % 52;
		j = rand() % 52;
		
		card1 = decktoshuffle[i];
		card2 = decktoshuffle[j];

		decktoshuffle[i] = card2;
		decktoshuffle[j] = card1;
	}
	return 0; 	
}

int dealhands(int shuffled_deck[52],int hand1[5], int hand2[5]){
	int i = 0;
	int offset = 0;

	for(i;i<5;i++){
		hand1[i] = shuffled_deck[i+offset];
		hand2[i] = shuffled_deck[i+offset+1];
		offset++;
	}
	return 0;
}

int convertinttocard(int hand[5], char handc[5][20]){
	int i;
	
	for(i;i<5;i++){

		switch(hand[i]){
			case 0:strcpy(handc[i], "2 of clubs");break;
			case 1:strcpy(handc[i], "3 of clubs");break;
			case 2:strcpy(handc[i], "4 of clubs");break;
			case 3:strcpy(handc[i], "5 of clubs");break;
			case 4:strcpy(handc[i], "6 of clubs");break;
			case 5:strcpy(handc[i], "7 of clubs");break;
			case 6:strcpy(handc[i], "8 of clubs");break;
			case 7:strcpy(handc[i], "9 of clubs");break;
			case 8:strcpy(handc[i], "10 of clubs");break;
			case 9:strcpy(handc[i], "Jack of clubs");break;
			case 10:strcpy(handc[i], "Queen of clubs");break;
			case 11:strcpy(handc[i], "King of clubs");break;
			case 12:strcpy(handc[i], "Ace of clubs");break;
	
			case 13:strcpy(handc[i], "2 of diamonds");break;
			case 14:strcpy(handc[i], "3 of diamonds");break;
			case 15:strcpy(handc[i], "4 of diamonds");break;
			case 16:strcpy(handc[i], "5 of diamonds");break;
			case 17:strcpy(handc[i], "6 of diamonds");break;
			case 18:strcpy(handc[i], "7 of diamonds");break;
			case 19:strcpy(handc[i], "8 of diamonds");break;
			case 20:strcpy(handc[i], "9 of diamonds");break;
			case 21:strcpy(handc[i], "10 of diamonds");break;
			case 22:strcpy(handc[i], "Jack of diamonds");break;
			case 23:strcpy(handc[i], "Queen of diamonds");break;
			case 24:strcpy(handc[i], "King of diamonds");break;
			case 25:strcpy(handc[i], "Ace of diamonds");break;

			case 26:strcpy(handc[i], "2 of Hearts");break;
			case 27:strcpy(handc[i], "3 of Hearts");break;
			case 28:strcpy(handc[i], "4 of Hearts");break;
			case 29:strcpy(handc[i], "5 of Hearts");break;
			case 30:strcpy(handc[i], "6 of Hearts");break;
			case 31:strcpy(handc[i], "7 of Hearts");break;
			case 32:strcpy(handc[i], "8 of Hearts");break;
			case 33:strcpy(handc[i], "9 of Hearts");break;
			case 34:strcpy(handc[i], "10 of Hearts");break;
			case 35:strcpy(handc[i], "Jack of Hearts");break;
			case 36:strcpy(handc[i], "Queen of Hearts");break;
			case 37:strcpy(handc[i], "King of Hearts");break;
			case 38:strcpy(handc[i], "Ace of Hearts");break;

			case 39:strcpy(handc[i], "2 of Spades");break;
			case 40:strcpy(handc[i], "3 of Spades");break;
			case 41:strcpy(handc[i], "4 of Spades");break;
			case 42:strcpy(handc[i], "5 of Spades");break;
			case 43:strcpy(handc[i], "6 of Spades");break;
			case 44:strcpy(handc[i], "7 of Spades");break;
			case 45:strcpy(handc[i], "8 of Spades");break;
			case 46:strcpy(handc[i], "9 of Spades");break;
			case 47:strcpy(handc[i], "10 of Spades");break;
			case 48:strcpy(handc[i], "Jack of Spades");break;
			case 49:strcpy(handc[i], "Queen of Spades");break;
			case 50:strcpy(handc[i], "King of Spades");break;
			case 51:strcpy(handc[i], "Ace of Spades");break;
		}
	}
	return 0;
}

//Evaluates if a hand is a flush returns a 0 if it is otherwise returns a -1 

int checkflush(int hand[5]){
	
	int i;
	int reference_i;
	int flushval;	
	double reference;
	
	reference = hand[0] / 13;
		
	reference_i = (int)reference;

	for(i = 1;i<5;i++){
		if(reference_i == 0){
			if(hand[i] >=0 && hand[i]< 13){
				flushval = 0;
			
			}else{
				flushval = -1;
				return flushval;
			}
		}
		
		if(reference_i == 1){
			if(hand[i] >=13 && hand[i] < 26){
				flushval = 0;
			
			}else{
				flushval = -1;
				return flushval;
			}
		}

		if(reference_i == 2){
			if(hand[i] >=26 && hand[i] < 39){
				flushval = 0;
			
			}else{
				flushval = -1;
				return flushval;
			}
		}
	
		if(reference_i == 3){
			if(hand[i] >=39 && hand[i] < 52){
				flushval = 0;
			
			}else{
				flushval = -1;
				return flushval;
			}
		}
	}
	return flushval;					
}	

int checkstraight(int handnumeric[5]){
	int sortedarray[5];
	int i,j;

	for(i=0;i<5;i++){
		sortedarray[i] = handnumeric[i];
		for(j = 1;j<5;j++){
			if(handnumeric[j] < handnumeric[i]){
				sortedarray[i] = handnumeric[i];
			}
		}
	}
	
	if((sortedarray[0]+4) != sortedarray[5]){
		return -1;
	}
	
	for(i=0;i<5;i++){
		if((sortedarray[i] +1) != sortedarray[i+1]){
			return -1;
		}
	}

	return 0;
}

int evaluatetype(int handtype, int hand[5],int handnumeric[5]){
	int isaflush;
	int isastraight;

	isaflush = checkflush(hand);
	isastraight = checkstraight(handnumeric);
	
	if(isaflush ==0 && isastraight ==0){
		handtype = 8;
		return 0;
	}	
}	
			
		
int main(){
	
	poker_player player_A, player_B;
	int i = 0;
	int deck[52];
	int adjuster;

	// Fill the deck with cards
	for(i;i<52;i++){
	deck[i]=i;
	}
	
	shuffledeck(deck);

	printf("The first 10 cards of the deck are \n");
	i = 0;
	for(i;i<10;i++){
		printf("%d \n",deck[i]);
	}

	dealhands(deck,player_A.hand,player_B.hand);
	
	for(i=0;i<5;i++){
		adjuster = player_A.hand[i]/13;
		player_A.handnumeric[i] = player_A.hand[i] - 13*adjuster;
	}
	
	for(i=0;i<5;i++){
		adjuster = player_B.hand[i]/13;
		player_B.handnumeric[i] = player_B.hand[i] - 13*adjuster;
	}

	printf("Player A's hand is:\n");
	i = 0;
	for(i;i<5;i++){
		printf("%d \n",player_A.hand[i]);
	}

	printf("Player B's hand is:\n");
	i = 0;
	for(i;i<5;i++){
		printf("%d \n",player_B.hand[i]);
	}	

	convertinttocard(player_A.hand,player_A.handc);

	printf("Player A's hand is:\n");
	i = 0;
	for(i;i<5;i++){
		printf("%s \n",player_A.handc[i]);
	}

	convertinttocard(player_B.hand,player_B.handc);

	printf("\n Player B's hand is:\n");
	i = 0;
	for(i;i<5;i++){
		printf("%s \n",player_B.handc[i]);
	}

	return 0;
}

