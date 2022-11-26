//
// Created by rzhan on 2022-11-24.
//

#ifndef LAB1TEMPLATE_TOURMANAGER_HPP
#define LAB1TEMPLATE_TOURMANAGER_HPP

#include "Tour.hpp"
#include <vector>

using namespace std;

class TourManager {
private:
    /**
     * A vector of Tour objects.
     */
    vector<Tour> tours;
    /**
     * Finds the elite Tour in a list of tours.
     * @param vec a vector of Tours
     * @return an int representing the index of the elite Tour
     */
    static int findElite(vector<Tour> vec);
    /**
     * Promotes a Tour to be the new elite.
     */
    void promote();
    /**
     * Generates a random integer within a bound.
     * @param lower an int, the lower bound of the random range
     * @param upper a different int, the upper bound of the random range
     * @return the randomly generated int
     */
    static int randInt(int lower, int upper);
    /**
     * Generates a list of randomly selected Tours to be used as parents.
     * @return a list of parent Tours
     */
    vector<Tour> selectParents();
    /**
     * Creates a child tour comprising of random cities from two parent Tours.
     * @param father a Tour
     * @param mother another Tour
     * @return the child Tour containning random cities from one or both parents
     */
    Tour createChild(Tour &father, Tour &mother);
    /**
     * Crosses over parents to create a list of child Tours.
     */
    void crossover();
    /**
     * Mutates the Tour objects in the tours variable.
     */
    void mutateTours();
public:
    /**
     * Default constructor.
     */
    TourManager() = default;
    /**
     * Explicit one variable constructor.
     * @param t a list of tours
     */
    explicit TourManager(vector<Tour> &t) : tours(t) {}
    /**
     * Gets the Elite tour in the list of tours.
     * @return the elite Tour
     */
    Tour getElite();
    /**
     * Gets the list of all tours.
     * @return a vector of Tour objects
     */
    vector<Tour> getTours;
    /**
     * Crosses over and mutates tours to try and improve the fitness of the tours.
     */
    void improve();
    /**
     * Overloaded << operator for printing out the tourManager.
     * @param os ostream object
     * @param tourManager TourManager object
     * @return ostream object with TourManger variables inserted into cout
     */
    friend ostream & operator << (ostream &os, TourManager &tourManager);
};


#endif //LAB1TEMPLATE_TOURMANAGER_HPP
