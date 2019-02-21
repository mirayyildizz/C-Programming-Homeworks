#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void lettergrade(int random){ /* Define a function that calculates letter grades. */
	if(random >= 90){ /* If the random number is greater than 90, give the 'A' letter note */
	 	printf("Letter Grade: A");
	}
	 
	else if(random >= 80 && random < 90){ /* Give an 'B' letter grade if the random number is between 80 and 90. */
		printf("Letter Grade: B");
	}
	
	else if(random >= 70 && random < 80){ /* Give an 'C' letter grade if the random number is between 70 and 80. */
		printf("Letter Grade: C");
	}
	
	else if(random >= 60 && random < 70){ /* Give an 'D' letter grade if the random number is between 60 and 70. */
	 	printf("Letter Grade: D");
	}
	 	
	else{
		printf("Letter Grade:F"); /* Give an  'F' if letter grade if the random number is less than 59. */
	} 
}

int main(){
	int number;  /* Define the required integers. */
	int i=0;
	int selection, random;
	double max=0, min=100, average=0, sum=0;
	int count1=0, count2=0, count3=0, count4=0, count5=0, index=0, indexmax=0, indexmin=0;
	int letter_grade=0;
	
	printf("Please enter number of students from keyboard between 3 and 50:");  /* Get a value between 3 and 50 for the user. */
	scanf("%d", &number);
	if(number < 3){  /* If the number is not between 3 and 50, indicate that it is not in range. */
		printf("Not in Range!\n");
		printf("Please enter number of students from keyboard between 3 and 50:"); /* Get a value between 3 and 50 for the user. */
		scanf("%d", &number);				
	}
	if(number > 50){
		printf("Not in Range!\n");
		printf("Please enter number of students from keyboard between 3 and 50:"); /* Get a value between 3 and 50 for the user. */
		scanf("%d", &number);
	}

	srand(40); 
 	for(i=1; i <= number; i++){  /* Get random numbers in the for loop. */
		random = rand()%101; 
 		printf(" %d ", random);
 		index++; /* Increase index. */
 	
 		if(random>=90){ /* Increase count1 if the random number is greater than 90. */
	 		count1++;
	 	}
	 	
		else if(random>=80 && random < 90){ /* Increase count2 if the random number is between 80 and 90. */
	 		count2++;
	 	}
	 	
	 	else if(random>=70 && random < 80){ /* Increase count3 if the random number is between 70 and 80. */
	 		count3++;
	 	}
	 	
	 	else if(random>=60 && random < 70){ /* Ýncrease count4 if the random number is between 60 and 70. */
	 		count4++;
	 	}
	 	
	 	else{ /* Ýncrease count5 if the random number is less than 59. */
	 		count5++;
	 	}
	 	
 		if(random > max){  /* If the random number is greater than the maximum value, the maximum number is equal to the random number. */
 			max = random;
			indexmax = index; /* indexmax equal to index. */	
	 	}
	 	
	 	if(random < min){ /* If the random number is less than the minimum value, the minimum number is equal to the random number. */
	 		min = random;
	 		indexmin = index; /* indexmin equal to index. */
	 	}	 	
	 
		sum = random + sum; /* Find the sum of random numbers. */
		average = sum / number; /* Find the average of random numbers. */
}

	while(selection!=-1){ /* If the selection is not -1, enter the loop. */
		printf("\n-------------------------------------------------------------------------------------------------------\n\n");
		printf(" \n Student Score Calculator Menu for %d Student\n", number); /* Print the menu on the screen. */
		printf("1-Most Successfull Student \n");
		printf("2-Most  Unsuccessfull Student \n");
		printf("3-Letter Grade Statistics \n");
		printf("4-Calculate Average \n");
		printf("5-Show all Data \n");
		printf("                                                       Make selection: "); /*Get an selection from the user. */
		scanf("%d", &selection);
		
		switch(selection){
	 	case 1:
	 		printf("Most Successfull Student: \n"); /* If you select case1, find the maximum number, index, and letter grade */
	 		printf("Score: %lf \n", max);
	 		printf("Index: %d \n", indexmax);
	 		lettergrade(max);
	 		break;
	 		
	 	case 2:
		 	printf("Most Unseccesfull Student: \n"); /* If you select case2, find the minimum number, index, and letter grade */
		 	printf("Score: %lf \n", min);
			printf("Index: %d \n", indexmin);
			lettergrade(min);
			break;
			
		case 3:
			printf("%d student got letter grade 'A' \n", count1); /* If you select case3, print out how many students have all the letter grades. */
			printf("%d student got letter grade 'B' \n", count2);
			printf("%d student got letter grade 'C' \n", count3);
			printf("%d student got letter grade 'D' \n", count4);
			printf("%d student got letter grade 'F' \n\n\n\n", count5);
			break;
			
		case 4:
			printf("The average score of %d student: %lf \n\n\n", number, average); /* if you select case4, calculate the average of grades. */
			break;	
			
		case 5:
			printf("Most Successfull Student: \n"); /* If you select option 5, show all results. */
	 		printf("Score: %lf \n", max);
	 		printf("Index: %d \n", indexmax);
	 		lettergrade(max);
	 		printf(" \nMost Unseccesfull Student: \n");
			printf("Score: %lf \n", min);
			printf("Index: %d \n", indexmin);
			lettergrade(min);
	 		printf(" \n\n%d student got letter grade 'A' \n", count1);
			printf("%d student got letter grade 'B' \n", count2);
			printf("%d student got letter grade 'C' \n", count3);
			printf("%d student got letter grade 'D' \n", count4);
			printf("%d student got letter grade 'F' \n\n\n", count5);
			printf("The average score of %d student: %lf \n\n\n", number, average);
			break;
		default: 
			printf("False selection!!");			 	
		} 	
	}

	return 0;
}

