#ifndef UAV_CALC_AIR_PROPERTIES_H
#define UAV_CALC_AIR_PROPERTIES_H

#include <cmath>

const double UNIVERSAL_GAS_CONST = 8.3143; //J/mol * K
const double GRAVITATIONAL_ACCELERATION = 9.81;
const double STANDART_AIR_TEMPERATURE = 293.15; //K
const double STANDART_AIR_DENSITY = 1.225; //kg/m^3
const double STANDART_AIR_PRESSURE = 101325; //Pa
const double AIR_THERMAL_EXPANSION_COEFFICIENT = 0.003661; // K^-1
const double STANDART_DYNAMIC_VISCOSITY = 1.8205; // Pa*s
const double SUTHERLAND_CONST = 119.8; //K

double calculateAbsoluteAirPressure (double temperature, double altitude)
{
    return STANDART_AIR_PRESSURE * exp(-1 * (GRAVITATIONAL_ACCELERATION * altitude) / (UNIVERSAL_GAS_CONST * (temperature)));
}

/**
 * Calculates the air density at a given location given the temperature and altitude.
 *
 * @param temperature The temperature in Kelvin.
 * @param altitude The altitude in meters.
 *
 * @return The air density in kilograms per cubic meter.
 */

double calculateDryAirDensity (double temperature, double altitude)
{
    return STANDART_AIR_DENSITY * (calculateAbsoluteAirPressure(temperature, altitude) / STANDART_AIR_PRESSURE) * (1 / (1 + AIR_THERMAL_EXPANSION_COEFFICIENT * (temperature - STANDART_AIR_TEMPERATURE)));
}

double calculateDynamicViscosity (double temperature, double humidity) 
{
    return STANDART_DYNAMIC_VISCOSITY * (pow(((temperature + SUTHERLAND_CONST) / STANDART_AIR_TEMPERATURE),1.5) * (1 + humidity * ((temperature + SUTHERLAND_CONST) / STANDART_AIR_TEMPERATURE)));
}

double calculateKinematicViscosity (double temperature, double altitude, double humidity)
{
    return calculateDynamicViscosity(temperature, humidity) / calculateDryAirDensity(temperature, altitude);
}

#endif