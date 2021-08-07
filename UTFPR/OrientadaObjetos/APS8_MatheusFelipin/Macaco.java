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
public class Macaco implements Animal{
    private final String classe = "mamifero";
    @Override
    public void Habilidade(String algo) {
       System.out.println("Macaco é capaz de  :" +algo);
   }
    public Macaco(){
        
    }
    @Override
    public void ClasseAnimal() {
      System.out.println("Macaco é um :" +classe);
    }
    
}
