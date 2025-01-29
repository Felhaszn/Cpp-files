#include <iostream>
#include "rsa.h"

using namespace std;

int main(){
    RSA num;

    long long encrypted;

    encrypted = num.encrypt(12);

    cout << num.decrypt(encrypted);

    return 0;
}