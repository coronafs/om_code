import numpy as np
import scipy.linalg as la

a1 = 1
a2 = 1
theta1 = 0 # podaj v radianih ali pa pi
theta2 = np.pi/8

matrika_J = np.array([[-a1*np.sin(theta1) - a2*np.sin(theta1 + theta2), -a2*np.sin(theta1+theta2)],
                    [a1*np.cos(theta1)+a2*np.cos(theta1+theta2), a2*np.cos(theta1+theta2)]])

print(matrika_J)

A = np.dot(matrika_J, np.transpose(matrika_J))
print(A)

eigvals, eigvecs = la.eig(A)

print(eigvecs)
print(eigvals)

mera_gibljivosti = np.sqrt(np.linalg.det(np.dot(matrika_J, np.transpose(matrika_J))))
print(mera_gibljivosti)

