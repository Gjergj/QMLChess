#include "move.h"

Move::Move()
{

}
Move::~Move()
{

}
void Move::read(const QJsonObject &json)
{
    fromIndex = json["firstMove"].toInt();
    toIndex = json["secondMove"].toInt();
}

void Move::write(QJsonObject &json) const
{
    json["firstMove"] = fromIndex;
    json["secondMove"] = toIndex;
}
int Move::getToIndex() const
{
    return toIndex;
}
void Move::setToIndex(int value)
{
    toIndex = value;
    toRow = toIndex/8;
    toColumn = toIndex % 8;
}
int Move::getFromRow() const
{
    return fromRow;
}
void Move::setFromRow(int value)
{
    fromRow = value;
}
int Move::getFromColumn() const
{
    return fromColumn;
}
void Move::setFromColumn(int value)
{
    fromColumn = value;
}
int Move::getToRow() const
{
    return toRow;
}
void Move::setToRow(int value)
{
    toRow = value;
}
int Move::getToColumn() const
{
    return toColumn;
}

void Move::setToColumn(int value)
{
    toColumn = value;
}
int Move::getFromIndex() const
{
    return fromIndex;
}

void Move::setFromIndex(int value)
{
    fromIndex = value;
    fromRow = fromIndex / 8;
    fromColumn = fromIndex % 8;
}


