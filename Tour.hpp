//
// Created by rzhan on 2022-11-23.
//

#ifndef LAB1TEMPLATE_TOUR_HPP
#define LAB1TEMPLATE_TOUR_HPP

#include "City.hpp"
#include <vector>
#include<ostream>

using namespace std;

class Tour {
private:
    static constexpr double MUTATION = 0.75;
    vector<City> cities;
    double fitness = 0;

    void randomizeOrder();
public:
    Tour() = default;
    explicit Tour(vector<City> &vec): cities(vec) {
        randomizeOrder();
        checkFitness();
    }
    Tour(const Tour &other);
    void checkFitness();
    void mutate();
    void addCity(City &city);
    double getFitness();
    double getDistance();
    bool hasCity(City &city);
    vector<City>& getCities();
    Tour & operator = (Tour other);
    friend ostream &operator << (ostream &os, Tour &tour);
    friend void swapTour(Tour &first, Tour &second);
};


#endif //LAB1TEMPLATE_TOUR_HPP
