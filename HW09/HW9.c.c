
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{ /*Create Forest struct*/ 
	int width;
	int height;
	char **map;
	int flower_x;
	int flower_y;
}Forest;

typedef struct{ /*Create Botanist struct*/
	int coord_x;
	int coord_y;
	int water_bottle_size;
}Botanist;

void init_game(Forest *forest, Botanist *botanist){ /* Read game in file*/
	int i,j;
	char com;
	FILE *input;
	input=fopen("init.txt","r"); /* Open file*/
	fscanf(input, "%d\n", &(botanist->water_bottle_size)); /* Read first row */
	//printf("%d\n",botanist->water_bottle_size);
	fscanf(input,"%d%c%d%c",&(forest->width),&com, &(forest->height),&com);
	//printf("%d%c%d\n", (forest->width),com, (forest->height));
	forest->map =(char**)malloc(sizeof(char*)*(forest->height+1));
	        for(i=0; i<(forest->height+1); i++){ /*Allocate space in memory.*/
	                forest->map[i]=(char*)malloc(sizeof(char)*(forest->width*2));
	        }
	       
                        for(i=0; i<(forest->height+1); i++){ /* Read game*/
                                for(j=0; j<(forest->width*2); j++){
                                        fscanf(input,"%c", &(forest->map[i][j]));
                                          if(forest->map[i][j]=='B'){
                                            botanist->coord_x=i;
                                            botanist->coord_y=j;
                                          }
                                          if(forest->map[i][j]=='F'){
                                            forest->flower_x=i;
                                            forest->flower_y=j;
                                          }
                                        //printf("%c",forest->map[i][j]);
                                }
                        }
                
	fclose(input);
}
void print_map(Forest *forest){ /*Print map*/
  int i, j;
  for(i=0; i<(forest->height+1); i++){ /*I expanded the memory area because the commas occupy memory too */
    for(j=0; j<(forest->width*2); j++){
      if(forest->map[i][j]==','){
        forest->map[i][j]=' ';
        printf("%c",forest->map[i][j]);
      }
      else{
        printf("%c",forest->map[i][j]);
      }
    }
  }
}
    

void search (Forest forest, Botanist botanist){ /*Recursive function*/
  if(botanist.water_bottle_size==0){/*Send a message when the water is empty*/
    print_map(&forest);
    printf("Help! I am on (%d,%d)\n", botanist.coord_x, (botanist.coord_y/2));
  }
  else if((botanist.coord_x==forest.flower_x) && (botanist.coord_y==forest.flower_y)){ /*Send a message when you reach the flower*/
    print_map(&forest);
    printf("I have found it on (%d,%d)!",botanist.coord_x, (botanist.coord_y/2));
  }
  else{
    int rndm; /*Take random numbers between 1 and 4 and classify them as right, left, top, bottom*/
    rndm=((rand()%4)+1);
      if(rndm==1){ /*For right*/
        if(forest.map[botanist.coord_x][(botanist.coord_y)+2]==' ' && botanist.coord_y!=18){
          forest.map[botanist.coord_x][(botanist.coord_y)+2]='B';
          forest.map[botanist.coord_x][botanist.coord_y]=' ';
          botanist.coord_y=botanist.coord_y+2;
          botanist.water_bottle_size--;
        }
      }
      
      if(rndm==2){ /*For left*/
        if(forest.map[botanist.coord_x][(botanist.coord_y)-2]==' ' && botanist.coord_y!=0){
           forest.map[botanist.coord_x][(botanist.coord_y)-2]='B';
          forest.map[botanist.coord_x][botanist.coord_y]=' ';
          botanist.coord_y=botanist.coord_y-2;
          botanist.water_bottle_size--;
        }
      }
      if(rndm==3){ /* For top*/
        if(forest.map[(botanist.coord_x)+1][botanist.coord_y]==' ' && botanist.coord_x!=9){
          forest.map[(botanist.coord_x)+1][botanist.coord_y]='B';
          forest.map[botanist.coord_x][botanist.coord_y]=' ';
          botanist.water_bottle_size--;
          botanist.coord_x=botanist.coord_x+1;
        }
        
      }
      if(rndm==4){ /* FOr bottom*/
        if(forest.map[(botanist.coord_x)-1][botanist.coord_y]==' '&& botanist.coord_x!=0){
           forest.map[(botanist.coord_x)-1][botanist.coord_y]='B';
          forest.map[botanist.coord_x][botanist.coord_y]=' ';
          botanist.coord_x=botanist.coord_x-1;
          botanist.water_bottle_size--;
        }
      }
      search(forest,botanist); /*Recursive*/
  }

  
}
int main(){ /* Call functions*/
        srand(time(NULL));
        Forest forest;
        Botanist botanist;
        printf("      GAME    \n");
        init_game(&forest,&botanist);
        print_map(&forest);
        printf("Searching....\n\n\n\n");
        search(forest,botanist);
        //free(forest.map);
        return 0;
}
