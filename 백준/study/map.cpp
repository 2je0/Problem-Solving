#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    unordered_map<string, int> umap;
    umap.insert({"������", 90});
    umap.emplace("������", 100);
    for (auto ele : umap)
    {
        cout << ele.first << " : " << ele.second << '\n';
    }
    auto search = umap.find("������");
    if (search != umap.end())
    {
        cout << "found" << endl;
    }
    else
        cout << "not found" << endl;
    umap.erase("������");

    return 0;
}