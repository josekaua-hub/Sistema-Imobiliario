#pragma once

#include <string>
using namespace std;
class Cliente{
private:
    static int nextId;
;

public:
    int id;
    string nome;
    string tel;
;
    Cliente( string tel, string nome);
};
