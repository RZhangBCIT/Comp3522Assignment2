//
// Created by rzhan on 2022-11-24.
//

#include "TourManager.hpp"
#include <iostream>
#include <set>
#include <random>

int TourManager::findElite(vector<Tour> vec) {
    double minFitness;
    int eliteIndex = 0;
    Tour elite;
    elite = vec[0];
    minFitness = elite.getFitness();

    for (int i = 0; i < (int) vec.size(); i++) {
        double fitness = vec[i].getFitness();
        if (fitness < minFitness) {
            elite = vec[i];
            minFitness = fitness;
            eliteIndex = i;
        }
    }
    return eliteIndex;
}

void TourManager::promote() {
    int elite = findElite(tours);
    std::swap(tours[0], tours[elite]);
}

int TourManager::randInt(int lower, int upper) {
    if (upper <= lower) {
        return lower;
    }
    random_device random;
    mt19937 generator(random());
    uniform_int_distribution<> distribution(lower, upper);

    return distribution(generator);
}

vector<Tour> TourManager::selectParents() {
    int poolSize = ceil(((double) tours.size()) * 0.2);
    vector<Tour> parentPool;
    for (int i = 0; i < poolSize; i++) {
        int index = randInt(1, (int) tours.size() - 1);
        parentPool.push_back(tours[index]);
    }
    return parentPool;
}

Tour TourManager::createChild(Tour &father, Tour &mother) {
    int ceiling = (int) father.getCities().size();
    int index = randInt(0, ceiling - 1);
    Tour child;
    vector<City> motherland = mother.getCities();
    vector<City> fatherland = father.getCities();

    for (int i = 0 ; i <= index; i++) {
        child.addCity(fatherland.at(i));
    }

    for (City & i : motherland) {
        if (!child.hasCity(i)) {
            child.addCity(i);
        }
    }

    child.getFitness();
    return child;
}

void TourManager::crossover() {
    vector<Tour> children;
    children.push_back(tours[0]); // Keep the elite

    while (children.size() < tours.size()) {
        // create a pool of potential fathers from the population.
        vector<Tour> fathers = selectParents();
        // select the fittest father.
        int eliteFather = findElite(fathers);
        Tour father = fathers.at(eliteFather);

        // create a pool of mothers from the population.
        vector<Tour> mothers = selectParents();
        // select the fittest mother.
        int eliteMother = findElite(mothers);
        Tour mother = mothers.at(eliteMother);

        // create a child and add it to the children vector
        Tour child = createChild(father, mother);
        children.push_back(child);
    }
    // set tours to this new vector of newly created Tours, keeping the previous elite
    tours = children;
}

void TourManager::mutateTours() {
    for (int i = 1; i < (int) tours.size(); i++) {
        tours.at(i).mutate();
    }
}

Tour TourManager::getElite() {
    return tours.at(0);
}

void TourManager::improve() {
    promote();
    crossover();
    mutateTours();
}

ostream &operator<<(ostream &os, TourManager &tourManager) {
    for (Tour &t : tourManager.getTours){
        os << t << "TourManager overloading <<" << endl;
    }
    return os;
}

