#include <iostream>
#include <vector>
#include <string>
using namespace std;

class vehicle
{
protected:
    int license_plate;
    string manufacturer;
    int carriage_limit;

public:
    vehicle(int l = 0, string m = "", int c = 0) 
        : license_plate(l), manufacturer(m), carriage_limit(c) {}
};

class gasoline : public vehicle
{
protected:
    int fuel_capacity;
    string fuel_type;

public:
    gasoline(int l = 0, string m = "", int c = 0, int fc = 0, string ft = "")
        : vehicle(l, m, c), fuel_capacity(fc), fuel_type(ft) {}
};

class electric : public vehicle
{
protected:
    int battery;
    int charging_time;

public:
    electric(int l = 0, string m = "", int c = 0, int b = 0, int ct = 0)
        : vehicle(l, m, c), battery(b), charging_time(ct) {}
};

class motorcycle : public gasoline
{
public:
    motorcycle(int l = 0, string m = "", int c = 0, int fc = 0, string ft = "")
        : gasoline(l, m, c, fc, ft) {}
};

class car : public gasoline
{
protected:
    int passenger_capacity;
    int max;
    int min;

public:
    car(int l = 0, string m = "", int c = 0, int fc = 0, string ft = "", int pc = 0)
        : gasoline(l, m, c, fc, ft), passenger_capacity(pc), max(0), min(0) {}

    void maintain()
    {
        cout << "Enter max passenger capacity: ";
        cin >> max;
        cout << "Enter min passenger capacity: ";
        cin >> min;
        if (passenger_capacity < min)
            passenger_capacity = min;
        else if (passenger_capacity > max)
            passenger_capacity = max;
    }
};

class truck : public gasoline
{
protected:
    int cargo_capacity;
    int max;
    int min;

public:
    truck(int l = 0, string m = "", int c = 0, int fc = 0, string ft = "", int cc = 0)
        : gasoline(l, m, c, fc, ft), cargo_capacity(cc), max(0), min(0) {}

    void maintain()
    {
        cout << "Enter max cargo capacity: ";
        cin >> max;
        cout << "Enter min cargo capacity: ";
        cin >> min;
        if (cargo_capacity < min)
            cargo_capacity = min;
        else if (cargo_capacity > max)
            cargo_capacity = max;
    }
};

class hybrid : public gasoline, public electric
{
protected:
    int energy_r_effi;

public:
    hybrid(int l = 0, string m = "", int c = 0, int fc = 0, string ft = "", int b = 0, int ct = 0, int ere = 0)
        : gasoline(l, m, c, fc, ft), electric(l, m, c, b, ct), energy_r_effi(ere) {}
};

class employee
{
protected:
    int id;
    string name;

public:
    employee(int i = 0, string n = "") : id(i), name(n) {}
};

class manager : public employee
{
public:
    manager(int i = 0, string n = "") : employee(i, n) {}

    void intro()
    {
        cout << "Mr. " << name << endl;
    }

    string getname()
    {
        return name;
    }
};

class driver : public employee
{
public:
    driver(int i = 0, string n = "") : employee(i, n) {}

    void intro()
    {
        cout << name << endl;
    }

    string getname()
    {
        return name;
    }
};

class branch
{
protected:
    vector<motorcycle> motorcycles;
    vector<car> cars;
    vector<truck> trucks;
    vector<electric> electrics;
    vector<hybrid> hybrids;
    vector<manager> managers;
    vector<driver> drivers;

public:
    branch()
    {
        motorcycles.resize(10);
        cars.resize(10);
        trucks.resize(10);
        electrics.resize(10);
        hybrids.resize(10);
        managers.resize(10);
        drivers.resize(30);

        for (int i = 0; i < 10; i++)
        {
            motorcycles[i] = motorcycle(1000 + i, "Yamaha", 200, 15, "petrol");
            cars[i] = car(2000 + i, "Honda", 500, 50, "petrol", 4);
            trucks[i] = truck(3000 + i, "Tata", 3000, 120, "diesel", 2000);
            electrics[i] = electric(4000 + i, "Tesla", 1000, 75, 60);
            hybrids[i] = hybrid(5000 + i, "Prius", 1000, 45, "Hybrid", 40, 120, 85);
        }

        for (int i = 0; i < 10; i++)
        {
            managers[i] = manager(i + 1, "Manager" + to_string(i + 1));
        }
        for (int i = 0; i < 30; i++)
        {
            drivers[i] = driver(i + 11, "Driver" + to_string(i + 11));
        }
    }

    void introduce()
    {
        for (int i = 0; i < 10; i++)
        {
            managers[i].intro();
        }
        for (int i = 0; i < 10; i++)
        {
            drivers[i].intro();
        }
    }

    void maintainence()
    {
        for (int i = 0; i < 10; i++)
        {
            cars[i].maintain();
        }
    }
};

int main()
{
    branch b;
    b.introduce();
    b.maintainence();
    return 0;
}
