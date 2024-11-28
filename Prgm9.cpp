/* Implementing Design Patterns in HMI
Goal: Implement and understand the Singleton, Factory, Observer, and Strategy design patterns.
Steps:
Singleton:
Implement a singleton class HMISystem to manage the overall HMI state.
Factory:
Create a factory to instantiate different types of controls (Button, Slider, etc.).
Observer:
Implement an observer to notify widgets when the system switches modes (e.g., Day/Night mode).
Strategy:
Use the strategy pattern to define different rendering behaviors (e.g., 2D vs. 3D).
Implementation Example (Observer Pattern):
 
Plain Text


cppCopy codeclass ModeObserver {public:    virtual void update(const std::string& mode) = 0;};class Button : public ModeObserver {    void update(const std::string& mode) override {        if (mode == "Night") {            // Adjust visibility        }    }}; */

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
 
using namespace std;
 
// Singleton: Manage overall HMI state
class HMISystem {
private:
    static HMISystem* instance;
    string currentMode;
 
    // Private constructor
    HMISystem() : currentMode("Day") {}
 
public:
    // Delete copy constructor and assignment operator
    HMISystem(const HMISystem&) = delete;
    HMISystem& operator=(const HMISystem&) = delete;
 
    static HMISystem* getInstance() {
        if (instance == nullptr) {
            instance = new HMISystem();
        }
        return instance;
    }
 
    void setMode(const string& mode) {
        currentMode = mode;
        cout << "HMI Mode set to: " << mode << endl;
    }
 
    string getMode() const {
        return currentMode;
    }
};
 
// Initialize static member
HMISystem* HMISystem::instance = nullptr;
 
// Factory: Create controls dynamically
class Control {
public:
    virtual void render() const = 0;
    virtual ~Control() {}
};
 
class Button : public Control {
public:
    void render() const override {
        cout << "Rendering Button" << endl;
    }
};
 
class Slider : public Control {
public:
    void render() const override {
        cout << "Rendering Slider" << endl;
    }
};
 
class ControlFactory {
public:
    static unique_ptr<Control> createControl(const string& type) {
        if (type == "Button") {
            return make_unique<Button>();
        } else if (type == "Slider") {
            return make_unique<Slider>();
        } else {
            return nullptr;
        }
    }
};
 
// Observer: Notify widgets when mode changes
class ModeObserver {
public:
    virtual void update(const string& mode) = 0;
    virtual ~ModeObserver() {}
};
 
class ButtonObserver : public ModeObserver {
public:
    void update(const string& mode) override {
        if (mode == "Night") {
            cout << "Button adjusted for Night mode." << endl;
        } else {
            cout << "Button adjusted for Day mode." << endl;
        }
    }
};
 
class SliderObserver : public ModeObserver {
public:
    void update(const string& mode) override {
        if (mode == "Night") {
            cout << "Slider adjusted for Night mode." << endl;
        } else {
            cout << "Slider adjusted for Day mode." << endl;
        }
    }
};
 
class HMIModeManager {
    vector<ModeObserver*> observers;
 
public:
    void addObserver(ModeObserver* observer) {
        observers.push_back(observer);
    }
 
    void notifyObservers(const string& mode) {
        for (auto observer : observers) {
            observer->update(mode);
        }
    }
};
 
// Strategy: Define rendering behaviors
class RenderingStrategy {
public:
    virtual void render() const = 0;
    virtual ~RenderingStrategy() {}
};
 
class Render2D : public RenderingStrategy {
public:
    void render() const override {
        cout << "Rendering in 2D mode." << endl;
    }
};
 
class Render3D : public RenderingStrategy {
public:
    void render() const override {
        cout << "Rendering in 3D mode." << endl;
    }
};
 
class HMIRenderer {
    RenderingStrategy* strategy;
 
public:
    HMIRenderer(RenderingStrategy* initialStrategy) : strategy(initialStrategy) {}
 
    void setStrategy(RenderingStrategy* newStrategy) {
        strategy = newStrategy;
    }
 
    void render() const {
        strategy->render();
    }
};
 
// Main: Combining all patterns
int main() {
    // Singleton: Manage HMI mode
    HMISystem* hmiSystem = HMISystem::getInstance();
    hmiSystem->setMode("Day");
 
    // Factory: Create controls
    auto button = ControlFactory::createControl("Button");
    auto slider = ControlFactory::createControl("Slider");
    button->render();
    slider->render();
 
    // Observer: Notify widgets about mode change
    ButtonObserver buttonObserver;
    SliderObserver sliderObserver;
 
    HMIModeManager modeManager;
    modeManager.addObserver(&buttonObserver);
    modeManager.addObserver(&sliderObserver);
 
    // Change to Night mode and notify observers
    hmiSystem->setMode("Night");
    modeManager.notifyObservers(hmiSystem->getMode());
 
    // Strategy: Switch rendering behaviors
    Render2D render2D;
    Render3D render3D;
 
    HMIRenderer renderer(&render2D);
    renderer.render();
 
    renderer.setStrategy(&render3D);
    renderer.render();
 
    return 0;
}
