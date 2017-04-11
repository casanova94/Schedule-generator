#ifndef MATERIA_H
#define MATERIA_H
#include "position.h"
#include<vector>

class materia{
private:
	position inicial;
	vector<position> cuerpo;
public:
materia();
~materia();
void setPosIni(int fila,int columna,string data);
int getFilaIni();
int getColumnaIni();
string getDataInicial();
void addElementToBody(position nuevo);
bool isInBody(int i,int j);
bool isHead(int i,int j);
void clearSubject();
int getSubjectSize();
bool isSubjectEmpty();
};


#endif

