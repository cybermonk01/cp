#include <bits/stdc++.h>

using namespace std;


void minL(vector<int>&v, vector<int>&left){
int pseudoIndex = -1;


stack<pair<int, int>> st;

for(int i = 0; i<v.size(); i++){

if(st.empty()){
    left.push_back(pseudoIndex);
}else if(!st.empty() && st.top().first<v[i] ){
    left.push_back(st.top().second);
}
else if(!st.empty() && st.top().first>= v[i]){

    while(!st.empty() && st.top().first>= v[i]){
        st.pop();
    }

    if(st.empty()){
        left.push_back(pseudoIndex);
    }else {
        left.push_back(st.top().second);
    }
}

st.push({v[i],i});
}

}


void minR(vector<int>&v, vector<int>&right){
int pseudoIndex = v.size();


stack<pair<int, int>> st;

for(int i = v.size()-1; i>=0; i--){

if(st.empty()){
    right.push_back(pseudoIndex);
}else if(!st.empty() && st.top().first<v[i] ){
    right.push_back(st.top().second);
}
else if(!st.empty() && st.top().first>= v[i]){

    while(!st.empty() && st.top().first>= v[i]){
        st.pop();
    }

    if(st.empty()){
        right.push_back(pseudoIndex);
    }else {
        right.push_back(st.top().second);
    }
}

st.push({v[i],i});
}
reverse(right.begin(), right.end());
}





int mah(vector<int> v){

    int n = v.size();

    vector<int> left;
    vector<int> right;


     minL(v, left);
     minR(v, right);


vector<int> width(n);
vector<int> area(n);
  
int maxi = -1;
    for(int i = 0; i<n; i++){
        width[i] = right[i] - left[i] -1;
        area[i] = width[i] * v[i];
        maxi = max(maxi, area[i]);
    }
    return maxi;
}







int main()
{

    vector<vector<int>> arr = {{0, 1, 1, 0},
                               {1, 1, 1, 1},
                               {1, 1, 1, 1},
                               {1, 1, 0, 0}};

    vector<int> v;
    int n = arr.size();
    int m = arr[0].size();

    for (int j = 0; j < m; j++)
    {

        v.push_back(arr[0][j]);
    }

    int maxi = mah(v);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                v[j] = 0;
            }
            else
            {
                v[j] = v[j] + arr[i][j];
            }
        }
        maxi = max(maxi, mah(v));
    }
    cout<<" max area histogram is "<<maxi;
}