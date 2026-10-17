#include <iostream>
#include <memory>
#include "HAL.h"
#include "GrababotController.h"

int main() {
    GrababotController robot;
    
    // Register standard off-the-shelf components (mocked for now)
    robot.addActuator(std::make_shared<MockServo>());

    // Run a test control cycle
    std::cout << "Executing dry-run control cycle...\n";
    robot.executeCycle(45.0f);

    return 0;
}