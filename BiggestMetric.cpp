//
// Created by Computer on 26.12.2018.
//

#include "BiggestMetric.h"

std::string BiggestMetric::getName() {
    return "Biggest";
}

double BiggestMetric::calculateWeight(std::vector<std::vector<Point>> vector) {
    int max = -1;
    for (auto &i : vector) {
        int cur = i.size();
        max = __max(max, cur);
    }
    return max;
}

std::string BiggestMetric::getDescription() {
    return "Returns number of points in the route with the biggest number of points";
}
