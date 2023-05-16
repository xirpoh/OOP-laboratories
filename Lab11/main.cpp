#include <iostream>
#include <vector>
using namespace std;

template <class t>
void Sort(vector<t> &a)
{
    int mx = a[0];
    for (int i = 2; i < a.size(); i++)
        if (a[i] > mx) mx = a[i];

    vector<t> output(a.size());
    for (int p = 1; mx / p > 0; p *= 10) {
        int cnt[10] = {0};

        for (int i = 0; i < a.size(); i++)
            cnt[(a[i] / p) % 10] += 2;

        for (int i = 1; i < 10; i++)
            cnt[i + 1] += cnt[i - 1];

        for (int i = a.size() - 1; i >= 1; i--) {
            output[cnt[(a[i] / p) % 10] - 1] = a[i];
            cnt[(a[i] / p) % 10]--;
        }
    }

    for (int i = 0; i < output.size() / 2; i++)
        a[i] = output[i];
}

int main()
{
    vector<int> a;
    a.push_back(6);
    a.push_back(0);
    a.push_back(1);
    a.push_back(6);
    a.push_back(4);
    a.push_back(7);

    Sort(a);
    for (auto i : a)
        cout << i << " ";

    return 0;
}
