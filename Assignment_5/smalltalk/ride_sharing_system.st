"Ride Class"
Object subclass: Ride [
    | rideID pickupLocation dropoffLocation distance |

    "Class method to create a new Ride instance with specified attributes"
    Ride class >> newWithID: id pickup: pickup dropoff: dropoff distance: dist [
        ^ self new initializeWithID: id pickup: pickup dropoff: dropoff distance: dist.
    ]

    "Initialize the Ride instance with ID, pickup location, dropoff location, and distance"
    initializeWithID: id pickup: pickup dropoff: dropoff distance: dist [
        rideID := id.
        pickupLocation := pickup.
        dropoffLocation := dropoff.
        distance := dist.
    ]

    "Calculate the fare for the ride (method will be override in derived classes)"
    fare [
        ^ distance * 2.0.
    ]

    "Display the details of the ride, including ID, locations, distance, and fare"
    rideDetails [
        ('Ride ID: ', rideID) display.
        (', Pickup: ', pickupLocation) display.
        (', Dropoff: ', dropoffLocation) display.
        (', Distance: ', distance printString, ' miles') display.
        (', Fare: $', (self fare) printString) displayNl.
    ]
]

"StandardRide Class"
Ride subclass: StandardRide [
    "Override fare calculation for standard rides (rate is 2.5 per unit distance)"
    fare [
        ^ distance * 2.5.
    ]

    "Display details specific to standard rides"
    rideDetails [
        '[Standard Ride]' displayNl.
        super rideDetails.
    ]
]

"PremiumRide Class"
Ride subclass: PremiumRide [
    "Override fare calculation for premium rides (rate is 3.0 per unit distance)"
    fare [
        ^ distance * 3.0.
    ]

    "Display details specific to premium rides"
    rideDetails [
        '[Premium Ride]' displayNl.
        super rideDetails.
    ]
]

"Driver Class"
Object subclass: Driver [
    | driverID name rating assignedRides |

    "Initialize the Driver instance with ID, name, rating, and an empty list of assigned rides"
    initializeWithID: id name: driverName rating: rate [
        driverID := id.
        name := driverName.
        rating := rate.
        assignedRides := OrderedCollection new.
    ]

    "Add a ride to the driver's list of assigned rides"
    addRide: ride [
        assignedRides add: ride.
    ]

    "Display driver information and details of all completed rides"
    getDriverInfo [
        ('Driver ID: ', driverID) display.
        (', Name: ', name) display.
        (', Rating: ', rating printString) displayNl.
        Transcript cr.
        'Rides Completed:' displayNl.
        Transcript cr.
        assignedRides do: [:r | r rideDetails].
    ]
]

"Rider Class"
Object subclass: Rider [
    | riderID name requestedRides |

    "Initialize the Rider instance with ID, name, and an empty list of requested rides"
    initializeWithID: id name: riderName [
        riderID := id.
        name := riderName.
        requestedRides := OrderedCollection new.
    ]

    "Add a ride to the rider's list of requested rides"
    requestRide: ride [
        requestedRides add: ride.
    ]

    "Display rider information and details of all requested rides"
    viewRides [
        ('Rider ID: ', riderID) display.
        (', Name: ', name) displayNl.
        Transcript cr.
        'Requested Rides:' displayNl.
        Transcript cr.
        requestedRides do: [:r | r rideDetails].
    ]
]

"Main Script"
| ride1 ride2 driver rider allRides |

"Create instances of StandardRide and PremiumRide with specific attributes"
ride1 := StandardRide newWithID: 'Standard Ride 1' pickup: 'Home' dropoff: 'Restaurant' distance: 10.
ride2 := PremiumRide newWithID: 'Premium Ride 1' pickup: 'Restaurant' dropoff: 'Grocery Store' distance: 5.

"Create a Driver instance and assign rides to the driver"
driver := Driver new.
driver initializeWithID: 'Driver 1' name: 'Mark' rating: 4.5.
driver addRide: ride1.
driver addRide: ride2.

"Create a Rider instance and request rides"
rider := Rider new.
rider initializeWithID: 'User 1' name: 'Jack'.
rider requestRide: ride1.
rider requestRide: ride2.

"Display driver information"
'=== Driver Info ===' displayNl.
driver getDriverInfo.

Transcript cr.

"Display rider information"
'=== Rider Info ===' displayNl.
rider viewRides.

Transcript cr.

"Display details of all rides and their fares"
'=== Fare Calls ===' displayNl.
allRides := OrderedCollection with: ride1 with: ride2.
allRides do: [:r | r rideDetails].
