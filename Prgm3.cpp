/*Event Handling System for Touchscreen Input
Objective: Simulate an event-driven system for processing touchscreen inputs on an HMI.
Requirements:
Create an Event class to represent user interactions:
Attributes: eventType (e.g., Tap, Swipe), x and y coordinates, and timestamp.
Implement an event queue using std::queue:
Store multiple events.
Process events one by one.
Handle specific events:
Tap: Display a message showing the tapped position.
Swipe: Calculate the swipe direction (up/down/left/right) and display it.
Simulate event generation:
Populate the queue with random events.
Deliverables:
A program simulating event processing.
Example output demonstrating event handling.
*/


#include<iostream>
#include<queue>
#include<cstdlib>
#include<ctime>
using namespace std;

enum eventType
{
    Tap,
    Swipe
};

class Event
{
public:
    eventType type;
    string timestamp;
    int x, y;
    
    
    Event(eventType t, int xCoord, int yCoord, const std::string &time)
        : type(t), x(xCoord), y(yCoord), timestamp(time)
    {}

    
    void displayEvent() const {
        cout << "Event type: " << (type == Tap ? "Tap" : "Swipe")
             << " | Coordinates: (" << x << ", " << y << ") | Timestamp: " << timestamp << endl;
    }
};


eventType getRandomEventType()
{
    return static_cast<eventType>(rand() % 2);
}


string getRandomTimestamp()
{
    return "2024-11-27 12:34:56";  
}


string getSwipeDirection()
{
    int direction = rand() % 4;
    switch (direction)
    {
        case 0: return "Up";
        case 1: return "Down";
        case 2: return "Left";
        case 3: return "Right";
        default: return "Unknown";
    }
}

int main()
{
  
    srand(time(0));
    
    queue<Event> eventQueue;
    
   
    for (int i = 0; i < 5; ++i)
    {
        int x = rand() % 500;     
        int y = rand() % 500;     
        
        eventType type = getRandomEventType();   
        string timestamp = getRandomTimestamp(); 
        
        
        Event newEvent(type, x, y, timestamp);
        eventQueue.push(newEvent);
    }
    
   
    while (!eventQueue.empty())
    {
        Event currentEvent = eventQueue.front(); 
        eventQueue.pop(); 
        
        currentEvent.displayEvent(); 
        
        
        if (currentEvent.type == Tap)
        {
            cout << "Action: Displaying Tap at (" << currentEvent.x << ", " << currentEvent.y << ")\n\n";
        }
        else if (currentEvent.type == Swipe)
        {
            string direction = getSwipeDirection(); 
            cout << "Action: Performing Swipe in " << direction << " direction.\n\n";
        }
    }
    
    return 0;
}

