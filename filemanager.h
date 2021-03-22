#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QList>
#include <QString>
#include <QDirIterator>
#include <QDebug>
#include "playerinventory.h"
#include <QDataStream>

class FileManager
{

private:
    QList<QFile> savedPlayerProfil;
    const QString defaultMapFolderPath = "E:/Qt_Projects/WideNinja/assets/Map/";
    const QString customPlayerSaveFilePath = "E:/Qt_Projects/WideNinja/assets/";
public:
    FileManager();

    QList<QList<QString>> loadDefaultMap(int mapNumber );
    void saveDefaultMap(QList<QList<QString>> mapNum, int mapNumber );

    void loadCustomMap(QList<QList<QString>> mapNum);
    void saveCustomMap(QList<QList<QString>> mapNum);

    void loadPlayerProfil(PlayerInventory* playerToLoad);
    void savePlayerProfil(PlayerInventory* playerToSave);
};

#endif // FILEMANAGER_H
