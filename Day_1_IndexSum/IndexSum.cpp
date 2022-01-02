#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        vector<string> res;

        // always sum < m+n-1 , this will be in ascending order
        // we will iterate over first list and second list if they are equal we will push in the result
        // suppose  to get sum as 0 we need i+j=0 , so if we have some value of sum then j = sum -i
        for (int sum = 0; sum < list1.size() + list2.size() - 1; sum++)
        {
            //for every sum we will interate over list 1
            for (int i = 0; i <= sum; i++)
            {
                //so in list 2 index of j will be sum-i
                int j = sum - i;
                if (i < list1.size() and j < list2.size() and list1[i] == list2[j])
                {
                    res.push_back(list1[i]);
                }
            }
            //since we are setting the sum in ascending order now 
            //if our vector has one element that means it is corresponding to the minimum index 
            if(res.size()>0)
            {
                break;
            }

        }
        return res;
    }
};

int main(){

Solution s;

vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
vector<string> list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
vector<string> res =s.findRestaurant(list1,list2);
for(int i=0;i<res.size();i++){
    cout<<res[i];
}

return 0;
}