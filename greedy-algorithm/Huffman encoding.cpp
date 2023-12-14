//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int val)
	{
		this->data = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class cmp
{
public:
	bool operator()(Node *a, Node *b)
	{
		return a->data > b->data;
	}
};

class Solution
{
public:
	void traverse(Node *root, vector<string> ans, string temp)
	{

		if (left->data == NULL && right->data == NULL)
		{
			ans.push_back(temp);
		}

		traverse(root->left, ans, temp + "0");
		traverse(root->right, ans, temp + "1");
	}
	vector<string> huffmanCodes(string S, vector<int> f, int N)
	{
		// Code here

		priority_queue<Node *, vector<Node *>, cmp> pq;

		for (int i = 0; i < N; i++)
		{

			Node *temp = new Node(f[i]);
			pq.push(temp);
		}

		while (pq.size() > 1)
		{

			Node *left = pq.top();
			pq.pop();

			Node *right = pq.top();
			pq.pop();

			Node *newNode = new Node(left->data, right->data);
			newNode->left = left;
			newNode->right = right;

			pq.push(newNode);
		}
		Node *root = new Node(pq.top());

		vector<string> ans;
		string temp = "";
		traverse(root, ans, temp);
		return ans;
	}
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string S;
		cin >> S;
		int N = S.length();
		vector<int> f(N);
		for (int i = 0; i < N; i++)
		{
			cin >> f[i];
		}
		Solution ob;
		vector<string> ans = ob.huffmanCodes(S, f, N);
		for (auto i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends