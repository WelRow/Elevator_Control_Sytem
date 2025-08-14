# C++ Elevator Control System Simulator

This project is a C++ console application that simulates the logic of a single elevator operating within a multi-story building.

## Features 

* **State-Driven Logic**: The elevator operates using a clean state machine (`IDLE`, `MOVING_UP`, `MOVING_DOWN`) to manage its behavior on each tick of the simulation.
* **Request Handling**: The system intelligently handles two types of requests:
    * **Car Calls**: Requests made from inside the elevator to a specific destination floor.
    * **Hall Calls**: Requests made from a floor to go in a specific direction (up or down).
* **Efficient Request Management**: Uses `std::set` to store pending floor requests, which automatically handles sorting and prevents duplicate requests. The `downRequests` set is cleverly sorted in descending order using `std::greater<int>` for efficient lookup of the next lowest floor.
* **Real-time Simulation**: The `main` function runs a continuous loop, calling the controller's `tick()` method to process one step of the simulation at a time, mimicking real-world operation.

## How to Build and Run

This project is configured to be built with Visual Studio.

1.  **Clone the repository:**
    ```bash
    git clone <your-repo-url>
    ```
2.  **Open the Solution:** Open the `Elevator_Control_Sytem.sln` file in Visual Studio.
3.  **Build the Project:** From the main menu, select `Build` > `Build Solution` (or press `Ctrl+Shift+B`).
4.  **Run the Simulation:** Run the project by pressing the "Local Windows Debugger" button or by pressing `F5`. A console window will appear and display the elevator's status as it services the hardcoded requests in `main.cpp`.
