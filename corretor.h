#pragma once

#include <string>
using namespace std;

class Corretor{
    private:
        static int nextId;
    
    public:
        int id;
        string nome;
        string tel;
        bool aval;
        double lat;
        double lon;

    Corretor(string tel, bool aval, double lat, double lon, string nome);
};