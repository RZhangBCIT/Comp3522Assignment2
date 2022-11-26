//
// Created by rzhan on 2022-11-23.
//

#include "Tour.hpp"
#include <random>
#include <algorithm>
#include <iostream>

using namespace std;
void Tour::randomizeOrder() {
    random_device random;
    mt19937 generator(random());
    shuffle(cities.begin(), cities.end(), generator);
}

Tour::Tour(const Tour &other) {
    cities = other.cities;
    fitness = other.fitness;
}

void Tour::checkFitness() {
    fitness = 1/getDistance();
}

double Tour::getDistance() {
    double distance = 0;
    for (int i = 0; i < (int) cities.size() - 1; ++i) {
        distance += cities[i].getDistance(cities[i+1]);
    }
    distance += cities[0].getDistance(cities[cities.size() - 1]);
    return distance;
}

void Tour::mutate() {
    random_device random;
    mt19937 generator(random());
    uniform_real_distribution<> distribution{};
    double coefficient_of_mutation = distribution(generator);
    for (int i = 0; i < (int) cities.size(); i++) {
        if (MUTATION <= coefficient_of_mutation) {
            continue;
        }
        if (i == 0) {
            swap(cities[0], cities[i]);
            continue;
        }
        if (i == (int) cities.size() - 1) {
            swap(cities[cities.size() - 2], cities[i]);
            continue;
        }
        double beforeOrAfter = distribution(generator);
        if (beforeOrAfter < 0.5) {
            swap(cities[i - 1], cities[i]);
        } else {
            swap(cities[i+1], cities[i]);
        }
    }
    checkFitness();
}

void Tour::addCity(City &city) {
    cities.push_back(city);
}

double Tour::getFitness() {
    return fitness;
}

vector<City> &Tour::getCities() {
    return cities;
}

bool Tour::hasCity(City &city) {
    for (City &c : cities) {
        if (c == city) {
            return true;
        }
    }
    return false;
}

Tour &Tour::operator=(Tour other) {
    swapTour(*this, other);
    return *this;
}

void swapTour(Tour &first, Tour &second) {
    swap(first.cities, second.cities);
    swap(first.fitness, second.fitness);
}

ostream &operator << (ostream &os, Tour &tour) {
    os << "Distance: " << tour.getDistance() << endl << "Cities: ";
    for (City &c : tour.cities) {
        os << c << ", ";
    }
    return os;
}
