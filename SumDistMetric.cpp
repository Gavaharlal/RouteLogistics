//
// Created by Computer on 26.12.2018.
//

#include "SumDistMetric.h"
#include <cmath>

std::string SumDistMetric::getName() {
    return "SumDistance";
}

std::string SumDistMetric::getDescription() {
    return "Returns sum of route's lengths";
}

double SumDistMetric::calculateWeight(std::vector<std::vector<Point>> vector) {
    double result = 0;
    for (auto &i : vector) {
        for (int j = 1; j < i.size(); ++j) {
            result += getDistance(i[j-1], i[j]);
        }
    }
    return result;
}

double SumDistMetric::getDistance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
