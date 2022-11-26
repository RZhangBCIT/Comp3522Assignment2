//Name: Ray Zhang, Leanne Holmes
//Student# : A01288597, A01250217

#include <iostream>
#include "SingletonFacade.hpp"

using namespace std;

int main() {
//    int cities;
//    int tours;
//    double fitnessThreshold;
//    cout << "Enter the number of cities: " << endl;
//    cin >> cities;
//    cout << "Enter the number of tours: " << endl;
//    cin >> tours;
//    cout << "Enter the minimum fitness threshold: " << endl;
//    cin >> fitnessThreshold;
//
//    SingletonFacade sf(cities, tours, fitnessThreshold);
//    sf.run();
    SingletonFacade sf(25,10,0.13);
    sf.run();
    return 0;
}
