#include <uavcalc/common/air.hpp>

namespace uavcalc
{

    const double Air::UNIVERSAL_GAS_CONST = 8.3143;                   
    const double Air::GRAVITATIONAL_ACCELERATION = 9.81;              

    // Standard atmospheric conditions at sea level
    const double Air::STANDARD_AIR_TEMPERATURE = 288.15;              
    const double Air::STANDARD_AIR_DENSITY = 1.225;                   
    const double Air::STANDARD_AIR_PRESSURE = 101325;                 

    // Air properties
    const double Air::AIR_THERMAL_EXPANSION_COEFFICIENT = 0.003661;   

    // Viscosity-related constants
    const double Air::STANDARD_DYNAMIC_VISCOSITY = 1.802e-5;          
    const double Air::SUTHERLAND_CONST = 119.8;                       

    // Gas component properties
    const double Air::DRYAIR_MOLAR_MASS = 0.0289652;                  
    const double Air::BOLTZMANN_CONST = 1.380649e-23;                 
    const double Air::LAPSE_RATE = 0.0065;                            

    // Water vapor properties
    const double Air::WATERVAPOUR_MOLAR_MASS = 0.018016;              
    const double Air::DRYAIR_GAS_CONST = 287.058;                     
    const double Air::WATERVAPOUR_GAS_CONST = 461.495;                

    // Herman Wobus equation coefficients for water vapor pressure
    const double Air::Eso = 6.1078;                                   
    const double Air::c0 = 0.99999683;
    const double Air::c1 = -0.90826951e-2;
    const double Air::c2 = 0.78736169e-4;
    const double Air::c3 = -0.61117958e-6;
    const double Air::c4 = 0.43884187e-8;
    const double Air::c5 = -0.29883885e-10;
    const double Air::c6 = 0.21874425e-12;
    const double Air::c7 = -0.17892321e-14;
    const double Air::c8 = 0.11112018e-16;
    const double Air::c9 = -0.30994571e-19;

double Air::waterVapourPressure(double temperature) 
{
    temperature -= 273.15; // Convert from Kelvin to Celsius

    double p = (c0 + temperature * 
               (c1 + temperature * 
               (c2 + temperature * 
               (c3 + temperature * 
               (c4 + temperature * 
               (c5 + temperature * 
               (c6 + temperature * 
               (c7 + temperature * 
               (c8 + temperature * (c9))))))))));
              
    return Eso / pow(p, 8);
}

double Air::absoluteAirPressure(double temperature, double altitude)
{
    return STANDARD_AIR_PRESSURE * exp(-1 * (GRAVITATIONAL_ACCELERATION * altitude) / 
           (UNIVERSAL_GAS_CONST * (temperature)));
}

double Air::dryAirDensity(double temperature)
{
    return (STANDARD_AIR_PRESSURE) / ((UNIVERSAL_GAS_CONST / DRYAIR_MOLAR_MASS) * STANDARD_AIR_TEMPERATURE);
}

double Air::dryAirDensity(double temperature, double altitude)
{
    return ((STANDARD_AIR_PRESSURE * DRYAIR_MOLAR_MASS) / (UNIVERSAL_GAS_CONST * STANDARD_AIR_TEMPERATURE)) * 
           pow(((1 - ((LAPSE_RATE * altitude) / STANDARD_AIR_TEMPERATURE))), 
           ((GRAVITATIONAL_ACCELERATION * DRYAIR_MOLAR_MASS) / (UNIVERSAL_GAS_CONST * LAPSE_RATE) - 1));
}

double Air::humidAirDensity(double temperature, double altitude) 
{
    return (absoluteAirPressure(temperature, altitude) / (DRYAIR_GAS_CONST * temperature)) +
          (waterVapourPressure(temperature) / (WATERVAPOUR_GAS_CONST * temperature));
}

double Air::dynamicViscosity(double temperature) 
{
  return STANDARD_DYNAMIC_VISCOSITY * ((0.555 * STANDARD_AIR_TEMPERATURE + SUTHERLAND_CONST) / 
         (0.555 * temperature + SUTHERLAND_CONST)) * pow((temperature / STANDARD_AIR_TEMPERATURE), 1.5);
}

double Air::kinematicViscosity(double temperature, double altitude) 
{
  return dynamicViscosity(temperature) / dryAirDensity(temperature, altitude);
}

} // namespace uavcalc