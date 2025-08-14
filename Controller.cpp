#include "Controller.h"

Controller::Controller(Elevator* existingElevator) : elevator(existingElevator) {
	
}

void Controller::check() {
	if (upRequests.empty() && downRequests.empty()) {
		return;
	}
	else if (upRequests.size() >= downRequests.size()) {
		bool listIsEmpty = false;

		do {
			if (upRequests.find(elevator->getCurrentFloor()) == upRequests.end()) {
				//stopping procedure
			}
			//if (elevator->getCurrentFloor() == std::next(upRequests.begin(), upRequests.size() - 1));

		} while (!listIsEmpty)
	}
}

void Controller::addFloorRequest(int floorNum, Direction direction) {
	if (direction == Direction::MOVING_UP) {
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