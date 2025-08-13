#include "Elevator.h"

Elevator::Elevator(int currentFloor, int floors) {
	this->currentFloor = currentFloor;
	this->dir = Direction::IDLE;
	this->doorIsOpen = false;
	this->floors = floors;
	std::cout << "Elevator has been created at floor " << this->currentFloor << " and its stands IDLE!" << std::endl;
}

void Elevator::move(int desiredFloor) {
	if (desiredFloor - this->currentFloor > 0) {
		this->dir = Direction::MOVING_UP;
		std::cout << "Moving up to floor " << desiredFloor << std::endl;
		// add a internal clock to simulate waiting between floors
		this->currentFloor = desiredFloor;
		std::cout << "Arrived at floor " << this->currentFloor << std::endl;
		Elevator::stop();
	}

	else if (desiredFloor - this->currentFloor < 0) {
		this->dir = Direction::MOVING_DOWN;
		std::cout << "Moving down to floor " << desiredFloor << std::endl;
		// add a internal clock to simulate waiting between floors
		this->currentFloor = desiredFloor;
		std::cout << "Arrived at floor " << this->currentFloor << std::endl;
		Elevator::stop();
	}

	else {
		std::cout << "You're currently on the floor you wish to be on." << std::endl;
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
