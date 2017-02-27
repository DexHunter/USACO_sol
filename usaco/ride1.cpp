/*
ID: xdx241
PROB: ride
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ofstream fout ("ride.out");
	ifstream fin  ("ride.in");
	string a, b;
    fin >> a >> b;
    int product_c = 1; //initialize product to 1
    int product_g = 1;
    for (int i=0; i < a.size(); i++){
        int charIndex = (a[i] - 'A') + 1;
        product_c *= charIndex;
    }
    for (int i=0; i < b.size(); i++){
        int charIndex = (b[i] - 'A') + 1;
        product_g *= charIndex;
    }

    if ((product_c % 47) ==( product_g % 47) ) {
        fout << "GO\n";
    }
    else {
        fout << "STAY\n";
    }
    return 0;

}



