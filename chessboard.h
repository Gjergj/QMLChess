#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "piece.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "king.h"
#include "emptypiece.h"
#include "move.h"
#include <QObject>
#include <QAbstractListModel>
#include <QTimer>
#include <QJSEngine>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QVector>
#include <QFile>
class ChessBoard : public QAbstractListModel
{


    Q_OBJECT
    Q_PROPERTY(QString totalWhiteTime READ getTotalWhiteTime NOTIFY totalWhiteTimeChanged)
    Q_PROPERTY(QString totalBlackTime READ getTotalBlackTime NOTIFY totalBlackTimeChanged)
    Q_PROPERTY(QString warning READ getWarning NOTIFY warningChanged)

signals:
    void totalWhiteTimeChanged();
    void totalBlackTimeChanged();
    void warningChanged();
public:
    ChessBoard(QObject *parent = 0);
    ~ChessBoard();
    enum RoleNames {
        CellImageSourceRole = Qt::UserRole,
        CurrentPieceColorRole = Qt::UserRole+2,
        CurrentPieceRole = Qt::UserRole+3
    };
    QHash<int, QByteArray> roleNames() const;
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    void ReplayMove(const int PieceIndex, bool reverseMove);
    QString getTotalWhiteTime() const {return totalWhiteTime_;}
    QString getTotalBlackTime() const {return totalBlackTime_;}
    QString getWarning() const {return warning_;}


    Q_INVOKABLE int PieceClicked(const int PieceIndex);
    Q_INVOKABLE int StartGame();
    Q_INVOKABLE int StopGame();
    Q_INVOKABLE int SaveGame(const QString Path);
    Q_INVOKABLE int LoadGame(const QString Path);
    Q_INVOKABLE void Initialise();
    Q_INVOKABLE int PlayNextMove();
    Q_INVOKABLE int PlayPreviousMove();
    Q_INVOKABLE void RefreshView();
private slots:
    void updateTimer();
private:
    Piece* board[8][8];
    QString playerTurn;
    void NextPlayerTurn();
//    bool CanMove(QString color);
//    bool IsInCheck(QString color);
//    bool IsGameOver();
    bool firstMove = true;//tells if the move firs piece is selected, true is first move , false second move
    //int FirstRow = 0;
    //int FirstColumn = 0;
    //int SecondRow = 0;
    //int SecondColumn = 0;
    QTimer *timer;
    int blacksSeconds = 0;
    int whitesSeconds = 0;
    QString totalWhiteTime_;
    QString totalBlackTime_;
    bool gameStopped = false;
    bool gameInitialized = false;
    QVector<Move> moves;
    QVector<Move> previouseMoves;
    QVector<Piece*> previouseMovesPiece;
    QString warning_;
    Move currentMove;
};

#endif // CHESSBOARD_H
