#pragma once

#include "Types.h"

struct Portal
{
	WallIndex wallIndex;
	SectorId sectorId;

	constexpr Portal(void);
	constexpr Portal(const WallIndex & wallIndex, const SectorId & sectorId);
	
	const WallIndex & GetWallIndex(void) const;
	
	const SectorId & GetSectorId(void) const;
};

constexpr Portal::Portal(void)
  : wallIndex(0), sectorId(0)
{
}

constexpr Portal::Portal(const WallIndex & wallIndex, const SectorId & sectorId)
	: wallIndex(wallIndex), sectorId(sectorId)
{
}
	
const WallIndex & Portal::GetWallIndex(void) const
{
	return this->wallIndex;
}
	
const SectorId & Portal::GetSectorId(void) const
{
	return this->sectorId;
}
