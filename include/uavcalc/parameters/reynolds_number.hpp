#pragma once

#include <uavcalc/common/air.hpp>

namespace uavcalc
{

class ReynoldsNumber
{
public:
    /**
     * Calculates the Reynolds number using kinematic viscosity.
     *
     * @param temperature The temperature in Kelvin.
     * @param altitude The altitude in meters.
     * @param humidity The humidity ratio.
     * @param flowSpeed The flow speed in meters per second.
     * @param characteristicLength The characteristic length of the body exposed to flow in meters.
     * @param kinematicViscosity The kinematic viscosity of the fluid.
     *
     * @return The Reynolds number.
     */

    static double computeWithKinematicViscosity(double temperature, double altitude, double humidity, 
                                                double flowSpeed, double characteristicLength);
    /**
     * Calculates the Reynolds number using dynamic viscosity.
     *
     * @param temperature The temperature in Kelvin.
     * @param humidity The humidity ratio.
     * @param fluidDensity The density of the fluid in kilograms per cubic meter.
     * @param flowSpeed The flow speed in meters per second.
     * @param characteristicLength The characteristic length in meters.
     * @param dynamicViscosity The dynamic viscosity of the fluid.
     *
     * @return The Reynolds number.
     */

    static double computeWithDynamicViscosity(double temperature, double humidity, double fluidDensity, 
                                          double flowSpeed, double characteristicLength);
};

} // namespace uavcalc