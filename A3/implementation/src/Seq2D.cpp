#include <vector>
#include <iostream>

#include "../include/Exceptions.h"
#include "../include/LineADT.h"
#include "../include/PointADT.h"
#include "../include/PathADT.h"
#include "../include/MapTypes.h"
#include "../include/Seq2D.h"

template<class T>
Seq2D<T>::Seq2D(std::vector< std::vector<T> > S, double scl){
	int sizeRow = S.at(0).size();

	if (scl <= 0 || S.size() == 0 || S.at(0).size() == 0)
		throw invalid_argument();
	for (int i = 1; i < S.size(); i++){
		if (sizeRow != S.at(i).size())
			throw invalid_argument();
	}

	this->s = S;
	this->scale = scl;
	this->nCol = S.size();
	this->nRow = sizeRow;
}

template<class T>
void Seq2D<T>::set(PointT p, T v){
	if (!validPoint(p))
		throw outside_bounds();
	this->s.at(p.y()).at(p.x()) = v;
}

template<class T>
T Seq2D<T>::get(PointT p){
	if (!validPoint(p))
		throw outside_bounds();
	return this->s.at(p.y()).at(p.x());
}

template<class T>
int Seq2D<T>::getNumRow(){
	return this->nRow;
}

template<class T>
int Seq2D<T>::getNumCol(){
	return this->nCol;
}

template<class T>
double Seq2D<T>::getScale(){
	return this->scale;

}


template<class T>
int Seq2D<T>::count(T t){
	int counts = 0;

	for (int i = 0; i < nRow && validRow(i); i++){
		for (int j = 0; j < nCol && validCol(j); j++){
			if (this->s.at(i).at(j) == t)
				counts++; 
			
		}
	}

	return counts;
}


template<class T>
int Seq2D<T>::count(LineT l, T t){

	if (!validLine(l))
		throw invalid_argument();

	int counts = 0;
	for (int i =0 ; i < l.len(); i++){
		if (this->s.at(pointsInLine(l).at(i).y()).at(pointsInLine(l).at(i).x()) == t)
			counts++;
	}

	return counts;
}

template<class T>
int Seq2D<T>::count(PathT pth, T t){

	if (!validPath(pth))
		throw invalid_argument();

	int counts=0;
	for (int i =0 ; i < pth.size(); i++){
		counts += count(pth.line(i), t);
	}

	return counts;
}


template<class T>
double Seq2D<T>::length(PathT pth){
	if (!validPath(pth))
		throw invalid_argument();

	return (pth.len())*(this->scale);

}

template<class T>
bool Seq2D<T>::connected(PointT p1, PointT p2){
	if (!validPoint(p1) || !validPoint(p2))
		throw invalid_argument();

	this->check = false;
	this->checked.clear();
	return PointsAdjacent(p1,p2);
} 

template<class T>
bool Seq2D<T>::pointChecked(PointT x){
	for (int i = 0; i < this->checked.size() ; i++){
		if (this->checked.at(i).x() == x.x()
			&& this->checked.at(i).y() == x.y())
			return true;
	}

	return false;
}

template<class T>
bool Seq2D<T>::PointsAdjacent(PointT p1,PointT p2){
	std::vector<PointT> adjacent;

	PointT W = PointT(p1.translate(-1,0));
	PointT E = PointT(p1.translate(1,0));
	PointT N = PointT(p1.translate(0,1));
	PointT S = PointT(p1.translate(0,-1));

	if (validPoint(W) && get(p1) == get(W) && (!pointChecked(W))) {adjacent.push_back(W); this->checked.push_back(W);}
	if (validPoint(E) && get(p1) == get(E) &&  (!pointChecked(E)))  {adjacent.push_back(E); this->checked.push_back(E);}
	if (validPoint(N) && get(p1) == get(N) && (!pointChecked(N))) {adjacent.push_back(N); this->checked.push_back(N);}
	if (validPoint(S) && get(p1) == get(S) && (!pointChecked(S))) {adjacent.push_back(S); this->checked.push_back(S);}

	for (int i = 0; i < adjacent.size(); i++){
		if (adjacent.at(i).x() == p2.x() && adjacent.at(i).y() == p2.y())
			return true; 
	}

	//search through each adjacent point
	for (int i = 0; i < adjacent.size(); i++)
		check = PointsAdjacent(adjacent.at(i), p2);
	
	if (check) return true;

	return false;

}


//local fns

template<class T>
bool Seq2D<T>::validRow(int i){
	return 0 <= i && i <= this->nRow - 1;
}

template<class T>
bool Seq2D<T>::validCol(int j){
	return 0 <= j && j <= this->nCol - 1; 
}

template<class T>
bool Seq2D<T>::validPoint(PointT p){
	return validRow(p.y()) && validCol(p.x());  	
}


template<class T>
bool Seq2D<T>::validLine(LineT l){

	for (int i =0 ; i < l.len(); i++){
		if (!validPoint(pointsInLine(l).at(i)))
			return false;
	}  
	return true;
}


template<class T>
bool Seq2D<T>::validPath(PathT pth){

	for (int i =0 ; i < pth.len(); i++){
		for (int line = 0; line < pth.size(); line++)
			if (!validLine(pth.line(line)))
				return false;
	}  
	return true;

}

template<class T>
std::vector<PointT> Seq2D<T>::pointsInLine(LineT l){
	int xval = 0;
	int yval = 0;

	switch (l.orient()){
		case W: xval = -1;
		case E: xval = 1; 
		case N: yval = 1;
		case S: yval = -1;
	}

	std::vector<PointT> linepts; 

	for (int i = 0; i < l.len(); i++){
		linepts.push_back(l.strt().translate(xval * i,yval * i));
	}

	return linepts;
}

template<class T>
std::vector<PointT> Seq2D<T>::pointsInPath(PathT p){
	std::vector<PointT> points;
	//iterate through the lines p.size()
	 for (int i =0 ; i < p.size(); i++){
	 	//iterate through the points in each line to append to a new sequence of points. 
	 	for (int j =0 ; j < p.line(i).len(); j++){
	 		points.push_back(pointsInLine(p.line(i)).at(j));
	 	}
	 }

	 return points;
}

template class Seq2D < LanduseT >;
template class Seq2D < int >;