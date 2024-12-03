#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

int intRand (int A, int P);
void rOnce (char x[], int xSize);
void randomsortE( );
void randomsortM( );
void randomsortH( );

void table_aE(int c , int r , char al[]);
void table_nE(int c, int r);

void table_aM(int c , int r , char al[]);
void table_nM(int c, int r);

void table_aH(int c , int r , char al[]);
void table_nH(int c, int r);

void PickCard_E();
void PickCard_M();
void PickCard_H();

void swap_E(int , int );
void swap_M(int , int );
void swap_H(int , int );
char name; 
int end = 1; 
int newscore;


//global variable
char alphabet_E[9]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
char alphabet_M[16]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
char alphabet_H[25]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O','P','Q','R','S','T','U','V','W','X','Y'};    

//Scoreboard
char playername[50];
int attemptno;

int easy(int, int, int); //declare easy score calculation function
int printeasy(int, int, int, int); // declare print easy scoreboard function

int moderate(int, int, int); //declare moderate score calculation function
int printmoderate(int, int, int, int); // declare print moderate scoreboard function

int hard(int, int, int); //declare hard score calculation function
int printhard(int, int, int, int); // declare print hard scoreboard function

struct playerData 
{                       /* playerData structure definition */
  
	char playername[50]; 		/* player nickname */
	char difficulty[15]; 	/* game difficulty level */
	int attemptno;			/* no. of attempts */
	int timetaken;			/* time taken */
	int score;      		/* player score */
	
}; /* end structure playerData */

void readFile( FILE *readPtr ); //read file
void newRecord( FILE *fPtr ); //add player record
int enterChoice( void ); //user choose

char ask;

int main() {
	
    int columns_E = 3, rows_E = 3;
    int columns_M = 4, rows_M = 4;
    int columns_H = 5, rows_H = 5;
	int num_E = columns_E*rows_E;
	int num_M = columns_M*rows_M;
	int num_H = columns_M*rows_H;
	
	int z; //for incorrect difficulty letter loop
    char choose; //choose difficulty
    char beep = '\007'; //7 in Ascii table is bell
    printf("%c",beep);
    
	//set the random seed intRand
    srand(time(0));
    
    FILE *cfPtr; /* playerrecord.dat file pointer */
	int choice;//choice for file after the game
   	
	do {
		end=1;
		printf("\t***Brain Workout Game***\n\n");
        printf( "Enter your name : ");
   	    gets(playername);		//use gets() to get player name string
		printf("\nChoose a difficulty level for the game \n[[E]-Easy || [M]-Moderate || [H]-Hard] : ");
		scanf("%c",&choose);
		
		if (tolower(choose)=='e') {
			
			int cards = 9;
			int Easygamescore = 0;
			
			printf("You have choose Easy Mode and you have 2 seconds\n ");
			clock_t start, end;
			start = clock();  //start time
			
			//print random array
			randomsortE(); { //random for EASY
       		table_aE(columns_E, rows_E, alphabet_E);
   			printf("\a");
			Sleep(2000);     
        
			system("cls");
			table_nE(columns_E, rows_E);
			
			end = clock();  //end time
   			int duration = ((int)end - start)/CLOCKS_PER_SEC;  //time taken
   			
   			Easygamescore = easy(cards, duration, attemptno);  //score calculation function
   			printeasy(Easygamescore, cards, duration, attemptno);  //scoreboard print function
   			
   			if ((cfPtr = fopen( "playerrecord.dat", "rb+")) == NULL) { 
				printf( "\nFile could not be opened.\n" );
			} /* end if */
			
			else {
				while ( ( choice = enterChoice() ) != 3 ) {
					switch ( choice ) {
						case 1:	/* file to read from record file */
						readFile( cfPtr );
						break;
					case 2: 	/* new record */
						newRecord( cfPtr );
						break;
					default:	printf( "Incorrect choice\n" );
					break;
					} /* end switch */
				} /* end while */
			fclose(cfPtr);
			} //end else
			} //end randomsort
		}//end easy game level
		
		else if (tolower(choose)=='m'){
			
			int cards = 16;
			int Moderategamescore = 0;
			
			printf("You have choose Moderate Mode and you have 3 seconds\n");	
			clock_t start, end;
			start = clock();  //start time
			
			//print random array
			randomsortM(); { //random untuk MODERATE
	    	table_aM(columns_M, rows_M, alphabet_M);
			printf("\a");
			Sleep(3000);
		
			system("cls");
			table_nM(columns_M, rows_M);
			
			end = clock();  //end time
   			int duration = ((int)end - start)/CLOCKS_PER_SEC;  //time taken
   			
   			Moderategamescore = moderate(cards, duration, attemptno);  //score calculation function
   			printmoderate(Moderategamescore, cards, duration, attemptno);  //scoreboard print function
   			
   			if ((cfPtr = fopen( "playerrecord.dat", "rb+")) == NULL) {
				printf( "\nFile could not be opened.\n" );
			} /* end if */
			else {
				while ( ( choice = enterChoice() ) != 3 ) {
					switch ( choice ) {
						case 1:	/* read file from record file */
						readFile( cfPtr );
						break;
					case 2: 	/* new record */
						newRecord( cfPtr );
						break;
					default:	printf( "Incorrect choice\n" );
					break;
					} /* end switch */
				} /* end while */
			fclose(cfPtr);
			} //end else
			} //end randomsort	
		}//end moderate game level
		
		else if (tolower(choose)=='h'){
			
			int cards = 25;
			int Hardgamescore = 0;
			
			printf("You have choose Hard Mode and you have 5 seconds\n");
	    	clock_t start, end;
			start = clock();  //start time
	    	
	    	//print random array
			randomsortH(); { //random untuk HARD
			table_aH(columns_H, rows_H, alphabet_H);
			printf("\a");
			Sleep(5000);
		
			system("cls");
			table_nH(columns_H, rows_H);
			
			end = clock();  //end time
   			int duration = ((int)end - start)/CLOCKS_PER_SEC;  //time taken
   			
   			Hardgamescore = hard(cards, duration, attemptno);  //score calculation function
   			printhard(Hardgamescore, cards, duration, attemptno);  //scoreboard print function
   			
   			if ((cfPtr = fopen( "playerrecord.dat", "rb+")) == NULL) {
				printf( "\nFile could not be opened.\n" );
			} /* end if */
			else {
				while ( ( choice = enterChoice() ) != 3 ) {
					switch ( choice ) {
						case 1:	/* read file from record file */
						readFile( cfPtr );
						break;
					case 2: 	/* new record */
						newRecord( cfPtr );
						break;
					default:	printf( "Incorrect choice\n" );
					break;
					} /* end switch */
				} /* end while */
			fclose(cfPtr);
			} //end else
			} //end randomsort
		}//end hard game level
		
		else {
			
	    	printf("\nIncorrect input, please try again!\n");
			
		}
		printf("\nWould you like to play again? (Y/N) : ");
	    fflush(stdin);
	    scanf("%c", &ask);
	    ask = toupper(ask);
	    
   	    gets(playername);		//use gets() to get player name string
	    
    }while(ask == 'Y');
    printf("Thanks for playing!");
    
	return 0;
}

//get integer random number in range A <= x <= P
    int intRand (int A, int P){
    double r = P - A + 1;
    return A + (int)(r * rand()/(RAND_MAX + 1.0));
    }

    int no_E [3][3]={1,2,3,4,5,6,7,8,9};
	int no_M [4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int no_H [5][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    
//get integer random number in range 0 <= x <= num of items of array
void rOnce (char x[], int xSize){
    int i, k;
    for(i=0 ; i<xSize ; ++i){
    //get next random char		
        x[i] = alphabet_E[intRand(0, xSize-1)];		
    	if(i>0){	
    		//test the char on repeating
    		for  (k=0 ; k<i ; ++k){
    			//get another random number
    			while (x[i]==x[k]){
    				x[i] = alphabet_E[intRand(0,xSize-1)];
    				k=0;
				}
			}
		}
	}	
}

//randomsort for Easy Mode
void randomsortE( ){
	int random_num;
	char temp;
	
	for(int i=0; i<9; i++)
	{
		random_num = intRand(0,8);
		
		temp = alphabet_E[i];
		alphabet_E[i] = alphabet_E[random_num];
		alphabet_E[random_num] = temp;
	}
}

//randomsort for Moderate Mode
void randomsortM( ){
	int random_num;
	char temp;
	
	for(int i=0; i<16; i++)
	{
		random_num = intRand(0,15);
		
		temp = alphabet_M[i];
		alphabet_M[i] = alphabet_M[random_num];
		alphabet_M[random_num] = temp;
	}
}  

//randomsort for Hard Mode
void randomsortH( ){
	int random_num;
	char temp;
	
	for(int i=0; i<25; i++)
	{
		random_num = intRand(0,24);
		
		temp = alphabet_H[i];
		alphabet_H[i] = alphabet_H[random_num];
		alphabet_H[random_num] = temp;
	}
}

//Table utk alphabet_E  
void table_aE(int c , int r , char al[]){
	
	
	printf("\n");
    printf("\t _______________________\n");
    
	for(int row = 0; row<r;row++){
		printf("\t|       |       |       |\n");
		for(int col=0; col<c;col++){ 
			printf("\t|   %c",al[col+row*c]);
			if(col==c-1)
			printf("\t|");
		}
	    printf("\n");
		printf("\t|_______|_______|_______|\n");

		if(c<3){
		printf("\t|       |       |       |\n");
		}
	}  
}

//Table utk number_E + ENDGAME
void table_nE(int c, int r) {
	int columns_E = 3, rows_E = 3;
	
	do {
	
	printf("Please choose your card");   	    
 	printf("\n");
	printf("\t _______________________\n");   	    
  		for(int r = 0; r<3 ; r++){
			printf("\t|       |       |       |\n");
			for(int c=0; c<3 ; c++){ 
				printf("\t|   %d",no_E[r][c]);
				if(c==2)
				printf("\t|");
			}
			printf("\n");
			printf("\t|_______|_______|_______|\n");
		}
	//pickcard loop
	if (end!=0) {
		
		PickCard_E();
		
	}
	}while(end!=0);
	
	table_aE(columns_E, rows_E, alphabet_E);
	printf("\n\nCongratulation %s. You have completed the game!!!\n", playername);	
}
	
//Table utk alphabet_M  
void table_aM(int c , int r , char al[]){
	printf("\n");
    printf("\t _______________________________\n");
    
	for(int row = 0; row<r;row++){
		printf("\t|       |       |       |       |\n");
		for(int col=0; col<c;col++){
			printf("\t|   %c",al[col+row*c]);
			if(col==c-1)
			printf("\t|");
		}
	    printf("\n");
		printf("\t|_______|_______|_______|_______|\n");

		if(c<3){
		printf("\t|       |       |       |       |\n");
		}
	}
}

//Table utk number_M + ENDGAME
void table_nM(int c, int r){
	int columns_M = 4, rows_M = 4;
	
	do {
		
	printf("Please choose your card");   	    
    printf("\n");
	printf("\t _______________________________\n");   	    
    for(int r = 0; r<4 ; r++){
		printf("\t|       |       |       |       |\n");
		for(int c=0; c<4 ; c++){ 
			printf("\t|   %d",no_M[r][c]);
			if(c==3)
			printf("\t|");
		}
	    printf("\n");
		printf("\t|_______|_______|_______|_______|\n");
	}
	
	//pickcard loop
    if (end!=0) {
		
		PickCard_M();
		
	}
	}while(end!=0);
	
	table_aM(columns_M, rows_M, alphabet_M);
	printf("\n\nCongratulation %s. You have completed the game!!!\n", playername);
}

//Table utk alphabet_H  
void table_aH(int c , int r , char al[]){
	printf("\n");
    printf("\t _______________________________________\n");
    
	for(int row = 0; row<r;row++){
		printf("\t|       |       |       |       |       |\n");
		for(int col=0; col<c;col++){
			printf("\t|   %c",al[col+row*c]);
			if(col==c-1)
			printf("\t|");
		}
	    printf("\n");
		printf("\t|_______|_______|_______|_______|_______|\n");

		if(c<3){
		printf("\t|       |       |       |       |       |\n");
		}
	}
}

//Table utk number_H + ENDGAME
void table_nH(int c, int r){
	int columns_H = 5, rows_H = 5;
	
	do {
		
	printf("Please choose your card");   	    
    printf("\n");
	printf("\t _______________________________________\n");   	    
    for(int r = 0; r<5 ; r++){
		printf("\t|       |       |       |       |       |\n");
		for(int c=0; c<5 ; c++){ 
			printf("\t|   %d",no_H[r][c]);
			if(c==4)
			printf("\t|");
		}
	    printf("\n");
		printf("\t|_______|_______|_______|_______|_______|\n");
	}
	
	//pickcard loop
    if (end!=0) {
    	
		PickCard_H();
		
	}
	}while(end!=0);
	
	table_aH(columns_H, rows_H, alphabet_H);
	printf("\n\nCongratulation %s. You have completed the game!!!\n", playername);
}

void PickCard_E() {
	int card1 = 0, card2 = 0;
	
	do {
		if(card1>9 || card2>9){
			printf("\n\nInvalid card number!!! Please try again!\a");
		}
		
		printf("\nPick your first card : ");
		scanf("%d", &card1);
		
		printf("Pick your second card : ");
		scanf("%d", &card2);
		
		attemptno++;  //increase no of attempts
		
	}while(card1>9 || card2>9);
	
	//array start from 0
	card1-=1;
	card2-=1;
	printf("First card is '%c' and Second card is '%c'\n", alphabet_E[card1], alphabet_E[card2]);
	swap_E(card1,card2);
	
	//to end the game
	if (alphabet_E[0]=='A' && alphabet_E[1]=='B' && alphabet_E[2]=='C' && alphabet_E[3]=='D' && alphabet_E[4]=='E' && alphabet_E[5]=='F' && alphabet_E[6]=='G' && alphabet_E[7]=='H' && alphabet_E[8]=='I'){
	end--;
	}
}

void PickCard_M() {
	int card1 = 0, card2 = 0;
	
	do {
		if(card1>16 || card2>16){
			printf("\n\nInvalid card number!!! Please try again!\a");
		}
		
		printf("\nPick your first card : ");
		scanf("%d", &card1);
		
		printf("Pick your second card : ");
		scanf("%d", &card2);
		
		attemptno++;  //increase no of attempts
			
	}while(card1>16 || card2>16);
	
	//array start from 0	
	card1-=1;
	card2-=1;
	
	printf("First card is '%c' and Second card is '%c'\n", alphabet_M[card1], alphabet_M[card2]);	
	swap_M(card1,card2);
	
	//to end the game
	if (alphabet_M[0]=='A' && alphabet_M[1]=='B' && alphabet_M[2]=='C' && alphabet_M[3]=='D' && alphabet_M[4]=='E' && alphabet_M[5]=='F' && alphabet_M[6]=='G' && alphabet_M[7]=='H' && alphabet_M[8]=='I' && alphabet_M[9]=='J' && alphabet_M[10]=='K' && alphabet_M[11]=='L' && alphabet_M[12]=='M' && alphabet_M[13]=='N' && alphabet_M[14]=='O' && alphabet_M[15]=='P'){
	end--;
	}
}

void PickCard_H() {
	int card1 = 0, card2 = 0;
	
	do {
		if(card1>25 || card2>25){
			printf("\n\nInvalid card number!!! Please try again!\a");
		}
		
		printf("\nPick your first card : ");
		scanf("%d", &card1);
		
		printf("Pick your second card : ");
		scanf("%d", &card2);
		
		attemptno++; //increase no of attempts
		
	}while(card1>25 || card2>25);
	
	//array start from 0
	card1-=1;
	card2-=1;
	
	printf("First card is '%c' and Second card is '%c'\n", alphabet_H[card1], alphabet_H[card2]);	
	swap_H(card1,card2);
	
	//to end the game
	if (alphabet_H[0]=='A' && alphabet_H[1]=='B' && alphabet_H[2]=='C' && alphabet_H[3]=='D' && alphabet_H[4]=='E' && alphabet_H[5]=='F' && alphabet_H[6]=='G' && alphabet_H[7]=='H' && alphabet_H[8]=='I' && alphabet_H[9]=='J' && alphabet_H[10]=='K' && alphabet_H[11]=='L' && alphabet_H[12]=='M' && alphabet_H[13]=='N' && alphabet_H[14]=='O' && alphabet_H[15]=='P' && alphabet_H[16]=='Q' && alphabet_H[17]=='R' && alphabet_H[18]=='S' && alphabet_H[19]=='T' && alphabet_H[20]=='U' && alphabet_H[21]=='V' && alphabet_H[22]=='W' && alphabet_H[23]=='X' && alphabet_H[24]=='Y'){
	end--;
	}	
}
  
void swap_E(int card1, int card2){ //untuk swap alphabet_E
	
	char temp;
	temp = alphabet_E[card1];
	alphabet_E[card1] = alphabet_E[card2];
	alphabet_E[card2] = temp;
	
	printf("\nAfter swapping : Card %d is '%c' and Card %d is '%c'\n\n",card1+1, alphabet_E[card1], card2+1, alphabet_E[card2]);
        
	//this part is for for showing correctly swapped letter
	if (alphabet_E[0]=='A') {
		printf("Alphabet 'A' is correctly swapped!\n");
	}
	if (alphabet_E[1]=='B') {
		printf("Alphabet 'B' is correctly swapped!\n");
	}
	if (alphabet_E[2]=='C') {
		printf("Alphabet 'C' is correctly swapped!\n");
	}
	if (alphabet_E[3]=='D') {
		printf("Alphabet 'D' is correctly swapped!\n");
	}
	if (alphabet_E[4]=='E') {
		printf("Alphabet 'E' is correctly swapped!\n");
	}
	if (alphabet_E[5]=='F') {
		printf("Alphabet 'F' is correctly swapped!\n");
	}
	if (alphabet_E[6]=='G') {
		printf("Alphabet 'G' is correctly swapped!\n");
	}
	if (alphabet_E[7]=='H') {
		printf("Alphabet 'H' is correctly swapped!\n");
	}
	if (alphabet_E[8]=='I') {
		printf("Alphabet 'I' is correctly swapped!\n");
	}	
}

void swap_M(int card1, int card2){ //untuk swap alphabet_M
	
	char temp;
	temp = alphabet_M[card1];
	alphabet_M[card1] = alphabet_M[card2];
	alphabet_M[card2] = temp;
	
	printf("\nAfter swapping : Card %d is '%c' and Card %d is '%c'\n\n",card1+1, alphabet_M[card1], card2+1, alphabet_M[card2]);
	
	//this part is for for showing correctly swapped letter
	if (alphabet_M[0]=='A') {
		printf("Alphabet 'A' is correctly swapped!\n");
	}
	if (alphabet_M[1]=='B') {
		printf("Alphabet 'B' is correctly swapped!\n");
	}
	if (alphabet_M[2]=='C') {
		printf("Alphabet 'C' is correctly swapped!\n");
	}
	if (alphabet_M[3]=='D') {
		printf("Alphabet 'D' is correctly swapped!\n");
	}
	if (alphabet_M[4]=='E') {
		printf("Alphabet 'E' is correctly swapped!\n");
	}
	if (alphabet_M[5]=='F') {
		printf("Alphabet 'F' is correctly swapped!\n");
	}
	if (alphabet_M[6]=='G') {
		printf("Alphabet 'G' is correctly swapped!\n");
	}
	if (alphabet_M[7]=='H') {
		printf("Alphabet 'H' is correctly swapped!\n");
	}
	if (alphabet_M[8]=='I') {
		printf("Alphabet 'I' is correctly swapped!\n");
	}
	if (alphabet_M[9]=='J') {
		printf("Alphabet 'J' is correctly swapped!\n");
	}
	if (alphabet_M[10]=='K') {
		printf("Alphabet 'K' is correctly swapped!\n");
	}
	if (alphabet_M[11]=='L') {
		printf("Alphabet 'L' is correctly swapped!\n");
	}
	if (alphabet_M[12]=='M') {
		printf("Alphabet 'M' is correctly swapped!\n");
	}
	if (alphabet_M[13]=='N') {
		printf("Alphabet 'N' is correctly swapped!\n");
	}
	if (alphabet_M[14]=='O') {
		printf("Alphabet 'O' is correctly swapped!\n");
	}
	if (alphabet_M[15]=='P') {
		printf("Alphabet 'P' is correctly swapped!\n");
	}
}

void swap_H(int card1, int card2){ //untuk swap alphabet_H
	
	char temp;
	temp = alphabet_H[card1];
	alphabet_H[card1] = alphabet_H[card2];
	alphabet_H[card2] = temp;
	
	printf("\nAfter swapping : Card %d is '%c' and Card %d is '%c'\n\n",card1+1, alphabet_H[card1], card2+1, alphabet_H[card2]);
	
	//this part is for for showing correctly swapped letter
	if (alphabet_H[0]=='A') {
		printf("Alphabet 'A' is correctly swapped!\n");
	}
	if (alphabet_H[1]=='B') {
		printf("Alphabet 'B' is correctly swapped!\n");
	}
	if (alphabet_H[2]=='C') {
		printf("Alphabet 'C' is correctly swapped!\n");
	}
	if (alphabet_H[3]=='D') {
		printf("Alphabet 'D' is correctly swapped!\n");
	}
	if (alphabet_H[4]=='E') {
		printf("Alphabet 'E' is correctly swapped!\n");
	}
	if (alphabet_H[5]=='F') {
		printf("Alphabet 'F' is correctly swapped!\n");
	}
	if (alphabet_H[6]=='G') {
		printf("Alphabet 'G' is correctly swapped!\n");
	}
	if (alphabet_H[7]=='H') {
		printf("Alphabet 'H' is correctly swapped!\n");
	}
	if (alphabet_H[8]=='I') {
		printf("Alphabet 'I' is correctly swapped!\n");
	}
	if (alphabet_H[9]=='J') {
		printf("Alphabet 'J' is correctly swapped!\n");
	}
	if (alphabet_H[10]=='K') {
		printf("Alphabet 'K' is correctly swapped!\n");
	}
	if (alphabet_H[11]=='L') {
		printf("Alphabet 'L' is correctly swapped!\n");
	}
	if (alphabet_H[12]=='M') {
		printf("Alphabet 'M' is correctly swapped!\n");
	}
	if (alphabet_H[13]=='N') {
		printf("Alphabet 'N' is correctly swapped!\n");
	}
	if (alphabet_H[14]=='O') {
		printf("Alphabet 'O' is correctly swapped!\n");
	}
	if (alphabet_H[15]=='P') {
		printf("Alphabet 'P' is correctly swapped!\n");
	}
	if (alphabet_H[16]=='Q') {
		printf("Alphabet 'Q' is correctly swapped!\n");
	}
	if (alphabet_H[17]=='R') {
		printf("Alphabet 'R' is correctly swapped!\n");
	}
	if (alphabet_H[18]=='S') {
		printf("Alphabet 'S' is correctly swapped!\n");
	}
	if (alphabet_H[19]=='T') {
		printf("Alphabet 'T' is correctly swapped!\n");
	}
	if (alphabet_H[20]=='U') {
		printf("Alphabet 'U' is correctly swapped!\n");
	}
	if (alphabet_H[21]=='V') {
		printf("Alphabet 'V' is correctly swapped!\n");
	}
	if (alphabet_H[22]=='W') {
		printf("Alphabet 'W' is correctly swapped!\n");
	}
	if (alphabet_H[23]=='X') {
		printf("Alphabet 'X' is correctly swapped!\n");
	}
	if (alphabet_H[24]=='Y') {
		printf("Alphabet 'Y' is correctly swapped!\n");
	}
}

//calculate player easy score
int easy(int cards, int duration, int attemptno) //pass by values
{
	return (cards + ((60-duration)*3) + ((cards-attemptno)*5));
}
                    
//calculate player moderate score
int moderate(int cards, int duration, int attemptno) //pass by values
{
	return (cards + ((90-duration)*3) + ((cards-attemptno)*5));
}

//calculate player hard score
int hard(int cards, int duration, int attemptno) //pass by values
{
	return (cards + ((120-duration)*3) + ((cards-attemptno)*5));
}


//print player scoreboard
int printeasy(int Easygamescore, int cards, int duration, int attemptno) //pass by values
{	
	char gamelevel[10];
	char recordholder[10];
	int topscore = 164;
	int topattempt = 8;
	int toptime = 10;
	strcpy(gamelevel, "Easy");
	strcpy(recordholder, "Doraemon");
	printf( "\nGame Level : %s", gamelevel);
	printf( "\t\t\tRecord holder : %s", recordholder);
	printf( "\nYour score : %d", Easygamescore);
	printf( "\t\t\tTop Score : %d", topscore );
   	printf( "\nNo. of Attempt : %d", attemptno);
   	printf( "\t\t\tNo. of Attempt : %d", topattempt );
   	printf( "\nTime Taken : %d second ", duration);
   	printf( "\t\t\tTime Taken : %d", toptime);
   	return 0;

}

//print player scoreboard
int printmoderate(int moderategamescore, int cards, int duration, int attemptno) //pass by values
{
	char gamelevel[10];
	char recordholder[10];
	int topscore = 206;
	int topattempt = 16;
	int toptime = 20;
	strcpy(gamelevel, "Moderate");
	strcpy(recordholder, "Zach");
	printf( "\nGame Level : %s", gamelevel);
	printf( "\t\t\tRecord holder : %s", recordholder );
	printf( "\nYour score : %d", moderategamescore);
	printf( "\t\t\tTop Score : ", topscore );
   	printf( "\nNo. of Attempt : %d", attemptno);
   	printf( "\t\t\tNo. of Attempt : ", topattempt );
   	printf( "\nTime Taken : %d second ", duration);
   	printf( "\t\t\tTime Taken : ", toptime );
   	return 0;
	
}

//print player scoreboard
int printhard(int Hardgamescore, int cards, int duration, int attemptno) //pass by values
{
	char gamelevel[10];
	char recordholder[10];
	int topscore = 295;
	int topattempt = 25;
	int toptime = 30;
	strcpy(gamelevel, "Hard");
	strcpy(recordholder, "Joe");
	printf( "\nGame Level : %s", gamelevel);
	printf( "\t\t\tRecord holder : %s", recordholder );
	printf( "\nYour score : %d", Hardgamescore);
	printf( "\t\t\tTop Score : ", topscore );
   	printf( "\nNo. of Attempt : %d", attemptno);
   	printf( "\t\t\tNo. of Attempt : ", topattempt );
   	printf( "\nTime Taken : %d second ", duration);
   	printf( "\t\tTime Taken : ", toptime );
   	return 0;
	
}

/* create formatted text file for printing */
void readFile( FILE *readPtr ) {
	FILE *cfPtr; /* playerrecord.dat file pointer */
	
	/* create playerData with default information */
	struct playerData player = {"", "", 0, 0, 0 }; 
	
	if ((cfPtr = fopen( "playerrecord.dat", "rb")) == NULL) {
		printf( "\nFile could not be opened.\n" );
	} /* end if */
	else {
		printf("\n\n%s\t%s\t%s\t\t%s\t%s\t\n", "Nickname", "Difficulty Level", 
				   "No. of Attempts", "Time Taken", "Your Score" );
				   
		while ( !feof( cfPtr ) ) {
			fread( &player, sizeof(struct playerData),1, cfPtr);
			/* display record */
			if ( player.score != 0 ) {
				printf("%6s\t\t%9s%23d%23d%15d\n\n",
				player.playername, player.difficulty, 
				player.attemptno, player.timetaken, player.score );
			} /* end if */
		} /* end while */
		fclose( cfPtr ); /* fclose closes the file */
	} /* end else */
}


/* create and insert record */
void newRecord( FILE *fPtr )  {
	FILE *cfPtr; /* playerrecord.dat file pointer */
	
	/* create playerData with default information */
	struct playerData player = {"", "", 0, 0, 0 };
	
	if ((cfPtr = fopen( "playerrecord.dat", "rb+")) == NULL) {
		printf( "\nFile could not be opened.\n" );
	} /* end if */
	else {
		printf( "Enter your score : ");
		scanf("%d", &player.score);

		printf( "Enter your nickname, difficulty level, no. of attempts, time taken\n\n" );
			
		fscanf(stdin, "%s%s%d%d", player.playername, player.difficulty, &player.attemptno, &player.timetaken);
			
		/* move file pointer to correct record in file */
		fseek(cfPtr,(player.score-1)*sizeof(struct playerData),SEEK_SET);
			
		/* write user-specified information in file */
		fwrite( &player, sizeof( struct playerData ), 1, cfPtr);
		}
	fclose ( cfPtr ); /* fclose closes the file */
}
	
/* enable user to input menu choice */
int enterChoice( void ) {
	int menuChoice; /* variable to store user's choice */
	
	/* display available options */
	printf( "\n\nEnter your choice\n"
			"1 - open .dat file of player records called \"playerrecords.dat\" for reading\n"
			"2 - add your record\n"
			"3 - end program\n? " );
	scanf( "%d", &menuChoice ); /* receive choice from user */
	return menuChoice;
} /* end function enterChoice */
