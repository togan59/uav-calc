#include <uavcalc/parameters/reynolds_number.hpp>

namespace uavcalc
{

double ReynoldsNumber::computeWithKinematicViscosity(double temperature, double altitude, double humidity, double flowSpeed, double characteristicLength) 
{
    return flowSpeed * characteristicLength / Air::kinematicViscosity(temperature, altitude);
}

static double computeWithDynamicViscosity(double temperature, double humidity, double fluidDensity, double flowSpeed, double characteristicLength) 
{
    return fluidDensity * flowSpeed * characteristicLength / Air::dynamicViscosity(temperature);
}

} // namespace uavcalc