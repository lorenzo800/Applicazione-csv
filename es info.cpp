#include <iostream>
#include <string>
using namespace std;

struct Info{
string ClasseToponimo;	
string DescrizioneToponimo	
int Numero;
string Subalterno;
int CAP;	
int SezioneISTAT;	
double Lat;	
double Lon;	
double Location;
	
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
		
	
	return 0;
}   //prendere il file. prendee il contenuto e metterli qui
