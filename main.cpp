#include <QApplication>

#include "maincontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<QList<QList<QString>>> map = {
        {{":/Background/ForestFloor"},
         {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"}, {"wall", ":/Terrain/Tree"},
         {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
         {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
         {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
         {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
         {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
         {"wall", ":/Terrain/Tree"}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {"wall", ":/Terrain/Tree"},
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
    };

    MainController *mc = new MainController(map);

    mc->loadMapSlot(0);

    return a.exec();
}
