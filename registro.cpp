#include "Registro.h"

Registro::Registro() {
	
}

void Registro::setCourse(string course){
	this->course=course;
}

void Registro::setDays(string days){
	this->days=days;
}

void Registro::setStartTime(string st){
	this->startTime=st;
}

void Registro::setEndTime(string et){
	this->endTime=et;
}

void Registro::setRoom(string room){
	this->room=room;
}

void Registro::setTeacherFirstName(string teacher){
	this->teacherFirstName=teacher;
}

void Registro::setTeacherLastName(string teacher){
	this->teacherLastName=teacher;
}

void Registro::setPlan(string plan){
	this->plan=plan;
}

string Registro::getCourse(){
	return this->course;
}

vector<string> Registro::getDays(){
	vector<string> dias;
	for(unsigned i=0;i<this->days.size();i++){
		switch(this->days[i]){
		case 'M':
			dias.push_back("Lunes");
		break;
		case 'T':
			if(days[i+1]=='h')dias.push_back("Jueves");
			else dias.push_back("Martes");
		break;
		case 'W':
			dias.push_back("Miercoles");
		break;
		case 'F':
			dias.push_back("Viernes");
		break;
		default:
			break;
		}
	}
	this->decodedDays=dias;
	return dias;
}


string Registro::getStartTime(){
	return this->startTime;
}
string Registro::getEndTime(){
	return this->endTime;
}
string Registro::getRoom(){
	return this->room;
}
string Registro::getTeacherFirstName(){
	return this->teacherFirstName;
}
string Registro::getTeacherLastName(){
	return this->teacherLastName;
}
string Registro::getPlan(){
	return this->plan;
}

Registro::~Registro(){
	this->course.clear();
	this->days.clear();
	this->endTime.clear();
	this->plan.clear();
	this->room.clear();
	this->startTime.clear();
	this->teacherFirstName.clear();
	this->teacherLastName.clear();
}

void Registro::setPositions(){
	vector<string> dias;
	vector<int> columnas;
	vector<int> filas;
	int aux=0;
	bool ind=false;
	string horas[28]={"7:30a","8:00a","8:30a","9:00a","9:30a",
		"10:00a","10:30a","11:00a","11:30a","12:00p","12:30p","1:00p","1:30p",
		"2:00p","2:30p","3:00p","3:30p","4:00p","4:30p","5:00p","5:30p","6:00p",
		"6:30p","7:00p","7:30p","8:00p","8:30p","9:00p"};
	
	dias=getDays();
	for(unsigned i=0;i<this->decodedDays.size();i++){
		if(!this->decodedDays[i].compare("Lunes"))aux=1;
		if(!this->decodedDays[i].compare("Martes"))aux=2;
		if(!this->decodedDays[i].compare("Miercoles"))aux=3;
		if(!this->decodedDays[i].compare("Jueves"))aux=4;
		if(!this->decodedDays[i].compare("Viernes"))aux=5;
		columnas.push_back(aux);
	}
	
	this->columnasPosicion=columnas;
	
	
	//esta sección se encarga de establecer las filas
	for(unsigned j=0;j<28;j++){
		if(!this->startTime.compare(horas[j]))filas.push_back(j+1),ind=true;
		else{
			if(!this->endTime.compare(horas[j]))filas.push_back(j),ind=false;
			else{
				if(ind)filas.push_back(j+1);
			}
		}
	}
	
	this->filasPosicion=filas;
}

vector<int> Registro::getFilasPosicion(){
	return this->filasPosicion;
}

vector<int> Registro::getColumnasPosicion(){
	return this->columnasPosicion;
}

string Registro::getId(){
	string s=this->course;
	string aux;
	bool flag=false;
	
	for(int i=1;i<s.size();i++){
		if(s[i-1]==' '&&s[i]!=' ')flag=true;
		if(flag)aux+=s[i];
	}		
	
	return aux;
}
