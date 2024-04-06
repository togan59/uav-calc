//  DEFINITIONS
//  T   :   Temperature (K)
//  ρ   :   Density (kg/m3)
//  μ   :   Dynamic Viscosity (kg/m.s)


#ifndef UAV_CALC_AIR_PROPERTIES_H
#define UAV_CALC_AIR_PROPERTIES_H

class AirProperties
{
public:
    AirProperties();
    ~AirProperties();

    struct Properties {
        double temperature;
        double density;
        double dynamic_viscosity;
    };

};

#endif