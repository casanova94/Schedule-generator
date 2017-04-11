#ifndef SUBJECTSRELATIONS_H
#define SUBJECTSRELATIONS_H
#include <string>
using namespace std;
class subjectsRelations {
private:
	string subjectName;
	string id;
public:
	subjectsRelations();
	~subjectsRelations();
	void setSubjectName(string subject);
	void setId(string id);
	string getsubjectName();
	string getId();
};

#endif

