#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool areAnagram(string &s1, string &s2)
{

    if (s1.length() != s2.length())
        return false;

    unordered_map<char, int> count;

    for (char c : s1)
    {
        count[c]++;
    }

    for (char c : s2)
    {
        if (count.find(c) == count.end() || count[c] <= 0)
        {
            return false;
        }
        count[c]--;
    }
    return true;
}

int countAnagramOccurences(string &text, string &pattern)
{

    int m = text.length();
    int n = pattern.length();

    if (n > m)
        return 0;

    int count = 0;

    for (int i = 0; i <= n - m; ++i)
    {
        string sub = text.substr(i, n);

        if (areAnagram(sub, pattern))
        {
            count++;
        }
    }
    return count;
}
int main()
{
    string text = "forxxorfxdofr";
    string pattern = "for";

    int occurrences = countAnagramOccurrences(text, pattern);
    cout << "Occurrences of anagrams: " << occurrences << endl;

    return 0;
}