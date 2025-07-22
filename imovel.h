#pragma once
#include <string>

using namespace std;

enum class Timovel{
    Casa,
    Apartamento,
    Terreno
};

class Imovel{
    private:
      static int nextId;

    public:
        int id;
        Timovel tipo;
        int propId;
        double lat;
        double lon;
        double preco;
        string ende;

        Imovel(string tipimo,int propId,double lat,double lon, double preco, string ende);
};