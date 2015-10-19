#ifndef MOVE_H
#define MOVE_H
#include <QJSEngine>
#include <QJsonObject>

class Move
{
public:
    Move();
    ~Move();

        void read(const QJsonObject &json);
        void write(QJsonObject &json) const;

        int getFromIndex() const;
        void setFromIndex(int value);
        int getToIndex() const;
        void setToIndex(int value);
        int getFromRow() const;
        void setFromRow(int value);

        int getFromColumn() const;
        void setFromColumn(int value);

        int getToRow() const;
        void setToRow(int value);

        int getToColumn() const;
        void setToColumn(int value);

private:

        int fromIndex;
        int fromRow;
        int fromColumn;

        int toIndex;
        int toRow;
        int toColumn;
};

#endif // MOVE_H
