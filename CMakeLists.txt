cmake_minimum_required(VERSION 3.13)
project(TASK10)

set(CMAKE_CXX_STANDARD 14)

add_executable(TASK10 main.cpp MetricI.h SplittingAlgorithmI.h Point.cpp Point.h
        BiggestMetric.cpp BiggestMetric.h SumDistMetric.cpp SumDistMetric.h LongestMetric.cpp LongestMetric.h
        GreedyAlgorithm.cpp GreedyAlgorithm.h RandomAlgorithm.cpp RandomAlgorithm.h
        DummyAlgorithm.cpp DummyAlgorithm.h)