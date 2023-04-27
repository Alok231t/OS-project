#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

string execCommand(const char* cmd) {
    char buffer[1024];
    string result = "";
    FILE* pipe = _popen(cmd, "r");
    if (pipe == NULL) {
        cerr << "Error executing command" << endl;
        exit(EXIT_FAILURE);
    }
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }
    _pclose(pipe);
    return result;
}

int main() {

    #ifndef ONLINE_JUDGE
                        freopen("inputf.in", "r", stdin);
                        freopen("outputf.out", "w", stdout);
                        #endif
                        
    const char* cmd = "dir";
    
    string output = execCommand(cmd);
    cout << output << endl;
    
    return 0;
}
