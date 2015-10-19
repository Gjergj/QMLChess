#include "knight.h"

bool Knight::CanMove(const Move &CurrentMove, Piece* board[8][8]){
    if ((CurrentMove.getFromColumn() == CurrentMove.getToColumn() + 1) || (CurrentMove.getFromColumn() == CurrentMove.getToColumn() - 1)) {
        if ((CurrentMove.getFromRow() == CurrentMove.getToRow() + 2) || (CurrentMove.getFromRow() == CurrentMove.getToRow() - 2)) {
            return true;
        }
    }
    if ((CurrentMove.getFromColumn() == CurrentMove.getToColumn() + 2) || (CurrentMove.getFromColumn() == CurrentMove.getToColumn() - 2)) {
        if ((CurrentMove.getFromRow() == CurrentMove.getToRow() + 1) || (CurrentMove.getFromRow() == CurrentMove.getToRow() - 1)) {
            return true;
        }
    }
    return false;
}
