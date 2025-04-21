#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>
#include <memory>
#include "Ride.h"

using namespace std;

class Driver {
    private:
        string driverID;                            // Unique identifier for the driver
        string name;                                // Name of the driver
        double rating;                              // Driver's rating
        vector<shared_ptr<Ride>> assignedRides;     // List of rides assigned to the driver

    public:
        Driver(string id, string name, double rating);
        void addRide(shared_ptr<Ride> ride);
        void getDriverInfo() const;
};

#endif
