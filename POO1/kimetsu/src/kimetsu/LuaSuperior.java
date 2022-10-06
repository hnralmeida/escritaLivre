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
public class LuaSuperior extends Oni{
    public LuaSuperior(String name, int poder) {
        super(name, poder, 300);
    }

    @Override
    public void atacar(Oni obj) {
        if(obj.check() == 1){
            switch(obj.getClass().getSimpleName()){
                case "Simples":
                    obj.setEnergia(0);
                    break;
                case "LuaSuperior":
                    obj.perderEnergia(this.getPoder());
                    break;
                case "LuaInferior":
                    obj.setEnergia(0);
                    break;
            }
        }
    }
}
