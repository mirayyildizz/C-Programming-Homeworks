#include <stdio.h> 

int find_size_of_line(char line[]){ /* function that finds the number of characters*/
	int i;
	for( i = 0; i < 1024; i++ ){
		if(line[i] != '\0'){
			continue;
		}
		else 
			break;
	}
	return i;
}
void reverse_line(char line[], int line_lenght){ /*reversing function*/
	line_lenght = find_size_of_line(line);
	int i = 0;
	int j = line_lenght-1; 
	int temp;
	while (i < j) {
		temp = line[i];
		line[i] = line[j];
		line[j] = temp;
		i++;
		j--;
	}
}
void encrypt_open_msg(){ 
	FILE *file;
	FILE *file2;
	char buffer[1024]; 
	int x, key, i = 0;
	int line_lenght;
	
	printf("Key:");
	scanf("%d",&key);

	file = fopen("open_msg.txt", "r"); /* open the file*/ 
	if( file == NULL ){ /*print error if file is empty*/
		perror("file error");
	}

	while( fgets(buffer, sizeof(buffer), file) != NULL){ /*if the file is not empty*/
		reverse_line(buffer, line_lenght); /*reverse the line*/
		line_lenght = find_size_of_line(buffer);	
			
		i = 0 ;

		file2 = fopen("secret_msg.txt", "a"); /*open another file*/
		if( file2 == NULL ){
			perror("file error"); /*print error if file is empty*/
		}
		while(i < line_lenght){ /* print characters as long as less than length*/
			if(buffer[i] <= 'z' && buffer[i] >= 'a' ){ 
				if(buffer[i]-key < 'a') /* if buffer[i]- key < 'a' add 26*/
					buffer[i]= buffer[i]-key+26;
				else
				 buffer[i]= buffer[i]-key;
			}
			else if(buffer[i]==' '){ /* translate " " into "_" */
				buffer[i]='_';
			}
			else if(buffer[i]=='.'){
				buffer[i]='*'; /* translate "." into "*" */
			}
			else{
	       			i++;
				continue;
			}
			i++;
		}
		printf("buffer : %s\n", buffer);
		fprintf(file2,"%s",buffer); /* print file*/
	}
	fclose(file);
	fclose(file2);	
} 
void decrypt_secret_msg(){
	FILE *file;
	FILE *file2;
	char buffer[1024]; 
	int x, key, i = 0;
	int line_lenght;
	printf("Key:");
	scanf("%d",&key);
	file = fopen("secret_msg.txt", "r"); /* open the file*/ 
	if( file == NULL ){ /*print error if file is empty*/
		perror("file error");
	}
	while( fgets(buffer, sizeof(buffer), file) != NULL){ /*if the file is not empty*/
		reverse_line(buffer, line_lenght); /*reverse the line*/
		line_lenght = find_size_of_line(buffer);	
			
		i = 0 ;

		file2 = fopen("open_msg.txt", "a");
		if( file2 == NULL ){
			perror("file error");
		}
		while(i < line_lenght){ /* print characters as long as less than length*/
			if(buffer[i] <= 'z' && buffer[i] >= 'a' ){ 
				if(buffer[i]+key > 'z')
					buffer[i]= buffer[i] + key - 26; /* if buffer[i]+key > 'z' decrease 26*/
				else
				 buffer[i]=buffer[i]+key;
			}
			else if(buffer[i]=='_'){
				buffer[i]=' ';
			}
			else if(buffer[i]=='*'){
				buffer[i]='.';
			}
			else{
	       			i++;
				continue;
			}
			i++;
		}
		printf("buffer : %s\n", buffer);
		fputs(buffer, file2);
		fprintf(file2,"%s",buffer); 
	}
	fclose(file);
	fclose(file2);	
} 
void menu(){ /* Menu function*/
	int selection;
	do{ /* print the menu as long as the choice is not 0 */
	printf("1. Encrypt \n2. Decrypt\n0. Exit\nChoice:");
	scanf("%d", &selection);
	switch(selection){
	case 1:
		encrypt_open_msg();
		break;
	case 2:	
		decrypt_secret_msg();
		break;
	case 0:
		break;
	default:
	 	printf("error");
	}
}
	while(selection!=0); 
}
int main(){
	char line[1024];
	int x,line_lenght;
	menu(); /* call the menu*/
	/*encrypt_open_msg(); 
	decrypt_secret_msg();*/
	return 0;
}
