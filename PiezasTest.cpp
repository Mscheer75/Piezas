/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, placedX)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	ASSERT_EQ(X, placed);
}

TEST(PiezasTest, placedDoubleO)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	ASSERT_EQ(O, placed);
}

TEST(PiezasTest, placedTripple)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	ASSERT_EQ(X, placed);
}

TEST(PiezasTest, placedQuad)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);

	ASSERT_EQ(Blank, placed);
}

TEST(PiezasTest, piece_at_reset)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	obj.reset();
	placed = obj.pieceAt(0,0);

	ASSERT_EQ(Blank, placed);
}

TEST(PiezasTest, piece_at_first_quadPlaced)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.pieceAt(0, 0);

	ASSERT_EQ(X, placed);
}

TEST(PiezasTest, piece_at_second_quadPlaced)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.pieceAt(1, 0);

	ASSERT_EQ(O, placed);
}

TEST(PiezasTest, piece_at_Third_quadPlaced)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.pieceAt(2, 0);

	ASSERT_EQ(X, placed);
}

TEST(PiezasTest, piece_at_fourth_Invalid)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.pieceAt(3, 0);

	ASSERT_EQ(Invalid, placed);
}

TEST(PiezasTest, piece_at_outOfBounds)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.pieceAt(4, 0);

	ASSERT_EQ(Invalid, placed);
}

TEST(PiezasTest, piece_at_quadPlaced_Blank)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.pieceAt(0, 1);

	ASSERT_EQ(Blank, placed);
}

TEST(PiezasTest, placedQuadPassIfNotO)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);

	ASSERT_NE(O, placed);
}

TEST(PiezasTest, placed_out_of_Bounds)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(-1);
	ASSERT_EQ(Invalid, placed);
}

TEST(PiezasTest, placed_out_of_Bounds2)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece(5);
	ASSERT_EQ(Invalid, placed);
}

TEST(PiezasTest, placed_char)
{
	Piezas obj;
	Piece placed = Invalid;
	placed = obj.dropPiece('a');
	ASSERT_EQ(Invalid, placed);
}

TEST(PiezasTest, gamestate_not_finished)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.gameState();
	ASSERT_EQ(Invalid, placed);
}


TEST(PiezasTest, gamestate_tie)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(3);

	placed = obj.gameState();
	ASSERT_EQ(Blank, placed);
}

TEST(PiezasTest, gamestate_tie2)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);

	placed = obj.gameState();
	ASSERT_EQ(Blank, placed);
} 

TEST(PiezasTest, gamestate_tie3)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);

	placed = obj.gameState();
	ASSERT_EQ(Blank, placed);
}

TEST(PiezasTest, gamestate_tie4)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(2);

	placed = obj.gameState();
	ASSERT_EQ(Blank, placed);
}

TEST(PiezasTest, gamestate_tie5)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);

	placed = obj.gameState();
	ASSERT_EQ(Blank, placed);
}

TEST(PiezasTest, gamestate_tie4_reset)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(2);
	obj.reset();
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(2);

	placed = obj.gameState();
	ASSERT_EQ(Blank, placed);
}

TEST(PiezasTest, gamestate_X_win)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(2);

	placed = obj.gameState();
	ASSERT_EQ(X, placed);
}


TEST(PiezasTest, gamestate_X_win2)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(3);

	placed = obj.gameState();
	ASSERT_EQ(X, placed);
}

TEST(PiezasTest, gamestate_X_win_Blowout)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);


	placed = obj.gameState();
	ASSERT_EQ(X, placed);
}

TEST(PiezasTest, pieaceAt_afterblowout)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);


	placed = obj.pieceAt(0,1);
	ASSERT_EQ(X, placed);
}

TEST(PiezasTest, pieaceAt_afterblowout2)
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);


	placed = obj.pieceAt(1,0);
	ASSERT_EQ(X, placed);
}

TEST(PiezasTest, pieaceAt_afterblowout_all)//this test was made after pure frustration
{
	Piezas obj;
	Piece placed = X;
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(0);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(1);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(2);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);
	placed = obj.dropPiece(3);
	placed = obj.dropPiece(6);

	placed = obj.pieceAt(0,0);
	ASSERT_EQ(X, placed);

	placed = obj.pieceAt(0,1);
	ASSERT_EQ(X, placed);

	placed = obj.pieceAt(0,2);
	ASSERT_EQ(X, placed);

	placed = obj.pieceAt(0,3);
	ASSERT_EQ(X, placed);

	placed = obj.pieceAt(1,0);
	ASSERT_EQ(X, placed);

	placed = obj.pieceAt(1,1);
	ASSERT_EQ(X, placed);

	placed = obj.pieceAt(1,2);
	ASSERT_EQ(X, placed);

	placed = obj.pieceAt(1,3);
	ASSERT_EQ(X, placed);

	placed = obj.pieceAt(2,0);
	ASSERT_EQ(X, placed);

	placed = obj.pieceAt(2,1);
	ASSERT_EQ(X, placed);

	placed = obj.pieceAt(2,2);
	ASSERT_EQ(X, placed);

	placed = obj.pieceAt(2,3);
	ASSERT_EQ(X, placed);




}
