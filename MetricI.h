//
// Created by Computer on 26.12.2018.
//

#pragma once

#include "Point.h"
#include <string>
#include <vector>

class MetricI {
public:
    virtual std::string getName() = 0;
    virtual std::string getDescription() = 0;
    virtual double calculateWeight(std::vector<std::vector<Point>>) = 0;
};