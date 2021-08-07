package aps8;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author MFY
 */
public class Pinguim implements Animal {
    private final String classe = "ave";
    @Override
    public void Habilidade(String algo) {
       System.out.println("Pinguim é capaz de  :" +algo);
    }
    public Pinguim(){
        
    }
    @Override
    public void ClasseAnimal() {
        System.out.println("Pinguim é um :" +classe);
   }
    
}
