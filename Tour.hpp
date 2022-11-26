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
    /**
     * Checks the fitness of this tour.
     */
    void checkFitness();
    /**
     * Mutates this tour, swapping the order of cities randomly.
     */
    void mutate();
    /**
     * Add a city to this tour.
     * @param city City object to be added
     */
    void addCity(City &city);
    /**
     * Gets the fitness of this tour.
     * @return double representing the fitness
     */
    double getFitness();
    /**
     * Gets the total distance of this tour.
     * @return double representing the total distance
     */
    double getDistance();
    /**
     * Checks if a city is part of this tour.
     * @param city City object to be checked
     * @return true if city is in this tour, else false
     */
    bool hasCity(City &city);
    /**
     * Gets the list of cities in this tour.
     * @return a vector of City objects
     */
    vector<City>& getCities();
    /**
     * Overloaded = operator to set one city equal to another.
     * @param other a City to be set equal to
     * @return the current city, set equal to the other
     */
    Tour & operator = (Tour other);
    /**
     * Overloaded << function for printing tour out.
     * @param os ostream object
     * @param tour a Tour object
     * @return ostream object with the Tour variables added to cout
     */
    friend ostream &operator << (ostream &os, Tour &tour);
    /**
     * Helper function for overloaded = operator.
     * @param first a tour
     * @param second a different tour
     */
    friend void swapTour(Tour &first, Tour &second);
};


#endif //LAB1TEMPLATE_TOUR_HPP
