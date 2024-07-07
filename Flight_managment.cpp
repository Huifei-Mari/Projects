#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Flight {
    int flightNumber;
    string destination;
    string departureTime;
    string arrivalTime;
};

vector<Flight> flights;

void addFlight() {
    Flight flight;
    cout << "Enter flight number: ";
    cin >> flight.flightNumber;
    cout << "Enter destination: ";
    cin >> flight.destination;
    cout << "Enter departure time: ";
    cin >> flight.departureTime;
    cout << "Enter arrival time: ";
    cin >> flight.arrivalTime;
    flights.push_back(flight);
    cout << "Flight added successfully!" << endl;
}

void displayFlights() {
    if (flights.empty()) {
        cout << "No flights available." << endl;
        return;
    }
    for (const auto& flight : flights) {
        cout << "Flight Number: " << flight.flightNumber << endl;
        cout << "Destination: " << flight.destination << endl;
        cout << "Departure Time: " << flight.departureTime << endl;
        cout << "Arrival Time: " << flight.arrivalTime << endl;
        cout << "-----------------------------" << endl;
    }
}

void deleteFlight() {
    int flightNumber;
    cout << "Enter flight number to delete: ";
    cin >> flightNumber;
    auto it = remove_if(flights.begin(), flights.end(), [&](Flight& flight) {
        return flight.flightNumber == flightNumber;
        });
    if (it != flights.end()) {
        flights.erase(it, flights.end());
        cout << "Flight deleted successfully!" << endl;
    }
    else {
        cout << "Flight not found." << endl;
    }
}

void displayMenu() {
    cout << "Flight Management System" << endl;
    cout << "1. Add Flight" << endl;
    cout << "2. Display Flights" << endl;
    cout << "3. Delete Flight" << endl;
    cout << "4. Add Predefined Destinations" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void addPredefinedDestinations() {
    flights.push_back({ 1001, "New York", "08:00 AM", "12:00 PM" });
    flights.push_back({ 1002, "Los Angeles", "09:00 AM", "01:00 PM" });
    flights.push_back({ 1003, "Chicago", "10:00 AM", "02:00 PM" });
    flights.push_back({ 1004, "Houston", "11:00 AM", "03:00 PM" });
    flights.push_back({ 1005, "Miami", "12:00 PM", "04:00 PM" });
    cout << "Predefined destinations added successfully!" << endl;
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            addFlight();
            break;
        case 2:
            displayFlights();
            break;
        case 3:
            deleteFlight();
            break;
        case 4:
            addPredefinedDestinations();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
