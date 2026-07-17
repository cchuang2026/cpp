#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;

ll numconverted(char c){
if(c=='A'){
    return 1;
}else if(c=='B'){
    return 2;
}else if(c=='C'){
    return 3;
}else if(c=='D'){
    return 4;
}else if(c=='E'){
    return 5;
}else if(c=='F'){
    return 6;
}else if(c=='G'){
    return 7;
}else if(c=='H'){
    return 8;
}else if(c=='I'){
    return 9;
}else if(c=='J'){
    return 10;
}else if(c=='K'){
    return 11;
}else if(c=='L'){
    return 12;
}else if(c=='M'){
    return 13;
}else if(c=='N'){
    return 14;
}else if(c=='O'){
    return 15;
}else if(c=='P'){
    return 16;
}else if(c=='Q'){
    return 17;
}else if(c=='R'){
    return 18;
}else if(c=='S'){
    return 19;
}else if(c=='T'){
    return 20;
}else if(c=='U'){
    return 21;
}else if(c=='V'){
    return 22;
}else if(c=='W'){
    return 23;
}else if(c=='X'){
    return 24;
}else if(c=='Y'){
    return 25;
}else if(c=='Z'){
    return 26;
}
}
int main(){
    //freopen("sample.in","r",stdin);
    string comet,group;
    cin >> comet>>group;
    ll totalcomet=1;
    for(int i=0;i<comet.size();i++){
        char c=comet[i];
        ll cur_num=numconverted(c);
        totalcomet=totalcomet*cur_num;
    }

    ll totalgroup=1;
    for(int i=0;i<group.size();i++){
        char c=group[i];
        ll cur_num=numconverted(c);
        totalgroup=totalgroup*cur_num;
    }

    if(totalgroup%47==totalcomet%47){
        cout<<"GO";
    }else {
        cout<<"STAY";
    }

    return 0;
}