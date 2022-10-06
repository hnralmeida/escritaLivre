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
public class LuaInferior extends Oni{
    public LuaInferior(String name, int poder) {
        super(name, poder, 200);
    }

    @Override
    public void atacar(Oni obj) {
        if(obj.check() == 1){
            switch(obj.getClass().getSimpleName()){
                case "Simples":
                    obj.perderEnergia(this.getPoder());
                    break;
                case "LuaSuperior":
                    obj.perderEnergia((int) (0.1*this.getPoder()));
                    break;
                case "LuaInferior":
                    obj.perderEnergia((int) (0.5*this.getPoder()));
                    break;
            }
        }
    }
}
