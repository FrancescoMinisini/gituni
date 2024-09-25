#include<iomanip>
#include <iostream> 
#include <fstream>
#include <cstring>
#include<math.h>
using namespace std;
bool is_perfect_square(int n);

int main () {
int n ; 
cin >> n;
if (is_perfect_square(n)) {
    cout << endl <<"è un quadrato perfetto"<< endl;
}
    return 0; 
}

bool is_perfect_square(int n) {
    bool value = false ; 
    float scarto = sqrtf(n)-(int)sqrtf(n);
    if (scarto == 0) {
        value = true; 
    }
    return value;
}