#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std; 

class Solution{
public: 
      vector<vector<int>> KClosest(vector<vector<int>>& points, int k){
        vector<vector<int>> res; 
        int n = points.size();
        if(n<k) return res; 
        priority_queue<tuple<double, int,int>, vector<tuple<double,int,int>>, greater<>> pq;
        for(auto point:points){
          double dis= sqrt(pow(point[0],2)+pow(point[1],2));
          pq.push({dis, point[0], point[1]});
        }
        while(k>0){
          auto [dis, x,y] = pq.top(); 
          pq.pop();
          res.push_back({x,y});
          --k;
        }
        return res;
      }
};
int main(){
  vector<vector<int>> points={{3,3}, {5,-1}, {-2,4}}; 
    int k=2; 
    Solution sol; 
    vector<vector<int>> res=sol.KClosest(points,k); 
    cout << "[ "; 
    for(auto point:res){
        cout <<  "[" << point[0] << "," << point[1] << "]" ;
    }
    cout << "]" << endl; 
    return 0; 
}
