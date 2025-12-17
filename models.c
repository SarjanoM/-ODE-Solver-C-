#include <stdio.h>
#include <math.h>
#include "models.h"

//First order differential equations 

void exponential_growth_solver(void){
    double P, k, P0, t;

    printf("Enter the initial value of P, k and the time at which you should find the population: \n");
    scanf("%lf%lf%lf", &P0, &k, &t);

    P = P0 * exp(k * t);
    P = round(P);
    printf("P(%.2lf) = %.0lf\n", t, P);
}

void logistic_growth_solver(void){
    double P, k, P0, M, t;

    printf("Enter the initial value of P, k, carrying capacity and the time at which you should find the population: ");
    scanf("%lf%lf%lf%lf", &P0, &k, &M, &t);

    P = M / (1 + (((M - P0) / P0) * exp(-k * t)));
    P = round(P);
    printf("P(%.2lf) = %.0lf\n", t, P);
}

void RL_solver(void){
    double I, E, R, L, t;
    
    printf("Enter the values of E, R, L, t repectively: ");
    scanf("%lf%lf%lf%lf", &E, &R, &L, &t);

    I = (E / R) * (1 - exp(-(R/L) * t));
    printf("I(%.2lf) = %.4lf\n", t, I);
}

void Newton_cooling_solver(void){
    double T, T_env, T0, k, t;

    printf("Enter the values of T_env, T0, k, t respectively: ");
    scanf("%lf%lf%lf%lf", &T_env, &T0, &k, &t);

    T = T_env + (T0 - T_env) * exp(-k * t);
    printf("T(%.2lf) = %.4lf\n", t, T);
}

//Second order differential equations 

void LCR_current_finder(void){
    int n, i;
    double R, L, C, E, k1, k2, k3, k4, y, z, l1, l2, l3, l4, z0, y0, x0, h = 0.0001;
    
    printf("Enter the initial value of y, z, L, R, C, external emf E and the time at which the value is required\n");
    scanf("%lf%lf%lf%lf%lf%lf%lf", &y0, &z0, &L, &R, &C, &E, &x0);
    
    n = x0 / h;
    
    for (i=0; i<n ; i++) {
        k1 = h * z0;
        l1 = h * ((E/L) - ((y0)/(L * C)) - ((R /L) * z0));
        
        k2 = h * (z0 + (l1/2.0));
        l2 = h * ((E/L) - (((y0 + (k1 /2.0)) /(L * C))) - ((R /L) * (z0 + (l1 /2.0))));
        
        k3 = h * (z0 + (l2/2.0));
        l3 = h * ((E/L) - (((y0 + (k2 /2.0)) /(L * C))) - ((R /L) * (z0 + (l2 /2.0))));
        
        k4 = h * (z0 + l3);
        l4 = h * ((E/L) - (((y0 + k3) /(L * C))) - ((R /L) * (z0 + l3)));
        
        y = y0 + ((k1 + (k2 / 2.0) + (k3 / 2.0) + k4) / 6.0);
        z = z0 + ((l1 + (l2 / 2.0) + (l3 / 2.0) + l4) / 6.0);
        
        y0 = y;
        z0 = z;
    }

    printf("q(%.2lf) = %.4lf\n", x0, y);
    printf("i(%.2lf) = %.4lf\n", x0, z);
}

void Mass_spring_finder(void){
    int n, i;
    double m, c, k, F, h = 0.0001;
    double y0, z0, x0, y, z;
    double k1, k2, k3, k4, l1, l2, l3, l4;

    printf("Enter the initial value of y (displacement), z (velocity), m, c, k, external force F and the time at which the value is required\n");
    scanf("%lf%lf%lf%lf%lf%lf%lf", &y0, &z0, &m, &c, &k, &F, &x0);

    n = x0 / h;
    for (i = 0; i < n; i++) {
        k1 = h * z0;
        l1 = h * ((F/m) - ((c/m) * z0) - ((k/m) * y0));

        k2 = h * (z0 + (l1 / 2.0));
        l2 = h * ((F/m) - ((c/m) * (z0 + (l1 / 2.0))) - ((k/m) * (y0 + (k1 / 2.0))));
        
        k3 = h * (z0 + (l2 / 2.0));
        l3 = h * ((F/m) - ((c/m) * (z0 + (l2 / 2.0))) - ((k/m) * (y0 + (k2 / 2.0))));
        
        k4 = h * (z0 + l3);
        l4 = h * ((F/m) - ((c/m) * (z0 + l3)) - ((k/m) * (y0 + k3)));
        
        y = y0 + ((k1 + (k2 / 2.0) + (k3 / 2.0) + k4) / 6.0);
        z = z0 + ((l1 + (l2 / 2.0) + (l3 / 2.0) + l4) / 6.0);
        
        y0 = y;
        z0 = z;
    }

    printf("y(%.2lf) = %.4lf\n", x0, y);
    printf("y'(%.2lf) = %.4lf\n", x0, z);
}
