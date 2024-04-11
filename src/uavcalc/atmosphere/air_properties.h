#ifndef UAV_CALC_AIR_PROPERTIES_H
#define UAV_CALC_AIR_PROPERTIES_H

#include <cmath>

// Fundamental physical constants
const double UNIVERSAL_GAS_CONST = 8.3143;                    // J/mol * K (Universal gas constant)
const double GRAVITATIONAL_ACCELERATION = 9.81;               // m/s^2 (Acceleration due to gravity)

// Standard atmospheric conditions at sea level
const double STANDARD_AIR_TEMPERATURE = 288.15;               // K (Standard air temperature)
const double STANDARD_AIR_DENSITY = 1.225;                    // kg/m^3 (Standard air density)
const double STANDARD_AIR_PRESSURE = 101325;                  // Pa (Standard air pressure)

// Air properties
const double AIR_THERMAL_EXPANSION_COEFFICIENT = 0.003661;    // K^-1 (Thermal expansion coefficient of air)

// Viscosity-related constants
const double STANDARD_DYNAMIC_VISCOSITY = 1.802e-5;           // Pa*s (Standard dynamic viscosity of air)
const double SUTHERLAND_CONST = 119.8;                        // K (Sutherland constant for air)

// Gas component properties
const double DRYAIR_MOLAR_MASS = 0.0289652;                   // kg/mol (Molar mass of dry air)
const double BOLTZMANN_CONST = 1.380649e-23;                  // J/K (Boltzmann constant)
const double LAPSE_RATE = 0.0065;                             // K/m (Environmental lapse rate)

// Water vapor properties
const double WATERVAPOUR_MOLAR_MASS = 0.018016;               // kg/mol (Molar mass of water vapor)
const double DRYAIR_GAS_CONST = 287.058;                      // J/kg * K (Specific gas constant for dry air)
const double WATERVAPOUR_GAS_CONST = 461.495;                 // J/kg * K (Specific gas constant for water vapor)

// Herman Wobus equation coefficients for water vapor pressure
const double Eso = 6.1078;                                    // Pa (Reference vapor pressure at 0°C)
const double c0 = 0.99999683;
const double c1 = -0.90826951e-2;
const double c2 = 0.78736169e-4;
const double c3 = -0.61117958e-6;
const double c4 = 0.43884187e-8;
const double c5 = -0.29883885e-10;
const double c6 = 0.21874425e-12;
const double c7 = -0.17892321e-14;
const double c8 = 0.11112018e-16;
const double c9 = -0.30994571e-19;

/**
 * Calculates the water vapor pressure at a given temperature using the Herman Wobus equation.
 *
 * @param temperature The temperature in Kelvin.
 *
 * @return The water vapor pressure in Pascals.
 */

double calculateWaterVapourPressure(double temperature) 
{
  temperature -= 273.15; // Convert from Kelvin to Celsius

  double p = (c0 + temperature * (c1 + temperature * (c2 + temperature * (c3 + temperature * (c4 + temperature * (c5 + temperature * (c6 + temperature * (c7 + temperature * (c8 + temperature * (c9))))))))));
  return Eso / pow(p, 8);
}

/**
 * Calculates the absolute air pressure at a given altitude and temperature using the barometric formula.
 *
 * @param temperature The temperature in Kelvin.
 * @param altitude The altitude in meters.
 *
 * @return The absolute air pressure in Pascals.
 */

double calculateAbsoluteAirPressure(double temperature, double altitude) 
{
  return STANDARD_AIR_PRESSURE * exp(-1 * (GRAVITATIONAL_ACCELERATION * altitude) / (UNIVERSAL_GAS_CONST * (temperature)));
}

/**
 * Calculates the dry air density at a given temperature.
 *
 * @param temperature The temperature in Kelvin.
 *
 * @return The dry air density in kilograms per cubic meter.
 */

double calculateDryAirDensity(double temperature) 
{
  return (STANDARD_AIR_PRESSURE) / ((UNIVERSAL_GAS_CONST / DRYAIR_MOLAR_MASS) * STANDARD_AIR_TEMPERATURE);
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
  return ((STANDARD_AIR_PRESSURE * DRYAIR_MOLAR_MASS) / (UNIVERSAL_GAS_CONST * STANDARD_AIR_TEMPERATURE)) * pow(((1 - ((LAPSE_RATE * altitude) / STANDARD_AIR_TEMPERATURE))), ((GRAVITATIONAL_ACCELERATION * DRYAIR_MOLAR_MASS) / (UNIVERSAL_GAS_CONST * LAPSE_RATE) - 1));
}

/**
 * Calculates the density of humid air at a given temperature and altitude.
 *
 * @param temperature The temperature in Kelvin.
 * @param altitude The altitude in meters.
 *
 * @return The density of humid air in kilograms per cubic meter.
 */

double calculateHumidAirDensity(double temperature, double altitude) 
{
  return (calculateAbsoluteAirPressure(temperature, altitude) / (DRYAIR_GAS_CONST * temperature)) + (calculateWaterVapourPressure(temperature) / (WATERVAPOUR_GAS_CONST * temperature));
}

/**
 * Calculates the dynamic viscosity of air at a given temperature.
 *
 * @param temperature The temperature in Kelvin.
 *
 * @return The dynamic viscosity in Pascal-seconds.
 */

double calculateDynamicViscosity(double temperature) 
{
  return STANDARD_DYNAMIC_VISCOSITY * ((0.555 * STANDARD_AIR_TEMPERATURE + SUTHERLAND_CONST) / (0.555 * temperature + SUTHERLAND_CONST)) * pow((temperature / STANDARD_AIR_TEMPERATURE), 1.5);
}

/**
 * Calculates the kinematic viscosity of air at a given temperature and altitude.
 *
 * @param temperature The temperature in Kelvin.
 * @param altitude The altitude in meters.
 *
 * @return The kinematic viscosity in square meters per second.
 */

double calculateKinematicViscosity(double temperature, double altitude) 
{
  return calculateDynamicViscosity(temperature) / calculateDryAirDensity(temperature, altitude);
}

#endif
