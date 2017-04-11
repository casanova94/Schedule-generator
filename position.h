#ifndef POSITION_H
#define POSITION_H
#include<iostream>
using namespace std;

class position{
private:
	int fila;
	int columna;
	string data;
public:
position();
~position();
void setFila(int f);
void setColumna(int c);
void setData(string d);
int getFila();
int getColumna();
string getData();
bool isPosition(int f,int c);
void clearPosition();
	
};



#endif

