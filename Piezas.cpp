#include "Piezas.h"
#include <vector>
#include <stdio.h>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{//resizes the board vector based on the Board sizes, then calls reset to set it to blank
	board.resize(BOARD_ROWS, std::vector <Piece> (BOARD_COLS));
	//reset(); <-- I thought I was being clevar by calling this but since you dont initialize it to turn x, this changes everything
	turn = X;	
	for(int i=0; i<BOARD_ROWS; i++)
		for(int j=0; j<BOARD_COLS; j++)
			board[i][j] = Blank;




}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{//traverse the board and sets it to blank 
	//turn = X;   <-- this should exist I think. Also students will mess this up, I wouldnt be surpised if this is a trap
	for(int i=0; i<BOARD_ROWS; i++)
		for(int j=0; j<BOARD_COLS; j++)
			board[i][j] = Blank;


}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
	bool placed = false;//a toggle to show if a piece has been placed 
	bool inBounds = false;//a toggle to toggle if the placement is inbounds
	Piece placedPiece = Blank;//a temporary palceholder to return what piece was played
	if( column <= BOARD_COLS && column > -1)
	{
		inBounds = true;
		for( int i = 0; i < BOARD_ROWS; i++)
		{
			if(board[i][column] == Blank && placed == false)
			{
				board[i][column] = turn;
				placed = true;
				placedPiece = turn;
			}
		
		}
	}

	if (turn == X)//this is to toggle whos turn it is
	{
		turn = O;
	}else if(turn == O)
	{
		turn = X;
	}

	if(!inBounds)
		placedPiece = Invalid;

    return placedPiece;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
	if(BOARD_ROWS > row && row >=0 && BOARD_COLS > column && column >= 0)//checks whats is in bounds
	{
		return board[row][column];//no need for a blank check, if the placement is blank it will return blank
	}

    return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
	int maxX = 0;
	int maxO = 0;

	int xCount = 1;
	int oCount = 1;
	for(int i = 0; i < BOARD_ROWS; i++)//this checks to see if the board is completely filled
	{
		for(int j =0; j < BOARD_COLS; j++)
		{
			if(board[i][j] == Blank || board[i][j] == Invalid)
				return Invalid;
		}
	}
	
	for(int i = 0; i < BOARD_ROWS; i++)//I am having a hard time on this logic 
	{
		
		/*this is supposed to check the cols and adds xCout or oCount based on the placement
		 *there is another nested for loop that checks the rows and adds them up
		 *this is getting tricky I been working on this for a few hours now
		 *
		 *
		 *I GOT IT!!!!!! 
		 * */
		xCount = 1;
		oCount = 1;
		for(int j =0; j< BOARD_COLS; j++)
		{
		        	
			if( j-1 >=0 && board[i][j] == board[i][j-1])
			{
				if(board[i][j] == X)
				{
					xCount++;
					if(xCount > maxX)
						maxX = xCount;
				}else
				{
					oCount++;
					if(oCount > maxO)
						maxO = oCount;


				}
			}
			else if(j-1 >=0) 
			{
				if(board[i][j-1] == X)
				{
					if(xCount > maxX)
						maxX = xCount;
					xCount = 1;
				}
				else if(board[i][j-1] == O )
				{
					if(oCount > maxO)
						maxO = oCount;

					oCount = 1;
				}
			}
			
		}
	}
	

	for(int i = 0; i < BOARD_COLS; i++)//nested for loop to check rows
	{
		xCount = 1;
		oCount = 1;

		for(int j =0; j < BOARD_ROWS; j++)
		{//in my mind I rotated the board and are counting the Rows as cols
			
			if(j-1 >=0 && board[j][i] == board[j-1][i]) 
			{
				if(board[j][i] == X )
				{
					xCount++;
					if(xCount > maxX)
						maxX = xCount;


				}else
				{
					oCount++;
					if(oCount > maxO)
						maxO = oCount;


				}
			}
			else if(BOARD_ROWS > j && j-1 >=0) 
			{
				if(board[j-1][i] == X)
				{
					if(xCount > maxX)
						maxX = xCount;
					xCount = 1;
				}
				else if(board[j-1][i] == O)
				{
					if(oCount > maxO)
						maxO = oCount;

					oCount = 1;
				}
			}	
		}
	}
	printf("maxX %i \n", maxX);
	printf("maxO %i \n", maxO);	
	if( maxX > maxO)
    		return X;
	else if(maxO > maxX)
		return O;
	else 
		return Blank;
}

