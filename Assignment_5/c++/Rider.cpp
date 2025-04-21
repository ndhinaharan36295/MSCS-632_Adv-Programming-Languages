#include "Rider.h"
#include <iostream>

using namespace std;

// Constructor to initialize a Rider class with ID and name
Rider::Rider(string id, string name): riderID(id), name(name) {}

// Method to request a ride
// Adds the requested ride to the list of requested rides
void Rider::requestRide(shared_ptr<Ride> ride) {
    requestedRides.push_back(ride);
}

// Method to view the details of all requested rides
void Rider::viewRides() const {
    cout << "Rider ID: " << riderID
        << ", Name: " << name
        << "\n\nRequested Rides:\n";
    for (const auto& ride : requestedRides) {
        ride->rideDetails();
    }
}