
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class MenuItem {
public:
    string name;
    vector<MenuItem> subMenus; 

    MenuItem(string itemName) : name(itemName) {}

    void addSubMenu(MenuItem subMenu) {
        subMenus.push_back(subMenu);
    }

   
    void displayMenu(int level = 0) {
        
        for (int i = 0; i < level; i++) {
            cout << "  ";
        }
        cout << name << endl;

        for (auto& subMenu : subMenus) {
            subMenu.displayMenu(level + 1);
        }
    }

    
    MenuItem* getSubMenu(int index) {
        if (index >= 0 && index < subMenus.size()) {
            return &subMenus[index];
        }
        return nullptr;
    }
};


class MenuNavigator {
private:
    MenuItem* currentMenu;

public:
    MenuNavigator(MenuItem* startMenu) : currentMenu(startMenu) {}

    void displayCurrentMenu() {
        cout << "\nCurrent Menu: " << currentMenu->name << endl;
        currentMenu->displayMenu(1);
    }

   
    void navigateDown(int index) {
        MenuItem* selectedMenu = currentMenu->getSubMenu(index);
        if (selectedMenu != nullptr) {
            currentMenu = selectedMenu;
        } else {
            cout << "Invalid selection!" << endl;
        }
    }

   
    MenuItem* getParentMenu(MenuItem* menu, MenuItem* rootMenu) {
       
        for (auto& subMenu : rootMenu->subMenus) {
            if (&subMenu == menu) {
                return rootMenu;
            }
            MenuItem* parent = getParentMenu(menu, &subMenu);
            if (parent != nullptr) {
                return parent;
            }
        }
        return nullptr;
    }

    void navigateUp() {
        MenuItem* parentMenu = getParentMenu(currentMenu, currentMenu);
        if (parentMenu != nullptr) {
            currentMenu = parentMenu;
        }
    }

    
    void enterMenu() {
       
    }
};


void handleUserInput(MenuNavigator& navigator) {
    int choice;
    while (true) {
        navigator.displayCurrentMenu();
        cout << "\nSelect an option: (1) Navigate Down (2) Navigate Up (3) Enter Menu (0) Exit: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting menu system." << endl;
            break;
        }

        switch (choice) {
        case 1: {
            int subMenuChoice;
            cout << "Enter submenu index: ";
            cin >> subMenuChoice;
            navigator.navigateDown(subMenuChoice);
            break;
        }
        case 2:
            navigator.navigateUp();
            break;
        case 3:
            navigator.enterMenu();
            cout << "You have entered the current menu." << endl;
            break;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }
    }
}

int main() {
    
    MenuItem mainMenu("Main Menu");

    MenuItem settings("Settings");
    settings.addSubMenu(MenuItem("Display Settings"));
    settings.addSubMenu(MenuItem("Audio Settings"));

    MenuItem media("Media");
    media.addSubMenu(MenuItem("Radio"));
    media.addSubMenu(MenuItem("Bluetooth Audio"));

    mainMenu.addSubMenu(settings);
    mainMenu.addSubMenu(media);

 
    MenuNavigator navigator(&mainMenu);

   
    handleUserInput(navigator);

    return 0;
}
