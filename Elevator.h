#pragma once
#include <vector>
#include <iostream>

enum class Direction {
	MOVING_UP,
	MOVING_DOWN,
	IDLE
};

class Elevator
{
public:
	Elevator(int currentFloor, int floors);

	void move(int desiredFloor);
	

private:
	int currentFloor;
	Direction dir;
	bool doorIsOpen;

	int floors;

	void stop();
	void openDoors();
	void closeDoors();
};

