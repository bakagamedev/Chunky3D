#pragma once

#include <avr/pgmspace.h>

#include "Types.h"
#include "Portal.h"
#include "Sector.h"
#include "Map.h"
#include "PgmSector.h"
#include "PgmMap.h"

template< typename T >
inline T * ProgmemCopy(T * destination, const T * source)
{
	return static_cast<T*>(memcpy_P(destination, source, sizeof(T)));
}

template< typename T >
inline T * ProgmemCopyRef(T & destination, const T * source)
{
	return static_cast<T*>(memcpy_P(&destination, source, sizeof(T)));
}

template< typename T >
inline T * ProgmemCopy(T * destination, const T * source, int count)
{
	return static_cast<T*>(memcpy_P(destination, source, sizeof(T) * count));
}

void pgmLoadMap(Map & map, const PgmMap * pgmMap)
{
	const PgmSector * sectors;
	{
		PgmMap tempMap;
		ProgmemCopyRef(tempMap, pgmMap);  
		map.sectorCount = tempMap.sectorCount;
		sectors = tempMap.sectors;
	}
	for (uint_least8_t i = 0; i < map.sectorCount; ++i)
	{
		PgmSector tempSector;
		ProgmemCopyRef(tempSector, sectors + i);

		map.sectors[i].pointCount = tempSector.wallPointCount;
		map.sectors[i].portalCount = tempSector.portalCount;

		memcpy_P(&(map.sectors[i].points), tempSector.points, tempSector.wallPointCount * sizeof(PointI));
		memcpy_P(&(map.sectors[i].portals), tempSector.portals, tempSector.portalCount * sizeof(Portal));
	}
}
