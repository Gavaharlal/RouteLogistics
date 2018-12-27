//
// Created by Computer on 27.12.2018.
//

#include "GreedyAlgorithm.h"
#include <cmath>

std::string GreedyAlgorithm::getName() {
    return "Greedy";
}

std::vector<std::vector<Point>> GreedyAlgorithm::doSplitting(int k, const std::vector<Point> &points) {
    std::vector<std::vector<Point>> result;
    std::vector<Point> curRoute;
    int lastPointIdx = 0;
    bool used[points.size()];
    for (int j = 1; j < points.size(); ++j) {
        used[j] = false;
    }

    curRoute.push_back(points[0]);
    used[0] = true;
    for (int i = 0; i < points.size(); ++i) {
        int curPointIdx = -1;
        for (int j = 0; j < points.size(); ++j) {
            if (!used[j] && (curPointIdx == -1 || getDistance(points[lastPointIdx], points[curPointIdx]) >
                                                  getDistance(points[lastPointIdx], points[j]))) {
                curPointIdx = j;
            }
        }
        if (curRoute.size() < k) {
            curRoute.push_back(points[curPointIdx]);
        } else {
            result.push_back(curRoute);
            curRoute.clear();
            curRoute.push_back(points[curPointIdx]);
        }

        used[curPointIdx] = true;
        lastPointIdx = curPointIdx;
    }
    if (!curRoute.empty()) {
        result.push_back(curRoute);
    }
    return result;
}

double GreedyAlgorithm::getDistance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
