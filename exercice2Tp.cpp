#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Reservation {
	private :
		int numero;
		string nom;
		int duree;
	public :
		void saisir(){
			cout <<"entrer le numero :";
			cin >> numero;
			cin.ignore();
			cout <<"entrer le nom :";
            getline(cin,nom);			
            cout <<"entrer la duree :";  
			cin >> duree;	
		}
		void afficher (){
			cout<<"le numero de place est :"<<numero<<endl;
			cout<<"le nom de client est :"<<nom<<endl;
			cout<<"la  duree en heures est :"<<duree<<endl;
		}
		int getNumero(){
			return numero;
		}
		string getNom(){
			return nom;
		}
		int getDuree(){
			return duree;
		}
};

int main(){
	vector<Reservation>reservations;
	int nbrRes;
	int numrechercher;
	
	cout<<"entrer le nombre de reservation enregistre:";
	cin>>nbrRes;
	
	for (int i =0;i<nbrRes;i++){
		cout<<"reservation "<<(i+1)<<":"<<endl;
		Reservation reservation;
		reservation.saisir();
		reservations.push_back(reservation);
	}
	
	cout<<"liste des reservations:"<<endl;
	for (int i = 0; i < reservations.size(); i++){
		reservations[i].afficher();
	}
	
	int totleDuree=0;
	for (int i = 0; i < reservations.size(); i++){
        totleDuree+=reservations[i].getDuree();	
	}  
	cout<<"la duree totale des reservations:"<<totleDuree<<endl;
    
    cout << "Entrer le numero de place a rechercher : ";
    cin >> numrechercher;
    
    bool trouve =false;
    for (int i = 0; i < reservations.size(); i++){
		if (reservations[i].getNumero()== numrechercher){
			cout << "Place reservee par : " << reservations[i].getNom() << endl;
			trouve=true;
			break;
		}
	}
	if (!trouve){
		cout<<"place libre"<<endl;
	}
    
    int placeASupprimer;
    cout << "\nNumero de place a supprimer : ";
    cin >> placeASupprimer;	
    
	for (vector<Reservation>::iterator it=reservations.begin();it!=reservations.end();++it){
		if (it->getNumero()==placeASupprimer){
			it = reservations.erase(it);
			cout << "Reservation supprimee" << endl;
			break;  
		}
		
	}
    
    cout << "\nListe apres suppression " << endl;
    for (int i = 0; i < reservations.size(); i++) {
        reservations[i].afficher();
    }
 	
	cout << "\nAjout d'une nouvelle reservation " << endl;
    Reservation nouvelle;
    nouvelle.saisir();
    reservations.push_back(nouvelle);
    
    if (!reservations.empty()) {  
        Reservation plusLongue = reservations[0];  
        for (int i = 0; i < reservations.size(); i++) {
            if (reservations[i].getDuree() > plusLongue.getDuree()) {
                plusLongue = reservations[i];
            }
        }
        cout << "\nClient avec la duree la plus longue : " << endl;
        plusLongue.afficher();
    }
    
    return 0;  
}
