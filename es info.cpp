#include <iostream>
#include <string>
using namespace std;

struct Info{
string ClasseToponimo;	
string DescrizioneToponimo;	
string Numero;
string Subalterno;
string CAP;	
string SezioneISTAT;	
float Lat;	
float Lon;	
float Location;
	
};
          	
void caricadati(info x[]; string a){
	
	//vedere se il file esiste se esiste
 ifstream fileInput("testo.txt"); 
    string linea;

    if (fileInput.is_open()) {
        while (fileInput>>linea){ 
            cout << linea << '\n';
        }
        fileInput.close(); 
    } else {
        cout << "Impossibile aprire il file";
    }
    
}


int main(int argc, char** argv) {
	
	int x;
	
	cout<<"menù:"<<endl;
	cout<<"1:aggiunge dati"<<endl;
	cout<<"2:visualizza i dati"<<endl;
	cout<<"inserire la funzione desiderata:"<<endl;
	
	cin>>x;
	
	switch(x){
	case 1:
	case 2:		
	}
	
	
	
	
	
	
	
	return 0;
}   //prendere il file. prendee il contenuto e metterli qui

