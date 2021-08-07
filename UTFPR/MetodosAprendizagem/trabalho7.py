#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 23:37:35 2019

@author: matheusfy
"""
#%% trab 7.1

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets


df = pd.read_csv('/home/matheusfy/Downloads/Base.csv', ',')
df['Rotulo'] = pd.factorize(df['Rotulo'])[0]
df['Sabor'] = pd.factorize(df['Sabor'])[0]
df['Cor_f'] = pd.factorize(df['Cor_f'])[0]
df['Cor_d'] = pd.factorize(df['Cor_d'])[0]
df['Textura'] = pd.factorize(df['Textura'])[0]
x = df.iloc[:, 1:]
x = x.drop(axis = 1,labels = 'Textura')
x = x.drop(axis = 1,labels = 'Cor_f')


#%% plot matrix de correlacao 
plt.style.use('ggplot')


plt.imshow(x.corr(), cmap=plt.cm.Reds, interpolation='nearest')
plt.colorbar()
tick_marks = [i for i in range(len(x.columns))]
plt.xticks(tick_marks, x.columns, rotation='horizontal')
plt.yticks(tick_marks, x.columns)
plt.show()


#%%

plt.matshow(x.corr())
plt.xticks(range(len(x.columns)), x.columns)
plt.yticks(range(len(x.columns)), x.columns)
plt.colorbar()
plt.show()



#%%  pegando base de dados da iris
iris = datasets.load_iris()
x = iris.data[148:, :]
#k = pd.DataFrame(x)
from numpy.linalg import pinv
import math
from scipy.spatial import distance

#%% calculado com funcao do scipy

#x = x[18:,1:3].values

x2 = np.cov(x, rowvar = False) 
x2inv = pinv(x2)
distance.mahalanobis(x[0], x[1],x2inv )

#%% calculado na mao

diferenca = x[0] - x[1]
covarianceMatrix = np.cov(x.T)
covarianceIMatrix = pinv(covarianceMatrix)
mahal = np.dot(np.dot(diferenca,covarianceIMatrix), diferenca)
math.sqrt(mahal)
