//
// Created by Computer on 26.12.2018.
//

#include "LongestMetric.h"
#include <cmath>

std::string LongestMetric::getName() {
    return "Longest";
}

std::string LongestMetric::getDescription() {
    return "Returns length of the longest route";
}

double LongestMetric::calculateWeight(std::vector<std::vector<Point>> vector) {
    double result = 0;
    for (auto &i : vector) {
        double curLength = 0;
        for (int j = 1; j < i.size(); ++j) {
            curLength += getDistance(i[j - 1], i[j]);
        }
        result = __max(result, curLength);
    }
    return result;
}

double LongestMetric::getDistance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
