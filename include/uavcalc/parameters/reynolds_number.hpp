#pragma once

#include <air.hpp>

namespace uavcalc
{

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

double calculateReWithKinematicViscosity(double temperature, double altitude, double humidity, double flowSpeed, double characteristicLength) 
{
    return flowSpeed * characteristicLength / kinematicViscosity(temperature, altitude);
}

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

double calculateReWithDynamicViscosity(double temperature, double humidity, double fluidDensity, double flowSpeed, double characteristicLength) 
{
    return fluidDensity * flowSpeed * characteristicLength / dynamicViscosity(temperature);
}

} // namespace uavcalc