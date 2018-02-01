#include <map>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

std::map<int, int> cache = {{1, 1}};

int collatz(int n){
    if ( cache.find(n) == cache.end() ){
        cache[n] = collatz(n % 2 == 0 ? n >> 1 : 3 * n + 1) + 1;
    } else {
        return cache[n];
    }

}

int main(){
    string line;
    while(getline(cin, line)){
        try {
            vector<int> res;
            istringstream iss(line);
            for(string line; iss >> line;){
                res.push_back(stoi(line));
            }
            int max = 0;
            for(int i = res[0]; i < res[1]; ++i){
                if(collatz(i) > max){
                    max = collatz(i);
                }
            }
            cout << res[0] << " " << res[1] << " " << max << endl;
        } catch (...) {}
    }
    return 0;
}
