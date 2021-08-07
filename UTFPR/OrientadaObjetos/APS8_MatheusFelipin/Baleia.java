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
public class Baleia implements Animal{
    private final String classe ;
    private  String Tipo ;
    @Override
    public void Habilidade(String algo) {
        System.out.println("Baleia é capaz de : " +algo);
    }
    public Baleia()
    {
       this.classe = "mamifero";
       this.Tipo = "orca";
       
    }
    @Override
    public void ClasseAnimal() {
        System.out.println("Baleia é um :" +classe);
    }
    
    
}
