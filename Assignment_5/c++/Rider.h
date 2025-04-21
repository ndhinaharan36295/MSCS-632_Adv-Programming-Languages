#ifndef RIDER_H
#define RIDER_H

#include <string>
#include <vector>
#include <memory>
#include "Ride.h"

using namespace std;

class Rider {
    private:
        string riderID;                             // Unique identifier for the rider
        string name;                                // Name of the rider
        vector<shared_ptr<Ride>> requestedRides;    // List of rides requested by the rider

    public:
        Rider(string id, string name);
        void requestRide(shared_ptr<Ride> ride);
        void viewRides() const;
};

#endif
