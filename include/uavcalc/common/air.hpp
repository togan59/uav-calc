#pragma once

#include <cmath>

namespace uavcalc
{
class Air 
{
public:
    // Fundamental physical constants
    static const double UNIVERSAL_GAS_CONST;                  
    static const double GRAVITATIONAL_ACCELERATION;           

    // Standard atmospheric conditions at sea level
    static const double STANDARD_AIR_TEMPERATURE;             
    static const double STANDARD_AIR_DENSITY;                 
    static const double STANDARD_AIR_PRESSURE;                

    // Air properties
    static const double AIR_THERMAL_EXPANSION_COEFFICIENT;    

    // Viscosity-related constants
    static const double STANDARD_DYNAMIC_VISCOSITY;           
    static const double SUTHERLAND_CONST;                    

    // Gas component properties
    static const double DRYAIR_MOLAR_MASS;                    
    static const double BOLTZMANN_CONST;                      
    static const double LAPSE_RATE;                           

    // Water vapor properties
    static const double WATERVAPOUR_MOLAR_MASS;               
    static const double DRYAIR_GAS_CONST;                     
    static const double WATERVAPOUR_GAS_CONST;                

    // Herman Wobus equation coefficients for water vapor pressure
    static const double Eso;                                   
    static const double c0, c1, c2, c3, c4, c5, c6, c7, c8, c9;
    
    /**
     * Calculates the water vapor pressure at a given temperature using the Herman Wobus equation.
     *
     * @param temperature The temperature in Kelvin.
     *
     * @return The water vapor pressure in Pascals.
     */

    static double waterVapourPressure(double temperature);

    /**
     * Calculates the absolute air pressure at a given altitude and temperature using the barometric formula.
     *
     * @param temperature The temperature in Kelvin.
     * @param altitude The altitude in meters.
     *
     * @return The absolute air pressure in Pascals.
     */

    static double absoluteAirPressure(double temperature, double altitude);

    /**
     * Calculates the dry air density at a given temperature.
     *
     * @param temperature The temperature in Kelvin.
     *
     * @return The dry air density in kilograms per cubic meter.
     */

    static double dryAirDensity(double temperature);

    /**
     * Calculates the air density at a given location given the temperature and altitude.
     *
     * @param temperature The temperature in Kelvin.
     * @param altitude The altitude in meters.
     *
     * @return The air density in kilograms per cubic meter.
     */

    static double dryAirDensity(double temperature, double altitude);

    /**
     * Calculates the density of humid air at a given temperature and altitude.
     *
     * @param temperature The temperature in Kelvin.
     * @param altitude The altitude in meters.
     *
     * @return The density of humid air in kilograms per cubic meter.
     */

    static double humidAirDensity(double temperature, double altitude);

    /**
     * Calculates the dynamic viscosity of air at a given temperature.
     *
     * @param temperature The temperature in Kelvin.
     *
     * @return The dynamic viscosity in Pascal-seconds.
     */

    static double dynamicViscosity(double temperature);

    /**
     * Calculates the kinematic viscosity of air at a given temperature and altitude.
     *
     * @param temperature The temperature in Kelvin.
     * @param altitude The altitude in meters.
     *
     * @return The kinematic viscosity in square meters per second.
     */

    static double kinematicViscosity(double temperature, double altitude);
};

} // namespace uavcalc