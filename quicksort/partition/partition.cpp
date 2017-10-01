#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void partition(vector <int>  ar) {
   // Enter code for partitioning and printing here. 
    vector<int> left;
    vector<int> right;
    vector<int> equal;
    int arrSize = ar.size();
    //
    int pivot = 0;
    /*
    cout << "capacity "<< ar.capacity() << endl;
    cout << "arrSize " << arrSize << endl;
    cout << "pivot " << pivot << endl;
    cout << "pivot value " << ar[pivot] << endl;
    */
    equal.push_back(ar[pivot]);
    for(int i = 0; i < arrSize ; i++)
    {
        if(ar[i] < ar[pivot])
        {
            left.push_back(ar[i]);
        }
        else if(ar[i] > ar[pivot])
        {
            right.push_back(ar[i]);
        }
    }
    for(int j = 0; j < left.size(); j++)
    {
        cout << left[j] << " ";
    }
    cout << equal[0] << " ";
    for(int k = 0; k < right.size(); k++)
    {
        cout << right[k] << " ";
    }
    
}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
   cin >> _ar_size;
    
     for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

   partition(_ar);
   
   return 0;
}
