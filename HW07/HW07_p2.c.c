#include <stdio.h>

int leap(int year){ /*Function that finds the leap year. */
	if( year % 4 == 0 ) /* If year%4==0, it is leap year.*/
        return 1;
    return 0;
}

int find_day_limit(int year, int month){  /*The function that returns the number of days in different months.*/
    if( month < 9 ){
        if( month%2 == 1 || month == 8 )
            return 31;
        else if( month == 2 ){
            if( leap(year) ){
                return 29;
            }
            return 28;
        }
        else
            return 30;
    }
    else{
        if( month%2 == 1 )
            return 30;
        else
            return 31;
    }
}
void date(){ /* Function that prints dates to terminal and file.*/
    	FILE *f; 
    	f = fopen("input_date.txt", "w");
	int day1, day2, month1, month2, year1, year2;
	printf("Enter a first day:"); /*Enter a first date.*/ 
	scanf("%d", &day1);
	printf("Enter a first month:");
	scanf("%d", &month1);
	printf("Enter a first year:");
	scanf("%d", &year1);
	printf("Enter a end day:"); /*Enter a end date.*/
	scanf("%d", &day2);
	printf("Enter a end month:");
	scanf("%d", &month2);
	printf("Enter a end year:");
	scanf("%d", &year2);

	int year_counter, month_counter, day_counter;
    	int day_limit, month_limit = 12;

	for( year_counter = year1; year_counter <= year2; year_counter++){ /*Increase the year_counter according to the circumstance in the loop and conditions.*/
		if( year1 == year2 ){   
			month_counter = month1;
			month_limit = month2;
		}
		else if( year_counter == year1 ) 
			month_counter = month1;
        	else if( year_counter == year2 ){
            		month_limit = month2;
            		month_counter = 1;
        	}
        	else
            		month_counter = 1;
        
		for( ;month_counter <= month_limit;month_counter++){ /* İncrease the month_counter according to the circumstance in the loop and conditions.*/
            		day_limit = find_day_limit(year_counter, month_counter);
			if( year1 == year2 && month1 == month2  ){ 
               			day_limit = day2;
                		day_counter = day1;
            		}
           		else if( year_counter == year1 && month_counter == month1 )
                		day_counter = day1;
            		else if( year_counter == year2 && month_counter == month2 ){
               			day_limit = day2;
                		day_counter = 1;
            		}
            		else
                		day_counter = 1; 
            
			for( ; day_counter <= day_limit;day_counter++ ){ /* İncrease the day_counter according to the circumstance in the loop and conditions.*/
				if(day_counter>=10 && month_counter>=10){ /*Add zeros as per conditions to print dates correctly*/
               		 		fprintf(f, "%d/%d/%d\n", day_counter, month_counter, year_counter);
					printf("%d/%d/%d\n", day_counter, month_counter, year_counter);
				}
				if(day_counter<10 && month_counter<10){
					fprintf(f, "0%d/0%d/%d\n", day_counter, month_counter, year_counter);
					printf("0%d/0%d/%d\n", day_counter, month_counter, year_counter);
				}
				if(day_counter<10 && month_counter>=10){
					fprintf(f, "0%d/%d/%d\n", day_counter, month_counter, year_counter);
					printf("0%d/%d/%d\n", day_counter, month_counter, year_counter);
				}
				if(day_counter>=10 && month_counter<10){
					fprintf(f, "%d/0%d/%d\n", day_counter, month_counter, year_counter);
					printf("%d/0%d/%d\n", day_counter, month_counter, year_counter);
				}
            		}
        	}
	}
	fclose(f);
}


int find_day(int month1, int year1, int day1){ /*The function that finds out which day of the week is the first day entered.*/
	int end=0, first=0, f_day=0,x; 
	/* http://mathforum.org/dr.math/faq/faq.calendar.html */
	int month_new = month1 - 2, century, year_lasttwo; /*According to the given form on the map, synchronize the month numbers to the two missing numbers*/
	year_lasttwo = year1 % 100; /*Find the last two digits of the first year.*/
	century = year1 / 100; /*Find the first two digits of the first year.*/
	if(month_new  <= 0 ){ /*Since we have reduced the month by two, the January and February months have remained in the other year. So we wrote this for the condition.*/
		month_new += 12;
		year_lasttwo--;
	} 

	f_day = day1 + ((13*month_new - 1) / 5) +year_lasttwo + (year_lasttwo / 4) + (century / 4) -(2 * century); /* Formula for finding the day.*/

	if( f_day  < 0 ){ /*If the result is negative, add 7 to the positive return.*/
		while(f_day < 0 )
			f_day += 7;
	}
	
	return f_day%7; /*Get mod(for 7). Rotate result.*/
}


int find_months(int month1){ /*Function that returns month numbers.*/
	if(month1==1){
		return 1; }
	if(month1==2)
		return 2;
	if(month1==3)
		return 3;
	if(month1==4)
		return 4;
	if(month1==5)
		return 5;
	if(month1==6)
		return 6;
	if(month1==7)
		return 7;
	if(month1==8)
		return 8;
	if(month1==9)
		return 9;
	if(month1==10)
		return 10;
	if(month1==11)
		return 11;
	if(month1==12)
		return 12;
}
void print_date(){ /*Function that prints the dates clearly.*/
	FILE *f;
	f = fopen("input_date.txt", "r"); /* Open files.*/
	FILE *f1;	
	f1 = fopen("new_date.txt", "a");
	int day1,month1,year1,f_day,x,y;
	while(!feof(f)){ /*Take it in every line until the end of the file..*/
		fscanf(f,"%d/%d/%d\n",&day1,&month1,&year1); 
		x= find_months(month1); /* Call the finds_months function.*/
		y= find_day(month1,year1,day1); /* Call the find_day function.*/
		if(x==1 && y==0){ /*Print dates to file and terminal according to conditions.*/
			printf("%d January %d, Sunday\n", day1,year1); 
			fprintf(f1,"%d January %d Sunday\n", day1,year1);
		}
		if(x==1 && y==1){
			printf("%d January %d, Monday\n", day1,year1);
			fprintf(f1,"%d January %d Monday\n", day1,year1);
		}
		if(x==1 && y==2){
			printf("%d January %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d January %d Tuesday\n", day1,year1);
		}
		if(x==1 && y==3){
			printf("%d January %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d January %d Wednesday\n", day1,year1);
		}
		if(x==1 && y==4){
			printf("%d January %d, Thursday\n", day1,year1);
			fprintf(f1,"%d January %d Thursday\n", day1,year1);
		}
		if(x==1 && y==5){
			printf("%d January %d, Friday\n", day1,year1);
			fprintf(f1,"%d January %d Friday\n", day1,year1);
		}
		if(x==1 && y==6){
			printf("%d January %d, Saturday\n", day1,year1);
			fprintf(f1,"%d January %d Sunday\n", day1,year1);
		}
		if(x==2 && y==0){
			printf("%d February %d, Sunday\n", day1,year1);
			fprintf(f1,"%d February %d, Sunday\n", day1,year1);
		}
		if(x==2 && y==1){
			printf("%d February %d, Monday\n", day1,year1);
			fprintf(f1,"%d February %d, Monday\n", day1,year1);
		}
		if(x==2 && y==2){
			printf("%d February %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d February %d, Tuesday\n", day1,year1);
		}
		if(x==2 && y==3){
			printf("%d February %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d February %d, Wednesday\n", day1,year1);
		}
		if(x==2 && y==4){
			printf("%d February %d, Thursday\n", day1,year1);
			fprintf(f1,"%d February %d, Thursday\n", day1,year1);
		}
		if(x==2 && y==5){
			printf("%d February %d, Friday\n", day1,year1);
			fprintf(f1,"%d February %d, Friday\n", day1,year1);
		}
		if(x==2 && y==6){
			printf("%d February %d, Saturday\n", day1,year1);
			fprintf(f1,"%d February %d, Saturday\n", day1,year1);
		}
		if(x==3 && y==0){
			printf("%d March %d, Sunday\n", day1,year1);
			fprintf(f1,"%d March %d, Sunday\n", day1,year1);
		}
		if(x==3 && y==1){
			printf("%d March %d, Monday\n", day1,year1);
			fprintf(f1,"%d March %d, Monday\n", day1,year1);
		}
		if(x==3 && y==2){
			printf("%d March %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d March %d, Tuesday\n", day1,year1);
		}
		if(x==3 && y==3){
			printf("%d March %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d March %d, Wednesday\n", day1,year1);
		}
		if(x==3 && y==4){
			printf("%d March %d, Thursday\n", day1,year1);
			fprintf(f1,"%d March %d, Thursday\n", day1,year1);
		}
		if(x==3 && y==5){
			printf("%d March %d, Friday\n", day1,year1);
			fprintf(f1,"%d March %d, Friday\n", day1,year1);
		}
		if(x==3 && y==6){
			printf("%d March %d, Saturday\n", day1,year1);
			fprintf(f1,"%d March %d, Saturday\n", day1,year1);
		}
		if(x==4 && y==0){
			printf("%d April %d, Sunday\n", day1,year1);
			fprintf(f1,"%d April %d, Sunday\n", day1,year1);
		}
		if(x==4 && y==1){
			printf("%d April %d, Monday\n", day1,year1);
			fprintf(f1,"%d April %d, Monday\n", day1,year1);
		}	
		if(x==4 && y==2){
			printf("%d April %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d April %d, Tuesday\n", day1,year1);
		}
		if(x==4 && y==3){
			printf("%d April %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d April %d, Wednesday\n", day1,year1);
		}	
		if(x==4 && y==4){
			printf("%d April %d, Thursday\n", day1,year1);
			fprintf(f1,"%d April %d, Thursday\n", day1,year1);
		}
		if(x==4 && y==5){
			printf("%d April %d, Friday\n", day1,year1);
			fprintf(f1,"%d April %d, Friday\n", day1,year1);
		}
		if(x==4 && y==6){
			printf("%d April %d, Saturday\n", day1,year1);		
			fprintf(f1,"%d April %d, Saturday\n", day1,year1);	
		}
		if(x==5 && y==0){
			printf("%d May %d, Sunday\n", day1,year1);
			fprintf(f1,"%d May %d, Sunday\n", day1,year1);
		}
		if(x==5 && y==1){
			printf("%d May %d, Monday\n", day1,year1);
			fprintf(f1,"%d May %d, Monday\n", day1,year1);
		}
		if(x==5 && y==2){
			printf("%d May %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d May %d, Tuesday\n", day1,year1);
		}
		if(x==5 && y==3){
			printf("%d May %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d May %d, Wednesday\n", day1,year1);
		}
		if(x==5 && y==4){
			printf("%d May %d, Thursday\n", day1,year1);
			fprintf(f1,"%d May %d, Thursday\n", day1,year1);
		}
		if(x==5 && y==5){
			printf("%d May %d, Friday\n", day1,year1);
			fprintf(f1,"%d May %d, Friday\n", day1,year1);
		}	
		if(x==5 && y==6){
			printf("%d May %d, Saturday\n", day1,year1);
			fprintf(f1,"%d May %d, Saturday\n", day1,year1);
		}
		if(x==6 && y==0){
			printf("%d June %d, Sunday\n", day1,year1);
			fprintf(f1,"%d June %d, Sunday\n", day1,year1);
		}
		if(x==6 && y==1){
			printf("%d June %d, Monday\n", day1,year1);
			fprintf(f1,"%d June %d, Monday\n", day1,year1);
		}
		if(x==6 && y==2){
			printf("%d June %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d June %d, Tuesday\n", day1,year1);
		}
		if(x==6 && y==3){
			printf("%d June %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d June %d, Wednesday\n", day1,year1);
		}
		if(x==6 && y==4){
			printf("%d June %d, Thursday\n", day1,year1);
			fprintf(f1,"%d June %d, Thursday\n", day1,year1);
		}
		if(x==6 && y==5){
			printf("%d June %d, Friday\n", day1,year1);
			fprintf(f1,"%d June %d, Friday\n", day1,year1);
		}
		if(x==6 && y==6){
			printf("%d June %d, Saturday\n", day1,year1);
			fprintf(f1,"%d June %d, Saturday\n", day1,year1);
		}
		if(x==7 && y==0){
			printf("%d July %d, Sunday\n", day1,year1);
			fprintf(f1,"%d July %d, Sunday\n", day1,year1);
		}
		if(x==7 && y==1){
			printf("%d July %d, Monday\n", day1,year1);
			fprintf(f1,"%d July %d, Monday\n", day1,year1);
		}
		if(x==7 && y==2){
			printf("%d July %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d July %d, Tuesday\n", day1,year1);
		}
		if(x==7 && y==3){
			printf("%d July %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d July %d, Wednesday\n", day1,year1);
		}	
		if(x==7 && y==4){
			printf("%d July %d, Thursday\n", day1,year1);
			fprintf(f1,"%d July %d, Thursday\n", day1,year1);
		}
		if(x==7 && y==5){
			printf("%d July %d, Friday\n", day1,year1);
			fprintf(f1,"%d July %d, Friday\n", day1,year1);
		}
		if(x==7 && y==6){
			printf("%d July %d, Saturday\n", day1,year1);
			fprintf(f1,"%d July %d, Saturday\n", day1,year1);
		}
		if(x==8 && y==0){
			printf("%d August %d, Sunday\n", day1,year1);
			fprintf(f1,"%d August %d, Sunday\n", day1,year1);
		}
		if(x==8 && y==1){
			printf("%d August %d, Monday\n", day1,year1);
			fprintf(f1,"%d August %d, Monday\n", day1,year1);
		}
		if(x==8 && y==2){
			printf("%d August %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d August %d, Tuesday\n", day1,year1);
		}
		if(x==8 && y==3){
			printf("%d August %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d August %d, Wednesday\n", day1,year1);
		}
		if(x==8 && y==4){
			printf("%d August %d, Thursday\n", day1,year1);
			fprintf(f1,"%d August %d, Thursday\n", day1,year1);
		}
		if(x==8 && y==5){
			printf("%d August %d, Friday\n", day1,year1);
			fprintf(f1,"%d August %d, Friday\n", day1,year1);
		}
		if(x==8 && y==6){
			printf("%d August %d, Saturday\n", day1,year1);
			fprintf(f1,"%d August %d, Saturday\n", day1,year1);
		}	
		if(x==9 && y==0){
			printf("%d September %d, Sunday\n", day1,year1);
			fprintf(f1,"%d September %d, Sunday\n", day1,year1);
		}
		if(x==9 && y==1){
			printf("%d September %d, Monday\n", day1,year1);
			fprintf(f1,"%d September %d, Monday\n", day1,year1);
		}
		if(x==9 && y==2){
			printf("%d September %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d September %d, Tuesday\n", day1,year1);
		}
		if(x==9 && y==3){
			printf("%d September %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d September %d, Wednesday\n", day1,year1);
		}
		if(x==9 && y==4){
			printf("%d September %d, Thursday\n", day1,year1);
			fprintf(f1,"%d September %d, Thursday\n", day1,year1);
		}
		if(x==9 && y==5){
			printf("%d September %d, Friday\n", day1,year1);
			fprintf(f1,"%d September %d, Friday\n", day1,year1);
		}
		if(x==9 && y==6){
			printf("%d September %d, Saturday\n", day1,year1);
			fprintf(f1,"%d September %d, Saturday\n", day1,year1);
		}			
		if(x==10 && y==0){
			printf("%d October %d, Sunday\n", day1,year1);
			fprintf(f1,"%d October %d, Sunday\n", day1,year1);
		}
		if(x==10 && y==1){
			printf("%d October %d, Monday\n", day1,year1);
			fprintf(f1,"%d October %d, Monday\n", day1,year1);
		}
		if(x==10 && y==2){
			printf("%d October %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d October %d, Tuesday\n", day1,year1);
		}
		if(x==10 && y==3){
			printf("%d October %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d October %d, Wednesday\n", day1,year1);
		}
		if(x==10 && y==4){
			printf("%d October %d, Thursday\n", day1,year1);
			fprintf(f1,"%d October %d, Thursday\n", day1,year1);
		}
		if(x==10 && y==5){
			printf("%d October %d, Friday\n", day1,year1);
			fprintf(f1,"%d October %d, Friday\n", day1,year1);
		}
		if(x==10 && y==6){
			printf("%d October %d, Saturday\n", day1,year1);
			fprintf(f1,"%d October %d, Saturday\n", day1,year1);
		}
		if(x==11 && y==0){
			printf("%d November %d, Sunday\n", day1,year1);
			fprintf(f1,"%d November %d, Sunday\n", day1,year1);
		}
		if(x==11 && y==1){
			printf("%d November %d, Monday\n", day1,year1);
			fprintf(f1,"%d November %d, Monday\n", day1,year1);
		}
		if(x==11 && y==2){
			printf("%d November %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d November %d, Tuesday\n", day1,year1);
		}
		if(x==11 && y==3){
			printf("%d November %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d November %d, Wednesday\n", day1,year1);
		}
		if(x==11 && y==4){
			printf("%d November %d, Thursday\n", day1,year1);
			fprintf(f1,"%d November %d, Thursday\n", day1,year1);
		}
		if(x==11 && y==5){
			printf("%d November %d, Friday\n", day1,year1);
			fprintf(f1,"%d November %d, Friday\n", day1,year1);
		}
		if(x==11 && y==6){
			printf("%d November %d, Saturday\n", day1,year1);
			fprintf(f1,"%d November %d, Saturday\n", day1,year1);
		}
		if(x==12 && y==0){
			printf("%d December %d, Sunday\n", day1,year1);
			fprintf(f1,"%d December %d, Sunday\n", day1,year1);
		}
		if(x==12 && y==1){
			printf("%d December %d, Monday\n", day1,year1);
			fprintf(f1,"%d December %d, Monday\n", day1,year1);
		}
		if(x==12 && y==2){
			printf("%d December %d, Tuesday\n", day1,year1);
			fprintf(f1,"%d December %d, Tuesday\n", day1,year1);
		}
		if(x==12 && y==3){
			printf("%d December %d, Wednesday\n", day1,year1);
			fprintf(f1,"%d December %d, Wednesday\n", day1,year1);
		}
		if(x==12 && y==4){
			printf("%d December %d, Thursday\n", day1,year1);
			fprintf(f1,"%d December %d, Thursday\n", day1,year1);
		}
		if(x==12 && y==5){
			printf("%d December %d, Friday\n", day1,year1);
			fprintf(f1,"%d December %d, Friday\n", day1,year1);
		 }
		if(x==12 && y==6){
			printf("%d December %d, Saturday\n", day1,year1);
			fprintf(f1,"%d December %d, Saturday\n", day1,year1);
		}
	}
	fclose(f); /* Close files.*/
	fclose(f1);
}
int main(){
	date(); /* Call functions.*/
	print_date();
}
