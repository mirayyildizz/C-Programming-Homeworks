#include<stdio.h>

typedef enum {white_man, black_man, white_king, black_king, empty}
piece;
typedef enum {white = 10, black = 20} 
player; 
int move2(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);

void init_board(piece board[][8]){ /* Create table.*/
	int i,j;
		for(i=0; i<8; i++){
			for(j=0; j<8; j++){
				if(i==1 || i==2){
					board[i][j]=black_man;
				}
				if(i==5 || i==6){
					board[i][j]=white_man;
				}
				if(i==0 || i==3 || i==4 || i==7){
					board[i][j]=empty;
				}
		}
	}
}
void display_board(piece board[][8]){ /* Print table. */
	int i,j;
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			if(board[i][j]==black_man)
				printf("b");
			if(board[i][j]==white_man)
				printf("w");
			if(board[i][j]==empty)
				printf("-");
			if(board[i][j]==black_king)
				printf("B");
			if(board[i][j]==white_king)
				printf("W");
		}
	printf("\n");
	}
}

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){ /*Function of moving men.*/
	/*Moving white men.*/
	if(p==white && board[from_x][from_y]==white_man){
		if((from_x)-(to_x)==1){
			if((from_y)-(to_y)==0){
				if(board[to_x][to_y]==white_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_man;
				}
			}	
		}
		else 
				return -2;
		 if((from_y)-(to_y)==1 && (from_x)-(to_x)==0){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_man;
			}		

		}
		 if((from_y)-(to_y)==-1 && (from_x)-(to_x)==0){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_man;
			}
		}
		else if(((from_y)-(to_y)!=1 || (from_y)-(to_y)!=-1) && ((from_x)-(to_x)!=0)){
			return -2;
		}
		if(board[from_x][from_y]!=white_man){
			return -1;
		}
	}
	/* Moving black men.*/
	if(p==black && board[from_x][from_y]==black_man){
		if((from_x)-(to_x)==-1){
			if((from_y)-(to_y)==0){
				if(board[to_x][to_y]==black_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_man;
				}
			}	
		}
		else 
				return -2;
		 if((from_y)-(to_y)==1 && (from_x)-(to_x)==0){
			if(board[to_x][to_y]==black_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_man;
			}		

		}
		 if((from_y)-(to_y)==-1 && (from_x)-(to_x)==0){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_man;
			}
		}
		else if(((from_y)-(to_y)!=1 || (from_y)-(to_y)!=-1) && ((from_x)-(to_x)!=0)){
			return -2; 
		}
		if(board[from_x][from_y]!=black_man){
			return -1;
		}
	}
	/* Make the men king*/
	int i,j;
	for(i=0; i<8; i++){
		if(board[0][i]==white_man){
		board[0][i]=white_king;
		}
	}
	for(j=0; j<8; j++){
		if(board[7][j]==black_man){
		board[7][j]=black_king;
		}
	} 
}
int move3(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p) { /*Function of moving the king*/
	/* Moving black king*/
	if(p==black && board[from_x][from_y]==black_king){
		if((from_x)-(to_x)==1){
			if((from_y)-(to_y)==0){
				if(board[to_x][to_y]==black_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
				}
			}	
		
		}
		if((from_x)-(to_x)==-1){
			if((from_y)-(to_y)==0){
				if(board[to_x][to_y]==black_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
				}
			}	
		
		}
		 
	 if((from_y)-(to_y)==1 && (from_x)-(to_x)==0){
			if(board[to_x][to_y]==black_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}		

		}
		 if((from_y)-(to_y)==-1 && (from_x)-(to_x)==0){
			if(board[to_x][to_y]==black_man){
				return -2;

			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}
		}
		/*else if(((from_y)-(to_y)!=1 || (from_y)-(to_y)!=-1) && ((from_x)-(to_x)!=0)){
			return -2; 
		} */
		if(board[from_x][from_y]!=black_king){
			return -1;
		}
	}
	if(p==black && board[from_x][from_y]==black_king){
		if((from_x)-(to_x)==2 && (from_y)-(to_y)==0 && board[to_x+1][to_y]==empty){
				if(board[to_x][to_y]==black_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
				}
		}
		if((from_x)-(to_x)==-2 && (from_y)-(to_y)==0 && board[to_x-1][to_y]==empty){
				if(board[to_x][to_y]==black_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
				}
		}	
		
		/*else 
				return -2;  */	
	 	if((from_y)-(to_y)==2 && (from_x)-(to_x)==0 && board[to_x][to_y+1]==empty){
			if(board[to_x][to_y]==black_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}		

		}
		if((from_y)-(to_y)==-2 && (from_x)-(to_x)==0 && board[to_x][to_y-1]==empty){
			if(board[to_x][to_y]==black_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}
		}
		/*else if(((from_y)-(to_y)!=2 || (from_y)-(to_y)!=-2) && ((from_x)-(to_x)!=0)){
			return -2; 
		}*/
		if(board[from_x][from_y]!=black_king){
			return -1;
		}
	}

	if(p==black && board[from_x][from_y]==black_king){
		if((from_x)-(to_x)==3 && (from_y)-(to_y)==0 && board[to_x+1][to_y]==empty && board[to_x+2][to_y]==empty){
				if(board[to_x][to_y]==black_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
				}
		}
		if((from_x)-(to_x)==-3 && (from_y)-(to_y)==0 && board[to_x-1][to_y]==empty && board[to_x-2][to_y]==empty){
				if(board[to_x][to_y]==black_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
				}
		}		
		/*else 
				return -2; */
	 	if((from_y)-(to_y)==3 && (from_x)-(to_x)==0 && board[to_x][to_y+1]==empty && board[to_x][to_y+2]==empty){
			if(board[to_x][to_y]==black_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}		

		}
		 if((from_y)-(to_y)==-3 && (from_x)-(to_x)==0 && board[to_x][to_y-1]==empty && board[to_x][to_y-2]==empty){
			if(board[to_x][to_y]==black_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}
		}
		/*else if(((from_y)-(to_y)!=3 || (from_y)-(to_y)!=-3) && ((from_x)-(to_x)!=0)){
			return -2;
		} */
		if(board[from_x][from_y]!=black_king){
			return -1;
		}
	}
	if(p==black && board[from_x][from_y]==black_king){
		if((from_x)-(to_x)==4 && (from_y)-(to_y)==0 && board[to_x+1][to_y]==empty && board[to_x+2][to_y]==empty && board[to_x+3][to_y]==empty){
				if(board[to_x][to_y]==black_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
				}
		}	
		if((from_x)-(to_x)==-4 && (from_y)-(to_y)==0 && board[to_x-1][to_y]==empty && board[to_x-2][to_y]==empty && board[to_x-3][to_y]==empty){
				if(board[to_x][to_y]==black_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
				}
		}	
		/*else 
				return -2 */
	 	if((from_y)-(to_y)==4 && (from_x)-(to_x)==0 && board[to_x][to_y+1]==empty && board[to_x][to_y+2]==empty && board[to_x][to_y+3]==empty){
			if(board[to_x][to_y]==black_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}		

		}
		 if((from_y)-(to_y)==-4 && (from_x)-(to_x)==0 && board[to_x][to_y-1]==empty && board[to_x][to_y-2]==empty && board[to_x][to_y-3]==empty){
			if(board[to_x][to_y]==black_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}
		}
		/*else if(((from_y)-(to_y)!=4 || (from_y)-(to_y)!=-4) && ((from_x)-(to_x)!=0)){
			return -2;
		} */
		if(board[from_x][from_y]!=black_king){
			return -1;
		}
	}
	if(p==black && board[from_x][from_y]==black_king){
		if((from_x)-(to_x)==5 && (from_y)-(to_y)==0 && board[to_x+1][to_y]==empty && board[to_x+2][to_y]==empty && board[to_x+3][to_y]==empty && board[to_x+4][to_y]==empty){
				if(board[to_x][to_y]==black_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
				}
		}
		if((from_x)-(to_x)==-5 && (from_y)-(to_y)==0 && board[to_x-1][to_y]==empty && board[to_x-2][to_y]==empty && board[to_x-3][to_y]==empty && board[to_x-4][to_y]==empty){
				if(board[to_x][to_y]==black_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=black_king;
				}
		}	
		/*else 
				return -2; */
	 	if((from_y)-(to_y)==5 && (from_x)-(to_x)==0 && board[to_x][to_y+1]==empty && board[to_x][to_y+2]==empty && board[to_x][to_y+3]==empty && board[to_x][to_y+4]==empty){
			if(board[to_x][to_y]==black_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}		
		}
		 if((from_y)-(to_y)==-5 && (from_x)-(to_x)==0 && board[to_x][to_y-1]==empty && board[to_x][to_y-2]==empty && board[to_x][to_y-3]==empty && board[to_x][to_y-4]){
			if(board[to_x][to_y]==black_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}
		}
		/*else if(((from_y)-(to_y)!=5 || (from_y)-(to_y)!=-5) && ((from_x)-(to_x)!=0)){
			return -2;
		} */
		if(board[from_x][from_y]!=black_king){
			return -1;
		}
	
	}
	/* Moving white king*/
	if(p==white && board[from_x][from_y]==white_king){
		if((from_x)-(to_x)==-1){
			if((from_y)-(to_y)==0){
				if(board[to_x][to_y]==white_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
				}
			}	
		}
		if((from_x)-(to_x)==1){
			if((from_y)-(to_y)==0){
				if(board[to_x][to_y]==white_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
				}
			}	
		}
		/*else 
				return -2; */
	 	if((from_y)-(to_y)==1 && (from_x)-(to_x)==0){ 
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}		

		}
		 if((from_y)-(to_y)==-1 && (from_x)-(to_x)==0){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}
		}
		/*else if(((from_y)-(to_y)!=1 || (from_y)-(to_y)!=-1) && ((from_x)-(to_x)!=0)){
			return -2;
		} */
		if(board[from_x][from_y]!=white_king){
			return -1;
		}
	}
	if(p==white && board[from_x][from_y]==white_king){
		if((from_x)-(to_x)==-2 && (from_y)-(to_y)==0 && board[to_x-1][to_y]==empty){
				if(board[to_x][to_y]==white_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
				}
		}	
		if((from_x)-(to_x)==2 && (from_y)-(to_y)==0 && board[to_x+1][to_y]==empty){
				if(board[to_x][to_y]==white_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
				}
		}
		/*else 
				return -2; */
	 	if((from_y)-(to_y)==2 && (from_x)-(to_x)==0 && board[to_x][to_y+1]==empty){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}		
		}
		if((from_y)-(to_y)==-2 && (from_x)-(to_x)==0 && board[to_x][to_y-1]==empty){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}
		}
		/*else if(((from_y)-(to_y)!=2 || (from_y)-(to_y)!=-2) && ((from_x)-(to_x)!=0)){
			return -2; */
		if(board[from_x][from_y]!=white_king){
			return -1;
		}
	}
	if(p==white && board[from_x][from_y]==white_king){
		if((from_x)-(to_x)==-3 && (from_y)-(to_y)==0 && board[to_x-1][to_y]==empty && board[to_x-2][to_y]==empty){
				if(board[to_x][to_y]==white_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
				}
		}	
		if((from_x)-(to_x)==3 && (from_y)-(to_y)==0 && board[to_x+1][to_y]==empty && board[to_x+2][to_y]==empty){
				if(board[to_x][to_y]==white_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
				}
		}	
		/*else 
				return -2; */
	 	if((from_y)-(to_y)==3 && (from_x)-(to_x)==0 && board[to_x][to_y+1]==empty && board[to_x][to_y+2]==empty){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}		
		}
		 if((from_y)-(to_y)==-3 && (from_x)-(to_x)==0 && board[to_x][to_y-1]==empty && board[to_x][to_y-2]==empty){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}
		}
		/*else if(((from_y)-(to_y)!=3 || (from_y)-(to_y)!=-3) && ((from_x)-(to_x)!=0)){
			return -2;
		} */
		if(board[from_x][from_y]!=white_king){
			return -1;
		}
	}
	if(p==white && board[from_x][from_y]==white_king){
		if((from_x)-(to_x)==-4 && (from_y)-(to_y)==0 && board[to_x-1][to_y]==empty && board[to_x-2][to_y]==empty && board[to_x-3][to_y]==empty){
				if(board[to_x][to_y]==white_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
				}
		}	
		if((from_x)-(to_x)==4 && (from_y)-(to_y)==0 && board[to_x+1][to_y]==empty && board[to_x+2][to_y]==empty && board[to_x+3][to_y]==empty){
				if(board[to_x][to_y]==white_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
				}
		}	
		/*else 
				return -2; */
	 	if((from_y)-(to_y)==4 && (from_x)-(to_x)==0 && board[to_x][to_y+1]==empty && board[to_x][to_y+2]==empty && board[to_x][to_y+3]==empty){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}		
		}
		 if((from_y)-(to_y)==-4 && (from_x)-(to_x)==0 && board[to_x][to_y-1]==empty && board[to_x][to_y-2]==empty && board[to_x][to_y-3]==empty){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}
		}
		/*else if(((from_y)-(to_y)!=4 || (from_y)-(to_y)!=-4) && ((from_x)-(to_x)!=0)){
			return -2; */
		if(board[from_x][from_y]!=white_king){
			return -1;
		}
	}
	if(p==white && board[from_x][from_y]==white_king){
		if((from_x)-(to_x)==-5 && (from_y)-(to_y)==0 && board[to_x-1][to_y]==empty && board[to_x-2][to_y]==empty && board[to_x-3][to_y]==empty && board[to_x-4][to_y]==empty){
				if(board[to_x][to_y]==white_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
				}
		}	
		if((from_x)-(to_x)==5 && (from_y)-(to_y)==0 && board[to_x+1][to_y]==empty && board[to_x+2][to_y]==empty && board[to_x+3][to_y]==empty && board[to_x+4][to_y]==empty){
				if(board[to_x][to_y]==white_man){
					return -2;
				}
				if(board[to_x][to_y]==empty){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=white_king;
				}
		}
		/*else 
				return -2; */
	 	if((from_y)-(to_y)==5 && (from_x)-(to_x)==0 && board[to_x][to_y+1]==empty && board[to_x][to_y+2]==empty && board[to_x][to_y+3]==empty && board[to_x][to_y+4]==empty){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}		

		}
		 if((from_y)-(to_y)==-5 && (from_x)-(to_x)==0 && board[to_x][to_y-1]==empty && board[to_x][to_y-2]==empty && board[to_x][to_y-3]==empty && board[to_x][to_y-4]){
			if(board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}
		}
		/*else if(((from_y)-(to_y)!=5 || (from_y)-(to_y)!=-5) && ((from_x)-(to_x)!=0)){
			return -2; */
		if(board[from_x][from_y]!=white_king){
			return -1;
		}
	}
 } 
int move2(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){ /* Function of feeding men to men or king*/
	/* For white men*/ 
	if(p==white && board[from_x][from_y]==white_man){
		while(((from_x)-(to_x)==2 && (from_y)-(to_y)==0) && board[from_x-1][from_y]==black_man){
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){	
				board[from_x-1][from_y]=empty;
				board[to_x][to_y]=white_man;
				/*to_x=(to_x)-1; */
				board[from_x][from_y]=empty;
				from_x=to_x;
				to_x=to_x-2;
			}
		}
		while(((from_y)-(to_y)==2  && (from_x)-(to_x)==0) && board[from_x][from_y-1] == black_man){
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y-1]=empty;
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_man;
				from_y=to_y;
				to_y=to_y-2;
			}		
		}
		while(((from_y)-(to_y)==-2  && (from_x)-(to_x)==0) && board[from_x][from_y+1] == black_man){
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y+1]=empty;
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_man;
				from_y=to_y;
				to_y=to_y+2;
			}			
		} 
	}
	/* For black men*/
	if(p==black && board[from_x][from_y]==black_man){
		while(((from_x)-(to_x)==-2 && (from_y)-(to_y)==0) && board[from_x+1][from_y]==white_man){
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){	
				board[from_x+1][from_y]=empty;
				board[to_x][to_y]=black_man;
				board[from_x][from_y]=empty;
				from_x=to_x;
				to_x=to_x+2;
			}
		}
		while(((from_y)-(to_y)==2  && (from_x)-(to_x)==0) && board[from_x][from_y-1] == white_man){
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y-1]=empty;
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_man;
				from_y=to_y;
				to_y=to_y-2;
			}		
		}
		while(((from_y)-(to_y)==-2  && (from_x)-(to_x)==0) && board[from_x][from_y+1] == white_man){
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y+1]=empty;
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_man;
				from_y=to_y;
				to_y=to_y+2;
			}			
		} 
	}
	int i;
	for(i=0; i<8; i++){
		if(board[0][i]==white_man){
		board[0][i]=white_king;
		}
		if(board[7][i]==black_man){
		board[7][i]=black_king;
		}
	}
	
}
int move4(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){ /* Function of feeding king to men or king*/
	/*For white king*/
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_x-to_x==2 && from_y-to_y==0 && (board[from_x-1][from_y]==black_man || board[from_x-1][from_y]==black_king)){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x-1][from_y]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x-2][from_y]==empty && (board[from_x-1][from_y]==black_man || board[from_x-1][from_y]==black_king)){
					board[from_x-1][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x-2;
					board[to_x][to_y]=white_king;
					from_x=from_x-1;
				}
			}
		}
	}
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_x-to_x==-2 && from_y-to_y==0 && (board[from_x+1][from_y]==black_man || board[from_x+1][from_y]==black_king)){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x+1][from_y]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x+2][from_y]==empty && (board[from_x+1][from_y]==black_man || board[from_x+1][from_y]==black_king)){
					board[from_x+1][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x+2;
					board[to_x][to_y]=white_king;
					from_x=from_x+1;
				}
			}
		}
	}
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_y-to_y==2 && from_x-to_x==0 && (board[from_x][from_y-1]==black_man || board[from_x][from_y-1]==black_king)){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y-1]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y-2]==empty && (board[from_x][from_y-2]==black_man || board[from_x][from_y-1]==black_king)){
					board[from_x][from_y-1]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y-2;
					board[to_x][to_y]=white_king;
					from_y=from_y-1;
				}
			}
		}
	}
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_y-to_y==-2 && from_x-to_x==0 && (board[from_x][from_y+1]==black_man || board[from_x][from_y+1]==black_king )){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y+1]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y+2]==empty && (board[from_x][from_y+1]==black_man || board[from_x][from_y+1]==black_king)){
					board[from_x][from_y+1]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y+2;
					board[to_x][to_y]=white_king;
					from_y=from_y+1;
				}
			}
		}
	}
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_x-to_x==3 && from_y-to_y==0 && (board[from_x-2][from_y]==black_man || board[from_x-2][from_y]==black_king) && board[from_x-1][from_y]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x-2][from_y]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x-3][from_y]==empty && (board[from_x-2][from_y]==black_man || board[from_x-2][from_y]==black_king)){
					board[from_x-2][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x-3;
					board[to_x][to_y]=white_king;
					from_x=from_x-1;
				}
			}
		}
	}
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_x-to_x==-3 && from_y-to_y==0 && (board[from_x+2][from_y]==black_man || board[from_x+2][from_y]==black_king) && board[from_x+1][from_y]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x+2][from_y]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x+3][from_y]==empty && (board[from_x+2][from_y]==black_man || board[from_x+2][from_y]==black_king)){
					board[from_x+2][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x+3;
					board[to_x][to_y]=white_king;
					from_x=from_x+1;
				}
			}
		}
	}
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_y-to_y==3 && from_x-to_x==0 && (board[from_x][from_y-2]==black_man || board[from_x][from_y-2]==black_king) && board[from_x][from_y-1]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y-2]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y-3]==empty && (board[from_x][from_y-2]==black_man || board[from_x][from_y-2]==black_king)){
					board[from_x][from_y-2]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y-3;
					board[to_x][to_y]=white_king;
					from_y=from_y-1;
				}
			}
		}
	}
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_y-to_y==-3 && from_x-to_x==0 && (board[from_x][from_y+2]==black_man || board[from_x][from_y+2]==black_king) && board[from_x][from_y+1]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y+2]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y+3]==empty && (board[from_x][from_y+2]==black_man || board[from_x][from_y+2]==black_king)){
					board[from_x][from_y+2]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y+3;
					board[to_x][to_y]=white_king;
					from_y=from_y+1;
				}
			}
		}
	}
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_x-to_x==4 && from_y-to_y==0 && (board[from_x-3][from_y]==black_man || board[from_x-3][from_y]==black_king) && board[from_x-2][from_y]==empty && board[from_x-1][from_y]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x-3][from_y]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x-4][from_y]==empty && (board[from_x-3][from_y]==black_man || board[from_x-3][from_y]==black_king)){
					board[from_x-3][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x-4;
					board[to_x][to_y]=white_king;
					from_x=from_x-1;
				}
			}
		}
	}
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_x-to_x==-4 && from_y-to_y==0 && (board[from_x+3][from_y]==black_man || board[from_x+3][from_y]==black_king) && board[from_x+2][from_y]==empty && board[from_x+1][from_y]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x+3][from_y]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x+4][from_y]==empty && (board[from_x+3][from_y]==black_man || board[from_x+3][from_y]==black_king)){
					board[from_x+3][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x+4;
					board[to_x][to_y]=white_king;
					from_x=from_x+1;
				}
			}
		}
	}
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_y-to_y==4 && from_x-to_x==0 && (board[from_x][from_y-3]==black_man || board[from_x][from_y-3]==black_king) && board[from_x][from_y-2]==empty && board[from_x][from_y-1]){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y-3]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y-4]==empty && (board[from_x][from_y-3]==black_man || board[from_x][from_y-3]==black_king)){
					board[from_x][from_y-3]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y-4;
					board[to_x][to_y]=white_king;
					from_y=from_y-1;
				}
			}
		}
	}
	if(p==white && board[from_x][from_y]==white_king){ 
		if(from_y-to_y==-4 && from_x-to_x==0 && (board[from_x][from_y+3]==black_man || board[from_x][from_y+3]==black_king) && board[from_x][from_y+2]==empty && board[from_x][from_y+1]){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y+3]=empty;
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y+4]==empty && (board[from_x][from_y+3]==black_man || board[from_x][from_y+3]==black_king)){
					board[from_x][from_y+3]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y+4;
					board[to_x][to_y]=white_king;
					from_y=from_y+1;
				}
			}
		}
	}
	/* For black king*/
	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_x-to_x==2 && from_y-to_y==0 && (board[from_x-1][from_y]==white_man || board[from_x-1][from_y]==white_king)){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x-1][from_y]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x-2][from_y]==empty && (board[from_x-1][from_y]==white_man || board[from_x-1][from_y]==white_king)){
					board[from_x-1][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x-2;
					board[to_x][to_y]=black_king;
					from_x=from_x-1;
				}
			}
		}
	}
	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_x-to_x==-2 && from_y-to_y==0 && (board[from_x+1][from_y]==white_man || board[from_x+1][from_y]==white_king)){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x+1][from_y]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x+2][from_y]==empty && (board[from_x+1][from_y]==white_man || board[from_x+1][from_y]==white_king)){
					board[from_x+1][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x+2;
					board[to_x][to_y]=black_king;
					from_x=from_x+1;
				}
			}
		}
	}
	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_y-to_y==2 && from_x-to_x==0 && (board[from_x][from_y-1]==white_man || board[from_x][from_y-1]==white_king)){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y-1]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y-2]==empty && (board[from_x][from_y-2]==white_man || board[from_x][from_y-1]==white_king)){
					board[from_x][from_y-1]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y-2;
					board[to_x][to_y]=black_king;
					from_y=from_y-1;
				}
			}
		}
	}
	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_y-to_y==-2 && from_x-to_x==0 && (board[from_x][from_y+1]==white_man || board[from_x][from_y+1]==white_king)){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y+1]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y+2]==empty && (board[from_x][from_y+1]==white_man)) {
					board[from_x][from_y+1]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y+2;
					board[to_x][to_y]=black_king;
					from_y=from_y+1;
					} 
			}
		}
	}

	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_x-to_x==3 && from_y-to_y==0 && (board[from_x-2][from_y]==white_man || board[from_x-2][from_y]==white_king) && board[from_x-1][from_y]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x-2][from_y]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x-3][from_y]==empty && (board[from_x-2][from_y]==white_man || board[from_x-2][from_y]==white_king)){
					board[from_x-2][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x-3;
					board[to_x][to_y]=black_king;
					from_x=from_x-1;
				}
			}
		}
	}
	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_x-to_x==-3 && from_y-to_y==0 && (board[from_x+2][from_y]==white_man || board[from_x+2][from_y]==white_king) && board[from_x+1][from_y]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x+2][from_y]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x+3][from_y]==empty && (board[from_x+2][from_y]==white_man || board[from_x+2][from_y]==white_king)){
					board[from_x+2][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x+3;
					board[to_x][to_y]=black_king;
					from_x=from_x+1;
				}
			}
		}
	}
	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_y-to_y==3 && from_x-to_x==0 && (board[from_x][from_y-2]==white_man || board[from_x][from_y-2]==white_king) && board[from_x][from_y-1]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y-2]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y-3]==empty && (board[from_x][from_y-2]==white_man || board[from_x][from_y-2]==white_king)){
					board[from_x][from_y-2]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y-3;
					board[to_x][to_y]=black_king;
					from_y=from_y-1;
				}
			}
		}
	}
	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_y-to_y==-3 && from_x-to_x==0 && (board[from_x][from_y+2]==white_man ||board[from_x][from_y+2]==white_king) && board[from_x][from_y+1]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y+2]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y+3]==empty && (board[from_x][from_y+2]==white_man || board[from_x][from_y+2]==white_king)){
					board[from_x][from_y+2]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y+3;
					board[to_x][to_y]=black_king;
					from_y=from_y+1;
				}
			}
		}
	}
	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_x-to_x==4 && from_y-to_y==0 && (board[from_x-3][from_y]==white_man || board[from_x-3][from_y]==white_king) && board[from_x-2][from_y]==empty && board[from_x-1][from_y]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x-3][from_y]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x-4][from_y]==empty && (board[from_x-3][from_y]==white_man || board[from_x-3][from_y]==white_king)){
					board[from_x-3][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x-4;
					board[to_x][to_y]=black_king;
					from_x=from_x-1;
				}
			}
		}
	}
	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_x-to_x==-4 && from_y-to_y==0 && (board[from_x+3][from_y]==white_man || board[from_x+3][from_y]==white_king) && board[from_x+2][from_y]==empty && board[from_x+1][from_y]==empty){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x+3][from_y]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_x=to_x;
				while(board[from_x+4][from_y]==empty && (board[from_x+3][from_y]==white_man || board[from_x+3][from_y]==white_king)){
					board[from_x+3][from_y]=empty;
					board[from_x][from_y]=empty;
					to_x=from_x+4;
					board[to_x][to_y]=black_king;
					from_x=from_x+1;
				}
			}
		}
	}
	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_y-to_y==4 && from_x-to_x==0 && (board[from_x][from_y-3]==white_man || board[from_x][from_y-3]==white_king) && board[from_x][from_y-2]==empty && board[from_x][from_y-1]){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y-3]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y-4]==empty && (board[from_x][from_y-3]==white_man || board[from_x][from_y-3]==white_king)){
					board[from_x][from_y-3]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y-4;
					board[to_x][to_y]=black_king;
					from_y=from_y-1;
				}
			}
		}
	}
	if(p==black && board[from_x][from_y]==black_king){ 
		if(from_y-to_y==-4 && from_x-to_x==0 && (board[from_x][from_y+3]==white_man || board[from_x][from_y+3]==white_king) && board[from_x][from_y+2]==empty && board[from_x][from_y+1]){ 
			if(board[to_x][to_y]==black_man || board[to_x][to_y]==white_man){ 
				return -2;
			}
			if(board[to_x][to_y]==empty){
				board[from_x][from_y+3]=empty;
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				from_y=to_y;
				while(board[from_x][from_y+4]==empty && (board[from_x][from_y+3]==white_man || board[from_x][from_y+3]==white_king)){
					board[from_x][from_y+3]=empty;
					board[from_x][from_y]=empty;
					to_y=from_y+4;
					board[to_x][to_y]=black_king;
					from_y=from_y+1;
				}
			}
		}
	}
	
	
}
void sample_game_1(){ /* A sample game.*/
	piece board[8][8]; 
	init_board(board);
	printf("\n");
	move(board, 5, 0, 4, 0, white);
	display_board(board); 
	printf("\n");
	move(board, 2, 0, 3, 0, black);
	display_board(board);
	printf("\n");
	move(board,5,2,4,2,white);
	display_board(board);
	printf("\n");
	move2(board,3,0,5,0,black);
	display_board(board);
	printf("\n");  
	move(board,7,5,7,4,white);
	display_board(board); 
	printf("\n");	
	move2(board,5,0,7,0,black);
	display_board(board);
	printf("\n");
	move(board,5,7,4,7,white);
	display_board(board);
	printf("\n");
	move3(board,7,0,4,0,black);
	display_board(board);
	printf("\n");
	move(board,5,3,4,3,white);
	display_board(board);
	printf("\n");
	move(board,2,7,3,7,black);
	display_board(board);
	printf("\n");
	move2(board,4,7,2,7,white);
	display_board(board);
	printf("\n");
	move(board,4,0,4,1,black);
	display_board(board);
	printf("\n");
	move3(board,0,7,4,7,white);
	display_board(board);
	printf("\n");
	move(board,2,1,3,1,black);
	display_board(board);
	printf("\n");
	move3(board,4,7,4,6,white);
	display_board(board);
	printf("\n");
	move(board,2,6,3,6,black);
	display_board(board);
	printf("\n");
	move4(board,4,6,2,6,white);
	display_board(board);
	printf("\n");
	move(board,2,5,3,5,black);
	display_board(board);
	printf("\n");
	move3(board,0,6,3,6,white);
	display_board(board);
	printf("\n");
	move(board,2,2,3,2,black);
	display_board(board);
	printf("\n");
	move4(board,3,6,3,4,white);
	display_board(board);
	printf("\n");
	move(board,1,0,2,0,black);
	display_board(board);
	printf("\n");
	move3(board,3,4,3,5,white);
	display_board(board);
	printf("\n");
	move(board,1,2,2,2,black);
	display_board(board);
	printf("\n");
	move4(board,3,5,0,5,white);
	display_board(board);
	printf("\n");
	move(board,2,3,3,3,black);
	display_board(board);
	printf("\n");
	move2(board,4,3,2,3,white);
	display_board(board);
	printf("\n");
	move4(board,4,0,4,3,black);
	display_board(board);
	printf("\n");
	move3(board,0,3,0,1,white);
	display_board(board);
	printf("\n");
	move4(board,4,3,5,3,black);
	display_board(board);
	printf("\n");
	move4(board,0,1,2,1,white);
	display_board(board);
	printf("\n");
	move4(board,4,3,4,0,black);
	display_board(board);
	printf("\n");
	move(board,5,4,4,4,white);
	display_board(board);
	printf("\n");
	move3(board,4,0,5,0,black);
	display_board(board);
	printf("\n");
	move(board,4,4,3,4,white);
	display_board(board);
	printf("\n");
	move4(board,5,0,5,2,black);
	display_board(board);
	printf("\n");
	move(board,6,7,5,7,white);
	display_board(board);
	printf("\n");
	move2(board,2,4,4,4,black);
	display_board(board);
	printf("\n");
	move(board,5,7,4,7,white);
	display_board(board);
	printf("\n");
	move4(board,5,2,7,2,black);
	display_board(board);
	printf("\n");
	move(board,5,6,4,6,white);
	display_board(board);
	printf("\n");
	move(board,3,2,4,2,black);
	display_board(board);
	printf("\n");
	move(board,4,7,3,7,white);
	display_board(board);
	printf("\n");
	move3(board,7,2,7,1,black);
	display_board(board);
	printf("\n");
	move3(board,0,5,0,0,white);
	display_board(board);
	printf("\n");
	move4(board,7,1,5,1,black);
	display_board(board);
	printf("\n");
	move4(board,0,0,3,0,white);
	display_board(board);
	printf("\n");
	move(board,2,2,3,2,black);
	display_board(board);
	printf("\n");
	move4(board,3,0,3,3,white);
	display_board(board);
	printf("\n");
	move(board,1,4,2,4,black);
	display_board(board);
	printf("\n");
	move3(board,3,3,3,4,white);
	display_board(board);
	printf("\n");
	move(board,4,2,5,2,black);
	display_board(board);
	printf("\n");
	move4(board,3,4,5,4,white);
	display_board(board);
	printf("\n");
	move(board,2,4,3,4,black);
	display_board(board);
	printf("\n");
	move(board,3,7,2,7,white);
	display_board(board);
	printf("\n");
	move(board,3,4,4,4,black);
	display_board(board);
	printf("\n");	
	move4(board,5,4,3,4,white);
	display_board(board);
	printf("\n");
	move3(board,5,1,3,1,black);
	display_board(board);
	printf("\n");
	move4(board,3,4,3,0,white);
	display_board(board);
	printf("\n");
	move(board,5,2,6,2,black);
	display_board(board);
	printf("\n");
	move(board,2,7,1,7,white);
	display_board(board);
}

void sample_game_2(){ /* Sample game 2*/
	piece board[8][8]={ 
        {empty,empty,empty,empty,empty,empty,empty,empty},
        {empty,empty,black_man,black_man,black_man,black_man,empty,empty},
        {empty,black_man,black_man,black_man,black_man,empty,black_man,black_man},
        {black_man,black_man,black_man,empty,empty,black_man,empty,black_man},
        {empty,empty,white_man,white_man,white_man,black_man,white_man,white_man},
        {white_man,white_man,white_man,white_man,white_man,empty,white_man,white_man},
        {empty,empty,white_man,white_man,white_man,white_man,empty,empty},
        {empty,empty,empty,empty,empty,empty,empty,empty}
    };
}
int check_end_of_game(piece board[][8]){ /*Funtion of game controlling*/
	int i,j,count1,count2;
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			if(board[i][j]==black_man || board[i][j]==black_king){
				count1++;
			}
			if(board[i][j]==white_man || board[i][j]==white_king){
				count1++;
			}
		}
	}
	if(count1!=0 && count2!=0)
		return -1;
	if(count1==0)
		return white;
	if(count2==0)
		return black;
}	 
int main(){ /* Call functions.*/
	piece board[8][8];
	sample_game_1();
	int x = check_end_of_game(board);
	if(x==-1)
		printf("Game continues.");
	if(x==white)
		printf("White wins the game.");
	if(x==black)
		printf("Black wins the game.");
return 0;
}
