#include "cliente.h"

int Cliente::nextId = 1;

Cliente::Cliente(string tel, string nome){
    this->id = nextId++;
    this->tel = tel;
    this->nome = nome;
}