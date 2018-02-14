#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iterator>

const int ENTER = 1; 
const int EXIT = 0;
const int MAX_REGISTROS = 1000;


using namespace std;

uint32_t numero_casos;
uint32_t precio_hora[24];

class Registro_coche  {
    public:
    string matricula, fecha;
    uint32_t kilometros;
    int accion;

    Registro_coche(string, string, uint32_t, int);
};

Registro_coche::Registro_coche (string mat, string fe, uint32_t km, int acc){
    matricula = mat;
    fecha = fe;
    kilometros = km;
    accion = acc;
}

vector<Registro_coche> registros(MAX_REGISTROS);

int main(){

cin >> numero_casos;
cout << "Numero de casos: " << numero_casos << endl;

    for (int caso = 0; caso < numero_casos; caso++){
        for(int i = 0; i < 24; i++){
            cin >> precio_hora[i];
        }
        string line;
        getline(cin, line);
        do{
            getline(cin, line);
            istringstream iss(line);
            vector<string> results(istream_iterator<string>{iss},
                                    istream_iterator<string>());
            for (string s : results){
                cout << "vector: " << s << endl;
            }

            registros.push_back(Registro_coche(results[0],results[1],stoi(results[2]),stoi(results[3])));
        }while(line != "");

        
    }
}