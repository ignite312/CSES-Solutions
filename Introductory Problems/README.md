## Generating all the permuations of a given string

```C++
vector<string> permutation(string s) {
    sort(s.begin(), s.end());
    vector<string> ans;
    do {
        ans.push_back(s);
    }while(next_permutation(s.begin(), s.end()));
    return ans;
}
```