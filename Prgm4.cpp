/*
Task 4: HMI Skin Customization System
Objective: Implement a system to manage different themes or skins for an HMI display.
Requirements:
Create a Theme class:

Attributes: backgroundColor, fontColor, fontSize, and iconStyle.
Implement methods to apply and display the theme.
Store multiple themes using std::map:

Example themes: Classic, Sport, and Eco.
Create a simple user interface to switch between themes:

Use console input to select a theme.
Display a preview of the selected theme on the console (e.g., "Sport Theme: Red Background, White Font").
Deliverables:
A C++ program that demonstrates theme switching.
Output displaying applied themes.
General Instructions:
Ensure your code follows OOP principles (e.g., use of classes, inheritance, and encapsulation).
Comment your code to explain each step and decision.
Include a README file with instructions for running the program.*/
 
#include <iostream>
#include <thread>
#include <map>
using namespace std;
 
/// @brief theme class
 
class Theme
{
    string backgroundColor;                                                         
    string fontColor;
    int fontSize;
    string iconStyle;
 
public:
    Theme(string backgroundColor, string fontColor, int fontSize, string iconStyle) : backgroundColor(backgroundColor), fontColor(fontColor), fontSize(fontSize), iconStyle(iconStyle) 
    {}
 
    // setters
    void setBackgroundColor(string backgroundColor) { this->backgroundColor = backgroundColor; }
 
    void setFontColor(string fontColor) { this->fontColor = fontColor; }
 
    void setFontSize(int fontSize) { this->fontSize = fontSize; }
 
    void setIconStyle(string iconStyle) { this->iconStyle = iconStyle; }
 
    // getters
    string getBackgroundColor() { return backgroundColor; }
    string getFontColor() { return fontColor; }
    int getFontSize() { return fontSize; }
    string getIconStyle() { return iconStyle; }
 
    // display theme
    virtual void displayTheme()
    {
        cout << "Default theme" << endl;
        cout << getBackgroundColor() << "-Background, " << getFontColor() << "-Font, " << getFontSize() << "-px, " << getIconStyle() << "-Style" << endl;
    }
};
 
// Classic theme
 
class Classic : public Theme
{
    string themeType;
 
public:
    Classic(string themeType, string backgroundColor, string fontColor, int fontSize, string iconStyle) : Theme(backgroundColor, fontColor, fontSize, iconStyle), themeType(themeType) {}
    // display theme overrriden
    void displayTheme()
    {
        cout << "applying theme--" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << themeType << "Theme, " << getBackgroundColor() << "-Background, " << getFontColor() << "-Font, " << getFontSize() << "-px, " << getIconStyle() << "-Style" << endl;
    }
};
 
// Sport theme
class Sport : public Theme
{
    string themeType;
 
public:
    Sport(string themeType, string backgroundColor, string fontColor, int fontSize, string iconStyle) : Theme(backgroundColor, fontColor, fontSize, iconStyle), themeType(themeType) {}
    void displayTheme()
    {
        cout << "applying theme.." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << themeType << "Theme, " << getBackgroundColor() << "-Background, " << getFontColor() << "-Font, " << getFontSize() << "-px, " << getIconStyle() << "-Style" << endl;
    }
};
 
// eco theme
class Eco : public Theme
{
    string themeType;
 
public:
    Eco(string themeType, string backgroundColor, string fontColor, int fontSize, string iconStyle) : Theme(backgroundColor, fontColor, fontSize, iconStyle), themeType(themeType) {}
    void displayTheme()
    {
        cout << "applying theme.." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << themeType << "Theme, " << getBackgroundColor() << "-Background, " << getFontColor() << "-Font, " << getFontSize() << "-px, " << getIconStyle() << "-Style" << endl;
    }
};
 
// switch theme
void switchTheme(Theme *theme)
{
    theme->displayTheme();
}
 
int main()
{
    // create Theme object and dispaly current theme
 
    Theme *theme = new Theme("Red", "White", 10, "Minimal");
    theme->displayTheme();
 
    // create multiple themes
    Theme *classic = new Classic("Classic", "Red", "White", 14, "Minimal");
    Theme *sport = new Sport("Sport", "Red", "Black", 16, "Dynamic");
    Theme *eco = new Eco("Eco", "Green", "White", 15, "Flat");
 
    // store themes in a map [key=themeType, value=theme Objecte]
    map<string, Theme *> themes;
    themes.insert({"Classic", classic});
    themes.insert({"Sport", sport});
    themes.insert({"Eco", eco});
 
    int choice, count = 0;
 
    cout << endl;
    // take input for theme
    while (true)
    {
        count++;
        if (count == 6)
        {
            break;
        }
        cout << endl;
        {
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Choose Theme:" << endl;
            cout << "1.Classic\n2.Sport\n3.Eco" << endl;
            cin >> choice;
            // display the theme based on selected theme
            switch (choice)
            {
            case 1:
                classic = themes["Classic"];
                switchTheme(classic);
                break;
            case 2:
                sport = themes["Sport"];
                switchTheme(sport);
                break;
            case 3:
                eco = themes["Eco"];
                switchTheme(eco);
                break;
            default:
                cout << "Please choose correct option.." << endl;
                switchTheme(theme);
                break;
            }
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
 
    delete theme;
    delete eco;
    delete classic;
    delete sport;
 
    return 0;
} 


