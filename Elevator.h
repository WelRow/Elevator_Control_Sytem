#pragma once
#include <iostream>

enum class Direction {
	MOVING_UP,
	MOVING_DOWN,
	IDLE
};

class Elevator
{
public:
	Elevator(int floors);

	void move(Direction direction);
	void stop();
	void openDoors();
	void closeDoors();
	int getCurrentFloor();
	

private:
	int currentFloor;
	Direction dir;
	bool doorIsOpen;
	int floors;

	
};

