#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iterator>



using namespace std;

uint32_t numero_casos;
uint32_t precio_hora[24];

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
        }while(line != "");

        cout << "FIN" << endl;
    }
}