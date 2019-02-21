#include<stdio.h>
		
	int step_5(int step5, int temp, int step4, int step3, int step2, int step1){ /* Function to find all digits of a 5-digit numbers. */
		step5 = temp / 10000; /* Find the fifth digit. */
			
		temp = temp % 10000; /* Find the forth digit. */
		step4 = temp / 1000;
				
		temp = temp % 1000; /* Find the third digit. */
		step3 = temp / 100;
				
		temp = temp % 100; /* Find the second digit.. */
		step2 = temp / 10;
				
		temp = temp % 10; /* Find the first digit. */
		step1 = temp / 1;
			printf(" The fifth Digit is %d \n", step1); /* Print the digits on the screen. */
			printf(" The forth Digit is %d \n", step2);
			printf(" The third Digit is %d \n", step3);
			printf(" The second Digit is %d \n", step4);
			printf(" The first  Digit is %d \n", step5);
	}
	
	int step_4(int step4, int temp, int step3, int step2, int step1){ /* Function to find all digits of a 4-digit numbers. */
		step4 = temp / 1000; /* Find the forth digit. */
			
		temp = temp % 1000; /* Find the third digit. */
		step3 = temp / 100;
			
		temp = temp % 100; /* Find the second digit.. */
		step2 = temp / 10;
			
		temp = temp % 10; /* /* Find the first digit. */
		step1 = temp / 1;
			printf(" The forth Digit is %d \n", step1); /* Print the digits on the screen. */
			printf(" The third Digit is %d \n", step2);
			printf(" The second Digit is %d \n", step3);
			printf(" The first Digit is %d \n", step4);
	}
	
	int step_3(int step3, int temp, int step2, int step1){ /* Function to find all digits of a 3-digit numbers. */
		step3 = temp / 100;/* Find the third digit. */
			
		temp = temp % 100; /* Find the second digit.. */
		step2 = temp / 10;
			
		temp = temp % 10; /* Find the first digit. */
		step1 = temp / 1; 
			printf(" The third Digit is %d \n", step1); /* Print the digits on the screen. */
			printf(" The second Digit is %d \n", step2);
			printf(" The first Digit is %d \n", step3);
	}
	
	int step_2(int step2, int temp, int step1){ /* Function to find all digits of a 2-digit numbers. */
		step2 = temp / 10; /* Find the second digit.. */
			
		temp = temp % 10; /* Find the first digit. */
		step1 = temp / 1;
			printf(" The second Digit is %d \n", step1); /* Print the digits on the screen. */	
			printf(" The first Digit is %d \n", step2);
	}

	int main(){ 
	int number;
	int step5, step4, step3, step2, step1, result, temp=0; /* Define integers. */
	printf("\n \n Enter a number:"); /* Get the number from the user. */
	scanf("%d", &number);
	if(number < 23 || number > 98760 ){
		printf("NOT IN RANGE \n");
	}
	
	else{
	temp=number; /* Assign another temp value to the number you give. */
	
		if(number>=10000 && number<98760){ /* If the number between 10000 and 98760 call step_5 function. */
			result = step_5(step5, temp, step4, step3, step2, step1);
		}
		if(number>=1000 && number<10000){ /*If the number between 1000 and 10000 call step_4 function. */
			result = step_4(step4, temp, step3, step2, step1);
		}
		if(number>=100 && number<1000){ /* If the number between 100 and 1000 call step_3 function.. */
			result = step_3(step3, temp, step2, step1);
		}
		if(number>=23 && number<100){ /* If the number between 23 and 100 call step_5 function. */
			result = step_2(step2, temp, step1);
		}
	
	
	}
	return 0;
}
