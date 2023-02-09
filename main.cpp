#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Item{
public:
    virtual int get_categorie()=0;
    virtual string get_nom()=0;
    virtual int get_niveau()=0;
    virtual int get_prix()=0;
    virtual int get_force()=0;
    virtual int get_defense()=0;
    virtual int get_soins()=0;
};

class Personnage{
private:
    string nom;
    int level;
    int force;
    int defense;
    int soin;
    int argent;
public:
    vector<Item*>magasin;
    vector<Item*>inventaire;

    static void show_item(Item* item){
        cout << item->get_nom() << ": " << "attaque +" << item->get_force() << ", defence +" << item->get_defense() << ", soins +" << item->get_soins() << ", niveau: " << item->get_niveau() << ", prix: " << item->get_prix() << "$" << endl;
    }

    Personnage(string nom,int nv,int fort,int def,int soin, int argent){
        this -> nom = nom;
        this -> level = nv;
        this -> force = fort;
        this -> defense = def;
        this -> soin = soin;
        this -> argent = argent;
    }

    void add_magasin(Item* item){
        magasin.push_back(item);
    }

    void add_inventaire(Item* item){
        inventaire.push_back(item);
    }

    static bool money_compatible(Item* item, Personnage* personnage) {
        if (personnage->argent >= item->get_prix()) {
            return true;
        }
        return false;
    }

    static void paiment(Item* item, Personnage* personnage){
        int personnage_argent = personnage -> argent;
        int item_prix = item->get_prix();
        personnage -> argent = personnage_argent - item_prix;
    }

    static void show_money(Personnage* personnage){
        cout << "Il vous reste: " <<personnage -> argent << "$" <<endl;
    }

    static bool level_compatible(Item* item, Personnage* personnage){
        if (personnage->level >= item->get_niveau()) {
            return true;
        }
        return false;
    }
};

class Arme : public Item {
private:
    string nom;
    int force;
    int niveau;
    int prix;
public:
    Arme (string nom , int force ,int niveau, int prix){
        this -> nom = nom;
        this -> force = force;
        this -> niveau = niveau;
        this -> prix = prix;
    }
    virtual int get_categorie(){
        return 1;
    }

    virtual string get_nom(){
        return nom;
    }
    virtual int get_force(){
        return force;
    }
    virtual int get_niveau(){
        return niveau;
    }
    virtual int get_prix(){
        return prix;
    }
    virtual int get_defense(){
        return 0;
    }
    virtual int get_soins(){
        return 0;
    }
};

class Armure : public Item{
    string nom;
    int defense;
    int niveau;
    int prix;
public:
    Armure(string nom, int defense, int niveau, int prix){
        this -> nom = nom;
        this -> defense = defense;
        this -> niveau = niveau;
        this -> prix = prix;
    }
    virtual int get_categorie(){
        return 2;
    }

    virtual string get_nom(){
        return nom;
    }
    virtual int get_defense(){
        return defense;
    }

    virtual int get_niveau(){
        return niveau;
    }
    virtual int get_prix(){
        return prix;
    }
    virtual int get_force(){
        return 0;
    }
    virtual int get_soins(){
        return 0;
    }
};

class Talisman : public Item{
    string nom;
    int soins;
    int niveau;
    int prix;
public:
    Talisman(string nom, int soins, int niveau, int prix){
        this -> nom = nom;
        this -> soins = soins;
        this -> niveau = niveau;
        this -> prix = prix;
    }
    virtual int get_categorie(){
        return 1;
    }
    virtual string get_nom(){
        return nom;
    }

    virtual int get_soins(){
        return soins;
    }

    virtual int get_niveau(){
        return niveau;
    }
    virtual int get_prix(){
        return prix;
    }
    virtual int get_defense(){
        return 0;
    }
    virtual int get_force(){
        return 0;
    }
};

int main(){
    std::vector<int> IndexItemBuy={0,1,3,5,4,2}; // attention au indice si 6 item vendu l'indice max 5
    Personnage personnage("Steve", 5, 10, 10, 10, 2500);
    personnage.add_magasin(new Arme("epee de la muerte", 10, 10, 1000));
    personnage.add_magasin(new Arme("epee en bois", 2, 2, 200));
    personnage.add_magasin(new Armure("armure de la muerte", 10, 6, 1000));
    personnage.add_magasin(new Armure("toge de peon", 1, 1, 100));
    personnage.add_magasin(new Talisman("talisman de la muerte", 10, 3, 100));
    personnage.add_magasin(new Talisman("talisman des dieux anciens", 50, 5, 2000));
    cout << "Marchant :\"Hey bienvenue dans mon magasin jeune aventurier, voici ce que je vends: \""<< endl;
    for (int i=0; i < personnage.magasin.size(); i++){
        cout<< i+1 << ") ";
        personnage.show_item(personnage.magasin[i]);
    }
    cout<< "\n"<<endl;

//partie achat
    for (int i=0; i < IndexItemBuy.size(); i++){
        if (IndexItemBuy[i] > IndexItemBuy.size()){ //securite pour eviter de tout casser
            cout<< "erreur d'indice dans la liste IndexItemBuy";
            return 1;
        }
        cout << personnage.magasin[IndexItemBuy[i]]->get_nom() ;
        if (personnage.money_compatible(personnage.magasin[IndexItemBuy[i]], &personnage)){
            cout << " -" << personnage.magasin[IndexItemBuy[i]]->get_prix() << "$ " ;
            personnage.add_inventaire((personnage.magasin[IndexItemBuy[i]]));
            personnage.paiment(personnage.magasin[IndexItemBuy[i]], &personnage);
            personnage.show_money(&personnage);
        }else{
            cout<< "\n/!\\ Marchant :\"Tu n'as pas assez d'argent malandrin\" /!\\"<<endl ;
        }
    }
    cout<< "Vous quittez le magasin\nMarchant :\"Je suis ravi d'avoir fait affaire avec toi... A la prochaine!!\"\n\n\nInventaire :" <<endl;

//partie affichage inventaire
    personnage.show_money(&personnage);
    for (int j=0; j < personnage.inventaire.size(); j++){
        personnage.show_item(personnage.inventaire[j]);
        if(personnage.level_compatible(personnage.inventaire[j], &personnage)){
            cout << "Equipable"<<endl;
        }else{
            cout << "/!\\ Non Equipable niveau trop faible/!\\"<< endl;
        }
    }
    return 0;
}