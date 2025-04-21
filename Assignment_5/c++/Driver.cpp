#include "Driver.h"
#include <iostream>

using namespace std;

// Constructor to initialize driver details
Driver::Driver(string id, string name, double rating): driverID(id), name(name), rating(rating) {}

// Method to add a ride to the driver's list of assigned rides
void Driver::addRide(shared_ptr<Ride> ride) {
    assignedRides.push_back(ride);
}

// Method to display driver information and details of completed rides
void Driver::getDriverInfo() const {
    cout << "Driver ID: " << driverID
        << ", Name: " << name
        << ", Rating: " << rating
        << "\n\nRides Completed:\n";

    // Iterate through the list of assigned rides and display their details
    for (const auto& ride : assignedRides) {
        ride->rideDetails();
    }
}