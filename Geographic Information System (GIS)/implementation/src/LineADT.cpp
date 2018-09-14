
#include "../include/LineADT.h"
#include "../include/MapTypes.h"
#include "../include/Exceptions.h"
#include "../include/PointADT.h"

LineT::LineT(PointT st, CompassT ornt, int l) : s(0,0){
	if (l == 0){
		throw invalid_argument();
	}
	this->s = st;
	this->o = ornt;
	this->L = l;
	}



PointT LineT::strt(){
	return PointT(this->s.x(), this->s.y());
}

PointT LineT::end(){
	PointT start = this->s;

	if (this->o == W) return PointT(this->s.x() -(this->L-1), this->s.y());
	if (this->o == E) 	return PointT(this->s.x() +(this->L-1), this->s.y());
	if (this->o == N) return PointT(this->s.x(), this->s.y() + this->L-1);
	if (this->o == S)  return PointT(this->s.x(), this->s.y() - this->L + 1);}

CompassT LineT::orient(){
	return this->o;
}
 
int LineT::len(){
	return this->L;
}

LineT LineT::flip(){
	if (this->o == N){
		return LineT(this->s,S,this->L);
	}
	else if (this->o == S){
		return LineT(this->s,N,this->L);
	}
	else if (this->o == E){
		return LineT(this->s,W,this->L);
	}
	return LineT(this->s,E,this->L);
}

LineT LineT::rotate(RotateT r){
	if (r == CW){
		if (this->o == N){
			return LineT(this->s,E,this->L);
		}
		else if (this->o == S){
			return LineT(this->s,W,this->L);
		}
		else if (this->o == E){
			return LineT(this->s,S,this->L);
		}
		else if (this->o == W){
			return LineT(this->s,N,this->L);
		}
	}
	//r is CCW
	else {
		if (this->o == N){
			return LineT(this->s,W,this->L);
		}
		else if (this->o == S){
			return LineT(this->s,E,this->L);
		}
		else if (this->o == E){
			return LineT(this->s,N,this->L);
		}
		else if (this->o == W){
			return LineT(this->s,S,this->L);
		}
	}
}

LineT LineT::translate(int x, int y){
	return LineT(this->s.translate(x, y), this->o, this->L);

};

	
