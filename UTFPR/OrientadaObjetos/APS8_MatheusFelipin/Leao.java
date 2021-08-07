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
public class Leao implements Animal {
    private final String classe = "mamifero";
    private String CorPelo ;
    @Override
    public void Habilidade(String algo) {
      System.out.println("Leao é capaz de  :" +algo);
   }
    public Leao(){
        this.CorPelo = "marrom";
    }
    @Override
    public void ClasseAnimal() {
      System.out.println("Leao é um :" +classe);
    }
    
}
