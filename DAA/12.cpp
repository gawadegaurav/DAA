#include <iostream>
#include <vector>
using namespace std;

void calcSubset(vector<int>& A, vector<vector<int> >& res,
                vector<int>& subset, int index)
{
    res.push_back(subset);

    for (int i = index; i < A.size(); i++) {
        subset.push_back(A[i]);
        calcSubset(A, res, subset, i + 1);
        subset.pop_back();
    }
}

vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;
    int index = 0;
    calcSubset(A, res, subset, index);
    return res;
}

int main()
{
    vector<int> array = { 1, 2, 3 };
    vector<vector<int> > res = subsets(array);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}
//git init
// git add README.md
// git commit -m "first commit"
// git branch -M main
// git remote add origin https://github.com/gawadegaurav/DAA.git
// git push -u origin main