//
// Created by rzhan on 2022-11-23.
//

#include<random>
#include <iostream>
#include "City.hpp"

int City::cityNum = 1;

City::City() {
    random_device random;
    mt19937 generator(random());
    uniform_int_distribution<> distribution(MIN_COORD, MAX_COORD);
    longitude = distribution(generator);
    latitude = distribution(generator);
    name = "City " + to_string(City::cityNum);
    cityNum++;
}

City::City(const City &copy) {
    name = copy.name;
    longitude = copy.longitude;
    latitude = copy.latitude;
}

int City::getLongitude() {
    return longitude;
}

int City::getLatitude() {
    return latitude;
}

string City::getName() {
    return name;
}

double City::getDistance(City &other) {
    int xPos = abs(latitude - other.latitude);
    int yPos = abs(longitude - other.longitude);
    // a^2 + b^2 = c^2
    double a2b2 = pow(xPos, 2) + pow(yPos, 2);
    double distance = sqrt(a2b2);
    return distance;
}

ostream &operator<<(ostream &os, City &city) {
    os << city.name;
    return os;
}

bool City::operator==(City &city) {
    if (name == city.name && longitude == city.longitude && latitude == city.latitude) {
        return true;
    } else {
        return false;
    }
}

bool City::operator!=(City &city) {
    if (*this == city) {
        return true;
    } else {
        return false;
    }
}

City &City::operator=(City city) {
    swapCities(*this, city);
    return *this;
}

void swapCities(City &first, City &second) {
    swap(first.name, second.name);
    swap(first.longitude, second.longitude);
    swap(first.latitude, second.latitude);
}

