#include "imgui/imgui.h" // Must include for ImGui calls
#include "Controller.h"  // Need full class definition to access methods
#include "Elevator.h"    // Need full class definition to access methods

// Helper function
const char* DirectionToString(Direction dir) {
    switch (dir) {
    case Direction::UP:   return "UP";
    case Direction::DOWN: return "DOWN";
    case Direction::IDLE: return "IDLE";
    }
    return "UNKNOWN";
}

namespace UI {
    void RenderUI(Controller& controller, Elevator& elevator) {
        ImGui::Begin("Elevator Controls");

        // --- Display Status ---
        ImGui::Text("Current Floor: %d", elevator.getCurrentFloor());
        ImGui::Text("Direction: %s", DirectionToString(elevator.getDirection()));

        ImGui::Separator();

        // --- Add Requests ---
        ImGui::Text("Make a request:");
        if (ImGui::Button("Call from Floor 5 (UP)")) {
            controller.addFloorRequest(5, Direction::UP);
        }
        ImGui::SameLine();
        if (ImGui::Button("Call from Floor 8 (DOWN)")) {
            controller.addFloorRequest(8, Direction::DOWN);
        }
        ImGui::SameLine();
        if (ImGui::Button("Add Multiple Floor Calls")) {
            controller.addFloorRequest(8, Direction::DOWN);
            controller.addFloorRequest(2, Direction::DOWN);
            controller.addFloorRequest(4, Direction::UP);
            controller.addFloorRequest(1, Direction::DOWN);
            controller.addFloorRequest(7, Direction::UP);
            controller.addFloorRequest(11, Direction::DOWN);

        }


        // You could add more buttons for every floor
        controller.tick();

        ImGui::End();
    }
}

