//----------------------------------------------------------------------------
//
//  DU Line class
//    Header
//
//  This class represents a line in two-dimensional space.
//
//----------------------------------------------------------------------------
//
//  Author:         Hoi Man Chang
//  Course:         MCS172
//  Date:           02/06/98
//
//  Modified:       JL Popyack: 04/28/98, 5/13/98, 4/22/99
//  Modified:       Paul Zoski 04/18/00
//                   -removed spurious spaces to fix
//					  "unexpected class" error
//  Modified:       JL Popyack, 4/15/2002
//
//----------------------------------------------------------------------------

	#ifndef _DULine_H
	#define _DULine_H

	#include <string>
	#include "DUPoint.h"
	using namespace std ;

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

	class DULine
	{
	  public:
		//------------------------------------------------------
		//----- Constructors -----------------------------------
		//------------------------------------------------------
		
		  	DULine();
		  	DULine(int x1, int y1, int x2, int y2);
		  	DULine(const DUPoint &p1, const DUPoint &p2);
	  	
		//------------------------------------------------------
		//----- Inspectors -------------------------------------
		//------------------------------------------------------
	  	
			DUPoint getPoint1 () const;
			DUPoint getPoint2 () const;
		
		//------------------------------------------------------
		//----- Mutators ---------------------------------------
		//------------------------------------------------------
		  	
		  	void setLine (int x1, int y1, int x2, int y2);
		  	void setLine (const DUPoint &p1, const DUPoint &p2);
			
			void setPoint1 (int x, int y);
			void setPoint2 (int x, int y);
			void setPoint1 (const DUPoint &p);
			void setPoint2 (const DUPoint &p);
		
		//------------------------------------------------------
		//----- Facilitators -----------------------------------
		//------------------------------------------------------
		
			//------------------------------------------------------
			// return DULine in string form
			   string toString () ;
			   
			//------------------------------------------------------
			// output DULine to given output stream
			   void output(ostream & sout);

	  private:
	 	DUPoint p1_ ;
	 	DUPoint p2_ ;
	 };
//----------------------------------------------------------------------------
//----- DUPoint: auxiliary operator descriptions -----------------------------
//----------------------------------------------------------------------------

ostream& operator<< (ostream& out, DULine &line) ;

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif