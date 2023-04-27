#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;


// Function to copy a file to a new location
void copy_file(string source_path, string dest_path) {
    ifstream source_file(source_path, ios::binary);
    if (!source_file.is_open()) {
        perror("open error");
        exit(EXIT_FAILURE);
    }

    ofstream dest_file(dest_path, ios::binary);
    if (!dest_file.is_open()) {
        perror("open error");
        exit(EXIT_FAILURE);
    }

    dest_file << source_file.rdbuf();  // copy the contents of the source file to the destination file

    source_file.close();
    dest_file.close();

    cout << "File copied successfully!" << endl;
}
 


// Function to delete a directory
void delete_directory(string dir_path) {
    int status = rmdir(dir_path.c_str());  // delete the directory
    if (status == -1) {
        perror("rmdir error");
        exit(EXIT_FAILURE);
    }

    cout << "Directory deleted successfully!" << endl;
}

int main() {


    #ifndef ONLINE_JUDGE
                        freopen("inputf.in", "r", stdin);
                        freopen("outputf.out", "w", stdout);
                        #endif
    
     copy_file("Alo/New.png", "Alo/Copy.txt");

     //delete_directory("System-Call");

    return 0;
}
