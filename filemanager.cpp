#include "filemanager.h"

FileManager::FileManager()
{
}

void FileManager::scanFileSysteme()
{


    QDirIterator iteratorRegular(basicFilePath, {"*.map"}, QDir::Files);
    int regularFileNameitr = 0;
    while (iteratorRegular.hasNext()) {
        QFile regularfile(iteratorRegular.next());
        QStringList regfilename = regularfile.fileName().split(".");
        if (regfilename.count()==2
                && regfilename[0].toInt() == regularFileNameitr
                && regfilename[1] == "map" ){
            if ( regularfile.open( QIODevice::ReadOnly ) ){
                qDebug() << "detected:" << regularfile.fileName() << "\n";
                defaultMapFiles.append(&regularfile);
                regularFileNameitr++;
            }
        }
    }
    qDebug()<< "Detected "<<regularFileNameitr<<"Regular Map Files"<<"\n";


}
QDataStream &operator>>(QDataStream &in, PlayerInventory player)
{
    QMap<QString, int> inventory;
    QMap<QString, int> tempInventory;
    int currentLocation;

    in >> inventory >> tempInventory>>currentLocation ;
    player.setInventory(inventory);
    player.setTempInventory(tempInventory);
    player.setCurrentLocation(currentLocation);
    return in;
}

QDataStream &operator<<(QDataStream &out, PlayerInventory player)
{

    out << player.getInventory() << player.getTempInventory()<<player.getCurrentLocation();

    return out;
}
void FileManager::loadPlayerProfil(PlayerInventory* playerToLoad)
{

    QFile file(customPlayerSaveFilePath);

    if(file.exists() && file.size() != 0){
        file.open(QIODevice::ReadWrite);
        QDataStream in(&file);    // read the data serialized from the file
        in >> *playerToLoad;
    }

}

void FileManager::savePlayerProfil(PlayerInventory* playerToSave)
{

    QFile file(customPlayerSaveFilePath);

    if(file.exists()){

        file.open(QIODevice::ReadWrite);
        QDataStream out(&file);    // read the data serialized from the file
        out << playerToSave;           // write in file
    }

}



