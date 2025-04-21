#include "StandardRide.h"
#include <iostream>

using namespace std;

// Constructor to initialize a StandardRide class that extends the Ride class
StandardRide::StandardRide(string id, string pickup, string dropoff, double dist)
    : Ride(id, pickup, dropoff, dist) {}

// Method to calculate the fare for a premium ride (overriding the base method)
// Premium rides have a fare rate of 2.5 per unit distance
double StandardRide::fare() const {
    return distance * 2.5;
}

// Method to display the details of a premium ride
void StandardRide::rideDetails() const {
    cout << "[Standard Ride]\n";
    Ride::rideDetails();
}
