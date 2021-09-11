#include "MapDefination.h"
#include <QFile>

ServerMap *MapDefination::createMap()
{
    ServerMap *map = ServerMapPrototype::create();
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    int size = QString(file.readLine()).toInt();
    for (int i = 0; i < size; i++)
    {
        int x = QString(file.readLine()).toInt();
        int y = QString(file.readLine()).toInt();
        int z = QString(file.readLine()).toInt();
        QString tileName = file.readLine();
        tileName.remove('\r');
        tileName.remove('\n');
        auto tile = AllRegistries::getInstance()->getRegistry<TileDefination>()->get(tileName)->createServerTile(x, y, z);
        map->tiles.insert(tile->index(), tile);
    }

    for (auto i : map->tiles)
        i->initMap(map);
    return map;
}
