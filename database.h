#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlTableModel>

class Database
{
public:
    Database();
    QSqlQuery query;
    QSqlRecord queryRecord;
    static QSqlDatabase& getDatabase();
};

#endif // DATABASE_H
