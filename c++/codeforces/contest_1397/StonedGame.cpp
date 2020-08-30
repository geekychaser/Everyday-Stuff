#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>v(n);

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<n;i++){
            cin>>v[i];
            pq.push(make_pair(v[i],i));
        }

        int a = -1; // t ne kya chla
        int b = -1; // hel ne chla 
        int counter = 0;

        pair<int,int>temp;
        pair<int,int>temp2;

        string winner = "HL";
        string looser = "";


        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            if(counter & 1){
                winner = "HL";
                if(temp.second != a){
                    temp.first--;
                    b = temp.second;
                    if(temp.first > 0){
                        pq.push(temp);
                    }
                }
                else{
                    if(pq.empty()){
                        looser = "T";
                        break;
                    }
                    else{
                        temp2 = pq.top();
                        pq.pop();
                        pq.push(temp);
                        temp2.first--;
                        b = temp2.second;
                        if(temp2.first > 0){
                            pq.push(temp2);
                        }

                    }
                }
            }
            else{
                winner = "T";
                if(temp.second != b){
                    temp.first--;
                    a = temp.second;
                    if(temp.first > 0){
                        pq.push(temp);
                    }
                }
                else{
                    if(pq.empty()){
                        looser = "HL";
                        break;
                    }
                    else{
                        temp2 = pq.top();
                        pq.pop();
                        pq.push(temp);
                        temp2.first--;
                        a = temp2.second;
                        if(temp2.first > 0){
                            pq.push(temp2);
                        }
                    }
                }
            }

            counter++;

        }

        if(looser == "")
            cout<<winner<<endl;
        else
            cout<<looser<<endl;
    }
}