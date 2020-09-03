#include <iostream>
#include <string>

using namespace std;

class Band {
  // MEMBERS
  private:
    string drum = "Drum!!"; 
    string bass = "BASS~";
    string guitar = "Guitar~";
    string vocal = "vocal~";

  public: 
    Band();
    Band(string drum, string bass, string guitar, string vocal);
    ~Band();
    void FightDrumAndBass();
    void LoveBassandGuitar();
    friend void printMembers(Band* skynote);
};

Band::Band() {
  cout << "Constructed" << endl;
}

Band::Band(string drum, string bass, string guitar, string vocal){
  cout << "Constructed" << endl;
  this->drum = drum; 
  this->bass = bass; 
  this->guitar = guitar; 
  this->vocal = vocal;
}


Band::~Band(){
  cout << "Destructed!" << endl;
}

void Band::FightDrumAndBass(){
      cout << drum << " and " << bass << " are fighting!! " << endl;
      return;
    }


void Band::LoveBassandGuitar(){
  cout << bass << " loves " << guitar << " !! " << endl;
  return;
}


void printMembers(Band* skynote){
  cout << skynote->drum << endl;
  cout << skynote->bass << endl;
  cout << skynote->guitar << endl;
  cout << skynote->vocal << endl;
}

int main(){
  Band* skynote = new Band("Jangho", "Seonghoon", "YoonKwon", "Minwook");
  Band* mirinae = new Band();
  printMembers(skynote);
  printMembers(mirinae);
  skynote->FightDrumAndBass();
  skynote->LoveBassandGuitar();
  mirinae->FightDrumAndBass();
  mirinae->LoveBassandGuitar();
  delete skynote; delete mirinae;
  return 0;
}
