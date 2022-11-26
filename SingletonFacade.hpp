//
// Created by rzhan on 2022-11-25.
//

#ifndef LAB1TEMPLATE_SINGLETONFACADE_HPP
#define LAB1TEMPLATE_SINGLETONFACADE_HPP

#include "TourManager.hpp"

using namespace std;

class SingletonFacade {
private:
    /**
     * The maximum number of iterations that should be completed trying to find an elite matching the fitness threshold.
     */
    static constexpr int ITERATIONS = 1000;
    /**
     * A TourManager object for managing the various Tours.
     */
    TourManager manager;
    /**
     * The best Tour.
     */
    Tour best;
    /**
     * A list of Tours.
     */
    vector<Tour> tours;
    /**
     * A list of City objects.
     */
    vector<City> cities;
    /**
     * The minimum fitness threshold that satisfies our search.
     */
    double fitness;
    /**
     * Reports the results of an iteration.
     * @param newTour a new tour object
     * @param oldTour the original tour object
     * @param distance the distance of the oldTour
     * @param iterations the number of iterations completed so far
     */
    void report(Tour &newTour, Tour &oldTour, double distance, int iterations);
    /**
     * The final report, printing out the results of the algorithm and whether or not it was able to find a suitably
     * fit Tour.
     * @param final the final Tour object
     * @param initial the starting Tour object
     * @param iterations the number of iterations completed to reach this point
     */
    void finalReport(Tour &final, Tour &initial, int iterations);
    /**
     * Generates a number of tours to add to the tours vector
     * @param tourNum the number of tours to be generated
     */
    void generateTours(int tourNum);
    /**
     * Generates a number off cities to add to the cities vector.
     * @param cityNum the number of cities to be generated
     */
    void generateCities(int cityNum);
    /**
     * Gets the fittest tour in the list until the fitness threshold is reached.
     */
    void getBestTour();
public:
    /**
     * Constructor taking in 3 variables and generating the related objects to prepare for finding the elite.
     * @param cNum an int, the number of cities to be generated in each Tour
     * @param tNum an int, the number of Tours to be generated
     * @param minFitness the minimum fitness threshold
     */
    SingletonFacade(int cNum, int tNum, double minFitness);
    /**
     * Gets the current best Tour.
     * @return the Tour with the highest fitness so far
     */
    Tour &getBest();
    /**
     * Gets the list of current Tours.
     * @return a vector of Tour objects
     */
    vector<Tour> getTours();
    /**
     * Hides the complexity of the genetic algorithm using the Singleton and Facade design patterns.
     */
    void run();
};


#endif //LAB1TEMPLATE_SINGLETONFACADE_HPP
