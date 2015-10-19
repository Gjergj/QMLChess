// File: queen.h 2015/09/17
// Author: Gjergji Ramku
// Description: Chess Piece Queen Class
#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include <QColor>
#include <QUrl>

class Queen : public Piece
{
public:
    Queen(QString pieceColor, QString cellImageSource) : Piece(pieceColor, cellImageSource){}
     ~Queen() {}
private:
    bool CanMove(const Move &CurrentMove, Piece* board[8][8]);
};

#endif // QUEEN_H
