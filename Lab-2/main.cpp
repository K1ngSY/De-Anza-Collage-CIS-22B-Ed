#include <iostream>
#include <string>

using namespace std;

class Cargo
{
private:
    string uld;
    string abrv;
    string id;
    int air;
    int wt;
    string dest;

public:
    ///Default constructor prototype
    Cargo();

    ///Full constructor prototype
    Cargo(const string uld, const string abrv, const string id, const int air, const int wt, const string dest);

    ///Destructor prototype
    ~Cargo();

    ///Mutator (setter) prototypes
    void setuldtype(string);
    void setabbrev(string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(double);
    void setdestination(string);

    ///Accessor (getter) prototypes
    string getuldtype() const;
    string getabbrev() const;
    string getuldid() const;
    int getaircraft() const;
    double getweight() const;
    string getdestination() const;

    void input(Cargo &);
    void output(Cargo &) const;
};

Cargo::Cargo()
    : uld("Unknown"), abrv("Unknown"), id("Unknown"), air(0), wt(0), dest("Unknown") {
    cout << "Cargo object created. --from default constructor" << endl;
}

Cargo::Cargo(const string uld, const string abrv, const string id, const int air, const int wt, const string dest)
    : uld(uld), abrv(abrv), id(id), air(air), wt(wt), dest(dest) {
    cout << "Cargo object created. --from constructor" << endl;

}

Cargo::~Cargo() {
    cout << "Cargo object destroyed. --from destructor" << endl;
}

void Cargo::setuldtype(string newUld) {
    uld = newUld;
}

void Cargo::setabbrev(string newAbrv) {
    abrv = newAbrv;
}

void Cargo::setuldid(string newId) {
    id = newId;
}

void Cargo::setaircraft(int newAir) {
    air = newAir;
}

void Cargo::setweight(double newWt) {
    wt = newWt;
}

void Cargo::setdestination(string newDest) {
    dest = newDest;
}

string Cargo::getuldtype() const {
    return uld;
}

string Cargo::getabbrev() const {
    return abrv;
}

string Cargo::getuldid() const {
    return id;
}

int Cargo::getaircraft() const {
    return air;
}

double Cargo::getweight() const {
    return wt;
}

string Cargo::getdestination() const {
    return dest;
}

void Cargo::input(Cargo &inputCargo) {
    string tempStr;
    int tempInt;

    cout << "Enter Unit Load Type: ";
    cin >> tempStr;
    inputCargo.setuldtype(tempStr);

    cout << "Enter Unit Load Abbreviation: ";
    cin >> tempStr;
    inputCargo.setabbrev(tempStr);

    cout << "Enter Unit Identifier: ";
    cin >> tempStr;
    inputCargo.setuldid(tempStr);

    cout << "Enter Aircraft Type: ";
    cin >> tempInt;
    inputCargo.setaircraft(tempInt);

    cout << "Enter Weight: ";
    cin >> tempInt;
    inputCargo.setweight(tempInt);

    cout << "Enter Destination Code: ";
    cin >> tempStr;
    inputCargo.setdestination(tempStr);
}


void Cargo::output(Cargo &inputCargo) const {
    cout << "Unit Load Type:         " << inputCargo.getuldtype() << endl;
    cout << "Unit Load Abbreviation: " << inputCargo.getabbrev() << endl;
    cout << "Unit Identifier:        " << inputCargo.getuldid() << endl;
    cout << "Aircraft Type:          " << inputCargo.getaircraft() << endl;
    cout << "Unit Weight:            " << inputCargo.getweight() << " pounds" << endl;
    cout << "Destination Code:       " << inputCargo.getdestination() << endl;
}


int main() {
    Cargo* defaultCargo = new Cargo();
    cout << "Default Cargo Object:" << endl;
    defaultCargo->output(*defaultCargo);
    delete defaultCargo;

    Cargo* userCargo = new Cargo();
    userCargo->input(*userCargo);
    userCargo->output(*userCargo);
    delete userCargo;

    return 0;
}
