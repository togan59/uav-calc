//
// Created by hk on 3/27/24.
//

//  DEFINITIONS
//  T   :   Temperature (K)
//  ρ   :   Density (kg/m3)
//  μ   :   Dynamic Viscosity (kg/m.s)
//  k   :   Thermal Conductivity (W/m.K)


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
        double thermal_conductivity;
    };

};

#endif //UAV_CALC_AIR_PROPERTIES_H
