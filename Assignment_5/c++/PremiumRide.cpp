#include "PremiumRide.h"
#include <iostream>

using namespace std;

// Constructor to initialize a PremiumRide class that extends the Ride class
PremiumRide::PremiumRide(string id, string pickup, string dropoff, double dist)
    : Ride(id, pickup, dropoff, dist) {}

// Method to calculate the fare for a premium ride (overriding the base method)
// Premium rides have a fare rate of 3.0 per unit distance
double PremiumRide::fare() const {
    return distance * 3.0;
}

// Method to display the details of a premium ride
void PremiumRide::rideDetails() const {
    cout << "[Premium Ride]\n";
    Ride::rideDetails();
}
