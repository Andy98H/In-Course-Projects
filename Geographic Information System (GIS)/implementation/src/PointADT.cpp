
#include "../include/PointADT.h"

PointT::PointT(int x, int y){
	this->xc = x;
	this->yc = y;
}

int PointT::x(){
	return this->xc;
};

int PointT::y(){
	return this->yc;
};

PointT PointT::translate(int x, int y){
	return PointT(this->xc + x, this->yc + y); 
}


