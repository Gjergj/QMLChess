#include "rook.h"

bool Rook::CanMove(const Move &CurrentMove, Piece* board[8][8]){
    if (CurrentMove.getFromRow() == CurrentMove.getToRow()) {
        int colOffset = (CurrentMove.getToColumn() - CurrentMove.getFromColumn() > 0) ? 1 : -1;
        for (int checkCol = CurrentMove.getFromColumn() + colOffset; checkCol !=  CurrentMove.getToColumn(); checkCol = checkCol + colOffset) {
            if (board[CurrentMove.getFromRow()][checkCol]->getCurrentPiece() != "E") {
                return false;
            }
        }
        return true;
    } else if (CurrentMove.getToColumn() == CurrentMove.getFromColumn()) {
        int rowOffset = (CurrentMove.getToRow() - CurrentMove.getFromRow() > 0) ? 1 : -1;
        for (int checkRow = CurrentMove.getFromRow() + rowOffset; checkRow !=  CurrentMove.getToRow(); checkRow = checkRow + rowOffset) {
            if (board[checkRow][CurrentMove.getFromColumn()]->getCurrentPiece() != "E") {
                return false;
            }
        }
        return true;
    }
    return false;
}
