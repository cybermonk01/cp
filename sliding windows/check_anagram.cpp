#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int countAnagram(string &s1, string &s2)
{
    int ans = 0;
    int m = s1.length();
    int n = s2.length();
    if (m < n)
        return 0;
    unordered_map<char, int> count;
    int totalCount = count.size();

    for (auto val : s2)
    {
        // pattern ki window banake map me vale store kro
        count[val]++;
    }

    int i = 0, j = 0;
    while (j < m)
    {
        // agar map me wo word milta hai jo ki text me hai so uss word ke count ko minus kar denge aur agar 0 ho jayega to uss map ka size chota kar denge
        if (count.find(s1[j]) != count.end())

        {

            count[s1[j]]--;

            if (count[s1[j]] == 0)
            {
                totalCount--;
            }
        }

        // k ki jagah yaha pattern ka size hoga
        if (j - i + 1 < n)
        {
            j++;
        }
        else if (j - i + 1 == n)
        {

            // window ka size barabar ho gaya
            if (totalCount == 0)
                ans++;

            // aage badhao window ko aur i  pointer me jo calculations hai usko apni pattern wali window me wapas lao

            if (count.find(s1[i]) != count.end()) // agar map me wo element mil gaya
                count[s1[i]]++;

            if (count[s1[i]] == 1)
                totalCount++;
            i++; // i bhi to badhana hai
        }

        j++;
    }
    return ans;
}

int main()
{

    string text = "forxxorfxdofr";
    string pattern = "for";

    int occurrences = countAnagram(text, pattern);
    cout << "Occurrences of anagrams: " << occurrences << endl;

    return 0;
}