// File: emptypiece.h 2015/09/17
// Author: Gjergji Ramku
// Description: Chess EmptyPiece Class
#ifndef EMPTYPIECE_H
#define EMPTYPIECE_H
#include "piece.h"
#include <QColor>
#include <QUrl>
class EmptyPiece : public Piece
{
public:
    EmptyPiece(QString pieceColor,QString cellImageSource) : Piece(pieceColor, cellImageSource){}
    EmptyPiece();
    ~EmptyPiece();
private:
    bool CanMove(const Move &CurrentMove, Piece* board[8][8]);
};

#endif // EMPTYPIECE_H
