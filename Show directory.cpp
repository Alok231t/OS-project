#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main() {
	
	#ifndef ONLINE_JUDGE
                        freopen("inputf.in", "r", stdin);
                        freopen("outputf.out", "w", stdout);
                        #endif
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        cout << "Current working directory: " << cwd << endl;
    } else {
        cerr << "Error getting current working directory" << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
