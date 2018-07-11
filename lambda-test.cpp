
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int main()
{
    vector<string> vs;
    
    vs.push_back("1");
    vs.push_back("12");
    vs.push_back("123");
    vs.push_back("1234");
    
    vector<string> v1;
    vector<string> v2;
    
    v1.push_back("3");
    v1.push_back("12");
    v1.push_back("123");
    v1.push_back("1234");
    
    v2.push_back("1");
    v2.push_back("12");
    v2.push_back("123");
    v2.push_back("1234");
    
    function<void(vector<string>&)> align([](vector<string> &v){for(auto &s : v) s.insert(0,4-s.length(),'0');});
    
    //vector<string> f([](vector<string> v){vector<string> r; /*for(auto s : v) r.push_back(s.insert(0,4-s.length(),'0'));*/ return r;});
    //function<vector<string>(vector<string>)> f = [](vector<string> v) {vector<string> r; for(auto &s : v) r.push_back(s.insert(0,4-s.length(),'0')); return r; };
    function<vector<string>(vector<string>)> f = [](vector<string> v) {for(auto &s : v) s.insert(0,4-s.length(),'0'); return v; };
    
    for(auto s : vs) cout << s << endl;
    
    cout << ((f(v1) > f(v2)) ? "true" : "false");
    
    cout << endl;
    
    //for(auto &s : vs) s.insert(0,4-s.length(),'0');
    align(vs);
    
    //for(int i=0;i<4;i++) vs[i].insert(0,4-vs[i].length(),' ');
    
    for(auto s : vs) cout << s.insert(0,"0x") << endl;

    return 0;
}
