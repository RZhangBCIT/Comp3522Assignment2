//Name: Ray Zhang,
//Student# : A01288597,

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
    SingletonFacade sf(50, 100, 0.0005);
    sf.run();
    return 0;
}
