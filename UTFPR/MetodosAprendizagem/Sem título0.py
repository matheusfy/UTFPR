#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Jul  5 10:45:52 2019

@author: matheusfy
"""

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Jul  5 00:03:09 2019

@author: matheusfy
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
import seaborn as sns


iris = datasets.load_iris()
x = iris.data[:, :2]

#%% plot 1-D usando 
plt.figure()
sns.distplot(iris.data[:,1])
plt.show()
#%% usando KDE 1-D

sns.kdeplot(iris.data[:,1], shade=True);


#%% plot 2-D bivariate Gaussian distribution  gráfico 1

from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D

# Our 2-dimensional distribution will be over variables X and Y
N = 120
X = np.linspace(4, 8, N)
Y = np.linspace(2, 4, N)
X, Y = np.meshgrid(X, Y)

# Mean vector and covariance matrix
vetor_medio = np.median(x, axis=0)
Sigma = np.cov(x.T)
#Sigma = np.array([[1,0],[0,1]])
pos = np.empty(X.shape + (2,))
pos[:, :, 0] = X
pos[:, :, 1] = Y

def multivariate_gaussian(pos, mu, Sigma):
    """Return the multivariate Gaussian distribution on array pos.

    pos is an array constructed by packing the meshed arrays of variables
    x_1, x_2, x_3, ..., x_k into its _last_ dimension.

    """
    n = mu.shape[0]
    Sigma_det = np.linalg.det(Sigma)
    Sigma_inv = np.linalg.inv(Sigma)
    N = np.sqrt((2*np.pi)**n * Sigma_det)
    # This einsum call calculates (x-mu)T.Sigma-1.(x-mu) in a vectorized
    # way across all the input variables.
    fac = np.einsum('...k,kl,...l->...', pos-mu, Sigma_inv, pos-mu)

    return np.exp(-fac / 2) / N

# The distribution on the variables X, Y packed into pos.
Z = multivariate_gaussian(pos, vetor_medio, Sigma)

# Create a surface plot and projected filled contour plot under it.
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_surface(X, Y, Z, rstride=3, cstride=3, linewidth=1, antialiased=True,
                cmap=cm.viridis)

cset = ax.contourf(X, Y, Z, zdir='z', offset=-0.15, cmap=cm.viridis)

# Adjust the limits, ticks and view angle
ax.set_zlim(-0.15,0.2)
ax.set_zticks(np.linspace(0,0.2,5))
ax.view_init(27, -21)

plt.show()




#%%   plots da gaussiana de cada caracteristica no canto
mean = np.mean(x,axis = 0)
cov = np.cov(x.T)
#mean, cov = [0, 1], [(1, .5), (.5, 1)]
data = np.random.multivariate_normal(mean, cov, 200)
df = pd.DataFrame(data, columns=["sepal length", "sepal width"])

sns.jointplot(x="sepal length", y="sepal width", data=df, kind="kde");

#%%

g = sns.jointplot(x="sepal length", y="sepal width", data=df, kind="kde", color="b")
g.plot_joint(plt.scatter, c="w", s=30, linewidth=1, marker="x")
g.ax_joint.collections[0].set_alpha(0)
g.set_axis_labels("$sepal length$","$sepal width$");