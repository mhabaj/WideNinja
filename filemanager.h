#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QList>
#include <QString>
#include <QDirIterator>
#include <QDebug>
#include "map.h"
#include "playerinventory.h"
class FileManager
{

private:
     QList<QFile*> defaultMapFiles;
     QList<QFile*> modifiedMapFiles;
     QList<QFile> savedPlayerProfil;
    const QString basicFilePath = "D:/Drive/Backup/backupUSB2GoNoir/FAC/4emeAnneePolytech/S8/C++/TP1/WideNinja/assets/Map/RegularMap/";
    const QString customPlayerSaveFilePath = "D:/Drive/Backup/backupUSB2GoNoir/FAC/4emeAnneePolytech/S8/C++/TP1/WideNinja/assets/saves/save.wide";
public:
    FileManager();
    void scanFileSysteme();
    void loadMapById(int mapNum);
    void loadPlayerProfil(PlayerInventory* playerToLoad);
    void savePlayerProfil(PlayerInventory* playerToSave);
};

#endif // FILEMANAGER_H
