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
public class Arara implements Animal{
    private final String Classe ;
    
    public Arara()
    {
        this.Classe = "ave";
    }
    @Override
    public void Habilidade(String algo)
    {
        System.out.println("Arara é capaz de : " + algo);
    }

    @Override
    public void ClasseAnimal() {
    System.out.println("Arara e uma " +Classe);
    }
    
}
