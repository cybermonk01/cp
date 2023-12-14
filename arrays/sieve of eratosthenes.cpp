#include<bits/stdc++.h>

using namespace std;



vector<bool> Sieve(int n){



    vector<bool>sieve(n+1, true);

sieve[0]= sieve[1]= false;

// for(int i = 2; i<=n ; i++){ //optimisation khali root n tak chalao 
for(int i = 2; i*i<=n ; i++){
if(sieve[i]== true){
  
    // int j = i*2; //optimisation  kyuki i*i ke pehle sab kat chuke honge
    int j = i*i;

    while(j<=n){
        sieve[j] = false;
        j+=i;
}
    }
}
return sieve;
}

int main(){


    vector<bool>sieve = Sieve(25);
for(int i = 0; i<= 25; i++){
  if(sieve[i] == true){
    cout<<i<<" ";
  }
}
}