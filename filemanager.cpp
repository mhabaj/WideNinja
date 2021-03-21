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
      qDebug()<<"Dossier ASSETS PAS TROUVE, on creer le dossier assets/ dans le repertoire du jeu..\n";
      pathDir.mkpath(".");
    }
    QDir pathDirMaps(appLocation + "/assets/Map/");
    if (!(pathDirMaps.exists()))
    {
        qDebug()<<"Dossier Map PAS TROUVE, on creer le dossier Map/ dans le repertoire du jeu..\n";

      pathDirMaps.mkpath(".");
      qDebug()<<"Dossier Maps VIDE, ON REMPLIE AVEC UNE NOUVELLE CARTE\n";
      initDefaultMapFromResources();
    }

    QDir pathDirSave(appLocation + "/assets/Save/");
    if (!(pathDirSave.exists()))
    {
        qDebug()<<"Dossier Save PAS TROUVE, on creer le dossier Save/ dans le repertoire du jeu..\n";
        pathDirSave.mkpath(".");

    }
}

QList<QList<QString>> FileManager::loadDefaultMap(int mapNumber)
{
    qDebug()<<"LOAD DEFAULT MAP STARTED------------------------------------------------------------------------------------------------\n";
    QList<QList<QString>> map;
    QString validUrl = defaultMapFolderPath + QString::number(mapNumber) +".map";
    QFile file(validUrl);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> map;
    qDebug()<<"LOAD DEFAULT MAP FINISHED------------------------------------------------------------------------------------------------\n";
    return map;
}
QList<QList<QString>> FileManager::loadDefaultMapFromResoureces(int mapNumber)
{
    qDebug()<<"On load le default depuis les ressources..------------------------------------------------------------------------------------------------\n";
    QList<QList<QString>> map;
    QString validUrl = defaultMapResourcesFolder + QString::number(mapNumber);
    QFile file(validUrl);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> map;
    qDebug()<<"------------------------------------------------------------------------------------------------\n";
    return map;
}

void FileManager::initDefaultMapFromResources()
{
    qDebug()<<"On copie la map de ressources au dossier save client.------------------------------------------------------------------------------------------------\n";
    int counter = 0;
   while (counter <= maxMapCount){

       saveDefaultMap(loadDefaultMapFromResoureces(counter),counter);
       counter++;
       }
       qDebug()<<"------------------------------------------------------------------------------------------------\n";
}

void FileManager::saveDefaultMap(QList<QList<QString> > mapNum, int mapNumber)
{
    qDebug()<<"SAVE DEFAULT MAP STARTED------------------------------------------------------------------------------------------------\n";
    QString validUrl = defaultMapFolderPath + QString::number(mapNumber) +".map";
    qDebug()<<"VALIDE URRRRLLLLL: \n"<<validUrl;
    QFile file(validUrl);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << mapNum;
    qDebug()<<"SAVE DEFAULT MAP FINISHED------------------------------------------------------------------------------------------------\n";
}

void FileManager::saveCustomMap(QList<QList<QString> > mapNum)
{
    QFile file(customSaveFilePath);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << mapNum;
    qDebug() << mapNum<< "<<<<CUSTOME MAP<<<<<"<<"\n";
}
