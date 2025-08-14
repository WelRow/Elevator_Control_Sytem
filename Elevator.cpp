#include "Elevator.h"

Elevator::Elevator(int floors) {
	this->currentFloor = 1;
	this->dir = Direction::IDLE;
	this->doorIsOpen = false;
	this->floors = floors;
	std::cout << "Elevator has been created at floor 1 and its stands IDLE!" << std::endl;
}

void Elevator::move(Direction direction) {
	switch (direction) {
	case Direction::MOVING_UP:
		if (this->dir == Direction::IDLE) {
			this->dir = Direction::MOVING_UP;
		}
		this->currentFloor++;
		break;

	case Direction::MOVING_DOWN:
		if (this->dir == Direction::IDLE) {
			this->dir = Direction::MOVING_DOWN;
		}
		this->currentFloor--;
		break;
	}
}

void Elevator::stop() {
	this->dir = Direction::IDLE;
}

void Elevator::openDoors() {
	if (this->dir == Direction::IDLE && this->doorIsOpen == false) {
		this->doorIsOpen = true;
	}
	else {
		std::cout << "There's been techniqual difficulties opening the door!" << std::endl;
	}
}

void Elevator::closeDoors() {
	if (this->dir == Direction::IDLE && this->doorIsOpen == true) {
		this->doorIsOpen = false;
	}
	else {
		std::cout << "There's been techniqual difficulties opening the door!" << std::endl;
	}
}

int Elevator::getCurrentFloor() {
	return currentFloor;
}