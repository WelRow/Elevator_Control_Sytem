#pragma once
#include <vector>
#include "Elevator.h"

class Controller
{
public:
	Controller(Elevator elevatorName);

	void addFloorRequest(int floorNum, Direction dir);
	void addCarRequest(int floorNum);

private:
	std::vector<int> upRequests;
	std::vector<int> downRequests;
};