//
// Created by rzhan on 2022-11-23.
//

#ifndef LAB1TEMPLATE_CITY_HPP
#define LAB1TEMPLATE_CITY_HPP

#include <string>

using namespace std;

static constexpr int MIN_COORD = 0;
static constexpr int MAX_COORD = 1000;

class City {
private:
    string name;
    int longitude = 0;
    int latitude = 0;
public:
    static int cityNum;
    City();
    City(const City &copy);
    int getLongitude();
    int getLatitude();
    string getName();
    double getDistance(City &other);
    friend ostream &operator << (ostream &os, City &city);
    bool operator == (City &city);
    bool operator != (City &city);
    City & operator = (City city);
    friend void swapCities(City &first, City &second);
};


#endif //LAB1TEMPLATE_CITY_HPP
