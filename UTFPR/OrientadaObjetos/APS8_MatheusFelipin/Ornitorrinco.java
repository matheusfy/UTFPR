package aps8;


import aps8.Animal;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author MFY
 */
public class Ornitorrinco implements Animal {
        private final String classe = "mamifero";
    @Override
    public void Habilidade(String algo) {
   System.out.println("Ornitorrinco é capaz de  :" +algo);
    }
    public Ornitorrinco(){
        
    }
    @Override
    public void ClasseAnimal() {
     System.out.println("ornitorrinco é um :" +classe);
   }
    
}
