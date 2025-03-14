#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void outputcaller(const vector<string>& a) {
    cout << "Unfollowers" << endl;
    for (const string& line : a) {
        cout << line << '\n';
    }

}

vector<string> comparison(const vector<string>& a, const vector<string>& b) {
    vector<string> result;
    for (const string& line : b) {
        if (find(a.begin(), a.end(), line) == a.end()) {  
            result.push_back(line);
        }
    }
    return result;
}

void inputcaller() {
    vector<string> myfollowers;
    vector<string> myfollowings;
    string line;

    cout << "Enter your followers here:\nPress Enter when finished" << endl;
    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        else if (line.find("Foto de Perfil") != string::npos) continue; 
        else{myfollowers.push_back(line);}
    }

    cout << "Enter your followings here:\nPress Enter when finished" << endl;
    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        else if (line.find("Foto de Perfil") != string::npos) continue;
        else myfollowings.push_back(line);
    }

    vector<string> result = comparison(myfollowers, myfollowings);
    outputcaller(result);
}

int main() {
    inputcaller();
    return 0;
}