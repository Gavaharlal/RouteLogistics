//
// Created by Computer on 27.12.2018.
//

#ifndef TASK10_RANDOMALGORITHM_H
#define TASK10_RANDOMALGORITHM_H

#include "SplittingAlgorithmI.h"

class RandomAlgorithm : public SplittingAlgorithmI{
public:
    std::string getName() override;

    std::vector<std::vector<Point>> doSplitting(int k, const std::vector<Point> &points) override;
};


#endif //TASK10_RANDOMALGORITHM_H
