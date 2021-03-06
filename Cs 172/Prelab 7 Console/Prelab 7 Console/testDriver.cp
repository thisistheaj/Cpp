//----------------------------------------------------------------------------
//
//-------------------------- DUPoint*, DULine* Tester ------------------------
//
//----------------------------------------------------------------------------
//
//  Program Name: testDriver cpp
//
//  This program investigates pointer concepts through the DUPoint and DULine 
//  classes.
//
//  Author:         JL Popyack
//  Course:         CS172
//  Date:           5/13/98
//
//  Modified:       JL Popyack: 5/8/2
//
//
//----------------------------------------------------------------------------

	#include <iostream>
	#include <string>
	#include "DUPoint.h"
	#include "DULine.h"
	using namespace std ;


//----------------------------------------------------------------------------
//
//-------------------------------- Prototypes --------------------------------
//
//----------------------------------------------------------------------------

	int  min_value  ( int &a, int &b ) ;
	int& min_element( int &a, int &b ) ;
	
//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------

	int main(void)
	{

		int i = 5, k = 7;
	
	//----------------------------------------------------------------------------
	// iPtr is a variable that can point to an integer
	//----------------------------------------------------------------------------
		int * iPtr ;
        int * kPtr;
					
	//----------------------------------------------------------------------------
	// iPtr is assigned the address of i
	// iPtr now "points at" i
	//----------------------------------------------------------------------------
		iPtr = &i ;
        kPtr = &k ;
	
	//----------------------------------------------------------------------------
	// Printing iPtr reveals the address of i
	//----------------------------------------------------------------------------
		cout << "iPtr=" << iPtr << endl ;
        cout << "kPtr=" << kPtr << endl ;
	//----------------------------------------------------------------------------
	// The object pointed at by iPtr may be referenced
	// as *iPtr
	//----------------------------------------------------------------------------
        
		cout << "*iPtr=" << *iPtr << endl ;
		cout << "i=" << i << endl ;
        cout << "*kPtr=" << *kPtr << endl ;
        cout << "k=" << k << endl ;
        
        swap(iPtr,kPtr);
        
        cout << "*iPtr=" << *iPtr << endl ;
        cout << "i=" << i << endl ;
        cout << "*kPtr=" << *kPtr << endl ;
        cout << "k=" << k << endl ;
	
	//----------------------------------------------------------------------------
	// jPtr is another 'integer pointer' variable
	//----------------------------------------------------------------------------
		int * jPtr ;
	
	//----------------------------------------------------------------------------
	// jPtr is assigned the value of iPtr
	// jPtr now holds the same address that iPtr holds
	//----------------------------------------------------------------------------
		jPtr = iPtr ;
		cout << "jPtr=" << jPtr << endl ;
	
	    return 0;
	}


//----------------------------------------------------------------------------
//
//-------------------------- Subprogram Definitions --------------------------
//
//----------------------------------------------------------------------------

	int  min_value  ( int &a, int &b )
	{
		if( a < b )
			return a ;
		else
			return b ;
	}
	
//----------------------------------------------------------------------------
//
	int& min_element( int &a, int &b )
	{
		if( a < b )
			return a ;
		else
			return b ;
	}

    template <typename T>
    void swap(T * a, T * b)
    {
        T temp = * b;
        * b = * a;
        * a = temp;
    }