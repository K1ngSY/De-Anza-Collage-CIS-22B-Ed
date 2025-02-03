#include <iostream>
#include <string>
using namespace std;

struct Cargo
{
      string uld;
      string abbr;
      string uldid;
      string dest;
      int air;
      int wt;
};

void inputCargo(Cargo*);
void outputCargo(Cargo*);

int main() {
    Cargo* userCargoPtr = new Cargo;

    inputCargo(userCargoPtr);
    outputCargo(userCargoPtr);

    delete userCargoPtr;
    
    return 0;
}   

void inputCargo(Cargo* input) {
    cout << "Enter unit type: ";
    cin >> input->uld;

    cout << "Enter unit abbreviation: ";
    cin >> input->abbr;

    cout << "Enter unit identifier: ";
    cin >> input->uldid;

    cout << "Enter aircraft type: ";
    cin >> input->air;

    cout << "Enter weight in pounds: ";
    cin >> input->wt;

    cout << "Enter destination: ";
    cin >> input->dest;
}

void outputCargo(Cargo* output) {
    cout << "Unit type " << output->uld << endl;
    cout << "Unit abbreviation " << output->abbr << endl;
    cout << "Unit ID " << output->uldid << endl;
    cout << "Aircraft " << output->air << endl;
    cout << "Weight " << output->wt << " pounds" << endl;
    cout << "Destination " << output->dest << endl;
}
