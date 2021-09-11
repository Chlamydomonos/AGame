#include "PathFinder.h"
#include "../map/ServerMap.h"

void PathFinder::clear()
{
	searchMap.clear();
	searchQueue.clear();
}

void PathFinder::search(unsigned long long from, int range)
{
	searchQueue.enqueue({ from, 0, 0xffffffffffffffff });

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
							searchQueue.enqueue({ i->index(), obj.steps + 1, obj.index });
			}
		}
	}
}

QSet<unsigned long long> PathFinder::getAvailablePositions()
{
	QSet <unsigned long long> out{};
	for (auto i : searchMap.keys())
		out.insert(i);
	return out;
}

QVector<unsigned long long> PathFinder::getPathTo(unsigned long long target)
{
	SearchNode node = searchMap[target];
	QVector<unsigned long long> out{};
	while (node.from != 0xffffffffffffffff)
	{
		out.push_front(node.index);
		node = searchMap[node.from];
	}
	return out;
}
