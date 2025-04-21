#ifndef STANDARD_RIDE_H
#define STANDARD_RIDE_H

#include "Ride.h"

using namespace std;

class StandardRide : public Ride {
    public:
        StandardRide(string id, string pickup, string dropoff, double dist);
        double fare() const override;
        void rideDetails() const override;
};

#endif
