#include "piece.h"

Piece::Piece(QString pieceColor, QString cellImageSource )
{
    cellImageSource_ = cellImageSource;
    currentPieceColor_ = pieceColor;
}
Piece::Piece()
{
    currentPieceColor_ = "";
    currentPiece_ = "E";//empty
}
Piece::~Piece()
{

}
bool Piece::IsAllowedToMove(const Move &CurrentMove, Piece* board[8][8]){
    Piece* dstPiece = board[CurrentMove.getToRow()][CurrentMove.getToColumn()];
    if ((dstPiece == 0) || (currentPieceColor_ != dstPiece->getCurrentPieceColor())) {
        return CanMove(CurrentMove, board);
    }
    return false;
}

