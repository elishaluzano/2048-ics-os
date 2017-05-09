#include "../../sdk/dexsdk.h"

int board[4][4];
int score = 0;
int didItMove = 0;

int main() 
{
	printf("2048");
	set_graphics(VGA_320X200X256);

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			board[i][j] = 0;
		}
	}

	drawBoard();
	randomizer();


	write_text("2", 150, 30, RED, 0); 
	write_text("0", 160, 30, YELLOW, 0); 
	write_text("4", 170, 30, BLUE, 0); 
	write_text("8", 180, 30, GREEN, 0); 

	write_text("Up(I)", 150, 60, LIGHTGRAY, 0); 
	write_text("Down(K)", 150, 68, LIGHTGRAY, 0); 
	write_text("Left(J)", 150, 76, LIGHTGRAY, 0); 
	write_text("Right(L)", 150, 84, LIGHTGRAY, 0); 
	write_text("New Game(N)", 150, 100, LIGHTGRAY, 0); 
	write_text("Exit(X)", 150, 108, LIGHTGRAY, 0); 

	char strscr[15];
	sprintf(strscr, "%d", score);	
	write_text("SCORE: ", 20, 170, LIGHTGRAY, 0); 
	write_text(strscr, 80, 170, LIGHTGRAY, 0); 


	char keypress;
	do{
		if (keypress=(char)getch()){
		
			if(keypress=='i' || keypress=='I'){
				didItMove = 0;
				redraw();
				move(3);
				up();
			}
			else if(keypress=='k' || keypress=='K'){
				didItMove = 0;
				redraw();
				move(4);
				down();
			}
			else if(keypress=='j' || keypress=='J'){
				didItMove = 0;
				redraw();
				move(1);
				left();
			}
			else if(keypress=='l' || keypress=='L'){
				didItMove = 0;
				redraw();
				move(2);
				right();
			}
			else if(keypress=='x' || keypress=='X'){
				return 0;
			}
			else if(keypress=='n' || keypress=='N'){
				for(int i=0; i<4; i++){
					for(int j=0; j<4; j++){
						board[i][j] = 0;
					}
				}
				drawBoard();
				drawVals();
				randomizer();
			}
		}
	}while(1);

	return 0;
}

void move(int dir){
	if(dir == 1){
		for(int i=0; i<4; i++){
			for(int j=0; j<3; j++){
				if(board[i][j] == 0){
					board[i][j] = board[i][j + 1];
					board[i][j + 1] = 0;
					didItMove = 1;
				}
			}
		}
	}
	else if(dir == 2){
		for(int i=3; i>=0; i--){
			for(int j=3; j>0; j--){
				if(board[i][j] == 0){
					board[i][j] = board[i][j-1];
					board[i][j-1] = 0;
					didItMove = 1;
				}
			}
		}
	}
	else if(dir == 3){
		for(int i=0; i<3; i++){
			for(int j=0; j<4; j++){
				if(board[i][j] == 0){
					board[i][j] = board[i+1][j];
					board[i+1][j] = 0;
					didItMove = 1;
				}
			}
		}
	}
	else if(dir == 4){
		for(int i=3; i>0; i--){
			for(int j=3; j>=0; j--){
				if(board[i][j] == 0){
					board[i][j] = board[i-1][j];
					board[i-1][j] = 0;
					didItMove = 1;
				}
			}
		}
	}
}

void left(){
	for(int a=0; a<4; a++){
		for(int b=0; b<3; b++){
			if(board[a][b] == 0) move(1);
		}
	}
	for(int a=0; a<4; a++){
		for(int b=0; b<3; b++){
			if(board[a][b] == board[a][b+1]){
				score += board[a][b] * 2;
				board[a][b] = board[a][b] * 2;
				board[a][b+1] = 0;
				move(1);
			}
		}
	}

	addNew();
}

void right(){
	for(int a=3; a>=0; a--){
		for(int b=3; b>0; b--){
			if(board[a][b] == 0) move(2);
		}
	}
	for(int a=3; a>=0; a--){
		for(int b=3; b>0; b--){
			if(board[a][b] == board[a][b-1]){
				score += board[a][b] * 2;
				board[a][b] = board[a][b] * 2;
				board[a][b-1] = 0;
				move(2);
			}
		}
	}

	addNew();
}

void up(){
	for(int a=0; a<3; a++){
		for(int b=0; b<4; b++){
			if(board[a][b] == 0) move(3);
		}
	}
	for(int a=0; a<3; a++){
		for(int b=0; b<4; b++){
			if(board[a][b] == board[a+1][b]){
				score += board[a][b] * 2;
				board[a][b] = board[a][b] * 2;
				board[a+1][b] = 0;
				move(3);
			}
		}
	}

	addNew();

}

void down(){
	for(int a=3; a>0; a--){
		for(int b=3; b>=0; b--){
			if(board[a][b] == 0) move(4);
		}
	}
	for(int a=3; a>0; a--){
		for(int b=3; b>=0; b--){
			if(board[a][b] == board[a-1][b]){
				score += board[a][b] * 2;
				board[a][b] = board[a][b] * 2;
				board[a-1][b] = 0;
				move(4);
			}
		}
	}

	addNew();
}

void addNew(){

	drawVals();


	for(int i=70; i<100; i++){
		for(int j=170; j<190; j++){
			write_pixel(i, j, BLACK);
		}
	}
	
	char strscr[15];
	sprintf(strscr, "%d", score);	
	write_text(strscr, 80, 170, LIGHTGRAY, 0); 

	int initRow;
	int initCol;

	do{
		initRow = rand() % 4;
		initCol = rand() % 4;
	}while(board[initRow][initCol] != 0);

	board[initRow][initCol] = 2;
	write_text("2", (initCol*30)+30, (initRow*30)+30, RED, 0); 

}

void drawVals(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			int aInt = board[i][j];
			if(aInt !=0){
				char str[15];
				sprintf(str, "%d", aInt);
				if(aInt ==2)		write_text(str, (j*30)+30, (i*30)+30, RED, 0); 
				else if(aInt ==4)	write_text(str, (j*30)+30, (i*30)+30, BLUE, 0); 
				else if(aInt ==8)	write_text(str, (j*30)+30, (i*30)+30, GREEN, 0); 
				else if(aInt ==16)	write_text(str, (j*30)+26, (i*30)+30, CYAN, 0); 
				else if(aInt ==32)	write_text(str, (j*30)+26, (i*30)+30, MAGENTA, 0); 
				else if(aInt ==64)	write_text(str, (j*30)+26, (i*30)+30, BROWN, 0); 
				else if(aInt ==128)	write_text(str, (j*30)+16, (i*30)+30, YELLOW, 0); 
				else if(aInt ==256)	write_text(str, (j*30)+16, (i*30)+30, LIGHTBLUE, 0); 
				else if(aInt ==512)	write_text(str, (j*30)+16, (i*30)+30, LIGHTGREEN, 0); 
				else if(aInt ==1024)	write_text(str, (j*30), (i*30)+30, LIGHTMAGENTA, 0);
				else if(aInt ==2048)	write_text(str, (j*30), (i*30)+30, LIGHTRED, 0); 
				else if(aInt ==4096)	write_text(str, (j*30), (i*30)+30, BLACK, 0); 
				else					write_text(str, (j*30), (i*30)+30, BLACK, 0); 
			}
		}
	}
}


void drawBox(int rowCount, int colCount){

	for(int x=0; x<4; x++){
		for(int y=0; y<4; y++){
			for(int j=rowCount; j<rowCount+25; j++){
				for (int i=colCount;i<colCount+25;i++)
					write_pixel(x+i+20, y+j+20, LIGHTGRAY);
			}
		}
	}
}

void drawBoard(){
	for(int rowCount=0; rowCount<120; rowCount+=30){
		for(int colCount=0; colCount<120; colCount+=30){
			drawBox(rowCount, colCount);
		}
	}
}


void redraw(){
	int a=0; int b=0;
	for(int rowCount=0; rowCount<120; rowCount+=30){
		for(int colCount=0; colCount<120; colCount+=30){
			if(board[a][b] != 0)	drawBox(rowCount, colCount);
			b++;
		}
		b = 0;
		a++;
	}
}

void randomizer(){
	int initBox = rand() % 2+2;

	for(int i=0; i<initBox; i++){
		int initRow = rand() % 4;
		int initCol = rand() % 4;

		board[initRow][initCol] = 2;

   		write_text("2", (initCol*30)+30, (initRow*30)+30, RED, 0); 
	}

}