#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <thread>

#include "MetricI.h"
#include "SplittingAlgorithmI.h"

#include "GreedyAlgorithm.h"
#include "DummyAlgorithm.h"
#include "RandomAlgorithm.h"


#include "BiggestMetric.h"
#include "LongestMetric.h"
#include "SumDistMetric.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

using std::cout;
using std::endl;

const std::string INPUT_FILE_NAME = "config.txt";
const std::string OUTPUT_FILE_NAME = "result.txt";
const int SLEEPING_TIME_IN_MILLIS = 3000;

std::vector<Point> readPoints(std::ifstream &in, int n) {
    std::vector<Point> result;
    double x, y;
    for (int i = 0; i < n; ++i) {
        in >> x >> y;
        result.emplace_back(x, y);
    }
    return result;
}

int main() {
    std::ifstream in;
    std::string algoArg;
    std::string metricArg;

    SplittingAlgorithmI *algorithm = nullptr;
    MetricI *metric = nullptr;

    while (true) {
        in.open(INPUT_FILE_NAME);


        in >> algoArg;
        in >> metricArg;

        if (algoArg == "Greedy") {
            algorithm = new GreedyAlgorithm();
        } else if (algoArg == "Dummy") {
            algorithm = new DummyAlgorithm();
        } else if (algoArg == "Random") {
            algorithm = new RandomAlgorithm();
        }

        if (metricArg == "Biggest") {
            metric = new BiggestMetric();
        } else if (metricArg == "Longest") {
            metric = new LongestMetric();
        } else if (metricArg == "SumDistance") {
            metric = new SumDistMetric();
        }

        int n, k;
        in >> n >> k;

        std::vector<Point> points = readPoints(in, n);

        std::vector<std::vector<Point>> splitting = algorithm->doSplitting(k, points);
        double metricResult = metric->calculateWeight(splitting);

        cout << "Algorithm: " << algorithm->getName() << endl;
        cout << "Metric: " << metric->getName() << endl;
        cout << "Points number : " << n << endl;
        cout << "Max point in route: " << k << endl;
        cout << "Result: " << metricResult << endl << endl;

        in.close();


        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEPING_TIME_IN_MILLIS));
    }

    return 0;
}

#pragma clang diagnostic pop
#pragma clang diagnostic pop