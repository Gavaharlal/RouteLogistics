#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc30-c"
//
// Created by Computer on 27.12.2018.
//

#include "RandomAlgorithm.h"
#include "ctime"


std::string RandomAlgorithm::getName() {
    return "Random";
}

std::vector<std::vector<Point>> RandomAlgorithm::doSplitting(int k, const std::vector<Point> &points) {
    std::vector<Point> permutation = points;
    for (int i = 0; i < points.size() - 1; ++i) {
        int j = rand() % (points.size() - i);
        std::swap(permutation[i], permutation[j]);
    }

    std::vector<std::vector<Point>> result;
    std::vector<Point> curRoute;
    int tmp = 0;
    while (tmp < permutation.size()) {
        int curRouteLength = rand() % k + 1;
        for (int i = 0; i < curRouteLength; ++i) {
            curRoute.push_back(permutation[tmp]);
            tmp++;
            if (tmp == permutation.size()) {
                break;
            }
        }
        result.push_back(curRoute);
        curRoute.clear();
    }

    return result;
}

#pragma clang diagnostic pop