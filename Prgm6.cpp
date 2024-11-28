/* Iterating Through Containers and Finding Elements
Goal: Practice iterating through containers and retrieving specific elements.
Scenario:
You are tasked with highlighting all active widgets on the HMI screen. The HMI has two main containers:
std::vector for dynamic widgets.
std::set for static widgets.
Steps:
Populate Containers:
Initialize a std::vector<std::string> with dynamic widgets ("Speedometer", "Tachometer", etc.).
Initialize a std::set<std::string> with static widgets ("Logo", "WarningLights").
Use Iterators:
Print all dynamic widgets using an iterator.
Check if a specific widget (e.g., "WarningLights") is in the std::set using std::set::find.
Advanced Iteration:
Combine both containers into a std::vector<std::string> using std::copy.
Use std::find to locate a specific widget in the combined container.
Output Results:
Print the widget list dynamically and show results of widget searches.*/





#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<std::string> dynamicWidgets = {"Speedometer", "Tachometer", "FuelGauge", "Temperature"};
    std::set<std::string> staticWidgets = {"Logo", "WarningLights", "BatteryStatus"};

    std::cout << "Dynamic Widgets:\n";
    for (size_t i = 0; i < dynamicWidgets.size(); i++) {
        std::cout << dynamicWidgets[i] << "\n";
    }

    if (staticWidgets.find("WarningLights") != staticWidgets.end()) {
        std::cout << "\n'WarningLights' is a static widget.\n";
    } else {
        std::cout << "\n'WarningLights' is not in the static widgets list.\n";
    }

    std::vector<std::string> allWidgets;
    allWidgets.insert(allWidgets.end(), dynamicWidgets.begin(), dynamicWidgets.end());
    allWidgets.insert(allWidgets.end(), staticWidgets.begin(), staticWidgets.end());

    std::cout << "\nAll Widgets:\n";
    for (const auto& widget : allWidgets) {
        std::cout << widget << "\n";
    }

    auto it = std::find(allWidgets.begin(), allWidgets.end(), "Tachometer");
    if (it != allWidgets.end()) {
        std::cout << "\n'Tachometer' is found in the combined widgets list.\n";
    } else {
        std::cout << "\n'Tachometer' is not in the combined widgets list.\n";
    }

    return 0;
}
