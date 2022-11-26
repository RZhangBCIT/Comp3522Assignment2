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
    vector<Tour> tours;
    static int findElite(vector<Tour> vec);
    void promote();
    static int randInt(int lower, int upper);
    vector<Tour> selectParents();
    Tour createChild(Tour &father, Tour &mother);
    void crossover();
    void mutateTours();
public:
    TourManager() = default;
    explicit TourManager(vector<Tour> &t) : tours(t) {}
    Tour getElite();
    vector<Tour> getTours;
    void improve();
    friend ostream & operator << (ostream &os, TourManager &tourManager);
};


#endif //LAB1TEMPLATE_TOURMANAGER_HPP
