// File: pawn.h 2015/09/17
// Author: Gjergji Ramku
// Description: Chess Piece Pawn Class
#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include <QColor>
class Pawn : public Piece
{
public:
    Pawn(QString pieceColor, QString cellImageSource) : Piece(pieceColor, cellImageSource){}
    ~Pawn() {}
private:
    bool CanMove(const Move &CurrentMove, Piece* board[8][8]);
};

#endif // PAWN_H
