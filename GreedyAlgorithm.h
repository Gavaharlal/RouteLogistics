//
// Created by Computer on 27.12.2018.
//

#ifndef TASK10_GREEDYALGORITHM_H
#define TASK10_GREEDYALGORITHM_H

#include "SplittingAlgorithmI.h"

class GreedyAlgorithm : public SplittingAlgorithmI {
public:
    std::string getName() override;
    std::vector<std::vector<Point>> doSplitting(int k, const std::vector<Point> &points) override;

private:
    double getDistance(Point, Point);
};


#endif //TASK10_GREEDYALGORITHM_H
