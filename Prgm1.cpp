
/*#include <iostream>
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
*/

#include<iostream>
#include<vector>

using namespace std;
struct menuNode{
    string data ;
    vector<menuNode*> child;
 
    menuNode(string data){
        this->data = data;
    }
    void addchild(menuNode *data){
        child.push_back(data);
    }  
};
 
 
void displayMenu(menuNode *menu){
     cout<<" == "<<menu->data<<" == "<<endl;
     if(menu->data.empty()){
        cout<<"No sub menu available...."<<endl;
     }else{
        for(auto  i = 0 ; i < menu->child.size(); i++){
            cout<<i+1 <<". "<<menu->child[i]->data<<endl;
        }
     }  
}
void navigate(menuNode *menu){
   int choice ;
     while(true){
           displayMenu(menu);
           cout<<"Choose an option(enter 0 to go back): "<<endl;
           cin>>choice;
 
           if(choice == 0){
            cout<<"Going back... "<<endl;
            break;
           }
           
        if(choice <1 || choice > menu->child.size()){
            cout<<"Invalid choice..."<<endl;
        }else{
            cout << "Navigating to " << menu->child[choice-1]->data << "...\n";
            navigate(menu->child[choice]);
        }                
     }
}
int main(){
    menuNode *root = new menuNode("Main menu");
    menuNode *submenu1 = new menuNode("settings");
    menuNode *submenu2 = new menuNode("media");
 
    root->addchild(submenu1);
    root->addchild(submenu2);
     
    menuNode *submenu1_1 = new menuNode("Display settings");
    menuNode *submenu1_2 = new menuNode("Audio settings");
 
    submenu1->addchild(submenu1_1);
    submenu1->addchild(submenu1_2);
 
    menuNode *submenu2_1 = new menuNode("Radio");
    menuNode *submenu2_2 = new menuNode("Bluethoo");
 
    //displayMenu(root);
    cout<<"Welcome to our playlist...."<<endl;
 
    navigate(root);
 
   return 0;
}
