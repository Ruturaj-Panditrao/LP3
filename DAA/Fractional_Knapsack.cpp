// Fractional Knapsack Problem using Greedy Strategy

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Custom Comparator Function to sort items based on Profit/Weight ratio in a Descending Fashion
// Items with high Profit/Weight Ratio should be Picked up First, since we solve by Greedy Strategy

bool compare(pair<int,int>p1, pair<int,int>p2)
{
    double v1 = (double) p1.first/p1.second;
    double v2 = (double) p2.first/p2.second;
    return v1>v2;
}


int main()
{
    int n;
    cout<<"Enter the Number of Items : "<<endl;
    cin>>n;
    vector<pair<int,int>>items(n);
    cout<<"For Each item, Enter the Profit and Weight : "<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<"Item "<<i<<endl;
        cout<<"Enter Profit : ";
        cin>>items[i-1].first;
        cout<<"Enter Weight : ";
        cin>>items[i-1].second;
        cout<<endl;
    }

    int weight;
    cout<<"Enter the Weight of the Knapsack : ";
    cin>>weight;

    sort(items.begin(),items.end(),compare);

    // Sort the items based on Profit/Weight ratio in a Descending Fashion
    // Items with high ratio should occur first

    double ans = 0; // Final Answer
    for(int i=0; i<n; i++)
    {
        if(weight >= items[i].second)
        {
            // We can take this item,
            // Knapsack has space for this entire item
            // Grab the item completely
            ans += items[i].first;
            weight-=items[i].second;
            continue;
        }

        // Grab as much of this item as you can
        double pw = (double) items[i].first/items[i].second;
        ans += pw*weight;
        // Since we did not go inside above if block, space in Knapsack is less than total weight of item,
        // So we grab as many fractions of that item as possible, until our knapsack is exhausted.
        weight = 0;
        break;
    }

    cout<<"Maximum Profit Achieved using Greedy Strategy is : "<<ans<<endl;
}

// Time Complexity : O(N)
// Space Complexity : O(1)
