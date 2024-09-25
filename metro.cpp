#include <iostream>
#include <list>
#include <string>
#include <array>
#include <stack>
#include <queue>
#include <utility>
#include <stdexcept>

#define STATION 53
#define INFINITE INT16_MAX

using namespace std;

class CompareByValue {
public:
    bool operator()(pair<int, int> &num1, pair<int, int> &num2) {
        return num1.second >= num2.second; // Compare by weight
    }
};

class Metro {
private:
    list<int> *start;                  // Adjacency list for stations
    int root[STATION];                 // Parent array for path reconstruction
    array<string, STATION> stationName = {
        "Gandhi Nagar", "Karond", "Berasia", "Budhwara", "Jahangirabad",
        "Mr.Road", "Kotra Sultanabad", "Nehru Nagar", "Syamla Hills", "Van Vihar", 
        "Jawahar Chowk", "Rangmahal", "Vidhan Sabha", "MP Nagar", "6 no Stop", 
        "Shivaji Nagar", "Char Imli", "Bittan Market", "Shahpura", "Gulmohar", 
        "Akriti Eco City", "Saliya", "Chandbad", "Ashoka Garden", "Govindpura", 
        "Minal", "Piplani", "Ayodhya Bypass", "Anand Nagar", "Awadhpuri", 
        "Barkheda Pathani", "Saket Nagar", "AIIMS", "Barkatullah University", 
        "Misrod", "Ratanpur", "Bairagarh", "Lalghati", "Tazul Masjid", 
        "Hamidia Hospital", "Kamla Park", "Polytechnic Square", "Roushanpura", 
        "New Market", "Mata Mandir", "MANIT Square", "Patrakar Colony", 
        "Chuna Bhatti", "Sarvdharm", "Bima Kunj", "Danish Kunj", 
        "Nayapura", "Bairagarh Chichli"};

protected:
    int weight(int u, int v);          // Weight function

public:
    Metro();                           // Constructor
    ~Metro();                          // Destructor
    void showStation();                // Display stations
    void SetStation();                 // Set up the metro stations
    string NameOfStation(int index);   // Get name of a station
    void TellMeRoute(int source, int destination); // Display route from source to destination
    array<int, STATION> AllPossibleDestination(int source); // Get all possible destinations from source
    int ToDestination(int source, int destination); // Get distance to a destination
    void ToAll(int source);            // Display distances to all stations
};

Metro::Metro() {
    start = new list<int>[STATION]; // Allocate memory for adjacency list
    fill(begin(root), end(root), -1); // Initialize root array
}

Metro::~Metro() {
    delete[] start; // Free memory
}

int Metro::weight(int u, int v) {
    return u == v ? 0 : 1; // Distance between connected stations is 1, otherwise 0
}

string Metro::NameOfStation(int index) {
    if (index < 0 || index >= STATION) {
        throw std::out_of_range("Station index is out of range.");
    }
    return stationName[index]; // Return the name of the station
}

void Metro::SetStation() {
    // Setup the connections (edges) between stations
    start[0].push_front(1);
    for (int i = 1; i <= 4; i++) {
        start[i].push_front(i - 1);
        start[i].push_front(i + 1);
    }
    start[5].push_front(4);
    start[5].push_front(42);
    start[6].push_front(42);
    start[6].push_front(7);
    start[7].push_front(6);
    start[7].push_front(8);
    start[8].push_front(7);
    start[9].push_front(10);
    start[10].push_front(9);
    start[10].push_front(11);
    start[11].push_front(10);
    start[11].push_front(43);
    start[12].push_front(43);
    start[12].push_front(13);
    start[13].push_front(12);
    start[13].push_front(23);
    start[13].push_front(24);
    start[13].push_front(14);
    for (int i = 14; i <= 20; i++) {
        start[i].push_front(i - 1);
        start[i].push_front(i + 1);
    }
    start[21].push_front(20);
    start[21].push_front(52);
    start[22].push_front(23);
    start[23].push_front(22);
    start[23].push_front(13);
    start[24].push_front(13);
    start[24].push_front(25);
    for (int i = 25; i <= 34; i++) {
        start[i].push_front(i - 1);
        start[i].push_front(i + 1);
    }
    start[35].push_front(34);
    start[36].push_front(37);
    for (int i = 37; i <= 41; i++) {
        start[i].push_front(i - 1);
        start[i].push_front(i + 1);
    }
    start[42].push_front(5);
    start[42].push_front(6);
    start[42].push_front(41);
    start[42].push_front(43);
    start[43].push_front(11);
    start[43].push_front(12);
    start[43].push_front(42);
    start[43].push_front(44);
    for (int i = 44; i <= 51; i++) {
        start[i].push_front(i - 1);
        start[i].push_front(i + 1);
    }
    start[52].push_front(51);
    start[52].push_front(21);
}

void Metro::showStation() {
    for (int i = 0; i < STATION; i++) {
        cout << i << " | " << stationName[i] << endl;
    }
    cout << "-------------------------" << endl;
}

array<int, STATION> Metro::AllPossibleDestination(int source) {
    // Dijkstra's Algorithm implementation
    bool vis[STATION] = {0};
    bool inHeap[STATION] = {0};
    array<int, STATION> arr;
    fill(arr.begin(), arr.end(), INFINITE);
    arr[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareByValue> temp;
    temp.push(make_pair(source, 0));
    inHeap[source] = true;

    while (!temp.empty()) {
        pair<int, int> t = temp.top();
        temp.pop();
        int u = t.first;
        vis[u] = true;
        
        for (int v : start[u]) { // Iterate through connected stations
            if (arr[u] + weight(u, v) < arr[v]) {
                arr[v] = arr[u] + weight(u, v);
                root[v] = u; // Update parent for path reconstruction
            }
            if (!vis[v] && !inHeap[v]) {
                temp.push(make_pair(v, arr[v]));
                inHeap[v] = true;
            }
        }
    }
    return arr;
}

int Metro::ToDestination(int source, int destination) {
    if (source < 0 || destination >= STATION) {
        throw std::out_of_range("Source or destination index is out of range.");
    }
    array<int, STATION> newArr = AllPossibleDestination(source);
    return newArr[destination]; // Return the minimum distance to destination
}

void Metro::ToAll(int source) {
    array<int, STATION> newArr = AllPossibleDestination(source);
    cout << "Minimum Number Of Stations From Source Station " << source << ":" << endl;
    for (int i = 0; i < STATION; i++) {
        cout << "To Destination Station " << i << " is " << newArr[i] << endl;
    }
}

void Metro::TellMeRoute(int source, int destination) {
    stack<int> s;
    array<int, STATION> flag = AllPossibleDestination(source);
    int x = destination;
    
    while (root[x] != -1) {
        s.push(x);
        x = root[x];
    }
    
    cout << "Route from Station " << source << " to Station " << destination << ": ";
    while (!s.empty()) {
        cout << stationName[s.top()] << " (" << s.top() << ") ";
        s.pop();
        if (!s.empty()) cout << "-->";
    }
    cout << endl;
}

int main() {
    Metro metro;                // Create a Metro object
    metro.SetStation();         // Initialize stations
    metro.showStation();        // Display available stations

    int source, destination;
    
    cout << "Enter source station number (0 to " << STATION - 1 << "): ";
    cin >> source;
    
    cout << "Enter destination station number (0 to " << STATION - 1 << "): ";
    cin >> destination;

    try {
        metro.TellMeRoute(source, destination); // Show route
        cout << "Distance: " << metro.ToDestination(source, destination) << endl; // Display distance
        metro.ToAll(source); // Display distances from source
    } catch (const std::out_of_range& e) {
        cerr << e.what() << endl; // Handle invalid index input
    }

    return 0; // Exit program successfully
}
