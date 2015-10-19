// File: bishop.h 2015/09/17
// Author: Gjergji Ramku
// Description: Chess Piece Bishop Class
#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include <QColor>
#include <QUrl>

class Bishop : public Piece
{
public:
    Bishop(QString pieceColor, QString cellImageSource) : Piece(pieceColor, cellImageSource){}
    ~Bishop() {}
private:
    bool CanMove(const Move &CurrentMove, Piece* board[8][8]);
};

#endif // BISHOP_H
