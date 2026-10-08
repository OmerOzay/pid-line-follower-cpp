#include "Track.h"
#include <cmath>

double Track::getLineY(double x) const {
    return 4.0 * std::sin(x * 0.05); 
}