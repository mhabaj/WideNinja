#include "filemanager.h"

FileManager::FileManager()
{

}

QList<QList<QString>> FileManager::loadDefaultMap(int mapNumber)
{
    qDebug()<<"LOAD DEFAULT MAP STARTED------------------------------------------------------------------------------------------------\n";
    QList<QList<QString>> map;
    QString validUrl = defaultMapFolderPath + QString::number(mapNumber);
    QFile file(validUrl);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> map;
    qDebug() << map;
    qDebug()<<"LOAD DEFAULT MAP FINISHED------------------------------------------------------------------------------------------------\n";
    return map;
}

void FileManager::saveDefaultMap(QList<QList<QString> > mapNum, int mapNumber)
{
    qDebug()<<"SAVE DEFAULT MAP STARTED------------------------------------------------------------------------------------------------\n";
    QString validUrl = defaultMapFolderPath + QString::number(mapNumber);
    QFile file(validUrl);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << mapNum;
    qDebug()<<"SAVE DEFAULT MAP FINISHED------------------------------------------------------------------------------------------------\n";
}

void FileManager::saveCustomMap(QList<QList<QString> > mapNum)
{
    QFile file(customPlayerSaveFilePath);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << mapNum;
    qDebug() << mapNum<< "<<<<CUSTOME MAP<<<<<"<<"\n";
}
