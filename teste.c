#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;


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
        int matrizAdjacencia[n][n];
        int gemCost[n]; // custo
        int bright[n]; // brilho
        int numInqueries; // numero de viagens
        for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrizAdjacencia[i][j] = 0;
                }
            }    

        for (int i = 0; i < (n-1); i++)
        {
            myfile >> x;
            myfile >> y;
            matrizAdjacencia[x][y] = 1;
        }

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

    }
    myfile.close();


    cout << "a" << endl;

    return 0;
}
    // #pragma omp parallel for reduction(+:area)