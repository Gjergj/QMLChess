// File: piece.h 2015/09/17
// Author: Gjergji Ramku
// Description: Chess Piece Class
#ifndef TILE_H
#define TILE_H
#include <QObject>
#include <QString>
#include <QColor>
#include <QDebug>
#include "move.h"
class Piece : public QObject
{
public:
    Piece(QString pieceColor, QString cellImageSource );
    Piece();
    ~Piece();
    QString getCellImageSource() const{return cellImageSource_;}
    QString getCurrentPieceColor() const{return currentPieceColor_;}
    QString getCurrentPiece() const{return currentPiece_;}

    void setCellImageSource(QString img){  cellImageSource_ = img; }
    void setCurrentPieceColor(QString pieceColor){currentPieceColor_ = pieceColor;}
    void setCurrentPiece(QString piece){currentPiece_ = piece;}
    bool IsAllowedToMove(const Move &CurrentMove, Piece* board[8][8]);
protected:
    virtual bool CanMove(const Move &CurrentMove, Piece* board[8][8]) = 0;
    QString cellImageSource_;
    QString currentPieceColor_;
    QString currentPiece_;
};

#endif // TILE_H
