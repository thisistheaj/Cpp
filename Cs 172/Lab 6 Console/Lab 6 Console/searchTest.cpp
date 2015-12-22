//----------------------------------------------------------------------------
//
//------------------------------- Sorting Test -------------------------------
//
//----------------------------------------------------------------------------
//
// Name    : Sorting Test
// Version : 2.1
//
// This program is used as a driver to test sorting
// methods and count number of comparisons and moves
// used by them.
//
// Lists of integers are generated randomly and sorted,
// with performance statistics reported afterwards.
//
// Author  : JL Popyack
// Date    : May, 1999
// Modified: May, 2002; May, 2011 -- added timer
//
//----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

//---------------------------------------------------------------------
// Global variables for #comparisons and #moves are
// declared in utilities.h
//---------------------------------------------------------------------

#include "utilities.h"
#include "quickSort.h"
using namespace std ;


//----------------------------------------------------------------------------
//
//-------------------------------- Prototypes --------------------------------
//
//----------------------------------------------------------------------------


// Generate random integers in the range 0..RAND_MAX
// and store them in v.
void generateRandom(vector<int> &v) ;

// Display elements of a vector, 10 per line
void showVector(vector<int> &v) ;

// searches a list in L probes for logsub2(L) = n elements
int binary_search(vector<int> & v, int fromIndex, int toIndex, int key, int & probes) ;
int binary_search(vector<int> & v,int key, int probes);



//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------

int main(void)
{
    //---------------------------------------------------------------------
    // v is the list to be sorted;
    // unsortedList holds the unsorted elements for re-use.
    // we don't display the vector elements if it exceeds MAX_REPORT_SIZE
    //---------------------------------------------------------------------
    vector<int> v, unsortedList ;
    int n ;
    const int MAX_REPORT_SIZE = 100 ;
    clock_t start,stop;
    int comparisons, moves ;
    double elapsedTime ;
    
    cout << "Number of elements in list to create: " ;
    cin >> n ;
    
    
    //SORT
    
    unsortedList.resize(n) ;
    generateRandom(unsortedList) ;
    v = unsortedList;
    
    
    comparisons = 0;
    moves = 0;
    start = clock() ;
    
    quickSort(v,comparisons,moves) ;
    
    stop = clock() ;
    elapsedTime = ( clock() - start ) / (double)CLOCKS_PER_SEC;
    
    cout << endl << "Sorted by quickSort: " << endl;
    if( n<=MAX_REPORT_SIZE )
        showVector(v) ;
    
    cout << endl
    << "Used " << comparisons
    << " comparisons, " << moves
    << " moves, in "
    << elapsedTime
    << " seconds"
    << endl;
    
    cout << endl << "Done." << endl;
    
    //SEARCH
    
    for (int i = 0; i < v.size(); i++) {
        int probes = 0;
        cout << "i = " << i << " v[i] = " << v[i] << endl;
        n = binary_search(v,v[i],probes);
        cout << "n = " << n << " v[n] = " << v[n] << endl;
        cout << "Used " << probes << " probes. " << endl;
    }
    
    
    return 0;
}



//----------------------------------------------------------------------------
//
//-------------------------- Subprogram Definitions --------------------------
//
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//
void generateRandom(vector<int> &v)
{
    //------------------------------------------------------
    // Generate random integers in the range 0..RAND_MAX
    // and store them in v.
    // v random seed is chosen from the system clock so that
    // the list generated will be unique.
    //------------------------------------------------------
    
    srand(time(0)) ;
    for(int i=0; i<v.size(); i++)
        v[i] = rand() ;
}


//----------------------------------------------------------------------------
//
void showVector(vector<int> &v)
{
    //------------------------------------------------------
    // Display elements of a vector, 10 per line
    //------------------------------------------------------
    vector<int> ::iterator it ;
    int count=0 ;
    for(it=v.begin(); it!=v.end(); it++)
    {
        cout << setw(6) << *it << " ";
        count = (count+1)%10 ;
        if( count==0 )
            cout << endl ;
    }
    cout << endl ;
}


int binary_search(vector<int> &v, int fromIndex, int toIndex, int key, int & probes)
{
    if (fromIndex > toIndex)
        return -1;
    
    
    
    int mid = (fromIndex + toIndex) / 2;
    
    int diff = v[mid] - key;
    if (diff == 0) /* v[mid] == key */{
        probes++;
        return mid;}
    else if (diff < 0) /* v[mid] < key */{
        probes++;
        return binary_search(v, mid + 1, toIndex, key, probes);}
    else{
        probes++;
        return binary_search(v, fromIndex, mid - 1, key, probes);}
}

int binary_search(vector<int> & v,int key, int & probes){
    return binary_search(v,0,v.size() - 1,key, probes);
}


