#pragma once
#include "Ardutils.h"

using FixedPointQ8x8 = Ardutils::Point2<Ardutils::Q8x8>;

using PointI = Ardutils::Point2<uint8_t>;
using PointF = Ardutils::Point2<float>;

using WallIndex = uint8_t;

using SectorId = uint8_t;

using Angle = Ardutils::FixedPoint<9, 6>;	//1 sign, 9 integer, 5 fraction = 16
