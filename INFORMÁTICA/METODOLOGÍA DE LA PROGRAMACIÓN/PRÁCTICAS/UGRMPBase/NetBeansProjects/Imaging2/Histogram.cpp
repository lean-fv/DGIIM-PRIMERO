/**
 * @file Histogram.cpp
 * @author MP
 */
#include<iostream>
#include<string>
#include "MPTools.h"
#include "Byte.h"
#include "Histogram.h"

using namespace std;

const double Histogram::HISTOGRAM_TOLERANCE=0.01; ///< Value of the default tolerance


string Histogram::inspect() const{
    std::string result = "";
    for (int i = 0; i < HISTOGRAM_LEVELS; i++) {
        result += to_string(_data[i]);
    }
    result = std::to_string(mphash((unsigned char*)result.c_str(), result.length()));
    result = std::to_string(HISTOGRAM_LEVELS) + " " + result;
    return result;
}
