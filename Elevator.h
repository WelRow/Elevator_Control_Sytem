#pragma once
#include <iostream>

enum class Direction {
	UP,
	DOWN,
	IDLE
};

class Elevator
{
public:
	Elevator(int floors);

	void moveOneFloor(Direction direction);
	void stop();
	void openDoors();
	void closeDoors();
	int getCurrentFloor();
	Direction getDirection();
	void setDirection(Direction direction);
	

private:
	int currentFloor;
	Direction direction;
	bool doorIsOpen;
	int floors;

	
};

