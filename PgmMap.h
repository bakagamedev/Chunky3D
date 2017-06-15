#pragma once

#include <Arduboy2.h>

#include "Ardutils.h"

#include "Sector.h"

struct PgmMap
{
	uint8_t sectorCount;
	//PgmSector sectors[16];
	const PgmSector * sectors;
	
	/*constexpr inline PgmMap(void) : sectors(nullptr), sectorCount(0) {}
	constexpr inline PgmMap(const PgmSector sectors[], const uint8_t & sectorCount)
		: sectors(sectors), sectorCount(sectorCount)
	{
	}*/
};
