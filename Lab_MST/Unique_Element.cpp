
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n; cin>>n;
//     vector<int> nums(n);
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     int ans=0;
//     for(int i=0;i<32;i++){
//         int count=0;

//         for(auto it: nums){
//             if(it & (1<<i)){
//                 count++;
//             }
//         }

//         if(count%3 != 0){
//             ans |= (1<<i);
//         }
//     }
//     cout<<ans;
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int a=0;
    int b=0;

    for(auto it:nums){
        a = (a^it)& ~b;
        b = (b^it)& ~a;
    }
    cout<<a<<endl;
}
