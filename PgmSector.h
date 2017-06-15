#pragma once

#include <Arduboy2.h>

#include "Ardutils.h"

#include "Types.h"
#include "Portal.h"

struct PgmSector
{
	const PointI * points;
	uint8_t wallPointCount;
	const Portal * portals;
	uint8_t portalCount;
	
	/*constexpr inline PgmSector(void) : points(nullptr), wallPointCount(0), portals(nullptr), portalCount(0) {}
	constexpr inline PgmSector(const PointI points[], const uint8_t & wallPointCount, const Portal portals[], const uint8_t & portalCount)
		: points(points), wallPointCount(wallPointCount), portals(portals), portalCount(portalCount)
	{
	}*/
};
