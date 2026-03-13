#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> token(n);
    for(int i=0;i<n;i++){
        cin>>token[i];
    }
    int power;
    cin>>power;

    int l=0; 
    int r=n-1;
    int score=0;
    int maxscore=0;

    sort(token.begin(), token.end());
    while(l<=r){
        if(token[l]<=power){
            score++;
            power -=token[l];
            l++;
            maxscore = max(maxscore, score);
        }
        else if(score>0){
            score--;
            power+= token[r];
            r--;
        }
        else break;
    }
    cout<<maxscore<<" ";
    return 0;
}
