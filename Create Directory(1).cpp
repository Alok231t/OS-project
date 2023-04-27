#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

void createDirectory(string path) {
    int status = system(("mkdir " + path).c_str());
    if (status == -1) {
        cerr << "Error creating directory" << endl;
        exit(EXIT_FAILURE);
    }
}

void writeFile(string path, const char* content) {
    FILE* fp = fopen(path.c_str(), "w");
    if (fp == NULL) {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%s", content);
    fclose(fp);
}

int main() {

    #ifndef ONLINE_JUDGE
                        freopen("inputf.in", "r", stdin);
                        freopen("outputf.out", "w", stdout);
                        #endif

    string s;
    cout<<"enter the file content: "<<endl;
    getline(cin,s);

    string filePath;
    cout<<"enter the file name: "<<endl;
    cin>>filePath;

    string dirPath;
    cout<<"enter the directory name: "<<endl;
    cin>>dirPath;

    const char* fileContent= s.c_str();
    filePath=dirPath+"/"+filePath+".txt";
    
    createDirectory(dirPath);
    writeFile(filePath, fileContent);
    
    return 0;
}