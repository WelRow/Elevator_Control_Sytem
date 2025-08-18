#pragma once
#include <set>
#include "Elevator.h"

class Controller
{
public:
	Controller(Elevator* existingElevator);

	void addFloorRequest(int floorNum, Direction direction);
	void addCarRequest(int floorNum);
	void tick();
	std::set<int> getUpRequests();
	std::set<int, std::greater<int>> getDownRequests();

private:
	std::set<int> upRequests;
	std::set<int, std::greater<int>> downRequests;
	Elevator* elevator;
	
};