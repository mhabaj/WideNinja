#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QList>
#include <QString>
#include <QDirIterator>
#include <QDebug>
#include "playerinventory.h"
#include <QDataStream>
#include <maincontroller.h>
class FileManager
{

private:
    QList<QFile> savedPlayerProfil;
    QString defaultMapFolderPath ;
    QString customSaveFilePath;
    const QString defaultMapResourcesFolder = ":/Map/";
    int maxMapNumber;

public:
    FileManager();
    FileManager(QString appLocation, int maxMapCount);

    QList<QList<QString>> loadDefaultMap(int mapNumber );
    QList<QList<QString>> loadDefaultMapFromResoureces(int mapNumber);

    void saveDefaultMap(QList<QList<QString>> mapNum, int mapNumber );
    void initDefaultMapFromResources();
    void loadCustomMap(QList<QList<QString>> mapNum);
    void saveCustomMap(QList<QList<QString>> mapNum);

    void loadPlayerProfil(PlayerInventory* playerToLoad);
    void savePlayerProfil(PlayerInventory* playerToSave);
};

#endif // FILEMANAGER_H
