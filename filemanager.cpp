#include "filemanager.h"


FileManager::FileManager()
{

}

FileManager::FileManager(QString appLocation, int maxMapCount)
{
    defaultMapFolderPath = appLocation + "/assets/Map/";
    customSaveFilePath = appLocation + "/assets/";
    maxMapNumber = maxMapCount - 1;

    QDir pathDir(appLocation + "/assets");
    if (!(pathDir.exists()))
    {
        pathDir.mkpath(".");
    }
    QDir pathDirMaps(appLocation + "/assets/Map/");
    if (!(pathDirMaps.exists()))
    {
        pathDirMaps.mkpath(".");
        initDefaultMapFromResources();
    }

    QDir pathDirSave(appLocation + "/assets/Save/");
    if (!(pathDirSave.exists()))
    {
        pathDirSave.mkpath(".");

    }
}

QList<QList<QString>> FileManager::loadDefaultMap(int mapNumber)
{
    QList<QList<QString>> map;
    QString validUrl = defaultMapFolderPath + QString::number(mapNumber) +".map";
    QFile file(validUrl);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> map;
    return map;
}
QList<QList<QString>> FileManager::loadDefaultMapFromResoureces(int mapNumber)
{
    QList<QList<QString>> map;
    QString validUrl = defaultMapResourcesFolder + QString::number(mapNumber);
    QFile file(validUrl);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> map;
    return map;
}

void FileManager::initDefaultMapFromResources()
{
    int counter = 0;
    while (counter <= maxMapNumber){
        saveDefaultMap(loadDefaultMapFromResoureces(counter),counter);
        counter++;
    }
}

void FileManager::saveDefaultMap(QList<QList<QString> > mapNum, int mapNumber)
{
    QString validUrl = defaultMapFolderPath + QString::number(mapNumber) +".map";
    QFile file(validUrl);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << mapNum;
}

void FileManager::saveCustomMap(QList<QList<QString> > mapNum)
{
    QFile file(customSaveFilePath);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << mapNum;
}
