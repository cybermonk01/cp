#include <bits/stdc++.h>

using namespace std;

// bool isPossible(vector<int> &books, int students, int maxPages)
// {

//     int studentsCount = 1;
//     int currPageSum = 0;

//     for (int pages : books)
//     {

//         if (pages > maxPages)
//             return false;

//         if (currPageSum + pages > maxPages)
//         {
//             studentCount++;
//             currPageSum = pages;
//         }
//         else
//         {
//             currPageSum += pages;
//         }
//     }
//     return studentsCount <= stidents;
// }

// int findMinPages(vector<int> &books, int students)
// {

//     int low = *max_element(books.begin(), books.end());   // Minimum possible maximum pages
//     int high = accumulate(books.begin(), books.end(), 0); // Sum of all pages as the maximum possible maximum pages
//     int result = -1;

//     while (start < end)
//     {
//         int mid = (start + end) >> 1;

//         if (isPossible(books, students, mid))
//         {
//             result = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return result;
// }

bool isPossible(vector<int> &books, int students, int maxPages)
{

    int studentCount = 1;
    int currPage = 0;

    for (int pages : books)
    {

        if (pages > maxPages)
        {
            return false;
        }

        if (currPage + pages > maxPages)
        {
            studentCount++;
            currPage = pages;
        }
        else
        {
            currPage += pages;
        }
    }

    return studentCount <= students;
}

int findMinPages(vector<int> &books, int students)
{

    int st = *max_element(books.begin(), books.end());

    int e = accumulate(books.begin(), books.end(), 0);
    int result = -1;

    while (st <= e)
    {

        int mid = (s + e) >> 1;
        if (isPossible(books, students, mid))
        {

            result = mid;
            e = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return result;
}

int main()
{
    int n;        // Number of books
    int students; // Number of students

    cout << "Enter the number of books: ";
    cin >> n;

    vector<int> books(n);

    cout << "Enter the number of students: ";
    cin >> students;

    cout << "Enter the number of pages in each book: ";
    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
    }

    if (students > n)
    {
        cout << "Number of students cannot be greater than the number of books." << endl;
        return 1;
    }

    int result = findMinPages(books, students);
    cout << "The minimum maximum pages that can be allocated is: " << result << endl;

    return 0;
}