#include<bits/stdc++.h>

using namespace std;
template <typename V>
class BST{
	private:
		struct BinaryNode{
			V value;
			BinaryNode* left;
			BinaryNode* right;
			BinaryNode(V v):value(v), left(nullptr), right(nullptr) {};
		};

	public:


		BinaryNode* root;
		BST(): root(nullptr){};
		
		void insert(V val)
		{
			BinaryNode *newNode = new BinaryNode(val);
			
			this->root = insertBST(this->root, newNode);

		}

		BinaryNode* insertBST(BinaryNode* root, BinaryNode* n)
		{
			if(!root)
			{
				root = n;
				return root;
			}
			else if(n->value < root->value)
				return insertBST(root->left,n);
			else
				return insertBST(root->right,n);
		}

		bool search(V val)
		{
			return searchBST(root, val);
		}

		bool searchBST(BinaryNode* root, V val)
		{
			if(!root)
				return false;
			if(val < root->value)
				return insertBST(root->left, val);
			else if(val > root->value)
				return insertBST(root->right, val);
			else
				return true;
		}


		bool delval(V key)
		{
			return deleteBST(root, key);
		}

		V findSmallest(BinaryNode* root)
		{
			if(!root->left)
				return root->value;
			findSmallest(root->left);
		}

		bool deleteBST(BinaryNode* root, V dltKey)
		{
			if(!root)
				return false;
			if(dltKey < root->value)
				return deleteBST(root->left, dltKey);
			else if(dltKey > root->value)
				return deleteBST(root->right, dltKey);
			else
			{
				if(!root->left)
				{
					root = root->right;
					return true;
				}
				else if(!root->right)
				{
					root = root->left;
					return true;
				}
				else
				{
					V small = findSmallest(root->right);
					root->value = small;
					deleteBST(root->right,small);
				}
			}
		}

		void display()
		{
			cout<<"Pre: ";
			preOrder(root);
			cout<< endl << "In: ";
			inOrder(root);
			cout<< endl << "Post: ";
			postOrder(root);
		}

		void preOrder(BinaryNode* root)
		{
			cout << root->value << " ";
			preOrder(root->left);
			preOrder(root->right);
		}

		void inOrder(BinaryNode* root)
		{
			preOrder(root->left);
			cout << root->value << " ";
			preOrder(root->right);
		}

		void postOrder(BinaryNode* root)
		{
			preOrder(root->left);
			preOrder(root->right);
			cout << root->value << " ";
		}
	
};

int main()
{
	return 0;
}