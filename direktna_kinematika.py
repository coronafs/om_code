import numpy as np

l1 = 2
l2 = 1
a1 = l1
a2 = l2
theta1 = np.pi/2
theta2 = np.pi/2
d1 = 0
d2 = 0
alfa1 = 0
alfa2 = 0


matrika_X1 = np.array([[np.cos(theta1), -np.sin(theta1)*np.cos(alfa1), np.sin(theta1)*np.sin(alfa1), a1*np.cos(theta1)],
                      [np.sin(theta1), np.cos(theta1)*np.cos(alfa1), -np.cos(theta1)*np.sin(alfa1), a1*np.sin(theta1)],
                      [0, np.sin(alfa1), np.cos(alfa1), d1],
                      [0, 0, 0, 1]])

matrika_X2 = np.array([[np.cos(theta2), -np.sin(theta2)*np.cos(alfa2), np.sin(theta2)*np.sin(alfa2), a2*np.cos(theta2)],
                      [np.sin(theta2), np.cos(theta2)*np.cos(alfa2), -np.cos(theta2)*np.sin(alfa2), a2*np.sin(theta2)],
                      [0, np.sin(alfa2), np.cos(alfa2), d2],
                      [0, 0, 0, 1]])

matrika_final = np.dot(matrika_X1, matrika_X2)


tocka = np.array([[0],
                  [0],
                  [0],
                  [1]])

premik = np.dot(matrika_final, tocka)

print(premik)