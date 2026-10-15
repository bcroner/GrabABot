#include "GrababotController.h"
#include <iostream>

void GrababotController::addActuator(std::shared_ptr<IActuator> actuator) {
    actuators.push_back(actuator);
}

void GrababotController::addSensor(std::shared_ptr<ISensor> sensor) {
    sensors.push_back(sensor);
}

void GrababotController::executeCycle(float targetState) {
    // Poll all off-the-shelf sensors
    for (const auto& sensor : sensors) {
        sensor->poll();
    }

    // Drive actuators based on control logic
    for (auto& actuator : actuators) {
        actuator->setPosition(targetState);
        std::cout << "[GrababotController] Actuator position updated to: " << actuator->getPosition() << "\n";
    }
}