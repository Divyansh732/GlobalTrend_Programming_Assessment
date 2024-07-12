#include <iostream>
#include <vector>
using namespace std;

int maxDifference(vector<int> nums){
    int n=nums.size();
    int max=nums[n-1];
    int min=nums[0];
    for(int i=0;i<n;i++){
        if(nums[i]<min)
        {
            min=nums[i];
        }
        else if (nums[i]>max)
        {
            max=nums[i];
        }
  }
  return max-min;
}
int main(){
    vector<int> num={56,33,99,11,76,55};
    cout<<"max difference between elements = "<<maxDifference(num)<<endl;
}