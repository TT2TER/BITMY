#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>

using namespace std;

long long int largest(vector<int>& heights)
{
    long long int ans = 0;
    vector<int> st;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.back()] > heights[i])
        {
            int cur = st.back();
            st.pop_back();
            int left = st.back() + 1;
            int right = i - 1;
            ans = max(ans, (long long int)(right - left + 1) * heights[cur]);
        }
        st.push_back(i);
    }
    return ans;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        vector<int> heights;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            heights.push_back(tmp);
        }
        long long int ans;
        ans = largest(heights);
        printf("%lld\n", ans);
    }
    return 0;
}