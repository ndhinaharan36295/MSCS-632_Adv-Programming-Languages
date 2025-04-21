#include "Ride.h"
#include <iostream>

using namespace std;

// Constructor to initialize a Ride class with ID, pickup location, dropoff location, and distance
Ride::Ride(string id, string pickup, string dropoff, double dist)
    : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist) {}

// Method to calculate the fare for a ride
// this method will be overriden in each of the derived classes
double Ride::fare() const {
    return distance * 1.0;
}

// Method to display the details of the ride
void Ride::rideDetails() const {
    cout << "Ride ID: " << rideID
        << ", Pickup: " << pickupLocation
        << ", Dropoff: " << dropoffLocation
        << ", Distance: " << distance
        << " miles, Fare: $" << fare() << "\n\n";
}

// Destructor for the Ride class
Ride::~Ride() {}
