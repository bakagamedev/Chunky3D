#pragma once
	
//Corner Wedge shape
PgmMapSectorPortals(1, 1)
{
	Portal(3, 1),
};
PgmMapSectorPoints(1, 1)
{
	PointI(0,0),
	PointI(8,0),
	PointI(8,4),
	PointI(4,8),
	PointI(0,8),
};

//Short connector
PgmMapSectorPortals(1, 2)
{
	Portal(0,0),
	Portal(2,2),
};

PgmMapSectorPoints(1, 2)
{
	PointI(4,8),
	PointI(8,4),
	PointI(12,8),
	PointI(8,12),
};

//Probably a hexagon.
PgmMapSectorPortals(1,3)
{
	Portal(0,1),
	Portal(4,4),
};

PgmMapSectorPoints(1,3)
{
	PointI(8,12),
	PointI(12,8),
	PointI(16,8),
	PointI(20,12),
	PointI(20,16),
	PointI(16,20),
	PointI(12,20),
	PointI(8,16),
};

//Corridor going to the right
PgmMapSectorPortals(1,4)
{
	Portal(2,5),
	Portal(4,3),
};

PgmMapSectorPoints(1,4)
{
	PointI(20,12),
	PointI(28,12),
	PointI(28,16),
	PointI(20,16),
};

//Stuff
PgmMapSectors(1)
{
	PgmMapSector(1, 1),
	PgmMapSector(1, 2),
	PgmMapSector(1, 3),
	PgmMapSector(1, 4),
};
PgmMap(1);
