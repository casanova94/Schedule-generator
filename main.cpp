#include<iostream>
#include <fstream>
#include "registro.h"
#include "materia.h"
#include "subjectsRelations.h";
using namespace std;

ofstream out("ScheduleByRoom.csv");
//funciones
vector<Registro>  readDocument();
void printRegisters(vector<Registro> registros);
vector<string> listAllRooms(vector<Registro> registros);
void createSchedule(vector<Registro> registros,vector<string> salones);
void printSchedule(vector<Registro> registros,string room);
void setScheduleForm(string matrix[29][6],string id);
vector<materia> registersToSubjects(string matrix[29][6]);
bool isEmpty(string s);
void printSchedules( vector<materia> listaMaterias,string matrix[29][6]);
vector<subjectsRelations> readSubRel();
string idToNameCourse(string Id,vector<subjectsRelations> relaciones);
int main (int argc, char *argv[]) {
	vector<Registro> registros;
	vector<string> salones;
	registros=readDocument();
	salones=listAllRooms(registros);
	createSchedule(registros,salones);
	
	return 0;
}


//implementación de las funciones
vector<Registro>  readDocument(){
	Registro aux;
	string s,line,auxs;
	vector<Registro> registros;
	vector<string> registerLine,pruebas;
	ifstream in("CSV_files/solution.csv");
	int column=1;
	
	while(getline(in,line,'\n')){
		registerLine.push_back(line);
	}
	
	for(unsigned k=0;k<registerLine.size();k++){
		auxs=registerLine[k];
		for(unsigned j=0;j<auxs.size();j++){
			
			if(','!=auxs[j])s=s+auxs[j];
			else{
				switch(column){
				case 1:
					aux.setCourse(s);
					s.clear();
					break;
				case 7:
					aux.setDays(s);
					s.clear();
					break;
				case 8:
					aux.setStartTime(s);
					s.clear();
					break;
				case 9:
					aux.setEndTime(s);
					s.clear();
					break;
				case 10:
					aux.setRoom(s);
					s.clear();
					break;
				case 11:
					s.replace(0,1,1,' ');
					aux.setTeacherLastName(s);
					s.clear();
					break;
				case 12:
					s.replace(s.size()-1,1,1,' ');
					aux.setTeacherFirstName(s);
					s.clear();
					break;
				default:
					s.clear();
					break;
				}column++;
			}
			if(j==auxs.size()-1){
				aux.setPlan(s);
				s.clear();
				registros.push_back(aux);
			}
			
		}column=1;	}
	
	return registros;
}


vector<subjectsRelations> readSubRel(){
	ifstream in("CSV_files/correspondencias.csv");
	int ind=0;
	//este contador es para los casos en los que los registros tienen una coma incluida
	int contador=0,contador2=1;
	string s,line;
	vector<subjectsRelations> relations;
	subjectsRelations aux;
	vector<string> relationLine;
	
	while(getline(in,line,'\n')){
		relationLine.push_back(line);
	}
	s.clear();
	line.clear();
	for(int i=0;i<relationLine.size();i++){
		s=relationLine[i];
		for(int j=0;j<s.size();j++){
			if(s[j]==',')contador++;}
		
		for(int j=0;j<s.size();j++){
			if(contador==1){
				if(s[j]==','){
					aux.setId(line);
					line.clear();
				}else{
					line+=s[j];
				}}else{
				if(s[j]==','){
					if(contador2==1){
						aux.setId(line);
						line.clear();
						contador2++;}else{
						line+=s[j];
					}
				}else{
					line+=s[j];
				}
				
			}
		}
		aux.setSubjectName(line);
		relations.push_back(aux);
		line.clear();
		contador=0;
		contador2=1;
	}
	
	return relations;
}

void printRegisters(vector<Registro> registros){
	for(unsigned i=0;i<registros.size();i++){
		cout<<"Course: "<<registros[i].getCourse()<<" Teacher name: "<<registros[i].getTeacherFirstName()<<" Course: "<<registros[i].getCourse()<<endl;
	}
}


vector<string> listAllRooms(vector<Registro> registros){
	vector<string> rooms;
	bool isInto;
		
	for(unsigned i=0;i<registros.size();i++){
		isInto=false;
		for(unsigned j=0;j<rooms.size();j++){
			if(rooms[j]==registros[i].getRoom())isInto=true;
		}
		if(!isInto)rooms.push_back(registros[i].getRoom());
		//cout<<endl<<registros[i].getRoom();
	}
	
	return rooms;
}
void createSchedule(vector<Registro> registros,vector<string> salones){
	//ofstream out("ScheduleByRoom.csv");
	ofstream out("solution/schedules.xls");
	vector<materia> listaMaterias;
	vector<int> filas,columnas;
	vector<Registro> aux;
	string horario[29][6];
	
	vector<subjectsRelations> relaciones;
	relaciones=readSubRel();
	
	out<<"<html>";
	
	for(unsigned i=0;i<salones.size();i++){
		for(unsigned j=0;j<registros.size();j++){
			if(registros[j].getRoom()==salones[i])aux.push_back(registros[j]);
		}
		
	
		//Establece el horario en la matriz
		setScheduleForm(horario,salones[i]);
		for(int i=0;i<aux.size();i++){
			aux[i].setPositions();
			filas=aux[i].getFilasPosicion();
			columnas=aux[i].getColumnasPosicion();
			for(unsigned f=0;f<filas.size();f++){
				for(unsigned c=0;c<columnas.size();c++){
					horario[filas[f]][columnas[c]]="<b>Profesor:</b> "+ aux[i].getTeacherFirstName()+aux[i].getTeacherLastName()+"<br><b> Materia: </b>"+idToNameCourse(aux[i].getId(),relaciones)+","+aux[i].getPlan()+"<br><b> De: </b>"+aux[i].getStartTime()+"m <b>a:</b> "+aux[i].getEndTime()+"m";
				} 
			} 	
			filas.clear();
			columnas.clear();
		}
		
		listaMaterias=registersToSubjects(horario);
		
		
		int s;
		bool isHead=false;
		bool isBody=false;
		
		
		out<<"<br>";
		out<<"<table border=\"1\">";
		for(int fila=0;fila<29;fila++){
			out<<"<tr>";
			for(int columnas=0;columnas<6;columnas++){
				for(int k=0;k<listaMaterias.size();k++){
					if(listaMaterias[k].isHead(fila,columnas))s=listaMaterias[k].getSubjectSize(),isHead=true;
					if(listaMaterias[k].isInBody(fila,columnas))isBody=true;
				}
				
				if(isHead){
					isHead=false;
					out<<"<td bgcolor=\"#FFFF00\" ALIGN=center  align=\"justify\" valign=\"top\" rowspan=\""<<s<<"\">";
					out<<horario[fila][columnas];
					out<<"</td>";
					
				}else{
					if(isBody){isBody=false;}
					else{
						if(fila==0||columnas==0){out<<"<td bgcolor=\"#D8D8D8\" ALIGN=center>";}
						else {out<<"<td>";}
						out<<horario[fila][columnas];
						out<<"</td>";
					}
					
				}
				
			}
			out<<"</tr>";
			
		}
		out<<"</table>";
		
//		//impresion a csv
//		for(int i=0;i<29;i++){
//			for(int j=0;j<6;j++){
//				out<<horario[i][j]<<",";
//			}out<<'\n';
//		}
//		out<<'\n';
		
		aux.clear();
	}
	out<<"</html>";
}
void printSchedule(vector<Registro> registros,string room){
	string horario[29][6];
	vector<int> filas,columnas;
	//ofstream out("ScheduleByRoom.csv");
	setScheduleForm(horario,room);
//	for(int i=0;i<29;i++){
//		for(int j=0;j<6;j++){
//			cout<<horario[i][j];
//		}cout<<endl;
//	}
	for(int i=0;i<registros.size();i++){
		registros[i].setPositions();
		filas=registros[i].getFilasPosicion();
		columnas=registros[i].getColumnasPosicion();
		for(unsigned f=0;f<filas.size();f++){
			for(unsigned c=0;c<columnas.size();c++){
				horario[filas[f]][columnas[c]]=registros[i].getTeacherFirstName();;
			}
		} 	
		filas.clear();
		columnas.clear();
	}
	
		for(int i=0;i<29;i++){
			for(int j=0;j<6;j++){
				out<<horario[i][j]<<",";
			}out<<'\n';
		}
	out<<'\n';
}
void setScheduleForm(string matrix[29][6],string id){
	for(int i=0;i<29;i++){
		for(int j=0;j<6;j++){
			matrix[i][j]=" ";
		}
	}
	matrix[0][0]="Salon: "+id;
	matrix[0][1]="Lunes";
	matrix[0][2]="Martes";
	matrix[0][3]="Miercoles";
	matrix[0][4]="Jueves";
	matrix[0][5]="Viernes";
	matrix[1][0]="7:30a";
	matrix[2][0]="8:00a";
	matrix[3][0]="8:30a";
	matrix[4][0]="9:00a";
	matrix[5][0]="9:30a";
	matrix[6][0]="10:00a";
	matrix[7][0]="10:30a";
	matrix[8][0]="11:00a";
	matrix[9][0]="11:30a";
	matrix[10][0]="12:00p";
	matrix[11][0]="12:30p";
	matrix[12][0]="1:00p";
	matrix[13][0]="1:30p";
	matrix[14][0]="2:00p";
	matrix[15][0]="2:30p";
	matrix[16][0]="3:00p";
	matrix[17][0]="3:30p";
	matrix[18][0]="4:00p";
	matrix[19][0]="4:30p";
	matrix[20][0]="5:00p";
	matrix[21][0]="5:30p";
	matrix[22][0]="6:00p";
	matrix[23][0]="6:30p";
	matrix[24][0]="7:00p";
	matrix[25][0]="7:30p";
	matrix[26][0]="8:00p";
	matrix[27][0]="8:30p";
	matrix[28][0]="9:00p";
}
vector<materia> registersToSubjects(string matrix[29][6]){
	bool first=true;
	vector<materia> listaMaterias;
	materia materiaAux;
	position posicionAux;
	
	for(int j=1;j<6;j++){
		for(int i=1;i<29;i++){
			X:
				if(!isEmpty(matrix[i][j])){
				if(first){
					materiaAux.setPosIni(i,j,matrix[i][j]);
					first=false;
					//cout<<materiaAux.getDataInicial();
				}else{
					if(matrix[i][j]==materiaAux.getDataInicial()){
						posicionAux.setFila(i);
						posicionAux.setColumna(j);
						posicionAux.setData(matrix[i][j]);
						materiaAux.addElementToBody(posicionAux);
						if(i==28&&j==5){
							first=true;
							listaMaterias.push_back(materiaAux);
							materiaAux.clearSubject();
						}						
					}else{
						first=true;
						listaMaterias.push_back(materiaAux);
						materiaAux.clearSubject();
						goto X;
					}					
				}				
			} else{
				first=true;
				if(!materiaAux.isSubjectEmpty()){
					listaMaterias.push_back(materiaAux);
					materiaAux.clearSubject();
				}
			}
		}
	}
	return listaMaterias;
}
bool isEmpty(string s){
	if(s==" ")return true;
	else return false;
}
void printSchedules( vector<materia> listaMaterias,string matrix[29][6]){

	
	
}
string idToNameCourse(string Id,vector<subjectsRelations> relaciones){
	bool found=false;
	int ind;
	string conversion=" ";
	
	for(int i=0;i<relaciones.size();i++){
		if(relaciones[i].getId()==Id)found=true,ind=i;
	}
	if(found)conversion=relaciones[ind].getsubjectName();
	
	//if(conversion==" ")cout<<"Id del registro:"<<Id<<endl;
	
	
	return conversion;
	
}
