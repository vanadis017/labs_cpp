#include <iostream>
#include <fstream>   
#include <cstring>   
using namespace std;


int main() {
    const char* filename = "storage.dat";
    const int RECORD_SIZE = 20; 

    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Failed: " << filename << endl;
        return 1;
    }

    char buffer[RECORD_SIZE + 1]; 
    int countFragile = 0;

    while (true) {
        
        in.read(buffer, RECORD_SIZE);

        streamsize bytesRead = in.gcount();
        if (bytesRead == 0) {
            break;
        }

        
        if (bytesRead < RECORD_SIZE) {
            for (streamsize i = bytesRead; i < RECORD_SIZE; ++i) {
                buffer[i] = '\0';
            }
        }
        buffer[RECORD_SIZE] = '\0';

   
        if (strstr(buffer, "fragile") != nullptr) {
            ++countFragile;
        }

        if (!in) {
            break;
        }
    }

    cout << countFragile << endl;

    return 0;
}
