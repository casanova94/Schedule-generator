#ifndef FORMATO_H
#define FORMATO_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class formato {
private:
vector<int> bodyRows,bodyCols;
int bodySize;
public:
	formato();
	~formato();

void setBodyRows(vector<int> rows);
void setBodyCols(vector<int> cols);
bool isHead(int row,int col);
bool isInBody(int row,int col);
int getBodySize();
};

#endif

