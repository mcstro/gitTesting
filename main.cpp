#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <fftw3.h>

using namespace std;

int main(){

    int a = 8;
    cout << 2*a << endl;
    // This is the line that needs attention
    ifstream file ("scottsComp/config.txt");

    filebuf* sbuf = file.rdbuf();
    string txt;
    if( file.good() ){
        size_t size = sbuf -> pubseekoff(0,file.end,file.in);
        sbuf -> pubseekpos(0,file.in);
        char* buffer = new char[size]; 
        sbuf -> sgetn( buffer, size );
        txt = string( buffer );
        delete[] buffer;
    }else{
        txt = "Couldn't find file";
    }

    // Can we find the fftw lib?
    fftw_complex *in;

    cout << txt << endl;
    cout << "Some more stuff was added to main" << endl;
    cout << "Yet another thing" << endl;

    // Definitely should have closed the file
    file.close();
    
    
    return 0;
    
}
