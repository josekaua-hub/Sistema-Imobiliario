#include "imovel.h"
using namespace std;

int Imovel::nextId = 1;

Imovel::Imovel(string tipimo,int propId,double lat,double lon, double preco, string ende){
    this->id = nextId++;
    this->propId = propId ;
    this->lat = lat;
    this->lon = lon;
    this->preco = preco; 
    this->ende = ende;


    if(tipimo == "Casa" || tipimo == "casa" ){
        this->tipo = Timovel::Casa ;
    }else if (tipimo == "Apartamento" || tipimo == "apartamento")
    {
        this->tipo = Timovel::Apartamento ;
    }else if (tipimo == "Terreno" || tipimo == "terreno")
    {
        this->tipo = Timovel::Terreno ;
    }else{
        this->tipo = Timovel::Casa;
    }
    
    
}