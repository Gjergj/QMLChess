// File: rook.h 2015/09/17
// Author: Gjergji Ramku
// Description: Chess Piece Rook Class
#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
#include "piece.h"
#include <QColor>
#include <QUrl>

class Rook : public Piece
{
public:
    Rook(QString pieceColor, QString cellImageSource) : Piece(pieceColor, cellImageSource){}
private:
    bool CanMove(const Move &CurrentMove, Piece* board[8][8]);
};

#endif // ROOK_H
