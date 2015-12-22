//----------------------------------------------------------------------------
//
//  DU Point class
//    Implementation
//
//  This class represents an ordered pair (x,y).
//
//----------------------------------------------------------------------------
//
//  Author:         Hoi Man Chang
//  Course:         MCS172
//  Date:           02/06/98
//
//  Modified:       JL Popyack: 04/28/98, 5/13/98, 4/22/99, 4/15/2
//
//----------------------------------------------------------------------------

	#include <iostream>
	#include <string>
	#include <sstream>

	#include "DUPoint.h"
	using namespace std ;
	

//----------------------------------------------------------------------------
//----- Constructors ---------------------------------------------------------
//----------------------------------------------------------------------------

	DUPoint::DUPoint()
	{ }

	DUPoint::DUPoint(int x, int y)
	{
		x_ = x;
		y_ = y;
	}

	DUPoint::DUPoint(const DUPoint &  p)
	{
		x_ = p.getX() ;
		y_ = p.getY() ;
	}

//----------------------------------------------------------------------------
//----- Destructor -----------------------------------------------------------
//----------------------------------------------------------------------------

	DUPoint::~DUPoint()
	{ }

//----------------------------------------------------------------------------
//----- Inspectors -----------------------------------------------------------
//----------------------------------------------------------------------------

	int DUPoint::getX() const
	{
		return x_;
	}

	int DUPoint::getY () const
	{
		return y_;
	}
  
//----------------------------------------------------------------------------
//----- Mutators -------------------------------------------------------------
//----------------------------------------------------------------------------

	void DUPoint::setX (int x)
	{
		x_ = x;
	}

	void DUPoint::setY (int y)
	{
		y_ = y;
	}

//----------------------------------------------------------------------------
//----- Facilitators ---------------------------------------------------------
//----------------------------------------------------------------------------


	string DUPoint::toString() const
	{
		//---------------------------------------------------------------------
		//  The ostringstream type allows output to be directed to
		//  a string in the same style as usually done with a stream.
		//---------------------------------------------------------------------

		ostringstream os;
		os << "(" << x_ << "," << y_ << ")";
		string s = os.str();
		return s;
	}


	//----------------------------------------------------------------------------

	void DUPoint::output(ostream & out) const
	{
		out << "(" << x_ << "," << y_ << ")" ;
	}


	//----------------------------------------------------------------------------

	void DUPoint::input(istream & in)
	{
		char ch ;
		in >> ch ;   // read "("
		in >> x_ ;
		in >> ch ;   // read ","
		in >> y_ ;
		in >> ch ;   // read ")"
	}
	
//----------------------------------------------------------------------------
//----- DUPoint: auxiliary operator descriptions -----------------------------
//----------------------------------------------------------------------------

	
	istream&  operator>> (istream&  in, DUPoint & p)
	{
		p.input(in);
		return(in);
	}

	//----------------------------------------------------------------------------

	ostream&  operator<< (ostream&  out, const DUPoint & p)
	{
		p.output(out) ;
		return out;
	}
