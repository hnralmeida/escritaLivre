/*
*   =========================================================================================
*   AUTORES: 	
*   			Henrique Almeida de Oliveira

*   Disciplina: Programacao Orientada a Objetos
*   Trabalho de POO1 - Camadas
*   =========================================================================================
*/

package domain;

import java.io.Serializable;


public class Pokemon implements Serializable {
    private String code, name, types;
    private int hp, attack, defense;
    private float spAtk;
    
    public int getHp() {
        return hp;
    }

    public void setHp(int hp) {
        this.hp = hp;
    }

    public int getAttack() {
        return attack;
    }

    public void setAttack(int attack) {
        this.attack = attack;
    }

    public int getDefense() {
        return defense;
    }

    public void setDefense(int defense) {
        this.defense = defense;
    }

    public float getSpAtk() {
        return spAtk;
    }

    public void setSpAtk(float spAtk) {
        this.spAtk = spAtk;
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public String getTypes() {
        return types;
    }

    public void setTypes(String types) {
        this.types = types;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

}
