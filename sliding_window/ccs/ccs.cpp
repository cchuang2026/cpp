#include<iostream>
#include <set>
using namespace std;

int main(){
    int n,q;
    cin >> n >>q;

    set<int> sleep;

    for(int i=0;i<q;i++){
        string op;
        cin >> op;

        if(op=="SLEEP"){
            int x;
            cin >> x;
            sleep.insert(x);
        }else if(op=="WAKE"){
            int x;
            cin >> x;
            sleep.erase(x);
        }else{
            int x,y;
            cin >> x>>y;

            auto lb=sleep.lower_bound(x);
            if(lb==sleep.end() || (*lb!=x && *lb>y)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}