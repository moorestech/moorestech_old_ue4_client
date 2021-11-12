#pragma once

struct Coordinate
{
	int X;
	int Y;
	
	bool operator < (const Coordinate& c) const {
		if (X < c.X){
			return true;
		}
		return false;
	}
};
