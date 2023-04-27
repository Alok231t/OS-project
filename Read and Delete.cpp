#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

 

// Function to read the contents of a file and print them to the console
void read_file(string file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        perror("open error");
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(file, line)) {  // read the contents of the file
        cout << line << endl;  // print the contents to the console
    }

    file.close();
}

 

// Function to delete a file
void delete_file(string file_path) {
    int status = unlink(file_path.c_str());  // delete the file
    if (status == -1) {
        perror("unlink error");
        exit(EXIT_FAILURE);
    }

    cout << "File deleted successfully!" << endl;
}

 
int main() {


    #ifndef ONLINE_JUDGE
                        freopen("inputf.in", "r", stdin);
                        freopen("outputf.out", "w", stdout);
                        #endif
    
   
      

     //read_file("/New.png");

     delete_file("/New.txt");


    return 0;
}
