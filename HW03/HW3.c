#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



int getInt(int mini, int maxi){  /*Function that checks whether the received number is between the maximum and minimum value.*/
	int input_value;
	scanf("%d", &input_value);
	if(input_value < mini || input_value > maxi){
		printf("Please enter another value:");
		scanf("%d", &input_value);
	}
		
	return input_value;
}

int numberGeneratorBetweenRange(int min, int max){ /* Function that generates random number between maximum and minimum value.*/
	int random;
	
	random = min + rand()%(max-min+1);
	return random;	    
}
void countOccurrence(){  
	int bigNumber, searchNumber, digit_big = 0, digit_src = 0, count = 0, temp;
	int mod, step = 0;
	printf("Big Number:");
	scanf("%d", &bigNumber);
	printf("Search Number:");
	scanf("%d", &searchNumber);	
    
    temp = bigNumber; /*loop that computes the number of digits of big number.*/
    while(temp > 0){
    	digit_big++;
		temp /= 10;
	}
	
	temp = searchNumber; /*loop that computes the number of digits of search number.*/
    while(temp > 0){
    	digit_src++;
		temp /= 10;
	}
	
	while(bigNumber >= searchNumber){  /*The resulting loop.*/
		mod = pow(10, digit_big - digit_src - step);
		if( bigNumber/mod == searchNumber)
		{
			count++;
		}
		mod = pow(10, digit_big - 1 - step);
		bigNumber = bigNumber - ((bigNumber/mod) * mod);
		if( bigNumber == searchNumber ){
			count++;
			break;
		}
		step++;
	}
		
    printf("Occurence: %d\n", count);
}

void triangleOfSequences(){ /*Function that generates triangles with numbers.*/
	int random2,i,j,multip=0; 
	random2=numberGeneratorBetweenRange(2, 10);
  	for(i=1; i<=random2; i++){ 
	    	for(j=1; j<=i; j++){ 
	        	multip = i*j;
			printf("%d ", multip);       	
	   	 } 
     	printf("\n"); 
  	}
}


void horseRacingGame(){ /* The function that shows the horse race.*/
	int horse, horse_num, i, k, unit, loser = 20, win = 0, winner = 0, our;
	horse = numberGeneratorBetweenRange(3,5);
	printf("Number of Horse: %d\n", horse);
	printf("Horse Number: "); 
	horse_num = getInt(1, horse);
	printf("Racing Starts..\n");
	
	for(i = 1; i <= horse; i++){ /*The loop that determines the winner according to randomly generated times.*/
		unit = numberGeneratorBetweenRange(10,20);
		printf("Horse %d:", i);
		for(k = 1; k <= unit; k++){
			printf("-");
		}
		printf("\n");
		
		if( unit < loser ){
			loser = unit;
			winner = i;
		}
		
		if(i == horse_num)
			our = unit;
	}
	
	if(our <= loser){
		winner = horse_num;
		win = 1;
	}	
									
	if(win)
		printf("You win! Winner is Horse %d\n", winner);
	else
		printf("You lose! Winner is Horse %d\n", winner);
}

void menu(){ /* The function that showing menu. */
	int selection;
		
	do{
		printf("1. Horse Racing Game \n");
		printf("2. Occurrence Counter \n");
		printf("3. Triangle of Sequences \n");
		printf("0. Exit \n\n");
		printf("Please select an option:");
		scanf("%d", &selection);
		
		switch(selection){
			case 1: 
				horseRacingGame();
				break;
			case 2:
				countOccurrence();
				break;
			case 3:
				triangleOfSequences();
				break;
			case 0:
				break;
	
		}
	}
	
	while(selection != 0);
} 

int main(){ /*Main function that calls functions and displays the result.*/
	srand(time(NULL));
	menu();
	return 0;
}
