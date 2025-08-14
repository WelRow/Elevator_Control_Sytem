#include <iostream>
#include "Elevator.h"
#include "Controller.h"

int main() {
	Elevator elevator(8);
	Controller controller(&elevator);

	controller.addFloorRequest(5, Direction::UP);
	controller.addCarRequest(9);
	controller.addFloorRequest(4, Direction::DOWN);
	controller.addCarRequest(1);

	while (true) {
		controller.tick();
	}

	return 0;
}