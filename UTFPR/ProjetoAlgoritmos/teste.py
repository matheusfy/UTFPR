#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep  2 10:22:03 2019

@author: matheusfy
"""
import numpy as np


arquivo = open("/home/matheusfy/Documentos/myProject/UTFPR/ProjetoAlgoritmos/frb30-15-mis/frb30-15-1.mis", "r")
lista = load(arquivo)

#%%

def load(arquivo):
    lista = arquivo.read().split('\n')
    informacao = lista.pop(0)
    print(lista[len(lista)-1])
    lista.pop(len(lista)-1)
    
    return lista
    
    
    
