#pragma once

#include <vector>
#include <memory>
#include "HAL.h"

class GrababotController {
private:
    std::vector<std::shared_ptr<IActuator>> actuators;
    std::vector<std::shared_ptr<ISensor>> sensors;

public:
    void addActuator(std::shared_ptr<IActuator> actuator);
    void addSensor(std::shared_ptr<ISensor> sensor);
    void executeCycle(float targetState);
};