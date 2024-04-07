#ifndef UAV_CALC_AIR_PROPERTIES_H
#define UAV_CALC_AIR_PROPERTIES_H

#include <cmath>    

const double UNIVERSAL_GAS_CONST = 8.3143;                  // J/mol * K
const double GRAVITATIONAL_ACCELERATION = 9.81;             // m/s^2
const double STANDARD_AIR_TEMPERATURE = 288.15;             // K
const double STANDARD_AIR_DENSITY = 1.225;                  // kg/m^3
const double STANDARD_AIR_PRESSURE = 101325;                // Pa
const double AIR_THERMAL_EXPANSION_COEFFICIENT = 0.003661;  // K^-1
const double STANDARD_DYNAMIC_VISCOSITY = 1.802e-5;         // Pa*s
const double SUTHERLAND_CONST = 119.8;                      // K
const double MOLAR_MASS = 0.0289652; 
const double BOLTZMANN_CONST = 1.380649e-23;
const double LAPSE_RATE = 0.0065;


/**
 * Calculates the absolute air pressure at a given altitude and temperature using the barometric formula.
 *
 * @param temperature The temperature in Kelvin.
 * @param altitude The altitude in meters.
 *
 * @return The absolute air pressure in Pascals.
 */

double calculateAbsoluteAirPressure (double temperature, double altitude)
{
    return STANDARD_AIR_PRESSURE * exp(-1 * (GRAVITATIONAL_ACCELERATION * altitude) / (UNIVERSAL_GAS_CONST * (temperature)));
}

/**
 * Calculates the air density at given temperature.
 *
 * @param temperature The temperature in Kelvin.
 *
 * @return The air density in kilograms per cubic meter.
 */

double calculateDryAirDensity (double temperature)
{
    return (STANDARD_AIR_PRESSURE) / ((UNIVERSAL_GAS_CONST / MOLAR_MASS) * STANDARD_AIR_TEMPERATURE);
}

/**
 * Calculates the air density at a given location given the temperature and altitude.
 *
 * @param temperature The temperature in Kelvin.
 * @param altitude The altitude in meters.
 *
 * @return The air density in kilograms per cubic meter.
 */

double calculateDryAirDensity(double temperature, double altitude)
{
    return ((STANDARD_AIR_PRESSURE * MOLAR_MASS) / (UNIVERSAL_GAS_CONST * STANDARD_AIR_TEMPERATURE)) * pow(((1 - ((LAPSE_RATE * altitude) / STANDARD_AIR_TEMPERATURE))),((GRAVITATIONAL_ACCELERATION * MOLAR_MASS) / (UNIVERSAL_GAS_CONST * LAPSE_RATE) - 1));
}

// TO DO ---> ADD HUMID AIR DENSITY
/**
 * Calculates the dynamic viscosity of air at a given temperature and humidity.
 *
 * @param temperature The temperature in Kelvin.
 * @param humidity The relative humidity (0-1).
 *
 * @return The dynamic viscosity in Pascal-seconds.
 */

double calculateDynamicViscosity (double temperature) 
{
    return STANDARD_DYNAMIC_VISCOSITY * ((0.555 * STANDARD_AIR_TEMPERATURE + SUTHERLAND_CONST) / (0.555 * temperature + SUTHERLAND_CONST)) * pow((temperature/STANDARD_AIR_TEMPERATURE),1.5); 
}

/**
 * Calculates the kinematic viscosity of air at a given temperature, altitude, and humidity.
 *
 * @param temperature The temperature in Kelvin.
 * @param altitude The altitude in meters.
 * @param humidity The relative humidity (0-1).
 *
 * @return The kinematic viscosity in square meters per second.
 */

double calculateKinematicViscosity (double temperature, double humidity)
{
    return calculateDynamicViscosity(temperature) / calculateDryAirDensity(temperature);
}

#endif