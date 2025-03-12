

import os
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
p_17 = np.array([
4.05,
3.75,
3.5 ,
3.0 ,
2.55])

u_17 = np.array([
148,
130,
120,
100,
80])

p_25 = np.array([
4.05,
3.8 ,
3.35,
2.85,
2.15])

u_25 = np.array([
150,
128,
110,
89 ,
64])

p_35 =np.array([
4  ,
3.3,
2.9,
2.4])

u_35 = np.array([
135,
98 ,
80 ,
60])

p_50 = np.array([
4.1,
3.5,
2.9,
2.3])

u_50 = np.array([
127,
97 ,
74 ,
53])
plot_1 = plt.figure(figsize=(12*0.9,10*0.9))
plt.grid(visible=True, linewidth=0.6)

plt.title('Зависимость $\Delta T(\Delta p)$', fontsize=18)
#plt.xlim(xmin=0, xmax=0.03)
#plt.ylim(ymin=0, ymax=100)
plt.ylabel('$\Delta T$, $^\circ C$', fontsize=20, rotation=0, ha='right')
plt.xlabel('$\Delta p$, бар', fontsize=20)
plt.tick_params(axis='both', which='major', labelsize=16, size=10)
plt.grid(visible=True, linewidth=0.6)



yerr_1 = 3
xerr_1 = 0.1



#z, err = np.polyfit(D, Q[1], deg=1, cov=True)
#polynom_2 = np.poly1d(z)
#plt.plot(D, polynom_2(D),"b--", linewidth=1, label="МНК")

plt.errorbar(
    p_17,
    u_17/38.9,
    fmt='ko',
    linewidth=0,
    markersize=8,
    elinewidth=1,
    label='17 $^\circ C$',
    xerr=xerr_1,
    yerr=yerr_1/38.9,
    capsize=3
)

plt.errorbar(
    p_25,
    u_25 / 40.7,
    fmt='ro',
    linewidth=0,
    markersize=8,
    elinewidth=1,
    label='25,2 $^\circ C$',
    xerr=xerr_1,
    yerr=yerr_1 / 40.7,
    capsize=3
)

plt.errorbar(
    p_35,
    u_35 / 41.6,
    fmt='bo',
    linewidth=0,
    markersize=8,
    elinewidth=1,
    label='35 $^\circ C$',
    xerr=xerr_1,
    yerr=yerr_1 / 41.6,
    capsize=3
)

plt.errorbar(
    p_50,
    u_50 / 42.5,
    fmt='yo',
    linewidth=0,
    markersize=8,
    elinewidth=1,
    label='50 $^\circ C$',
    xerr=xerr_1,
    yerr=yerr_1 / 42.5,
    capsize=3
)

z_1 = np.polyfit(p_17, u_17/38.9, deg=1)
polynom_1 = np.poly1d(z_1)
plt.plot(p_17, polynom_1(p_17),"k--", linewidth=1)

z_2 = np.polyfit(p_25, u_25 / 40.7, deg=1)
polynom_2 = np.poly1d(z_2)
plt.plot(p_25, polynom_2(p_25),"r--", linewidth=1)

z_3 = np.polyfit(p_35, u_35 / 41.6, deg=1)
polynom_3 = np.poly1d(z_3)
plt.plot(p_35, polynom_3(p_35),"b--", linewidth=1)

z_4 = np.polyfit(p_50, u_50 / 42.5, deg=1)
polynom_4 = np.poly1d(z_4)
plt.plot(p_50, polynom_4(p_50),"y--", linewidth=1)


plt.legend(fontsize=18, markerscale = 1)
plt.show()

plot_1.savefig(
    'DPDT.pdf',
    format='pdf',
    bbox_inches='tight',
    #pad_inches=4
)