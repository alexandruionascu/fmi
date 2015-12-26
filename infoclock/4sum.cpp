#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< vector<int> > fourSum(vector<int>& nums, int target)
    {

        vector< vector<int> > solution;
        vector< pair <int, pair <int, int> > > sums;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                int sum = nums[i] + nums[j];
                sums.push_back(make_pair(sum, make_pair(i, j)));
            }
        }

        sort(sums.begin(), sums.end());

        int left = 0;
        int right = sums.size() - 1;

        while(left < right)
        {
            if(sums[left].first + sums[right].first == target)
            {
                vector<int> sol;
                sol.push_back(sums[left].second.first);
                sol.push_back(sums[left].second.second);
                sol.push_back(sums[right].second.first);
                sol.push_back(sums[right].second.second);

                solution.push_back(sol);
            }
            else if(sums[left].first + sums[right].first < target)
            {
                left++;
            }
            else right--;
        }

        return solution;
    }


int main()
{

    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);

    vector< vector<int> > a = fourSum(v, 3);
}
