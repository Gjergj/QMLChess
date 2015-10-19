#include "chessboard.h"

ChessBoard::ChessBoard(QObject *parent)
    : QAbstractListModel(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
}
int ChessBoard::StartGame(){
    timer->start(1000);
    gameStopped = false;
    return 0;
}

int ChessBoard::StopGame(){
    gameStopped = true;
    timer->stop();
    return 0;
}
void ChessBoard::updateTimer(){
    if(playerTurn == "W"){
        if(whitesSeconds == 86400)//max 24 hour match, to much caffeine in your blood
            whitesSeconds = 0;
        whitesSeconds++;
        int minutes = whitesSeconds / 60;
        int hours = minutes / 60;
        int seconds = whitesSeconds % 60;
        totalWhiteTime_ = QString::number(hours) + ":" + QString::number(minutes) + ":" +  QString::number(seconds);
        emit totalWhiteTimeChanged();
    }
    else{
        if(blacksSeconds == 86400)//max 24 hour match, to much caffeine in your blood
            blacksSeconds = 0;
        blacksSeconds++;
        int minutes = blacksSeconds / 60;
        int hours = minutes / 60;
        int seconds = blacksSeconds % 60;
        totalBlackTime_ = QString::number(hours) + ":" + QString::number(minutes) + ":" +  QString::number(seconds);
        emit totalBlackTimeChanged();
    }
}
int ChessBoard::SaveGame(const QString Path){
    if(gameStopped){

        QJsonObject gameObject;
        QJsonArray jsonMoveArray;
        foreach (const Move move, moves) {
            QJsonObject moveObject;
            move.write(moveObject);
            jsonMoveArray.append(moveObject);
        }
        gameObject["ChessGame"] = jsonMoveArray;
        QUrl filePath(Path);
        QFile saveFile( filePath.toLocalFile());

        if (!saveFile.open(QIODevice::WriteOnly)) {
            warning_ = "Couldn't save to file.";
            emit warningChanged();
            return -1;
        }
        QJsonDocument saveDoc(gameObject);
        saveFile.write(saveDoc.toJson());
    }
    return 0;
}
int ChessBoard::LoadGame(const QString Path){

    QUrl filePath(Path);
    QFile ReadFile( filePath.toLocalFile());

    if (!ReadFile.open(QIODevice::ReadOnly)) {
        warning_ = "Couldn't read file.";
        emit warningChanged();
        return -1;
    }
    QByteArray saveData = ReadFile.readAll();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(saveData,&jsonError));
    if(jsonError.error != QJsonParseError::NoError){
        warning_ = "Saved Game file error";
        emit warningChanged();
        return -1;
    }
    moves.clear();
    previouseMoves.clear();
    previouseMovesPiece.clear();
    QJsonObject movesObj = jsonDoc.object();
    QJsonArray movesArray = movesObj["ChessGame"].toArray();
    for (int moveIndex = 0; moveIndex < movesArray.size(); ++moveIndex) {
        QJsonObject moveObject = movesArray[moveIndex].toObject();
        Move move;
        move.read(moveObject);
        moves.push_back(move);
    }

    return 0;
}

ChessBoard::~ChessBoard() {
    if(gameInitialized){
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if(board[row][col] != 0){
                    delete board[row][col];
                    board[row][col] = 0;
                }
            }
        }
        for (QVector<Piece*>::const_iterator i = previouseMovesPiece.constBegin(); i != previouseMovesPiece.constEnd(); ++i)
            delete *i;
    }
}
QHash<int, QByteArray> ChessBoard::roleNames() const {
    QHash<int, QByteArray> m_roleNames;
    m_roleNames[CellImageSourceRole] = "CellImageSource";
    m_roleNames[CurrentPieceColorRole] = "CurrentPieceColor";
    m_roleNames[CurrentPieceRole] = "CurrentPiece";
    return m_roleNames;
}
int ChessBoard::rowCount(const QModelIndex &parent) const
{
    return 64;
}
QVariant ChessBoard::data(const QModelIndex &index, int role) const
{
    int IndexNum = index.row();
    if(IndexNum < 0 || IndexNum >= 64) {
        return QVariant();
    }
    int row = IndexNum/8;
    int column = IndexNum % 8;
    const Piece* piece = board[row][column];

    switch(role) {
    case CellImageSourceRole:
        return piece->getCellImageSource();
    case CurrentPieceColorRole:
        return piece->getCurrentPieceColor();
    case CurrentPieceRole:
        return piece->getCurrentPiece();
    }
    return QVariant();
}

void ChessBoard::Initialise()
{
    totalWhiteTime_ = "00:00:00";
    totalBlackTime_ = "00:00:00";
    if(gameInitialized){
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                delete board[row][col];
                board[row][col] = 0;
            }
        }
    }
    gameInitialized = true;
    for (int col = 0; col < 8; ++col) {
        board[6][col] = new Pawn("B","qrc:/img/pawnb.svg");
    }
    board[7][0] = new Rook("B","qrc:/img/rookb.svg");
    board[7][1] = new Knight("B","qrc:/img/knightb.svg");
    board[7][2] = new Bishop("B","qrc:/img/bishopb.svg");
    board[7][3] = new King("B","qrc:/img/kingb.svg");
    board[7][4] = new Queen("B","qrc:/img/queenb.svg");
    board[7][5] = new Bishop("B","qrc:/img/bishopb.svg");
    board[7][6] = new Knight("B","qrc:/img/knightb.svg");
    board[7][7] = new Rook("B","qrc:/img/rookb.svg");


    for (int col = 0; col < 8; ++col) {
        board[2][col] = new EmptyPiece();
    }
    for (int col = 0; col < 8; ++col) {
        board[3][col] = new EmptyPiece();
    }
    for (int col = 0; col < 8; ++col) {
        board[4][col] = new EmptyPiece();
    }
    for (int col = 0; col < 8; ++col) {
        board[5][col] = new EmptyPiece();
    }

    for (int iCol = 0; iCol < 8; ++iCol) {
        board[1][iCol] = new Pawn("W","qrc:/img/pawnw.svg");
    }

    board[0][0] = new Rook("W","qrc:/img/rookw.svg");
    board[0][1] = new Knight("W","qrc:/img/knightw.svg");
    board[0][2] = new Bishop("W","qrc:/img/bishopw.svg");
    board[0][3] = new King("W","qrc:/img/kingw.svg");
    board[0][4] = new Queen("W","qrc:/img/queenw.svg");
    board[0][5] = new Bishop("W","qrc:/img/bishopw.svg");
    board[0][6] = new Knight("W","qrc:/img/knightw.svg");
    board[0][7] = new Rook("W","qrc:/img/rookw.svg");
    playerTurn = "W";

    firstMove = true;

    currentMove.setFromIndex(0);
    currentMove.setToIndex(0);

    blacksSeconds = 0;
    whitesSeconds = 0;
    gameStopped = false;
    moves.clear();
    previouseMoves.clear();
    previouseMovesPiece.clear();
}

int ChessBoard::PlayNextMove()
{
    if(moves.size() > 0){
        Move move = moves.front();
        previouseMoves.push_front(move);
        moves.pop_front();
        ReplayMove(move.getFromIndex(),false);
        ReplayMove(move.getToIndex(),false);
        return 0;
    }
    else{
        warning_ = "Moves Ended";
        emit warningChanged();
        return -1;
    }
}

int ChessBoard::PlayPreviousMove()
{
    if(previouseMoves.size() > 0){
        Move move = previouseMoves.front();
        moves.push_front(move);
        previouseMoves.pop_front();
        ReplayMove(move.getToIndex(),true);//old second move is the is current first
        ReplayMove(move.getFromIndex(),true);
        return 0;
    }
    else{
        warning_ = "Previous Moves Ended";
        emit warningChanged();
        return -1;
    }
}

void ChessBoard::RefreshView()
{
    emit dataChanged( index(0), index(63) );
    emit totalWhiteTimeChanged();
    emit totalBlackTimeChanged();
}
void ChessBoard::NextPlayerTurn() {
    if(playerTurn == "W")
        playerTurn = "B";
     else playerTurn = "W";
}

/// \return  1 - highlight tile, 2-do not change the highlighting

int ChessBoard::PieceClicked(const int PieceIndex) {

    if( (PieceIndex < 0) || (PieceIndex > 63) )
        return -1;
    int row = PieceIndex/8;
    int column = PieceIndex % 8;
    if(gameStopped)
        return 2;
    if(firstMove){
        if(
                (board[row][column]->getCurrentPieceColor() == "E") ||
                (board[row][column]->getCurrentPieceColor() != playerTurn)
                ){
            firstMove = true;
            return 0;
        }
        currentMove.setFromIndex(PieceIndex);
        firstMove = false;
        return 1;
    }
    if(!firstMove){//second move
        if((board[row][column]->getCurrentPieceColor() == playerTurn) ){
            return 2;//do not change the highlighting
        }
        currentMove.setToIndex(PieceIndex);
    }
    Piece* movingPiece = board[currentMove.getFromRow()][currentMove.getFromColumn()];
    // Check that the piece is the correct color
    if ((movingPiece->getCurrentPiece() != "E") && (movingPiece->getCurrentPieceColor() == playerTurn)) {
        // Check that the destination is a valid destination
        if (movingPiece->IsAllowedToMove(currentMove, board)) {
            delete board[currentMove.getToRow()][currentMove.getToColumn()];

            board[currentMove.getToRow()][currentMove.getToColumn()] = 0;
            board[currentMove.getToRow()][currentMove.getToColumn()] = board[currentMove.getFromRow()][currentMove.getFromColumn()];
            board[currentMove.getFromRow()][currentMove.getFromColumn()] = new EmptyPiece();

            emit dataChanged( index(0), index(63) );
            NextPlayerTurn();
            firstMove = true;
            moves.push_back(currentMove);
        }
        else{
            firstMove = true;
        }
    }
    return 0;
}

void ChessBoard::ReplayMove(const int PieceIndex, bool reverseMove) {
    if( (PieceIndex < 0) || (PieceIndex > 63) )
        return;
    int row = PieceIndex/8;
    int column = PieceIndex % 8;
    if(firstMove){
        currentMove.setFromIndex(PieceIndex);
        firstMove = false;
        return;
    }
    if(!firstMove){//second move
        currentMove.setToIndex(PieceIndex);
    }
    if(reverseMove){
        delete board[currentMove.getToRow()][currentMove.getToColumn()];
        board[currentMove.getToRow()][currentMove.getToColumn()] = 0;
        board[currentMove.getToRow()][currentMove.getToColumn()] = board[currentMove.getFromRow()][currentMove.getFromColumn()];
        board[currentMove.getFromRow()][currentMove.getFromColumn()] = previouseMovesPiece.back();
        previouseMovesPiece.pop_back();
    }else{
        previouseMovesPiece.push_back(board[currentMove.getToRow()][currentMove.getToColumn()]);
        board[currentMove.getToRow()][currentMove.getToColumn()]		= board[currentMove.getFromRow()][currentMove.getFromColumn()];
        board[currentMove.getFromRow()][currentMove.getFromColumn()] = new EmptyPiece();
    }
    emit dataChanged( index(0), index(63) );
    firstMove = true;

    return;
}

