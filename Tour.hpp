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
    /**
     * The rate of mutation; a constant.
     */
    static constexpr double MUTATION = 0.75;
    /**
     * A vector of city objects.
     */
    vector<City> cities;
    /**
     * The fitness of this tour.
     */
    double fitness = 0;
    /**
     * Randomize the order of the cities in this tour.
     */
    void randomizeOrder();
public:
    /**
     * Default constructor for Tour class.
     */
    Tour() = default;
    /**
     * Explicit Tour constructor initializing the cities variable to a vector of cities.
     * @param vec a vector of cities
     */
    explicit Tour(vector<City> &vec): cities(vec) {
        randomizeOrder();
        checkFitness();
    }
    /**
     * Copy constructor for Tour class.
     * @param other a Tour class to be copied
     */
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
