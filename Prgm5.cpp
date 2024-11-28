/*Working with STL Algorithms
Goal: Practice commonly used STL algorithms in the context of managing HMI control states (e.g., button visibility, slider values).
Scenario:
Imagine an HMI dashboard with buttons and sliders. Each control has a unique ID and a state (visible, invisible, disabled).
Steps:
Define the data structure:
Create a struct Control:
cppCopy codestruct Control {    int id;               // Unique ID    std::string type;     // "button" or "slider"    std::string state;    // "visible", "invisible", "disabled"}; 
Initialize the container:
Create a std::vector<Control> and populate it with sample controls (5 buttons and 5 sliders).
Use the following algorithms:
std::for_each: Iterate through all controls and print their details.
std::find: Find a control with a specific ID.
std::find_if: Find the first invisible control.
std::adjacent_find: Check for consecutive controls with the same state.
std::count: Count the number of visible controls.
std::count_if: Count sliders that are disabled.
std::equal: Compare two subranges of controls to check if they are identical.
Implementation Example:
cppCopy codeauto invisibleControl = std::find_if(controls.begin(), controls.end(),    [](const Control& ctrl) { return ctrl.state == "invisible"; }); 
Output Results:
Print the results of each algorithm in a user-friendly format.*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
// Define the Control struct
struct Control {
    int id;                 // Unique ID
    string type;            // "button" or "slider"
    string state;           // "visible", "invisible", "disabled"
 
    // Overloading the equality operator
    bool operator==(const Control& other) const {
        return id == other.id && type == other.type && state == other.state;
    }
};
 
// Function to print the details of a Control
void printControl(const Control& control) {
    cout << "ID: " << control.id 
         << ", Type: " << control.type 
         << ", State: " << control.state << endl;
}
 
int main() {
    // Initialize the container with sample controls
    vector<Control> controls = {
        {1, "button", "visible"}, {2, "button", "invisible"}, 
        {3, "button", "disabled"}, {4, "button", "visible"}, 
        {5, "button", "visible"}, {6, "slider", "visible"}, 
        {7, "slider", "invisible"}, {8, "slider", "disabled"}, 
        {9, "slider", "disabled"}, {10, "slider", "visible"}
    };
 
    // 1. std::for_each: Iterate through all controls and print their details
    cout << "All controls:" << endl;
    for_each(controls.begin(), controls.end(), printControl);
    cout << endl;
 
    // 2. std::find: Find a control with a specific ID
    int searchId = 3;
    auto foundControl = find_if(controls.begin(), controls.end(), 
                                [searchId](const Control& ctrl) { return ctrl.id == searchId; });
    if (foundControl != controls.end()) {
        cout << "Control with ID " << searchId << " found:" << endl;
        printControl(*foundControl);
    } else {
        cout << "Control with ID " << searchId << " not found." << endl;
    }
    cout << endl;
 
    // 3. std::find_if: Find the first invisible control
    auto invisibleControl = find_if(controls.begin(), controls.end(), 
                                    [](const Control& ctrl) { return ctrl.state == "invisible"; });
    if (invisibleControl != controls.end()) {
        cout << "First invisible control found:" << endl;
        printControl(*invisibleControl);
    } else {
        cout << "No invisible control found." << endl;
    }
    cout << endl;
 
    // 4. std::adjacent_find: Check for consecutive controls with the same state
    auto consecutiveSameState = adjacent_find(controls.begin(), controls.end(), 
                                              [](const Control& a, const Control& b) { return a.state == b.state; });
    if (consecutiveSameState != controls.end()) {
        cout << "Consecutive controls with the same state found:" << endl;
        printControl(*consecutiveSameState);
        printControl(*(consecutiveSameState + 1));
    } else {
        cout << "No consecutive controls with the same state found." << endl;
    }
    cout << endl;
 
    // 5. std::count: Count the number of visible controls
    int visibleCount = count_if(controls.begin(), controls.end(), 
                                [](const Control& ctrl) { return ctrl.state == "visible"; });
    cout << "Number of visible controls: " << visibleCount << endl;
    cout << endl;
 
    // 6. std::count_if: Count sliders that are disabled
    int disabledSlidersCount = count_if(controls.begin(), controls.end(), 
                                        [](const Control& ctrl) { return ctrl.type == "slider" && ctrl.state == "disabled"; });
    cout << "Number of disabled sliders: " << disabledSlidersCount << endl;
    cout << endl;
 
    // 7. std::equal: Compare two subranges of controls to check if they are identical
    if (controls.size() >= 4) { // Ensure there are enough elements for comparison
        bool areEqual = equal(controls.begin(), controls.begin() + 2, controls.begin() + 2, controls.begin() + 4);
        cout << "Are the first two controls identical to the next two? " 
             << (areEqual ? "Yes" : "No") << endl;
    } else {
        cout << "Not enough controls to compare subranges." << endl;
    }
 
    return 0;
}
