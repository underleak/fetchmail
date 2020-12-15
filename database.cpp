#include "database.h"

Database::Database()
{
    query = QSqlQuery(getDatabase());
}

QSqlDatabase& Database::getDatabase()
{
    static QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setDatabaseName("mail");
    database.setUserName("root");
    database.setPassword("12345");
    if (!database.isOpen()){
        if(!database.open())
            qDebug() << database.lastError().text();
    }
    return database;
}
