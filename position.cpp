#include "position.h"

position::position() {
	
}

position::~position() {
	
}

void position::setFila(int f){
	this->fila=f;
}
void position::setColumna(int c){
	this->columna=c;
}
void position::setData(string d){
	this->data=d;
}
int position::getFila(){return this->fila;}
int position::getColumna(){return this->columna;}
string position::getData(){return this->data;}

bool position::isPosition(int f,int c){
	if(fila==f&&columna==c)return true;
	else return false;}
	
void position::clearPosition(){
		fila=0;
		columna=0;
		data.clear();
	}
	
