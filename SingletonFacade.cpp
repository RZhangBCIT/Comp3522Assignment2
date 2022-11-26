//
// Created by rzhan on 2022-11-25.
//

#include "SingletonFacade.hpp"
#include <iostream>


void SingletonFacade::report(Tour &newTour, Tour &oldTour, double distance, int iterations) {
    cout << "Iteration number: " << iterations << endl;
    cout << "Previous best distance: " << oldTour.getDistance() << endl;
    cout << "New best distance: " << newTour.getDistance() << endl;
    if (newTour.getDistance() < oldTour.getDistance()) {
        cout << "Best distance improved by: " << oldTour.getDistance() - newTour.getDistance() << endl;
        cout << "Total distance improved by: " << distance - newTour.getDistance() << endl;
    } else {
        cout << "No improvement to distance" << endl;
    }
    cout << "----------------------------------------------------" << endl;
}

void SingletonFacade::finalReport(Tour &final, Tour &initial, int iterations) {
    cout << "Iterations complete!" << endl << "Final Results: " << endl;
    if (final.getFitness() > fitness) {
        cout << "Fitness target achieved!" << endl;
        cout << "Initial fitness: " << initial.getFitness() << endl;
        cout << "Fitness threshold: " << fitness << endl;
        cout << "New fitness: " << final.getFitness() << endl;
    } else {
        cout << "Failed to find new fittest Tour." << endl;
        cout << "Fitness target: " << fitness << endl;
        cout << "Closest fitness level found: " << final.getFitness() << endl;
    }
    cout << "==========================" << endl;
    cout << "Initial tour: " << initial << endl;
    cout << "==========================" << endl;
    cout << "Best tour: " << final << endl;
}

void SingletonFacade::generateTours(int tourNum) {
    for (int i = 0; i < tourNum; i++) {
        tours.emplace_back(cities);
    }
}

void SingletonFacade::generateCities(int cityNum) {
    for (int i = 0; i < cityNum; i++) {
        cities.emplace_back();
    }
}

void SingletonFacade::getBestTour() {
    Tour base = manager.getElite();
    double baseDistance = base.getDistance();
    Tour currentElite = base;
    int iterations = 0;
    while (currentElite.getFitness() < fitness && iterations < ITERATIONS) {
        manager.improve();
        Tour potentialElite = manager.getElite();
        iterations++;

        report(potentialElite, currentElite, baseDistance, iterations);

        if (currentElite.getFitness() < potentialElite.getFitness()) {
            currentElite = potentialElite;
        }
    }

    this->best = currentElite;
    finalReport(currentElite, base, iterations);
}

SingletonFacade::SingletonFacade(int cNum, int tNum, double minFitness) : best(), fitness(minFitness) {
    generateCities(cNum);
    generateTours(tNum);
    manager = TourManager(tours);
}

Tour &SingletonFacade::getBest() {
    return best;
}

vector<Tour> SingletonFacade::getTours() {
    return tours;
}

void SingletonFacade::run() {
    getBestTour();
}
