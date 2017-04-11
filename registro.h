#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Registro {
private:
	string course,days,startTime,endTime,room,teacherFirstName,teacherLastName,plan;
	vector<string> decodedDays;
	vector<int> filasPosicion;
	vector<int> columnasPosicion;
public:
	Registro();
	~Registro();
	void setCourse(string course);
	void setDays(string days);
	void setStartTime(string st);
	void setEndTime(string et);
	void setRoom(string room);
	void setTeacherFirstName(string teacher);
	void setTeacherLastName(string teacher);	
	void setPlan(string plan);
	void setPositions();
	string getCourse();
	vector<string> getDays();
	string getStartTime();
	string getEndTime();
	string getRoom();
	string getTeacherFirstName();
	string getTeacherLastName();
	string getPlan();
	vector<int> getColumnasPosicion();
	vector<int> getFilasPosicion();
	string getId();
};

#endif
