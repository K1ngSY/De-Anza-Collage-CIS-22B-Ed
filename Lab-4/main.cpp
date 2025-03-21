#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Cargo {
private:
    string uld;
    string abrv;
    string id;
    int air;
    double wt;
    string dest;

public:
    Cargo()
        : uld("Unknown"), abrv("Unknown"), id("Unknown"), air(0), wt(0), dest("Unknown") {
        cout << "\nCargo object created --from default constructor" << endl;
    }

    Cargo(const string uld, const string abrv, const string id, const int air, const double wt, const string dest)
        : uld(uld), abrv(abrv), id(id), air(air), wt(wt), dest(dest) {
        cout << "\nCargo object created --from fully loaded constructor" << endl;
    }

    Cargo(const Cargo &other)
        : uld(other.uld), abrv(other.abrv), id(other.id), air(other.air), wt(other.wt), dest(other.dest) {
        cout << "\nCargo object created --from copy constructor" << endl;
    }

    ~Cargo() {
        cout << "\nCargo object destroyed --from destructor" << endl;
    }

    void setUldType(string uld) { this->uld = uld; }
    void setAbbrev(string abrv) { this->abrv = abrv; }
    void setId(string id) { this->id = this->abrv + id + "IB"; }
    void setAircraft(int air) { this->air = air; }
    void setWeight(double wt) { this->wt = wt; }
    void setDestination(string dest) { this->dest = dest; }

    string getuldtype() const { return uld; }
    string getabbrev() const { return abrv; }
    string getuldid() const { return id; }
    int getaircraft() const { return air; }
    double getweight() const { return wt; }
    string getdestination() const { return dest; }

    bool operator==(const Cargo &other) const {
        return (this->abrv == other.abrv && this->id == other.id);
    }
};

void output(const Cargo &outputObj) {
    cout << outputObj.getuldtype() << " " << outputObj.getabbrev() << " " << outputObj.getuldid() << " " << outputObj.getaircraft() << " " << outputObj.getweight() << " " << outputObj.getdestination() << endl;
    cout << setw(24) << "Unit Load Type: ";
    cout << outputObj.getuldtype() << endl;
    cout << setw(24) << "Unit Load Abbreviation: ";
    cout << outputObj.getabbrev() << endl;
    cout << setw(24) << "Unit Identifier: ";
    cout << outputObj.getuldid() << endl;
    cout << setw(24) << "Aircraft Type: ";
    cout << outputObj.getaircraft() << endl;
    cout << setw(24) << "Unit Weight: ";
    cout << outputObj.getweight() << " pounds" << endl;
    cout << setw(24) << "Destination Code: ";
    cout << outputObj.getdestination() << endl;
}


void input() {
    ifstream inputFile;
    inputFile.clear();
    try {
        inputFile.open("cardataX.txt");
        if (!inputFile.is_open()) {
            throw runtime_error("Error opening the \"cardataX.txt\" or \"cardataX.txt\" not found");
        }
    }
    catch (runtime_error &myErr) {
        cout << myErr.what();
        exit(1);
    }
    cout << "Input file cardataX.txt is open." << endl;

    string cargostring;
    while(getline(inputFile, cargostring))   ///read in one line of data, six or seven pieces
    {
        string abrv;
        string id;
        int air;
        double wt;
        string dest;
        string type1;
        string type2;
        istringstream cargoISS(cargostring); ///place line in the input string stream

        cargoISS >> type1;
        if ((type1.compare("Combo")) == 0)///looking for Combo              
            {
                cargoISS >> type2 >> abrv >> id >> air >> wt >> dest;///seven pieces of data
                type1 = type1 + " " + type2;///valid Combo Flat, maybe
            }
            else
            {
               cargoISS >> abrv >> id >> air >> wt >> dest;///six pieces of data
            }
        Cargo temp(type1, abrv, id, air, wt, dest);
        output(temp);
        cout << endl;  
    }
    inputFile.close();
    cout << "\nInput file cardataX.txt is close." << endl;
}

int main() {
    input();
    return 0;
}
