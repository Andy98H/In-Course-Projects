#include <vector>
#include "../include/LineADT.h"
#include "../include/Exceptions.h"
#include "../include/PointADT.h"
#include "../include/PathADT.h"
#include "../include/MapTypes.h"


PathT::PathT(PointT st,CompassT ornt, int l){
	LineT ln = LineT(st,ornt,l);
	this->s.push_back(ln);
}

void PathT::append(CompassT ornt, int l){
	LineT newline(adjPt(ornt), ornt, l);

	// i iterates through the points in newline
	for (int i = 0; i < newline.len();i++){
		//j iterated through the lines in s
		for (int j = 0; j < this->s.size(); j++){
			//k iterates through the points in a line j in s
			for (int k = 0; k < this->s.at(j).len(); k++)
				if (pointsInLine(newline).at(i).x() == pointsInLine(this->s.at(j)).at(k).x()
					&& pointsInLine(newline).at(i).y() == pointsInLine(this->s.at(j)).at(k).y()){
					throw invalid_argument(); 
			}
		}

	}

	this->s.push_back(newline);
}

PointT PathT::strt(){
	return this->s.front().strt();
}

PointT PathT::end(){
	return this->s.back().end();
}

LineT PathT::line(int i){
	if (i >= this->s.size())
		throw outside_bounds();
	return LineT(this->s.at(i).strt(), this->s.at(i).orient(), this->s.at(i).len());
}

int PathT::size(){
	return this->s.size();
}

int PathT::len(){
	int sum = 0;
	for (int i = 0; i < this->s.size(); i++){
		sum+= this->s.at(i).len();
	}

	return sum;
}

PathT PathT::translate(int dx, int dy){

	PointT start = this->s.at(0).strt().translate(dx,dy);
	CompassT ornt = this->s.at(0).orient();
	int l = this->s.at(0).len();

	PathT s2 = PathT(start, ornt, l);

	for (int i = 1 ; i < this->s.size(); i++){
		s2.s.push_back(this->s.at(i).translate(dx,dy));
	}

	return s2;
}

//local fns
PointT PathT::adjPt(CompassT ornt){
	if(ornt== N)
		return this->s.back().end().translate(0,1);
	else if(ornt== S) 
		return this->s.back().end().translate(0,-1);
	else if(ornt== W) 
		return this->s.back().end().translate(-1,0);
	else if(ornt== E) 
		return this->s.back().end().translate(1,0);
	

}


std::vector<PointT> PathT::pointsInLine(LineT l){
	std::vector<PointT> linepts; 
	int xval = 0;
	int yval = 0;

		if(l.orient()== W) xval = -1;
		else if(l.orient()== E) xval = 1; 
		else if(l.orient()== N) yval = 1;
		else if(l.orient()== S) yval = -1;
	

	for (int i = 0; i < l.len(); i++){
		linepts.push_back(l.strt().translate(xval*i,yval*i));
	}

	return linepts;
}

