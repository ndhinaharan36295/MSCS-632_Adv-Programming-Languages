#ifndef PREMIUM_RIDE_H
#define PREMIUM_RIDE_H

#include "Ride.h"

using namespace std;

class PremiumRide : public Ride {
    public:
        PremiumRide(string id, string pickup, string dropoff, double dist);
        double fare() const override;
        void rideDetails() const override;
};

#endif
