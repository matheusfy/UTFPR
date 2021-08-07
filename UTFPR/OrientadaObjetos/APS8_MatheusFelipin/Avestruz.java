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
public class Avestruz implements Animal{
    private final String classe;
    
    @Override
    public void Habilidade(String algo)
    {
        System.out.println("Avestruz é capaz de : " +algo);
    }
    public Avestruz()
    {   this.classe = "Ave";
    }

    @Override
    public void ClasseAnimal() {
     System.out.println("Avestruz é uma : "+classe);
    }
    
}
