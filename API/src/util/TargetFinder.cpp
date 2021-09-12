#include "TargetFinder.h"
#include "../map/ServerMap.h"

void TargetFinder::clear()
{
    searchMap.clear();
    searchQueue.clear();
}

void TargetFinder::search(unsigned long long from, int range)
{
	searchQueue.enqueue({ from, 0, false });

	while (!searchQueue.isEmpty())
	{
		auto obj = searchQueue.dequeue();
		if (!searchMap.contains(obj.index) || searchMap[obj.index].steps > obj.steps)
		{
			searchMap[obj.index] = obj;
			if (obj.steps == range)
				continue;
			else
			{
				auto tile = map->getTile(obj.index);

				for (auto i : tile->getNeighbours())
					if (i != nullptr && dynamic_cast<const TileDefination *>(i->getPrototype())->isWalkable())
						if (map->getUnit(i->index()) == nullptr)
							searchQueue.enqueue({ i->index(), obj.steps + 1, 
								map->getUnit(i->index())
								&& map->getUnit(i->index())->getSyncUnit()->getPlayer() != map->getUnit(from)->getSyncUnit()->getPlayer()
								});
			}
		}
	}
}

QSet<unsigned long long> TargetFinder::getAvailablePositions()
{
	QSet<unsigned long long> out;
	for (auto &i : searchMap)
	{
		if (i.isTarget)
			out.insert(i.index);
	}
	return out;
}
