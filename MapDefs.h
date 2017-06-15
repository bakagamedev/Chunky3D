#pragma once

#include "Types.h"
#include "Portal.h"
#include "PgmSector.h"
#include "PgmMap.h"

#define PgmMapSectorPortals(x, y) PROGMEM const Portal map##x##Sector##y##Portals[] =
	
#define PgmMapSectorPoints(x, y) PROGMEM const PointI map##x##Sector##y##Points[] =
	
#define PgmMapSectors(x) PROGMEM const PgmSector map##x##Sectors[] =

#define PgmMapSector(x, y) \
	{ \
		map##x##Sector##y##Points, sizeof(map##x##Sector##y##Points) / sizeof(PointI), \
		map##x##Sector##y##Portals, sizeof(map##x##Sector##y##Portals) / sizeof(Portal) \
	}

#define PgmMap(x) PROGMEM const PgmMap map##x = { sizeof(map##x##Sectors) / sizeof(PgmSector), map##x##Sectors }; 