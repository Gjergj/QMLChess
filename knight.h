// File: knight.h 2015/09/17
// Author: Gjergji Ramku
// Description: Chess Piece Knight Class
#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
#include "piece.h"
#include <QColor>
#include <QUrl>

class Knight : public Piece
{
public:
    Knight(QString pieceColor, QString cellImageSource) : Piece(pieceColor, cellImageSource){}

private:
    bool CanMove(const Move &CurrentMove, Piece* board[8][8]);
};

#endif // KNIGHT_H
