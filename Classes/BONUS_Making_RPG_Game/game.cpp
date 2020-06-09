#include "game.hpp"
#include "heroes/heroes.cpp"
#include "enemies/enemies.cpp"

int main(){
    // Make new heroes in the game
    Environment* env;
    Heroes* warrior = new Warrior("Warrior");
    Heroes* archer = new Archer("Archer");
    Heroes* wizard = new Wizard("Wizard");
    Heroes* hermit = new Hermit("Hermit");
    // Make new enemies in the game
    Enemies* wyvern = new Wyvern();
    Enemies* gollem = new Gollem();
    Enemies* mushroom = new Mushroom(env);
    Enemies* wraith = new Wraith();
    // Put them in new Enviroment!
    env = new Environment(warrior, archer, wizard, hermit, 
                          wyvern, gollem, mushroom, wraith);
    while(true){

    }
    delete warrior, archer, wizard, hermit, gollem, mushroom, wraith, env; 
    return 0;
}