/*Simulate an Instrument Cluster Data Display
Objective: Create a simplified data display system to simulate speed, fuel level, and engine temperature.
Requirements:
Implement a class-based design:
Create a VehicleData class to store parameters like speed, fuel level, and engine temperature.
Create a Display class to show these parameters on the console.
Simulate real-time updates:
Use a random number generator to update speed, fuel level, and temperature every second.
Display the updated data in a formatted manner (e.g., speed: 80 km/h, fuel: 50%, temperature: 90°C).
Add constraints:
Display warnings when parameters exceed thresholds (e.g., temperature > 100°C or fuel < 10%).
Deliverables:
A C++ program using multithreading (std::thread) to update and display data.
Output showcasing real-time updates and warnings.
*/

#include<iostream>
#include<string>
#include<random>
#include<thread>
#include<chrono>
#include<cstdlib>
#include<ctime>

using namespace std;

class VehicleData
{
    public:

    int speed;
   int fuelLevel;
    int enginetemperature;

    VehicleData()
    {
        speed = 0;
        fuelLevel = 100;
        enginetemperature= 90;

    }

void  updatevehicleData()
{
     srand(time(0));  //specific time purpose we are using

        
        speed = rand() % 81; 
        fuelLevel = rand() % 51;  
        enginetemperature = rand() % 61 + 60; 
}
};
class Display
{
    public:
    void showVehicleData(VehicleData vehicle)
    {
        cout<<"speed: "<< vehicle.speed <<endl;
        cout<<"fuelLevel: "<< vehicle.fuelLevel <<endl;
        cout<<"enginetemperature: "<< vehicle.enginetemperature <<endl;
               
              
    if(vehicle.enginetemperature > 100)
    {
        cout<< "warning: Engine temperature is too high! (>100°C)" <<endl;
    }
    else if(vehicle.fuelLevel < 10 )
    {
        cout<<"Warning:fuel level is low!" << endl;
    }
    }
};

void updateAndDisplayData(VehicleData& vehicle, Display& display) {
    while (true) {
        vehicle.updatevehicleData();  
        display.showVehicleData(vehicle);  

        
        this_thread::sleep_for(chrono::seconds(3));
    }
}
int main()
{
   
VehicleData myCar;
Display display;

 thread dataThread(updateAndDisplayData, ref(myCar), ref(display));
/*The line thread dataThread(updateAndDisplayData, ref(myCar), ref(display)); creates a new thread in C++ that runs the updateAndDisplayData function.*/
   dataThread.join();

    return 0;

} 


