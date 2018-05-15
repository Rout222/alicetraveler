#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

bool achaCaminho (int * matrizCaminho, int * matrizAdj, int n, int origem, int destino, int contador , int pai){
    if(matrizAdj[origem*n+destino] == 1){
        matrizCaminho[contador] = origem;
        return true;
    }
    cout << contador << endl;
    for (int i = 0; i < n; ++i)
    {
        if(matrizAdj[origem*n+i] == 1 && i != pai){
            if(achaCaminho(matrizCaminho,matrizAdj, n, i, destino, contador+1, origem)){
                matrizCaminho[contador] = origem;
                return true;
            }
        }
    }
}


void Busca(int * matrizAdj, int n, int origem, int destino){
    int matrizCaminho[n];
    for (int i = 0; i < n; ++i)
    {
        matrizCaminho[i] = -1;
    }

    achaCaminho(matrizCaminho, matrizAdj, n, origem, destino, 0, -1);

    for (int i = 0; i < n; ++i)
    {
        cout << matrizCaminho[i] << " | ";
    }
}



int main()
{
    string line;
    ifstream myfile ("inputfile.txt");
    int x,y;
    int n; // numero de cidade
    int k; // dollars
    if(myfile.is_open()){
        myfile >> n;
        myfile >> k;
        int matrizAdjacencia[n*n];
        int gemCost[n]; // custo
        int bright[n]; // brilho
        int numInqueries; // numero de viagens
        for (int i = 0; i < n*n; i++)
        {
            matrizAdjacencia[i] = 0;
        }    
        for (int i = 0; i < n; ++i)
        {
            matrizAdjacencia[i * n + i] = 1;
        }

        for (int i = 0; i < (n-1); i++)
        {
            myfile >> x;
            myfile >> y;
            matrizAdjacencia[(x-1)*n+(y-1)] = 1;
            matrizAdjacencia[(y-1)*n+(x-1)] = 1;
        }

        // for (int i = 0; i < n*n; ++i)
        // {
        //     cout << " \t" << matrizAdjacencia[i];
        //     if(i%n == n-1)
        //         cout << endl;
        // }

        for (int i = 0; i < n; i++)
        {
            myfile >> gemCost[i];

        }
        for (int i = 0; i < n; i++)
        {
            myfile >> bright[i];
        }

        myfile >> numInqueries;
        int travels[numInqueries][2]; // viagens x pra y
        for (int i = 0; i < numInqueries; i++)
        {
            myfile >> travels[i][0];
            myfile >> travels[i][1];
        }

        for (int i = 0; i < numInqueries; ++i)
        {
            Busca(matrizAdjacencia, n, travels[i][0]-1, travels[i][1]-1);
        }
    }
    myfile.close();






    return 0;
}


    // #pragma omp parallel for reduction(+:area)