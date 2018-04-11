
#include <fstream>
#include <iostream>

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

int main() {
  int n = 0;
  cout << "No of complex numbers: ";
  cin >> n;

  Complex entry[10];

  for (int i = 0; i < n; i++) {
    cout << "Real and imag parts ";
    cin >> entry[i].real >> entry[i].imag;
  }

  ofstream file;
  file.open("data.txt", ios::out);

  for (int i = 0; i < n; i += 2) {
    file << entry[i] << entry[i + 1] << endl;
  }
  file.close();

  return 0;
}