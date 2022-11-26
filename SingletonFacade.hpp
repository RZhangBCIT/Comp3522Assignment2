//
// Created by rzhan on 2022-11-25.
//

#ifndef LAB1TEMPLATE_SINGLETONFACADE_HPP
#define LAB1TEMPLATE_SINGLETONFACADE_HPP

#include "TourManager.hpp"

using namespace std;

class SingletonFacade {
private:
    static constexpr int ITERATIONS = 1000;
    TourManager manager;
    Tour best;
    vector<Tour> tours;
    vector<City> cities;
    double fitness;
    void report(Tour &newTour, Tour &oldTour, double distance, int iterations);
    void finalReport(Tour &final, Tour &initial, int iterations);
    void generateTours(int tourNum);
    void generateCities(int cityNum);
    void getBestTour();
public:
    SingletonFacade(int cNum, int tNum, double minFitness);
    Tour &getBest();
    vector<Tour> getTours();
    void run();
};


#endif //LAB1TEMPLATE_SINGLETONFACADE_HPP
