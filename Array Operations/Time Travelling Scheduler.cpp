#include <iostream>
#include<string>
using namespace std;
class Event 
{
protected:
	string timestamp;				// Timestamp of the event
	string eventData;				// Description or data associated with the event

public:

	Event() : timestamp("0000-00-00 00:00"), eventData("No Data") {} //for error resolving

	// Constructor
	Event(const string& timestamp, const string& eventData)
	{
		this->timestamp = timestamp;
		this->eventData = eventData;
	}

	Event(const Event& other) 
	{
		timestamp = other.timestamp;
		eventData = other.eventData;
	}

	string getTimestamp() const
	{
		return timestamp;
	}

	string getEventData() const
	{
		return eventData;
	}
		
	void setTimestamp(const string& timestamp)
	{
		this->timestamp = timestamp;
	}

	void setEventData(const string& eventData)
	{
		this->eventData = eventData;
	}

	bool operator< (const Event& other) const
	{
		return this->timestamp < other.timestamp;	//lexicographical comparison
	}

	bool operator>(const Event& other) const 
	{
		return this->timestamp > other.timestamp;
	}

	bool operator==(const Event& other) const
	{
		return this->timestamp == other.timestamp;
	}

	Event& operator=(const Event& other) 
	{
		if (this != &other)
		{ // Protect against self-assignment
			this->timestamp = other.timestamp;
			this->eventData = other.eventData;
		}
		return *this;
	}


	void display() const 
	{
		//cout << "Hello World" << endl;
		cout << timestamp << " " << eventData << endl;
	}

};

class Snapshot 
{
protected:
	Event* events;							// Pointer to a dynamic array of events
	int numEvents;							// Number of events in the snapshot

public:
	Snapshot() : events(NULL), numEvents(0) {}

	Snapshot(Event* eventsArray, int size) 
	{
		numEvents = size;                 
		events = new Event[numEvents];    

		for (int i = 0; i < numEvents; ++i)
		{
			events[i] = eventsArray[i];
		}
	}

	// Copy constructor
	Snapshot(const Snapshot& other) 
	{
		numEvents = other.numEvents;
		events = new Event[numEvents];

		for (int i = 0; i < numEvents; ++i)
		{
			events[i] = other.events[i];
		}
	}

	Snapshot& operator=(const Snapshot& other)
	{
		if (this != &other)
		{
			delete[] events;

			// Allocate new memory and copy data
			numEvents = other.numEvents;
			events = new Event[numEvents];

			for (int i = 0; i < numEvents; ++i)
			{
				events[i] = other.events[i];
			}
		}

		return *this;
	}


	~Snapshot() 
	{
		delete[] events;
	}

	Event* getEvents() const
	{
		if (numEvents == 0)
			return NULL;

		Event* eventsCopy = new Event[numEvents];

		for (int i = 0; i < numEvents; ++i)
		{
			eventsCopy[i] = events[i];
		}

		return eventsCopy;
	}

	int getNumEvents() const
	{
		return numEvents;
	}

	void displaySnapshot() const
	{
		cout << "Snapshot of " << numEvents << " event(s):" << endl;
		for (int i = 0; i < numEvents; ++i)
		{
			cout << i + 1 << ". ";
			events[i].display(); 
		}
	}
};

class Scheduler
{
protected:

	Event* events;				// Dynamic array to store current events in sorted order
	int eventCount;				// Number of events currently stored
	int eventCapacity;			// Capacity of the dynamic array assume 100

	Snapshot* history;			 // Dynamic array of Snapshot objects assume 50 max
	int historyCount;			// Number of snapshots saved
	int historyCapacity;		// Capacity of the history array


public:

	Scheduler(int initialCapacity = 100)
	{
		eventCapacity = initialCapacity;
		eventCount = 0;
		events = new Event[eventCapacity];

		historyCapacity = 50;
		historyCount = 0;
		history = new Snapshot[historyCapacity]; 
	}

	~Scheduler()
	{
		delete[] events;
		delete[] history;
	}

	// Event Operations
	void addEvent(const string& timestamp, const string& eventData)
	{
		// Check if the array is full
		if (eventCount >= eventCapacity)
		{
			cout << "Error: Event capacity reached. Cannot add more events." << endl;
			return;
		}

		// Find the position to insert the event
		int insertPos = binarySearchForAdd(timestamp);

		// Create the new event
		Event newEvent(timestamp, eventData);

		// Shift events to the right to make space for the new event
		for (int i = eventCount; i > insertPos; --i)
		{
			events[i] = events[i - 1];
		}

		// Insert the new event
		events[insertPos] = newEvent;
		eventCount++;

		cout << eventData << " " << "Added!" << endl;
	}

	void removeEvent(const string& timestamp)
	{
		// Find the position of the event to remove
		int removePos = binarySearch(timestamp);

		// If the event is not found
		if (removePos == -1)
		{
			cout << "Event Not Found!" << endl;
			return;
		}

		// Shift events to the left to fill the gap created by the removed event
		for (int i = removePos; i < eventCount - 1; ++i)
		{
			events[i] = events[i + 1];
		}

		// Decrement the event count
		eventCount--;

		cout << timestamp << " Removed!" << endl;
	}

	Event* queryEvent(const string& timestamp)
	{
		int pos = binarySearch(timestamp);

		// If the event is found, return a pointer to it
		if (pos != -1)
		{
			return &events[pos];
		}

		// If the event is not found, return `NULL`
		return NULL;
	}

	Event* queryRange(const string& start, const string& end, int& count)
	{
		count = 0; 

		// Find the start position using binary search
		int startPos = binarySearchForAdd(start);
		int endPos = binarySearchForAdd(end);

		// Adjust startPos to include an exact match if the range includes `start`
		if (startPos > 0 && events[startPos - 1].getTimestamp() == start)
		{
			--startPos;
		}

		// Check for a valid range
		if (startPos >= eventCount || start > events[eventCount - 1].getTimestamp())
		{
			return NULL; // No events in the range
		}

		// Count the number of events in the range
		for (int i = startPos; i < eventCount && events[i].getTimestamp() <= end; ++i)
		{
			++count;
		}

		// If no events are in the range, return NULL
		if (count == 0)
		{
			return NULL;
		}

		// Allocate a new array to store the events in the range
		Event* range = new Event[count];
		int index = 0;

		// Populate the range array with events
		for (int i = startPos; i < eventCount && events[i].getTimestamp() <= end; ++i)
		{
			range[index++] = events[i];
		}

		return range;
	}

	// Time Travel
	void timeTravel(int snapshotIndex) 
	{
		// Validate the snapshot index
		if (snapshotIndex < 0 || snapshotIndex >= historyCount)
		{
			cout << "Invalid snapshot index. Unable to time travel." << endl;
			return;
		}

		// Get the snapshot to restore
		Snapshot& snapshotToRestore = history[snapshotIndex];

		// Free the current events array
		delete[] events;

		// Restore the events array from the snapshot
		eventCount = snapshotToRestore.getNumEvents();
		events = new Event[eventCapacity];

		// Retrieve the events array from the snapshot
		Event* snapshotEvents = snapshotToRestore.getEvents();
		for (int i = 0; i < eventCount; ++i)
		{
			events[i] = snapshotEvents[i]; // Copy each event
		}

		delete[] snapshotEvents;

		
	}


	void addSnapshot()
	{
		if (historyCount >= historyCapacity)
		{
			cout << "Snapshot history is full. Cannot add more snapshots." << endl;
			return;
		}

		// Create a new snapshot with the current state of events
		Snapshot newSnapshot(events, eventCount);

		// Add the snapshot to the history array
		history[historyCount++] = newSnapshot;

	}


	// Utility Methods
	void displayEvents() const 
	{
		if (eventCount == 0)
		{
			return;
		}

		for (int i = 0; i < eventCount; ++i)
		{
			events[i].display();
		}
	}

	void displayHistory() const 
	{
		if (historyCount == 0)
		{
			return;
		}

		for (int i = 0; i < historyCount; ++i)
		{
			cout << "Snapshot " << i << endl;

			Event* snapshotEvents = history[i].getEvents();

			if (snapshotEvents == NULL)
			{
				cout << "Error: Snapshot events are null." << endl;
				continue;
			}

			int snapshotEventCount = history[i].getNumEvents();

			for (int j = 0; j < snapshotEventCount; ++j)
			{
				//cout << "Checksheckds" << endl;
				snapshotEvents[j].display();
			}

		}
	}


	//It returns the index position where it found the Event, 0 otherwise
	//This is useful for removeEvent, queryEvent, and queryRange
	int binarySearch(const string& timestamp)
	{
		int left = 0, right = eventCount - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			if (events[mid].getTimestamp() == timestamp)
				return mid; // Found the event

			if (events[mid].getTimestamp() < timestamp)
				left = mid + 1; // Search in the right half
			else
				right = mid - 1; // Search in the left half
		}

		return -1; // Not found
	}

	int binarySearchForAdd(const string& timestamp)
	{
		int left = 0, right = eventCount;

		while (left < right)
		{
			int mid = left + (right - left) / 2;

			if (events[mid].getTimestamp() < timestamp)
				left = mid + 1; // Search in the right half
			else
				right = mid; // Potential position for insertion
		}

		return left; // Return the position where the event should be inserted
	}
};

int main()
{
	Scheduler scheduler; // Create an instance of the scheduler
	string command;

	while (getline(cin, command))
	{
		// Read an entire line of input
		if (command == "EXIT")
			break;

		// Parse the command and execute appropriate actions
		if (command.rfind("ADD", 0) == 0)
		{
			// Format: ADD <timestamp> <eventData>
			string timestamp = command.substr(4, 16);
			string eventData = command.substr(21); // Extract the event data
			if (!eventData.empty() && (eventData.back() == '\n' || eventData.back() == '\r')) {
				eventData.pop_back();
			}
			scheduler.addEvent(timestamp, eventData);
		}
		else if (command.rfind("REMOVE", 0) == 0)
		{
			// Format: REMOVE <timestamp>
			string timestamp = command.substr(7, 16);
			scheduler.removeEvent(timestamp);
		}
		else if (command.rfind("QUERY", 0) == 0 && command.find("QUERYRANGE") == string::npos)
		{
			// Format: QUERY <timestamp>
			string timestamp = command.substr(6, 16);
			Event* event = scheduler.queryEvent(timestamp);
			if (event)
			{
				event->display();
			}
			else
			{
				cout << "Event not found at timestamp " << timestamp << endl;
			}
		}
		else if (command.rfind("SNAPSHOT", 0) == 0)
		{
			// Manually create a snapshot
			scheduler.addSnapshot();
			cout << "Snapshot created." << endl;
		}
		else if (command.rfind("QUERYRANGE", 0) == 0)
		{
			// Format: QUERYRANGE <startTimestamp> <endTimestamp>
			size_t spacePos = command.find(' ', 11);
			size_t nextSpacePos = command.find(' ', spacePos + 1);

			string startTS = command.substr(11, nextSpacePos - 11);
			string endTS = command.substr(nextSpacePos + 1);
			int count = 0;
			Event* events = scheduler.queryRange(startTS, endTS, count);
			if (events)
			{
				for (int i = 0; i < count; ++i)
				{
					events[i].display();
				}
				delete[] events; // Free the dynamically allocated memory
			}
			else
			{
				cout << "No events found in the range " << startTS << " to " << endTS << endl;
			}
		}
		else if (command.rfind("DISPLAY", 0) == 0)
		{
			scheduler.displayEvents();
		}
		else if (command.rfind("SHOWSNAPSHOTS", 0) == 0)
		{
			// Display available snapshots
			scheduler.displayHistory();
		}
		else if (command.rfind("TIMETRAVEL", 0) == 0)
		{
			// Format: TIMETRAVEL <snapshotIndex>
			int snapshotIndex = stoi(command.substr(11));
			scheduler.timeTravel(snapshotIndex);
			cout << "Time traveled to snapshot " << snapshotIndex << "." << endl;
		}

	}

	cout << "Scheduler program exited." << endl;
	return 0;
}

