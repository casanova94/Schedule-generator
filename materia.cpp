#include "materia.h"

materia::materia() {
	
}

materia::~materia() {
	
}

void materia::setPosIni(int fila,int columna,string data){
	inicial.setFila(fila);
	inicial.setColumna(columna);
	inicial.setData(data);
}

int materia::getFilaIni(){return inicial.getFila();}
int materia::getColumnaIni(){return inicial.getColumna();}
string materia::getDataInicial(){return inicial.getData();}

void materia::addElementToBody(position nuevo){
	cuerpo.push_back(nuevo);
}

bool materia::isInBody(int i,int j){
	bool ans=false;
	for(unsigned k=0;k<cuerpo.size();k++){
		if(cuerpo[k].isPosition(i,j))ans=true;
	}
	return ans;
}

bool materia::isHead(int i,int j){
	bool ans=false;
	if(inicial.getFila()==i&&inicial.getColumna()==j)ans=true;
	return ans;
}

void materia::clearSubject(){
	cuerpo.clear();
	inicial.clearPosition();
}

int materia::getSubjectSize(){
	int size;
	size=cuerpo.size()+1;
	return size;
}

bool materia::isSubjectEmpty(){
	if(cuerpo.size()<1)return true;
	else return false;
}
