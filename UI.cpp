#include "imgui/imgui.h" // Must include for ImGui calls
#include "Controller.h"  
#include "Elevator.h"    
#include <string>

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
    void RenderUI(Controller& controller, Elevator& elevator, int numFloors) {
        ImGui::Begin("Elevator Control Panel");

        // Get a reference to the request sets for easier access
        const auto& upRequests = controller.getUpRequests();
        const auto& downRequests = controller.getDownRequests();

        // Split the window into two columns
        ImGui::Columns(4, "Layout", true);

        // --- SECTION 1: VISUAL ELEVATOR SHAFT ---
        ImGui::Text("Live Status");
        int currentFloor = elevator.getCurrentFloor();
        for (int i = numFloors; i >= 1; --i) {
            // Change color if this is the current floor
            if (i == currentFloor) {
                ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.6f, 0.8f, 1.0f)); // Blue
            }

            std::string floorLabel = "Floor " + std::to_string(i);
            if (ImGui::Button(floorLabel.c_str(), ImVec2(-1.0f, 0.0f))) {
                // Optional: clicking the floor could be a car request
                controller.addCarRequest(i);
            }

            if (i == currentFloor) {
                ImGui::PopStyleColor(1);
            }
        }

        
        // Move to the next column
        ImGui::NextColumn();

        // --- SECTION 2: HALL CALLS (OUTSIDE) ---
        ImGui::Text("Hall Calls");
        for (int i = 1; i <= numFloors; i++) {
            ImGui::Text("Floor %d", i);
            ImGui::SameLine();

            // Add a unique ID to each button to avoid conflicts
            ImGui::PushID(i);

            // UP button (not on top floor)
            if (i < numFloors) {
                if (ImGui::Button("UP")) {
                    controller.addFloorRequest(i, Direction::UP);
                }
            }

            if (i != 1) {
                ImGui::SameLine();
            }
            
            // DOWN button (not on ground floor)
            if (i > 1) {
                if (ImGui::Button("DOWN")) {
                    controller.addFloorRequest(i, Direction::DOWN);
                }
            }
            ImGui::PopID();
        }

        
        ImGui::NextColumn();

        // --- SECTION 3: CAR KEYPAD (INSIDE) ---
        ImGui::Text("Car Keypad");
        for (int i = 1; i <= numFloors; ++i) {
            ImGui::PushID(i + numFloors); // Use a different ID range
            if (ImGui::Button(std::to_string(i).c_str(), ImVec2(50, 50))) {
                controller.addCarRequest(i);
            }
            ImGui::PopID();

            // Arrange buttons in a grid
            if (i % 3 != 0) {
                ImGui::SameLine();
            }
        }

        ImGui::Dummy(ImVec2(0.0f, 20.0f));

        ImGui::NextColumn();

        // --- SECTION 4: PENDING REQUEST QUEUES ---
        ImGui::Text("Request Queues");
        ImGui::Text("Status: %s", DirectionToString(elevator.getDirection()));

        if (ImGui::TreeNode("Up Requests")) {
            for (int floor : upRequests) {
                ImGui::Text(" - Floor %d", floor);
            }
            ImGui::TreePop();
        }
        if (ImGui::TreeNode("Down Requests")) {
            for (int floor : downRequests) {
                ImGui::Text(" - Floor %d", floor);
            }
            ImGui::TreePop();
        }

        // Stop using columns for the rest of the window
        ImGui::Columns(1);
        

        ImGui::End();
    }
}

