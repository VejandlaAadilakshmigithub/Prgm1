/* Sorting, Searching, and Merging
Goal: Practice sorting, searching, and merging in an HMI-related context.
Scenario:
A new feature requires merging two lists of controls into a single sorted list for efficient access.
Steps:
Sorting:
Sort the controls by their ID using std::sort.
Use std::stable_sort to maintain relative order for controls with equal IDs.
Binary Search:
Search for a control by ID using std::lower_bound and std::upper_bound.
Merging:
Merge two sorted lists of controls using std::merge.
Use std::inplace_merge to combine controls from two different segments in the same list.
Set Operations:
Use std::set_union and std::set_intersection to identify common and unique controls.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
 
using namespace std;
 
// Define the Control struct
struct Control {
    int id;
    string type;  // "button" or "slider"
    string state; // "visible", "invisible", "disabled"
};
 
// Function to print controls
void printControls(const vector<Control>& controls) {
    for (const auto& control : controls) {
        cout << "ID: " << control.id 
             << ", Type: " << control.type 
             << ", State: " << control.state << endl;
    }
    cout << "-----------------------" << endl;
}
 
// Comparator for sorting controls by ID
bool compareById(const Control& a, const Control& b) {
    return a.id < b.id;
}
 
int main() {
    // Step 1: Initialize two lists of controls
    vector<Control> controls1 = {
        {5, "button", "visible"}, {2, "slider", "disabled"}, {8, "button", "invisible"}
    };
    vector<Control> controls2 = {
        {3, "slider", "visible"}, {9, "button", "visible"}, {1, "slider", "invisible"}
    };
 
    cout << "Original Controls List 1:" << endl;
    printControls(controls1);
 
    cout << "Original Controls List 2:" << endl;
    printControls(controls2);
 
    // Step 2: Sorting
    sort(controls1.begin(), controls1.end(), compareById);
    sort(controls2.begin(), controls2.end(), compareById);
 
    cout << "Sorted Controls List 1:" << endl;
    printControls(controls1);
 
    cout << "Sorted Controls List 2:" << endl;
    printControls(controls2);
 
    // Step 3: Binary Search
    int searchId = 3;
    auto lower = lower_bound(controls1.begin(), controls1.end(), Control{searchId, "", ""}, compareById);
    auto upper = upper_bound(controls1.begin(), controls1.end(), Control{searchId, "", ""}, compareById);
 
    if (lower != controls1.end() && lower->id == searchId) {
        cout << "Control with ID " << searchId << " found using lower_bound:" << endl;
        cout << "ID: " << lower->id << ", Type: " << lower->type << ", State: " << lower->state << endl;
    } else {
        cout << "Control with ID " << searchId << " not found in Controls List 1." << endl;
    }
 
    cout << "Upper bound points to control with ID: " 
         << (upper != controls1.end() ? to_string(upper->id) : "None") << endl;
    cout << "-----------------------" << endl;
 
    // Step 4: Merging
    vector<Control> mergedControls;
    merge(controls1.begin(), controls1.end(), controls2.begin(), controls2.end(), back_inserter(mergedControls), compareById);
 
    cout << "Merged Controls:" << endl;
    printControls(mergedControls);
 
    // Step 5: In-place Merge
    vector<Control> combinedControls = controls1;
    combinedControls.insert(combinedControls.end(), controls2.begin(), controls2.end());
    inplace_merge(combinedControls.begin(), combinedControls.begin() + controls1.size(), combinedControls.end(), compareById);
 
    cout << "Controls after in-place merge:" << endl;
    printControls(combinedControls);
 
    // Step 6: Set Operations
    set<int> ids1, ids2, unionIds, intersectionIds;
 
    for (const auto& control : controls1) ids1.insert(control.id);
    for (const auto& control : controls2) ids2.insert(control.id);
 
    set_union(ids1.begin(), ids1.end(), ids2.begin(), ids2.end(), inserter(unionIds, unionIds.begin()));
    set_intersection(ids1.begin(), ids1.end(), ids2.begin(), ids2.end(), inserter(intersectionIds, intersectionIds.begin()));
 
    cout << "Union of IDs:" << endl;
    for (int id : unionIds) cout << id << " ";
    cout << endl;
 
    cout << "Intersection of IDs:" << endl;
    for (int id : intersectionIds) cout << id << " ";
    cout << endl;
 
    return 0;
}
