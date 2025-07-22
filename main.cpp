#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include "cliente.h"
#include "imovel.h"
#include "corretor.h"

#include <cmath>
#ifndef M_PI
#define M_PI 3.14
#endif

using namespace std;



constexpr double EARTH_R = 6371.0; // Raio da Terra em km

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

struct Visita
{
    string horario;
    int imovelId;
};


int main(){


// Leitura dos dados dos corretores
vector<Corretor> corretores;
int n;
cin >> n;

for (int i = 0; i < n; i++) {
    string tel, nome;
    int aval;
    double lat, lon;

    cin >> tel >> aval >> lat >> lon;
    getline(cin >> ws, nome); 

     corretores.emplace_back(tel, aval, lat, lon, nome);
}

//Leitura dos clientes
vector<Cliente> cliente;
cin>>n;

for (int i = 0; i < n; i++)
{
      string tel, nome;
      cin >> tel;
      getline(cin >> ws, nome);
      cliente.emplace_back(tel, nome);
}

//Leitura dos imóveis
vector<Imovel> imovel;

cin >> n;

for (int i = 0; i < n; i++)
{
      string tipo, ende;
      int propId;
      double lat,lon,preco;
      cin>> tipo >> propId >> lat >> lon >> preco;
      getline(cin >> ws, ende);

      imovel.emplace_back(tipo, propId, lat, lon, preco, ende);
}



//filtrar avaliadores
 vector<Corretor> avaliadores;
    for (Corretor c : corretores) {
        if (c.aval == 1)
            avaliadores.push_back(c);
    }



 // Distribuir imóveis por round-robin
    sort(imovel.begin(), imovel.end(), [](Imovel a, Imovel b) { return a.id < b.id; });
    vector<vector<Imovel>> imoveisPorCorretor(avaliadores.size());
    for (int i = 0; i < imovel.size(); i++) {
        imoveisPorCorretor[i % avaliadores.size()].push_back(imovel[i]);
    }

    // Agendamento por vizinho mais próximo
    vector<vector<Visita>> agenda(avaliadores.size());
    for (int i = 0; i < avaliadores.size(); i++) {
        Corretor& cor = avaliadores[i];
        vector<Imovel> lista = imoveisPorCorretor[i];

        double lat = cor.lat, lon = cor.lon;
        int minutos = 9 * 60; // 09:00

        while (!lista.empty()) {
            int idx = 0;
            double menor = haversine(lat, lon, lista[0].lat, lista[0].lon);
            for (int j = 1; j < lista.size(); j++) {
                double d = haversine(lat, lon, lista[j].lat, lista[j].lon);
                if (d < menor) {
                    menor = d;
                    idx = j;
                }
            }

            Imovel alvo = lista[idx];
            lista.erase(lista.begin() + idx);
            int deslocamento = (int)(menor * 2);
            minutos += deslocamento;

            char hora[6];
            sprintf(hora, "%02d:%02d", minutos / 60, minutos % 60);
            agenda[i].push_back({hora, alvo.id});

            minutos += 60;
            lat = alvo.lat;
            lon = alvo.lon;
        }
    }

    // Impressão final
    for (int i = 0; i < avaliadores.size(); i++) {
        cout << "Corretor " << avaliadores[i].id << endl;
        for (Visita v : agenda[i]) {
            cout << v.horario << " Imovel " << v.imovelId << endl;
        }
        cout << endl;
    }
return 0;
}