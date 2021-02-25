#include <QApplication>

#include "maincontroller.h"
#include "map.h"
#include "playerentity.h"
#include "pathmonsterentity.h"
/*
    {{":/Background/ForestFloor"},
     {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {"pathMonster", ":/Character/Wolf", "1", "1", "2:3:4:3:1:3:3:3"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"warp", "1", ":/Terrain/Warp"}, {"player"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"warp", "1", ":/Terrain/Warp"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}
    },
    {{":/Background/ForestFloor"},
     {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"player"}, {"warp", "0", ":/Terrain/Warp"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"warp", "0", ":/Terrain/Warp"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
     {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}
    }
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Map *m1 = new Map(":/Background/ForestFloor");

    m1->setEntity(new PlayerEntity(":/Character/NinjaRight", 2, 14, 3, 3));
    m1->setEntity(new PathMonsterEntity(":/Character/Wolf", 2, 7, 1, 1, "R:4:U:4:L:2:D:2:L:2:D:2"));

    MainController *mc = new MainController();

    mc->loadMapSlot(m1);

    return a.exec();
}
