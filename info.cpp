#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct DatiAggiuntivi {
    string clTop;
    string descTop;
    string num;
    string sub;
    string cap;
    string istat;
};

struct Geo {
    float lt;
    float ln;
    string loc;
};

struct Elemento {
    DatiAggiuntivi a;
    Geo g;
};

int main() {
    Elemento db[1000]; 
    int n = 0;       
    int x;            
    do {
        cout << "1-carica i primi 1000 record dal file" << endl;
        cout << "2-visualizza i dati in memoria" << endl;
        cout << "3-cerca via e mostra in ordine di numero crescente" << endl;
        cout << "0-esci dal programma" << endl;
        cout << "inserisci la tua scelta: ";
        cin >> x;

        switch (x) {
            case 1: {
                n = 0; 
                ifstream f("dati.txt");
                if (!f.is_open()) {
                    cout << "impossibile aprire il file" << endl;
                } else {
                    while (n < 1000 && 
                           f >> db[n].a.clTop 
                             >> db[n].a.descTop
                             >> db[n].a.num
                             >> db[n].a.sub
                             >> db[n].a.cap
                             >> db[n].a.istat
                             >> db[n].g.lt
                             >> db[n].g.ln
                             >> db[n].g.loc) {
                        n++;
                    }
                    f.close();
                    cout << "dati caricati" << endl;
                }
                break;
            }
            case 2: {
                if (n == 0) {
                    cout << "memoria vuota carica i dati con 1" << endl;
                } else {
                    for (int i = 0; i < n; i++) {
                        cout << "record " << i + 1 << endl;
                        cout << "classe toponimo: " << db[i].a.clTop << endl;
                        cout << "descrizione: " << db[i].a.descTop << endl;
                        cout << "numero: " << db[i].a.num << endl;
                        cout << "subalterno: " << db[i].a.sub << endl;
                        cout << "CAP: " << db[i].a.cap << endl;
                        cout << "sezione ISTAT: " << db[i].a.istat << endl;
                        cout << "latitudine: " << db[i].g.lt << endl;
                        cout << "longitudine: " << db[i].g.ln << endl;
                        cout << "location: " << db[i].g.loc << endl;
                        cout << "------------------------------------------" << endl;
                    }
                }
                break;
            }
            case 3: {
                if (n == 0) {
                    cout << "memoria vuota carica i dati con 1" << endl;
                } else {
                    string v; 
                    cout << "inserisci il nome della via da cercare: ";
               cin >> v;

                    Elemento res[1000]; 
                    int c = 0;       

               for (int i = 0; i < n; i++) {
                        if (db[i].a.descTop == v) {
                            res[c] = db[i];
                            c++;
                        }
                    }

                    if (c == 0) {
                        cout << "nessun record trovato per la via: " << v << endl;
                    } else {
                        cout << "trovati " << c << " record per la via " << v << endl;
                        
                        
              for (int i = 0; i < c - 1; i++) {
                    for (int j = 0; j < c - i - 1; j++) {
                                if (res[j].a.num > res[j + 1].a.num) {
                         Elemento t = res[j];
                                    res[j] = res[j + 1];
                                    res[j + 1] = t;
                       }
                      }
                      }
                 for (int i = 0; i < c; i++) {
                        cout << "civico: " << res[i].a.num 
                                << " classe: " << res[i].a.clTop
                                << " CAP: " << res[i].a.cap 
                                << " posizione latitudine: " << res[i].g.lt 
                             << ", posizione longitudine: " << res[i].g.ln << endl;
                       }
                    }
                }
                break;
            }
            case 0:
                cout << "uscita programma" << endl;
                break;
            default:
                cout << "scelta non valida rifai" << endl;
                break;
        }
    } while (x != 0);

    return 0;
}