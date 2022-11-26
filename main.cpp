//Name: Ray Zhang, Leanne Holmes
//Student# : A01288597, A01250217

#include <iostream>
#include "SingletonFacade.hpp"

using namespace std;

int main() {
    int option;
    cout << "Welcome! Would you like to run with the default settings or enter your own?" << endl;
    cout << "Enter 1 for default options, or two to set your own parameters." << endl;
    cin >> option;
    if (option == 1) {
        SingletonFacade sf(32,32,0.13);
        sf.run();
    } else if (option == 2) {
        int cities;
        int tours;
        double fitnessThreshold;
        cout << "Enter the number of cities: " << endl;
        cin >> cities;
        cout << "Enter the number of tours: " << endl;
        cin >> tours;
        cout << "Enter the minimum fitness threshold: " << endl;
        cin >> fitnessThreshold;

        SingletonFacade sf(cities, tours, fitnessThreshold);
        sf.run();
    } else {
        cout << "Error! You must enter 1 or 2. Please restart the program and try again." << endl;
    }
    return 0;
}
