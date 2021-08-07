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
public class Gato implements Animal {
    private final String classe = "mamifero";
    private String raca ;
    @Override
    public void Habilidade(String algo) {
     System.out.println("Gato é capaz de : " +algo);
    }
    public Gato(){
        this.raca = "seimes";
    }

    @Override
    public void ClasseAnimal() {
        System.out.println("Gato é um :" +classe);
    }
    
}
