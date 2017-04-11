#include "formato.h"

formato::formato() {
	
}

formato::~formato() {
	
}

void formato::setBodyRows(vector<int> rows){
	this->bodyRows=rows;
	this->bodySize=this->bodyRows.size();
}

void formato::setBodyCols(vector<int> cols){
	this->bodyCols=cols;
}


	
bool formato::isHead(int row, int col){
	bool answer=false;
	int headRow;
	headRow=this->bodyRows[0];
	
	for(int i=0;i<this->bodyCols.size();i++){
		if(headRow==row&&bodyCols[i]==col)answer=true;
	}
	return answer;
}

bool formato::isInBody(int row,int col){
	bool answer=false;
	for(int i=1;i<this->bodyRows.size();i++){
		for(int j=0;j<this->bodyCols.size();j++){
			if(this->bodyRows[i]==row&&this->bodyCols[i]==col)answer=true;
		}
	}
	return answer;
}

int formato::getBodySize(){
	return this->bodySize;
}
