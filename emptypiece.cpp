#include "emptypiece.h"

EmptyPiece::EmptyPiece()
{
}
EmptyPiece::~EmptyPiece(){

}

bool EmptyPiece::CanMove(const Move &CurrentMove, Piece* board[8][8]) {
    return false;//because you can not move an empty piece
}
