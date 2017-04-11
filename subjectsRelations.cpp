#include "subjectsRelations.h"



subjectsRelations::subjectsRelations() {
	this->id=" ";
	this->subjectName=" ";
}

subjectsRelations::~subjectsRelations() {
	
}

void subjectsRelations::setSubjectName(string subject){
	this->subjectName=subject;
}
void subjectsRelations::setId(string id){
	this->id=id;
}
string subjectsRelations::getsubjectName(){
	return this->subjectName;
}
string subjectsRelations::getId(){
	return this->id;
}
