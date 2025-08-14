#include "Elevator.h"

Elevator::Elevator(int floors) {
	this->currentFloor = 1;
	this->direction = Direction::IDLE;
	this->doorIsOpen = false;
	this->floors = floors;
	std::cout << "Elevator has been created at floor 1 and its stands IDLE!" << std::endl;
}

void Elevator::moveOneFloor(Direction direction) {
	switch (direction) {
	case Direction::UP:
		std::cout << "Elevator Going up to floor" << this->getCurrentFloor() + 1 << std::endl;
		this->currentFloor++;
		break;

	case Direction::DOWN:
		std::cout << "Elevator Going down to floor" << this->getCurrentFloor() - 1 << std::endl;
		this->currentFloor--;
		break;
	}
}

void Elevator::stop() {
	std::cout << "Elevator stopped at floor " << this->getCurrentFloor() << std::endl;
	this->direction = Direction::IDLE;
}

void Elevator::openDoors() {
	std::cout << "Elevator doors opening at floor " << this->getCurrentFloor() << std::endl;
	this->doorIsOpen = true;
}

void Elevator::closeDoors() {
	std::cout << "Elevator doors closing at floor " << this->getCurrentFloor() << std::endl;
	this->doorIsOpen = false;
}

int Elevator::getCurrentFloor() {
	return this->currentFloor;
}

Direction Elevator::getDirection() {
	return this->direction;
}

void Elevator::setDirection(Direction direction) {
	this->direction = direction;
}