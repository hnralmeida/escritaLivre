/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kimetsu;

/**
 *
 * @author 2021122760046
 */
public class Simples extends Oni{

    public Simples(String name) {
        super(name, 10, 100);
    }

    @Override
    public void atacar(Oni obj) {
        if(obj.check() == 1){
            switch(obj.getClass().getSimpleName()){
                case "Simples":
                    obj.perderEnergia(this.getPoder());
                    break;
                case "LuaSuperior":
                    break;
                case "LuaInferior":
                    break;
            }
        }        
    }
    
}
