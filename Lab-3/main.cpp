#include <iostream>
#include <string>

using namespace std;

double kiloToPound(double kg);

class Cargo {
private:
    string uld;
    string abrv;
    string id;
    int air;
    double wt;
    string dest;

public:
    // Default constructor
    Cargo()
        : uld("Unknown"), abrv("Unknown"), id("Unknown"), air(0), wt(0), dest("Unknown") {
        cout << "Cargo object created --from default constructor" << endl;
    }

    // Parameterized constructor
    Cargo(const string uld, const string abrv, const string id, const int air, const double wt, const string dest)
        : uld(uld), abrv(abrv), id(abrv + id + "IB"), air(air), wt(wt), dest(dest) {
        bool isKg = false;
        string unit = "none";
        while (!(unit == "kg" || unit == "p")) {
        cout << "Enter Unit of Weight (kg|p): ";
        cin >> unit;
        cin.ignore();
        if (!(unit == "kg" || unit == "p"))
            cout << "Invalid unit! Please enter \"kg\" or \"p\"!" << endl;
        }
        if (unit == "kg") isKg = true;
        else isKg = false;
        if (isKg) this->wt = kiloToPound(wt);
        else this->wt = wt;
        cout << "\nCargo object created --from parameterized constructor" << endl;
    }

    // Copy Constructor
    Cargo(const Cargo &other)
        : uld(other.uld), abrv(other.abrv), id(other.id), air(other.air), wt(other.wt), dest(other.dest) {
        cout << "\nCargo object created --from copy constructor" << endl;
    }

    // Destructor
    ~Cargo() {
        cout << "\nCargo object destroyed --from destructor" << endl;
    }

    // Mutator (Setter) Functions
    void setUldType(string uld) {this->uld = uld;}
    void setAbbrev(string abrv) {this->abrv = abrv;}
    void setId(string id) {this->id = this->abrv + id + "IB";}
    void setAircraft(int air) {this->air = air;}
    void setWeight(double wt) {
        string tempStr = "none";
        bool isKg;
        while (!(tempStr == "kg" || tempStr == "p")) {
        cout << "Enter Unit of Weight (kg|p): ";
        cin >> tempStr;
        cin.ignore();
        if (!(tempStr == "kg" || tempStr == "p"))
            cout << "Invalid unit! Please enter \"kg\" or \"p\"!" << endl;
        }
        if (tempStr == "kg") isKg = true;
        else isKg = false;
        if (isKg) this->wt = kiloToPound(wt);
        else this->wt = wt;
    }
    void setDestination(string dest) {this->dest = dest;}

    // Accessor (Getter) Functions
    string getuldtype() const {return uld;}
    string getabbrev() const {return abrv;}
    string getuldid() const {return id;}
    int getaircraft() const {return air;}
    double getweight() const {return wt;}
    string getdestination() const {return dest;}

    // Friend Function
    friend double kiloToPound(double obj);

    // Overloaded Operators
    bool operator==(const Cargo &other) const;
};

double kiloToPound(double kg) {
    return kg * 2.2;
}

bool Cargo::operator==(const Cargo &other) const{
    if (this->abrv == other.abrv && this->id == other.id)
        return true;
    else 
        return false;
}

void input(Cargo &inputCargo) {
    string tempStr;
    int tempInt;

    cout << "Enter Unit Load Type: ";
    getline(cin, tempStr);
    inputCargo.setUldType(tempStr);

    cout << "Enter Unit Load Abbreviation: ";
    cin >> tempStr;
    cin.ignore();
    inputCargo.setAbbrev(tempStr);

    cout << "Enter Unit Identifier (five-digit code only): ";
    cin >> tempStr;
    cin.ignore();
    inputCargo.setId(tempStr);

    cout << "Enter Aircraft Type: ";
    cin >> tempInt;
    cin.ignore();
    inputCargo.setAircraft(tempInt);

    cout << "Enter Weight: ";
    cin >> tempInt;
    cin.ignore();
    inputCargo.setWeight(tempInt);

    cout << "Enter Destination Code: ";
    cin >> tempStr;
    cin.ignore();
    inputCargo.setDestination(tempStr);
}

void output(const Cargo &outputObj) {
    cout << "Unit Load Type:         " << outputObj.getuldtype() << endl;
    cout << "Unit Load Abbreviation: " << outputObj.getabbrev() << endl;
    cout << "Unit Identifier:        " << outputObj.getuldid() << endl;
    cout << "Aircraft Type:          " << outputObj.getaircraft() << endl;
    cout << "Unit Weight:            " << outputObj.getweight() << " pounds" << endl;
    cout << "Destination Code:       " << outputObj.getdestination() << endl;
}

int main() {
    Cargo unit1("Container", "AYK", "68943", 737, 1654, "PDX");
    cout << "Unit1 output:" << endl;
    output(unit1);

    Cargo unit2(unit1);
    cout << "\nUnit1 output:" << endl;
    output(unit1);
    cout << "\nUnit2 output:" << endl;
    output(unit2);

    Cargo unit3;
    if (unit1 == unit2)
        cout << "\nunit1 is the same as unit2\n";
    else
        cout << "\nunit1 is not the same as unit2\n";

    if (unit2 == unit3)
        cout << "\nunit2 is the same as unit3\n";
    else
        cout << "\nunit2 is not the same as unit3\n";
    return 0;
}