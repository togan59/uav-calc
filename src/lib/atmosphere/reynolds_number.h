#ifndef REYNOLDS_NUMBER_H
#define REYNOLDS_NUMBER_H

/*
[EN] The Reynolds number (Re) is a dimensionless value that
measures the ratio of inertial forces to viscous
forces and descibes the degree of laminar or turbulent
flow. Systems that operate at the same Reynolds number
will have the same flow characteristics even if the fluid,
speed and characteristic lengths vary. 

    "Re = ρ.u.L / μ"  or "Re = u.L / ν"
    
        ρ : density of the fluid (SI units: kg/m3)
        u : flow speed (m/s)
        L : characteristic length (m)
        μ : dynamic viscosity of the fluid (Pa·s or N·s/m2 or kg/(m·s))
        ν : kinematic viscosity of the fluid (m2/s).
*/

double calcReWithKinematicViscosity(double flowSpeed, double characteristicLength, double kinematicViscosity) {
    return flowSpeed * characteristicLength / kinematicViscosity;
}

double calcReWithDynamicViscosity(double fluidDensity, double flowSpeed, double characteristicLength, double dynamicViscosity) {
    return fluidDensity * flowSpeed * characteristicLength / dynamicViscosity;
}

#endif