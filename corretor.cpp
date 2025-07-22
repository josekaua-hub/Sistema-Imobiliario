#include "corretor.h"

using namespace std;

int Corretor::nextId = 1;

Corretor::Corretor(string tel, bool aval, double lat, double lon, string nome){
      this->id = nextId++;
    this->tel = tel;
    this->aval = aval;
    this->lat = lat;
    this->lon = lon;
    this->nome = nome;

}