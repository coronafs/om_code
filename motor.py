#!/usr/bin/python3

def T_motor (r, J_l, alpha_l, B_l, omega_l, J_m, B_m):
    return 1/r * (J_l*alpha_l + B_l*omega_l + J_m*alpha_l*(r**2) + B_m*omega_l*(r**2)) 

print (T_motor(r=100, J_l=0.004, alpha_l=24, B_l=0.01, omega_l=12, J_m=2e-6, B_m=0) )

