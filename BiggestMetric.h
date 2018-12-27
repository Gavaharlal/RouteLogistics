//
// Created by Computer on 26.12.2018.
//

#ifndef TASK10_BIGGESTMETRIC_H
#define TASK10_BIGGESTMETRIC_H

#include "MetricI.h"
class BiggestMetric : public MetricI {
public:
    std::string getName() override;
    std::string getDescription() override;
    double calculateWeight(std::vector<std::vector<Point>> vector) override;
};


#endif //TASK10_BIGGESTMETRIC_H
