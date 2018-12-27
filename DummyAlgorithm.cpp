//
// Created by Computer on 27.12.2018.
//

#include "DummyAlgorithm.h"

std::string DummyAlgorithm::getName() {
    return "Dummy";
}

std::vector<std::vector<Point>> DummyAlgorithm::doSplitting(int k, const std::vector<Point> &points) {
    std::vector<std::vector<Point>> result;
    std::vector<Point> curRoute;
    int tmp = 0;
    curRoute.push_back(points[tmp]);
    tmp++;
    while (tmp < points.size()) {
        curRoute.push_back(points[tmp]);
        tmp++;
        if (tmp % k == 0) {
            result.push_back(curRoute);
            curRoute.clear();
        }
    }
    return result;
}
