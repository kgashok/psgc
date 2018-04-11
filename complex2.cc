
#include <iostream>
#include <fstream>

using namespace std;

class Complex {
public:
  int real;
  int imag;
  Complex() {}
  Complex(int r, int i) {
    real = r;
    imag = i;
  }

  friend ofstream &operator<<(ofstream &fs, Complex &c) {
    fs << "(" << c.real << " +i" << c.imag << ") ";
    return fs;
  }
  
  
};

#include <stdio.h> 

int main() {

  Complex entry[10];
  
  FILE* fp = fopen ("data.txt", "r"); 
  
  int real, imag, real2, imag2; 
  int count = 0; 
  while(fscanf (fp, "(%d + i%d) (%d +i%d)\n", &real, &imag, &real2, &imag2)>0) {
    cout << real << " " << imag << endl
        << real2 << " " << imag2 << endl; 
        
    int real3 = real + real2; 
    int imag3 = imag + imag2; 
    
    entry[count].real = real3; 
    entry[count++].imag = imag3;  
  }

  // write the results to output file 
  ofstream file;
  file.open("data2.txt", ios::out);

  for (int i = 0; i < count; i++) {
    file << entry[i] << endl;
  }
  file.close();

  return 0;
}