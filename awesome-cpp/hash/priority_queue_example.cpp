#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
/*
vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
    vector<vector<int>> result;
    result.reserve(k);
    priority_queue<point> q;

    for(auto& p : points)
    {
        int distance = p[0] * p[0] + p[1] * p[1];
        q.push({distance, p[0], p[1]});
        if(k < q.size())
        {
            q.pop();
        }
    }

    while(!q.empty())
    {
        auto p = q.top();
        q.pop();
        vector<int> temp = {p.x, p.y};
        result.push_back(std::move(temp));
    }
    return result;
}
*/
struct point
{
    int distance;
    int x;
    int y;
    bool operator<(const point& rhs) const
    {
        return this->distance > rhs.distance;
    }
};
/**
 *
 struct myComp
 {
    bool operator()(const ListNode *x, const ListNode *y)
    {
        return x->val > y->val;
    }
 ;

 ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, myComp> minHeap;
 */
int main()
{
    // std::priority_queue<point> q;
    // q.push({5, 10, 10});
    // q.push({4, 10, 10});
    // q.push({-1, 10, 10});
    // while(!q.empty())
    // {
    //     point p = q.top();
    //     q.pop();
    //     printf("distance: %d (%d %d)\n", p.distance, p.x, p.y);
    // }

    // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,
    // int>>,
    //                     std::greater<std::pair<int, int>>>
    //     q;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        q;
    q.push({5, 10});
    q.push({4, 10});
    q.push({-1, 10});
    while(!q.empty())
    {
        auto [x, y] = q.top();
        q.pop();
        printf("(%d %d)\n", x, y);
    }
}