/*Advanced STL Operations
Goal: Perform advanced operations such as transformations and conditional modifications on HMI states.
Scenario:
The system needs to process HMI states based on certain conditions (e.g., hide all sliders during night mode).
Steps:
Manipulate Control States:
Use std::copy to create a backup of the control list.
Use std::fill to set all states to "disabled" temporarily.
Use std::generate to generate random states ("visible", "invisible", "disabled") for testing.
Apply Transformations:
Use std::transform to change the state of all sliders to "invisible".
Use std::replace to replace "disabled" with "enabled" for testing.
Use std::remove_if to filter out invisible controls from the list.
Other Operations:
Use std::reverse to reverse the control order (e.g., for a debug layout).
Use std::partition to group visible controls together.
Output Results:
Show intermediate results after each operation.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
 
using namespace std;
 
// Define the Control struct
struct Control {
    int id;
    string type;  // "button" or "slider"
    string state; // "visible", "invisible", "disabled"
};
 
// Function to print the controls
void printControls(const vector<Control>& controls) {
    for (const auto& control : controls) {
        cout << "ID: " << control.id 
             << ", Type: " << control.type 
             << ", State: " << control.state << endl;
    }
    cout << "-----------------------" << endl;
}
 
int main() {
    // Step 1: Populate the control list
    vector<Control> controls = {
        {1, "button", "visible"}, {2, "slider", "visible"}, 
        {3, "button", "invisible"}, {4, "slider", "disabled"}, 
        {5, "button", "visible"}, {6, "slider", "disabled"}
    };
 
    cout << "Original Controls:" << endl;
    printControls(controls);
 
    // Step 2: std::copy to create a backup
    vector<Control> backupControls;
    copy(controls.begin(), controls.end(), back_inserter(backupControls));
    cout << "Backup Controls:" << endl;
    printControls(backupControls);
 
    // Step 3: std::fill to set all states to "disabled" temporarily
    fill(controls.begin(), controls.end(), Control{0, "reset", "disabled"});
    cout << "Controls after fill:" << endl;
    printControls(controls);
 
    // Step 4: std::generate to assign random states for testing
    vector<string> possibleStates = {"visible", "invisible", "disabled"};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 2);
 
    generate(controls.begin(), controls.end(), [&]() {
        return Control{rand() % 100, "slider", possibleStates[dist(gen)]};
    });
    cout << "Controls after generate:" << endl;
    printControls(controls);
 
    // Step 5: std::transform to change slider states to "invisible"
    transform(controls.begin(), controls.end(), controls.begin(), [](Control& control) {
        if (control.type == "slider") {
            control.state = "invisible";
        }
        return control;
    });
    cout << "Controls after transform (sliders invisible):" << endl;
    printControls(controls);
 
    // Step 6: std::replace to change "disabled" to "enabled"
    for_each(controls.begin(), controls.end(), [](Control& control) {
        if (control.state == "disabled") {
            control.state = "enabled";
        }
    });
    cout << "Controls after replace (disabled -> enabled):" << endl;
    printControls(controls);
 
    // Step 7: std::remove_if to filter out invisible controls
    controls.erase(remove_if(controls.begin(), controls.end(), [](const Control& control) {
        return control.state == "invisible";
    }), controls.end());
    cout << "Controls after remove_if (no invisibles):" << endl;
    printControls(controls);
 
    // Step 8: std::reverse to reverse the order
    reverse(controls.begin(), controls.end());
    cout << "Controls after reverse:" << endl;
    printControls(controls);
 
    // Step 9: std::partition to group visible controls
    partition(controls.begin(), controls.end(), [](const Control& control) {
        return control.state == "visible";
    });
    cout << "Controls after partition (visible grouped):" << endl;
    printControls(controls);
 
    return 0;
}
