#include <iostream>
#include <vector>
#include <memory>

#include "StandardRide.h"
#include "PremiumRide.h"
#include "Driver.h"
#include "Rider.h"

using namespace std;

int main() {
    shared_ptr<Ride> standardRide = make_shared<StandardRide>("Standard Ride 1", "Home", "Restaurant", 10.0);
    shared_ptr<Ride> premiumRide = make_shared<PremiumRide>("Premium Ride 1", "Restaurant", "Grocery Store", 5.0);

    Driver driver("Driver 1", "Mark", 4.5);
    driver.addRide(standardRide);
    driver.addRide(premiumRide);

    Rider rider("User 1", "Jack");
    rider.requestRide(standardRide);
    rider.requestRide(premiumRide);

    cout << "=== Driver Info ===\n";
    driver.getDriverInfo();

    cout << "\n=== Rider Info ===\n";
    rider.viewRides();

    cout << "\n=== Fare Calls ===\n";
    vector<shared_ptr<Ride>> allRides = {standardRide, premiumRide};
    for (const auto& ride : allRides) {
        ride->rideDetails();
    }

    return 0;
}
