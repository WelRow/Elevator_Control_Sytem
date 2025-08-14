#include "Controller.h"

Controller::Controller(Elevator* existingElevator) : elevator(existingElevator) {
	
}

void Controller::tick() {
	Direction currentState = elevator->getDirection();

	switch (currentState) {
		case Direction::IDLE: {
			if (!upRequests.empty()) {
				std::cout << "Elevator has Up requests and now going up" << std::endl;
				elevator->setDirection(Direction::UP);
			}
			else if (!downRequests.empty()) {
				std::cout << "Elevator has Down request and now going down" << std::endl;
				elevator->setDirection(Direction::DOWN);
			}
			break;
		}

		case Direction::UP: {
			if (upRequests.empty()) {
				std::cout << "Elevator Stopping going Up" << std::endl;
				elevator->setDirection(Direction::IDLE);
				return;
			}

			if (upRequests.count(elevator->getCurrentFloor())) {
				elevator->stop();
				elevator->openDoors();
				elevator->closeDoors();
				upRequests.erase(elevator->getCurrentFloor());
			}
			else {
				int highestRequest = *upRequests.rbegin();
				if (elevator->getCurrentFloor() < highestRequest) {
					elevator->moveOneFloor(Direction::UP);
				}
				else {
					elevator->setDirection(Direction::IDLE);
				}
			}
			break;
		}

		case Direction::DOWN: {
			if (downRequests.empty()) {
				std::cout << "Elevator Stopping going Down" << std::endl;
				elevator->setDirection(Direction::IDLE);
				return;
			}

			if (downRequests.count(elevator->getCurrentFloor())) {
				elevator->stop();
				elevator->openDoors();
				elevator->closeDoors();
				downRequests.erase(elevator->getCurrentFloor());
			}
			else {
				int lowestRequest = *downRequests.rbegin();
				if (elevator->getCurrentFloor() > lowestRequest) {
					elevator->moveOneFloor(Direction::DOWN);
				}
				else {
					elevator->setDirection(Direction::IDLE);
				}
			}
			break;
		}
	}
}

void Controller::addFloorRequest(int floorNum, Direction direction) {
	if (direction == Direction::UP) {
		upRequests.insert(floorNum);
	}
	else {
		downRequests.insert(floorNum);
	}
}

void Controller::addCarRequest(int floorNum) {
	if (floorNum > elevator->getCurrentFloor()) {
		upRequests.insert(floorNum);
	}
	else {
		downRequests.insert(floorNum);
	}
}