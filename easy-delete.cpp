#include <iostream>
#include <string>
#include <filesystem>
#include <windows.h> // for Sleep function
#include <unordered_set>
#include <unordered_map>
using namespace std;
namespace fs = filesystem;

string file_ext = ".raf";

void easy_delete(){
    fs::path p = fs::current_path();
    fs::create_directory("To-be deleted");
    fs::path tbd = p / "To-be deleted";
    unordered_map<string,int> occurences;
    unordered_set<string> multiple_occ;
    unordered_set<string> duplicates = {};
    for(auto& entry : fs::directory_iterator(p)){
        if(entry==p/"easy-delete.exe" || entry==p/"easy-delete.cpp") continue;
        if (!entry.is_regular_file()) continue;
        string x = entry.path().stem().string();
        if(occurences.find(x)==occurences.end()){
            occurences[x] = 1;
        }
        else{
            occurences[x] = occurences[x]+1;
            if (occurences[x]==2) duplicates.insert(x);
            else if(duplicates.find(x)!=duplicates.end() && occurences[x] > 2){
                duplicates.erase(x);
                if(multiple_occ.find(x)==multiple_occ.end())multiple_occ.insert(x);
            }
            else continue;
        }
        
    }
    int counter=0;
    for(auto& entry : duplicates){
        fs::path e = fs::path(entry+file_ext);
        fs::copy_file(e,tbd/e);
        bool x = fs::remove(e);
        if (x){
            cout << "Moved: " << entry+file_ext << "\n";
            ++counter;
        }
    }
    for(string entry: multiple_occ){
        entry.erase(entry.begin(),entry.begin()+entry.rfind('\\')+1);
        cout << "Failed to delete filename(duplicates detected): " << entry << "\n";
    }
    cout << "Total Files Deleted: " << counter << "\n";
    return;
}

int main(){
    string yes;
    cout << "This script will scan through all the files in your current directory and delete files if the corresponding jpeg is deleted.\n";
    cout << "Press Y to continue, otherwise press any key.\n";
    cin >> yes;
    if(yes=="Y"||yes=="y"){
        easy_delete();
    }
    else{
        return 0;
    }
    cout << "You may now close the program...";
    cin >> yes;
    cout << "Program closing..."; //You probably won't see this

}