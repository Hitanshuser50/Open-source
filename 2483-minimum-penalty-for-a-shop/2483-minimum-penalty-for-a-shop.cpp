class Solution {
public:
    int bestClosingTime(string customers) {
         int n = customers.size();
        int ans=INT_MAX,ind = -1,a=0,b=0;
       vector<pair<int,int>>v(n);
       for(int i=0;i<n;i++){
           if(customers[i]=='Y'){
               a++;v[i] = {a,b};
           }
           else if(customers[i]=='N'){
               b++;v[i] = {a,b};
           }
       }
       for(int i=0;i<n;i++){
           int temp = v[i].second + v[n-1].first - v[i].first;
           if(customers[i]=='Y')temp++;
           else if(customers[i]=='N')temp--;
           if(ans>temp){
               ans = temp;
               ind =i;
           }
       }
        return ans>v[n-1].second?n:ind;
    }
};