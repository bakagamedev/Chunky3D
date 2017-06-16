#pragma once
#include "Ardutils.h"

using FixedPointQ8x8 = Ardutils::Point2<Ardutils::FixedPoint<7, 8>>;

using PointI = Ardutils::Point2<uint8_t>;
using PointF = Ardutils::Point2<float>;

using WallIndex = uint8_t;

using SectorId = uint8_t;

using Angle = Ardutils::FixedPoint<4, 11>;	//1 sign, 4 integer, 11 fraction = 16
