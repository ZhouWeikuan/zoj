#include<iostream>
#include<sstream>

using namespace std;

int main(){
    int lastsecond = 0;
    int lastspeed = 0;
    double lastkm = 0;
    int now;
    int elp;
    
    string s;
    int hour,minute,second;
    char c;
        
    while(getline(cin,s,'\n')){
        istringstream istream(s);
        istream >> hour >>c >> minute >>c >>second;
        now = hour *3600 + minute * 60 + second;
        elp = now - lastsecond;
        if(elp < 0){
            elp += 24 * 3600;
        }
        lastkm  += (elp *lastspeed)/3600.0;
        lastsecond = now;
        if(istream >> elp){
            lastspeed = elp;
        } else {            
            cout.width(2);
            cout.fill('0');
            cout<<hour<<c;
            cout.width(2);
            cout.fill('0');
            cout<<minute<<c;
            cout.width(2);
            cout.fill('0');
            cout<<second<<" ";
            cout.setf(ios::fixed);
            cout.precision(2);
            cout<<lastkm<<" km"<<endl;
        }
        
    }
    return 0;
}
