#include <iostream>
using namespace std;

const double PI = 3.14;
const double CM_TO_KM = 100000.0;

class TwoWheelerVehicle {
private:
    string manufacturer_name;
    string serial_number;

public:
    TwoWheelerVehicle(string manufacturer, string serial) 
        : manufacturer_name(manufacturer), serial_number(serial) {}

virtual ~TwoWheelerVehicle() {}

    void Info() const {
        cout << "Manufacturer: " << manufacturer_name << endl;
        cout << "Serial Number: " << serial_number << endl;
    }
   virtual void display_alert() const {}
};

class ElectricCycle : public TwoWheelerVehicle {
private:
    double tire_radius_cm;
    int wheel_revolutions;
    double max_distance_per_charge = 100.0;

public:
    ElectricCycle(string manufacturer, string serial, double radius, int revolutions) 
        : TwoWheelerVehicle(manufacturer, serial), tire_radius_cm(radius), wheel_revolutions(revolutions) {}

~ElectricCycle() {}

    double calculateDistanceTraveled() const {
        double circumference_km = (2 * PI * tire_radius_cm) / CM_TO_KM;
      double DistanceTraveled = circumference_km * wheel_revolutions;
        return DistanceTraveled;
    }

    void Info() const {
        TwoWheelerVehicle::Info();
        cout << "Tire Radius: " << tire_radius_cm << " cm" << endl;
        cout << "Wheel Revolutions: " << wheel_revolutions << endl;
        cout << "Distance Traveled: " << calculateDistanceTraveled() << " km" << endl;
        
        double distance_traveled = calculateDistanceTraveled();
        if (distance_traveled > 85) {
            cout << "BATTERY LOW!" << endl;
        } else {
            cout << "BATTERY OK!" << endl;
        }
    }
       virtual void display_alert() const {}
};

int main() {

    ElectricCycle vehicles[6] = {
        ElectricCycle("KTM", "K001", 35.0, 5000),
        ElectricCycle("BMW", "B001", 30.0, 4000),
        ElectricCycle("Byrd", "BR001", 33.0, 4500),
        ElectricCycle("Kawasaki", "KW001", 32.0, 3000),
        ElectricCycle("Tesla", "T001", 36.0, 2000),
        ElectricCycle("Hyundai", "H001", 34.0, 6000)
    };

    for (int i = 0; i < 6; ++i) {
        cout << "Vehicle " << i + 1 << ":" << endl;
        vehicles[i].Info();
        cout << "--------------------------" << endl;
    }

    return 0;
}
