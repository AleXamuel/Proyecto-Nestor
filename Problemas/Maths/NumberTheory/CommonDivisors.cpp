//https://cses.fi/problemset/task/1081

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
 
vector<int> get_divisors(int n){
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            divisors.push_back(i);
            if (i != n / i){
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;    
} 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    vector<int> arr(n, 0);
    unordered_set<int>arrSet;
    int maxi = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arrSet.find(arr[i]) == arrSet.end()) 
            arrSet.insert(arr[i]); 
        else{
            maxi = max(maxi, arr[i]); //para numeros repetidos, puede que el gcd entre dos numeros sean ellos mismos
        }
    }
    sort(arr.begin(), arr.end());
    unordered_set<int>div;
      
    for (int i = n - 1; i >= 0; i--){
        vector<int> divisors = get_divisors(arr[i]);
        if (arr[i] / 2 < maxi && i == n - 1) // si ya tenemos un numero guardado en maxi, verificamos si el divisisor siguiente mas grande es menor a nuestro maximo, el divisor siguiente mas grande posible es el numero mas grande del arreglo divido en 2, esto evita hacer iteraciones innecesarias.
            break;
        sort(divisors.begin(), divisors.end(), greater<int>());
        for (int divisor : divisors){
            if (div.find(divisor) == div.end())
                div.insert(divisor);
            else{
                maxi = max(maxi, divisor);
                break;
            }
        }
    }
    cout << maxi << endl;
    return 0;
}
