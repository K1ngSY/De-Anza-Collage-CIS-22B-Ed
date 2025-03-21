///lab 5 Full Solution (with exception handling forward list and vectors examples)
///complete as of 8/1/2024
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <forward_list>
#include <vector>
#include <sstream>
#include <algorithm> 

using namespace std;
const int MAXLOAD737 = 46000;
const int MAXLOAD767 = 116000;

class Cargo   ///now an abstract due to pure virtual function
{
protected:
    string uldtype;
    string abbrev;
    string uldid;
    int aircraft;
    double weight;
    string destination;

public:
    ///Default constructor prototype
    Cargo();

    ///Full constructor prototype
    Cargo(const string &uldtype,
          const string &abbrev,
          const string &uldid,
          const int &aircraft,
          const double &weight,
          const string &destination);

    ///Copy constructor prototype
    Cargo(const Cargo &unit);

    ///Destructor prototype
    ~Cargo();

    ///Mutator (setters) prototypes
    void setuldtype(string);
    void setabbrev(string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(double);
    void setdestination(string);

    ///Accessor (getters) prototypes
    string getuldtype() const;
    string getabbrev() const;
    string getuldid() const;
    int getaircraft() const;
    double getweight() const;
    string getdestination() const;

    virtual void maxweight(double&, double, string) = 0;  ///to be overridden

}; ///end of Cargo class

class Boeing737 : public Cargo  ///derived from Cargo
{
using Cargo::Cargo;///allows inheritance of constructors, destructor

private:
    int total737wt;
public:
    void maxweight(double&, double, string)override; ///overridden from Cargo class
};

class Boeing767 : public Cargo   ///derived from Cargo
{
using Cargo::Cargo;

private:
    int total767wt;
public:
    void maxweight(double&, double, string)override;
};
void output(Cargo&);
void input();
void checkPlane(int);
void checkType(string, string);
void checkAbrv(string, string, int);

int main()
{
    input();
    return 0;
}

Cargo::Cargo()
{
    uldtype = "XXX";
    abbrev = " ";
    uldid = "xxxxxIB";
    aircraft = 700;
    weight = 0.0;
    destination = "NONE";
}

Cargo::Cargo(const string &uld,
            const string &abrv,
            const string &id,
            const int &craft,
            const double &wt,
            const string &dest)
{
    uldtype = uld;
    abbrev = abrv;
    uldid = id;
    aircraft = craft;
    weight = wt;
    destination = dest;
}

Cargo::Cargo(const Cargo &unit1)
{
    uldtype=unit1.uldtype;
    abbrev=unit1.abbrev;
    uldid=unit1.uldid;
    aircraft=unit1.aircraft;
    weight=unit1.weight;
    destination=unit1.destination;
}

Cargo::~Cargo()
{
    // cout << "Cargo destructor called\n" << endl;
}

void Cargo::setuldtype(string type)
{
    uldtype = type;
}

void Cargo::setabbrev(string abrv)
{
    abbrev = abrv;
}

void Cargo::setuldid(string id)
{
    uldid = id;
}

void Cargo::setaircraft(int air)
{
    aircraft = air;
}

void Cargo::setweight(double wt)
{
    weight = wt;
}

void Cargo::setdestination(string dest)
{
    destination = dest;
}

string Cargo::getuldtype() const
{
    return uldtype;
}

string Cargo::getabbrev() const
{
    return abbrev;
}

string Cargo::getuldid() const
{
    return uldid;
}

int Cargo::getaircraft() const
{
    return aircraft;
}

double Cargo::getweight() const
{
    return weight;
}

string Cargo::getdestination() const
{
    return destination;
}

void load737(forward_list<Boeing737> &mylist737,
                const string type,
                const string abrv,
                const string id,
                const int craft,
                const double wt,
                const string dest,
                double &totwt737)  ///added for use by maxweight, note not const so can be changed
{
    Boeing737 uld737 (type, abrv, id, craft, wt, dest);
    try{
        uld737.maxweight(totwt737, uld737.getweight(), uld737.getuldid());
        mylist737.push_front(uld737);
    }
    catch(runtime_error &except){
        cout << except.what() << endl;
    }
/*
build a Boeing737 object, use constructor from Cargo class
check on maxweight, if too heavy let maxweight throw error
if you get this far object is ok, push it onto linked list
*/
}

void load767(forward_list<Boeing767> &mylist767,
                const string type,
                const string abrv,
                const string id,
                const int craft,
                const double wt,
                const string dest,
                double &totwt767)
{
    Boeing767 uld767 (type, abrv, id, craft, wt, dest);
    try{
        uld767.maxweight(totwt767, uld767.getweight(), uld767.getuldid());
        mylist767.push_front(uld767);
    }
    catch(runtime_error &except){
        cout << except.what() << endl;
    }
//same as Boeing737 except for Boeing767
}

void Boeing737::maxweight(double &totwt737, double wt, string id){
    if (totwt737 > MAXLOAD737){
        totwt737 -= wt; ///remove wt if overweight
        int overload = wt;
        throw runtime_error("Error: " + id + "'s " + (to_string(overload)) + " pounds is too heavy for 737, rejected load!");
    }
}
void Boeing767::maxweight(double &totwt767, double wt, string id){
    if (totwt767 > MAXLOAD767){
        totwt767 -= wt; ///remove if overweight
        int overload = wt;
        throw runtime_error("Error: " + id + "'s " + (to_string(overload)) + " pounds is too heavy for 767, rejected load!");
    }
}

void output(Cargo& unit)
{
    cout << fixed << showpoint << setprecision(2);
    cout << "***********************************************************\n";
    cout << setw(19) << "Unit load type: " << unit.getuldtype() << endl;
    cout << setw(19) << "Unit abbreviation: " << unit.getabbrev() << endl;
    cout << setw(19) << "Unit identifier: " << unit.getuldid() << endl;
    cout << setw(19) << "Aircraft type: " << unit.getaircraft() << endl;
    cout << setw(19) << "Unit weight: " << unit.getweight() << " pounds" << endl;
    cout << setw(19) << "Destination code: " << unit.getdestination() << endl;
    cout << "***********************************************************\n";
}

void input()
{
    string cargostring;
    string type1;
    string type2;
    string abrv;
    string uld;
    int plane;
    double weight;
    string dest;
    string datafile;
    ifstream inputFile;
    double totwt737 = 0;
    double totwt767 = 0;
    int i = 0;
    forward_list<Boeing737> mylist737;
    forward_list<Boeing767> mylist767;
///******************************************************************
    do{
    try{
        inputFile.clear();
        cout << "\nWhat\"s the name of your data file:\n";
        getline(cin,datafile);
        cout << "datafile is " << datafile << endl;
        inputFile.open(datafile);
        if (!inputFile)
            throw runtime_error("Bad filename\n\n");
        cout << datafile + " open\n\n";
        }
    catch(runtime_error &excpt){
        cout << datafile << " " << excpt.what();
    }
    }
    while(!inputFile);
///************************************************************************
    while(getline(inputFile, cargostring))   ///read in one line of data
    {

        istringstream cargoISS(cargostring); ///place line in the input string stream
        cargoISS >> type1;

        if (type1 == "Combo")///looking for Combo             ///is there a better
            {
                cargoISS >> type2 >> abrv >> uld >> plane >> weight >> dest;///way to do this

                type1 = type1 + " " + type2;///valid Combo Flat, maybe
            }
            else
            {
                cargoISS >> abrv >> uld >> plane >> weight >> dest;///finish reading last of data
            }

        try{
        checkType(uld, type1);///check for Container, Pallet or Combo Flat
        checkPlane(plane);///737 or 767
        checkAbrv(uld, abrv, plane);

        if (plane == 737){
            totwt737 += weight;
            load737(mylist737,type1,abrv,uld,plane,weight,dest,totwt737);
        }

        if (plane == 767){
            totwt767 += weight;
            load767(mylist767,type1,abrv,uld,plane,weight,dest,totwt767);
        }
        }

        catch(runtime_error &excpt){
            cout << excpt.what() << endl;
        }
    }

    inputFile.close(); ///you opened it, you close it

    for (Boeing737& out737 : mylist737)
    {
        cout << "737 Linked List Unit# " << ++i << endl;
        output(out737);
    }
    i = 0;
    for (auto out767 : mylist767)
    {
        cout << "767 Linked List Unit# " << ++i << endl;
        output(out767);
    }
    cout << "total weight for 737 load is " << totwt737 << endl;
    cout << "total weight for 767 load is " << totwt767 << endl;

}///end of input

void checkType(string uld, string type1){
    if((type1 != "Container") && (type1 != "Pallet") && (type1 != "Combo Flat")) {
        throw runtime_error("Error: \"" + uld + "\" is a bad load type!");
    }
}

void checkPlane(int air){
    if ((air != 737) && (air != 767)) {
        throw runtime_error("Error: \"" + to_string(air) + "\" is not 737 or 767!");
    }
}

void checkAbrv(string uld, string abrv, int plane){
    string testUld = uld.substr(0, 3);
    int testPlane;

    if (uld.size() < 3) {
        throw runtime_error("Error: ULD identifier \"" + uld + "\" is too short!");
    }

    if (plane == 737) {
        vector<string> validAbrv737 = {"AYF", "AYK", "AAA", "AYY", "PAG", "PMC", "PLA", "CFE", "CFK", "CFM"};
        if (find(validAbrv737.begin(), validAbrv737.end(), abrv) == validAbrv737.end()) {
            throw runtime_error("Error: Abbreviation \"" + abrv + "\" is not valid for aircraft 737!");
        }
    } else if (plane == 767) {
        vector<string> validAbrv767 = {"AKE", "APE", "AKC", "AQP", "AQF", "AAP", "P1P", "P6P", "CFQ", "CFX", "CFP"};
        if (find(validAbrv767.begin(), validAbrv767.end(), abrv) == validAbrv767.end()) {
            throw runtime_error("Error: Abbreviation \"" + abrv + "\" is not valid for aircraft 767!");
        }
    } else {
        throw runtime_error("Error: Unknown aircraft type!");
    }
}






