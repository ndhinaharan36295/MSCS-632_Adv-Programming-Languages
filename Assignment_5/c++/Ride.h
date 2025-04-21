#ifndef RIDE_H
#define RIDE_H

#include <string>

using namespace std;

class Ride {
    protected:
        string rideID;              // Unique identifier for the ride
        string pickupLocation;      // Pickup location for the ride
        string dropoffLocation;     // Dropoff location for the ride
        double distance;            // Distance of the ride

    public:
        Ride(string id, string pickup, string dropoff, double dist);
        virtual double fare() const;
        virtual void rideDetails() const;
        virtual ~Ride();
};

#endif
