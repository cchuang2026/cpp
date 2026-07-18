#include<iostream>
#include<vector>
using namespace std;

int main(){
   
    int l;
    cin >> l;

    vector<int> v(l);
    for(int i=0;i<l;i++) cin >> v[i];

    sort(v.begin(),v.end());

    int q;
    cin >> q;

    for(int i=0;i<q;i++){
        int x;
        cin >> x;

        auto it=upper_bound(v.begin(),v.end(),x);

        int smaller=(it-v.begin())-1;
        cout<<"Smaller: "<<smaller<<", ";

        int bigger=(v.end()-it)+1;
        cout<<"Greater: "<<bigger<<endl;

    }
}