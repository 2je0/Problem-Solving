#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    unordered_map<string, int> umap;
    umap.insert({"이제영", 90});
    umap.emplace("이제원", 100);
    for (auto ele : umap)
    {
        cout << ele.first << " : " << ele.second << '\n';
    }
    auto search = umap.find("이이이");
    if (search != umap.end())
    {
        cout << "found" << endl;
    }
    else
        cout << "not found" << endl;
    umap.erase("이제영");

    return 0;
}