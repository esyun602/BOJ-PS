#include <filesystem>
#include<iostream>
using namespace std::filesystem;
using namespace std;
int main(){
    string path = "./";
    for(auto& file: recursive_directory_iterator()){
        cout<<file.path()<<'\n';
    }
}
