//
// Created by Computer on 26.12.2018.
//
#pragma once

#include <string>
#include <vector>
#include "Point.h"

class SplittingAlgorithmI {
public:
    virtual std::string getName() = 0;
    virtual std::vector<std::vector<Point>> doSplitting(int , const std::vector<Point>& ) = 0;
};