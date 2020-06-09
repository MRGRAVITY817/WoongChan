#ifndef WIZARD_CPP
#define WIZARD_CPP

#include "./heroes.cpp"

Wizard::Wizard(const char _name[]) 
: Heroes(_name, 75.0f, 7) {
    maxHealth = 75;
}

Wizard::~Wizard() {}

void Wizard::charm(Enemies* E1, Enemies* E2, Enemies* E3){
    if(isMagicable(1)){
        int wizardAttack = intelligence * 0.1 * attackPoint;
        cout << "The Wizard gave " << wizardAttack << " points of damage to "
        << E1->getName() << " "
        << E2->getName() << " "
        << E3->getName() << " !" << endl;
        magicka -= 10;
        E1->damaged(wizardAttack);
        E2->damaged(wizardAttack);
        E3->damaged(wizardAttack);
    }
    else {}
}

void Wizard::healHero(Heroes* H){
    if(isMagicable(2)) {
        magicka -= 20;
        int healPoint = intelligence * 0.2 * attackPoint;
        cout << "The Wizard healed " << H->getName() << " with " << healPoint << " points." << endl;
        H->healed(healPoint);
    }
    else {}
}

void Wizard::ressurection(float luck, Heroes* H) {
    if(!isMagicable(3) && H->getHealth()>0) return;
    
    cout << "Ressurection is risky. Without luck, you might lose your life. " << endl;
    cout << "Still want to ressurect your friend? (Y/n) : " ;
    char choice; cin >> choice;
    if(choice=='Y' || choice=='y') {
        magicka -= 30;
        if(luck<33) {
            cout << "Ressurection Failed and also ... the Wizard died :(" << endl;
            setHealth(0); beDead();
        }
        else if(luck>=33 && luck<66) {
            cout << "Ressurection Succeeded ... but the Wizard died :(" << endl;
            H->setHealth(50.0f); 
            setHealth(0); beDead();
        }
        else {
            cout << "Ressurection Succeeded ... and also the Wizard is alive!" << endl;
            H->setHealth(50.0f);
        }
    }
    else {}
} 

void Wizard::meditate() {
    if(magicka==maxMagicka){
        cout << "Magicka Full" << endl;
        return;
    }
    cout << "Meditating..." << endl;
    if(magicka+20 >= maxMagicka){
        magicka = maxMagicka;
    }
    else
        magicka += 20;
}

bool Wizard::isMagicable(int skill) {
    switch(skill){
        case 1:
            if(magicka>=10){
                cout << "Charm skill Ready. " << endl;
                return true;
            }
            else{
                cout << "Not enough Magicka for Charm (10 needed). " << endl;
                return false;
            }
        case 2:
            if(magicka>=20){
                cout << "Heal skill Ready. " << endl;
                return true;
            }
            else{
                cout << "Not enough Magicka for Heal (20 needed). " << endl;
                return false;
            }
        case 3:
            if(magicka>=30){
                cout << "Ressurection skill Ready. " << endl;
                return true;
            }
            else{
                cout << "Not enough Magicka for Ressurection (30 needed). " << endl;
                return false;
            }
    }    
    return false;
}

void Wizard::printStatus(){
    cout << name << " "
         << "HP: " << health << "/" << maxHealth << " "
         << "SP: " << shieldPoint << "/" << maxShieldPoint << " ";
    if(!isAlive){
        cout << "[DEAD]" << endl;
        return;
    }
    cout << "MP: " << magicka << "/" << maxMagicka << " ";
    // Defensing status
    cout << endl;
}
#endif