#include <iostream>
#include <iomanip>
#include "exec.cpp"


using namespace std;



int main(){

    vector<string> sortNames;
    sortNames.push_back("Seleção");
    sortNames.push_back("Inserção");
    sortNames.push_back("Shell");
    sortNames.push_back("Heap");
    sortNames.push_back("Merge");
    sortNames.push_back("Quick");
    sortNames.push_back("StlSort");
    sortNames.push_back("StlStableSort");
    sortNames.push_back("StlSortHeap");



    cout << "INICIANDO Os TESTES\n";


    int max = 100; //numero de execuções
    double v[36]; //vetor que guardará o somatório dos tempos de execução
    cout << "**Cenário 1: 10000 inteiros de 10^0 a 10^6 gerados aleatóriamente**\n";
    cout << "**Cenário 2: 100000 inteiros de 10^0 a 10^6 gerados aleatóriamente**\n";
    cout << "**Cenário 3: 10000 inteiros ordenados [0, 1, 2, 3...9999]\n";
    cout << "**Cenário 4: 10000 inteiros inversamente ordenados [9999, 9998, 9997 ... 0]\n";


    cout << "De 0 a 8 média de tempos do cenário 1\n";
    cout << "De 9 a 17 média de tempos do cenário 2\n";
    cout << "De 18 a 26 média de tempos do cenário 3\n";
    cout << "De 27 a 35 média de tempos do cenário 4\n";


    //Inicializar o vetor com 0
    for(int k = 0; k<36; k++)
        v[k] = 0;

    //Execuções
    for (int numExec = 0; numExec < max; numExec++)
        exec(v);


    //Calcula a média
    for(int k = 0; k<36; k++){
        v[k] = v[k]/max;
        //Print do nome da ordenação + Médias
        cout << k << " " << sortNames.at(k%9) << ": " << v[k] << endl;
    }

    return 0;

}

