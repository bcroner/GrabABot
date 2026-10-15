#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// Abstract Sensor Interface for off-the-shelf components
class ISensor {
public:
    virtual ~ISensor() = default;
    virtual void poll() = 0;
    virtual float readValue() const = 0;
};

// Abstract Actuator Interface for standard PWM/stepper controllers
class IActuator {
public:
    virtual ~IActuator() = default;
    virtual void setPosition(float target) = 0;
    virtual float getPosition() const = 0;
};

// Mock implementation for development without hardware connected
class MockServo : public IActuator {
private:
    float currentPosition = 0.0f;
public:
    void setPosition(float target) override {
        // Simulate smooth movement toward target
        currentPosition += (target - currentPosition) * 0.2f;
        std::cout << "[MockServo] Position updated to: " << currentPosition << "\n";
    }
    float getPosition() const override {
        return currentPosition;
    }
};

// Core Robot Controller Logic
class GrababotController {
private:
    std::vector<std::shared_ptr<IActuator>> actuators;
    std::vector<std::shared_ptr<ISensor>> sensors;

public:
    void addActuator(std::shared_ptr<IActuator> actuator) {
        actuators.push_back(actuator);
    }

    void addSensor(std::shared_ptr<ISensor> sensor) {
        sensors.push_back(sensor);
    }

    void executeCycle(float targetState) {
        // Poll all off-the-shelf sensors
        for (const auto& sensor : sensors) {
            sensor->poll();
        }

        // Drive actuators based on control logic
        for (auto& actuator : actuators) {
            actuator->setPosition(targetState);
        }
    }
};

int main() {
    GrababotController robot;
    
    // Register standard off-the-shelf components (mocked for now)
    robot.addActuator(std::make_shared<MockServo>());

    // Run a test control cycle
    std::cout << "Executing dry-run control cycle...\n";
    robot.executeCycle(45.0f);

    return 0;
}