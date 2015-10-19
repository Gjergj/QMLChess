#include "pawn.h"

bool Pawn::CanMove(const Move &CurrentMove, Piece* board[8][8]){
        Piece* dstPiece = board[CurrentMove.getToRow()][CurrentMove.getToColumn()];
        if (dstPiece->getCurrentPiece() == "E") {
            if (CurrentMove.getFromColumn() == CurrentMove.getToColumn()) {
                if (getCurrentPieceColor() == "W") {
                    if (CurrentMove.getToRow() == CurrentMove.getFromRow() + 1) {
                        return true;
                    }
                } else {
                    if (CurrentMove.getToRow() == CurrentMove.getFromRow() - 1) {
                        return true;
                    }
                }
            }
        } else {
            if ((CurrentMove.getFromColumn() == CurrentMove.getToColumn() + 1) || (CurrentMove.getFromColumn() == CurrentMove.getToColumn() - 1)) {
                if (getCurrentPieceColor() == "W") {
                    if (CurrentMove.getToRow() == CurrentMove.getFromRow() + 1) {
                        return true;
                    }
                } else {
                    if (CurrentMove.getToRow() == CurrentMove.getFromRow() - 1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
