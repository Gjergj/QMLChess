// File: king.h 2015/09/17
// Author: Gjergji Ramku
// Description: Chess Piece King Class
#ifndef KING_H
#define KING_H
#include "piece.h"
#include <QColor>

class King : public Piece
{
public:
    King(QString pieceColor,QString cellImageSource) : Piece(pieceColor,cellImageSource){}
    ~King() {}
private:
    bool CanMove(const Move &CurrentMove, Piece* board[8][8]);
};

#endif // KING_H
