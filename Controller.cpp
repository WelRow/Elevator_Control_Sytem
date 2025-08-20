#include "Controller.h"

Controller::Controller(Elevator* existingElevator) : elevator(existingElevator) {
	
}

void Controller::tick() {
	Direction currentState = elevator->getDirection();

	switch (currentState) {
		// when idle, it checked the requests if any has appeared.
		// if so, it will change the currentState to the following direction,
		// making it switch cases in its next tick.
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

			// Elevator will stop at a floor that is currently on its request set.
			// After procedure, it will delete the floor from the set.
			if (upRequests.count(elevator->getCurrentFloor())) {
				elevator->stop();
				elevator->openDoors();
				elevator->closeDoors();
				upRequests.erase(elevator->getCurrentFloor());
			}
			// Knowing its not at a requested floor, it will continue going in its 
			// direction if the highest/lowest call is more/less than the elevator
			// current floor. (e.g. highest call is 10 and current floor is 4, the
			// elevator will keep going till its current floor is 10) else, it will 
			// go IDLE
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

		// explanation is the same from UP case.
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
	if (floorNum > elevator->getCurrentFloor()) {
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

std::set<int> Controller::getUpRequests() {
	return upRequests;
}

std::set<int, std::greater<int>> Controller::getDownRequests() {
	return downRequests;
}

