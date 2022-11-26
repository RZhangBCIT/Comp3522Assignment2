//
// Created by rzhan on 2022-11-23.
//

#ifndef LAB1TEMPLATE_CITY_HPP
#define LAB1TEMPLATE_CITY_HPP

#include <string>

using namespace std;

static constexpr int MIN_COORD = 0;
static constexpr int MAX_COORD = 1000;

/**
 * City class for Comp 3522 at BCIT.
 */
class City {
private:
    /**
     * Name of the city.
     */
    string name;
    /**
     * longitudinal coordinate of the city.
     */
    int longitude = 0;
    /**
     * latitudinal coordinate of the city.
     */
    int latitude = 0;
public:
    /**
     * total number of cities.
     */
    static int cityNum;
    /**
     * Default constructor.
     */
    City();
    /**
     * Copy constructor for City class.
     * @param copy a City object to copy
     */
    City(const City &copy);
    /**
     * Gets the longitude of the city.
     * @return an int
     */
    int getLongitude();
    /**
     * Gets the latitude of the city.
     * @return an int
     */
    int getLatitude();
    /**
     * Gets the name of the city.
     * @return a string
     */
    string getName();
    /**
     * Gets the distance between this city and a different city.
     * @param other another city
     * @return double representing the straight-line distance between the two cities
     */
    double getDistance(City &other);
    /**
     * Overloaded insertion function for printing a city.
     * @param os ostream object
     * @param city City object
     * @return ostream object with the city's instance variables inserted into cout
     */
    friend ostream &operator << (ostream &os, City &city);
    /**
     * Overloaded == operator for comparing 2 cities.
     * @param city City object to be compared
     * @return true if the two cities are the same, else false
     */
    bool operator == (City &city);
    /**
     * Overloaded != operator for comparing 2 cities.
     * @param city City object to be compared
     * @return true if the two cities are not the same, else false
     */
    bool operator != (City &city);
    /**
     * Overloaded = operator for setting one city equal to another.
     * @param city City to be set equal to
     * @return first City, now equal to the param city
     */
    City & operator = (City city);
    /**
     * Helper function for overloaded = operator
     * @param first a City object
     * @param second a different City object
     */
    friend void swapCities(City &first, City &second);
};


#endif //LAB1TEMPLATE_CITY_HPP
