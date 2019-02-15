/*
 * author: bayleaf
 * date: 2/15/2019
 * file. bst.hpp
 */
 
 
 /* 
  * Templated Binary Search Tree for all the computer science nerds out there 
  */
  
 #ifndef BST_HPP
 #define BST_HPP
 
#include <iostream>
#include <functional>
#include <initializer_list>
#include <queue>
#include <cstdint>
  
  
namespace ads
{
	
	/*  binary search tree */
	template<typename T>
	class BinarySearchTree
	{
		public:
		
			/* BSTNode representation */
			struct BSTNode
			{
				T val;
				BSTNode* left;
				BSTNode* right;
				BSTNode(T value) : val(value), left(nullptr), right(nullptr) {}
			};
			
			BinarySearchTree() = default;
			
			/* Insert one value */
			BinarySearchTree(T root_val) { insert(root_val, &this->root); }
			
			/* Insert one value */
			BinarySearchTree(std::initializer_list<T> keys) { insertVals(keys, &this->root); }
			
			~BinarySearchTree() { destroy(this->root); root = nullptr; }
			
			/* Delete copy ops */
			BinarySearchTree(const BinarySearchTree& right) = delete;
			BinarySearchTree& operator=(const BinarySearchTree& right) = delete;
			
			/* Delete move ops for now */
			BinarySearchTree(BinarySearchTree&& right) = delete;
			BinarySearchTree& operator=(BinarySearchTree&& right) = delete;
			
			/* Inserts the BSTNode with the new key */
			void insertValue(T key)
			{
				insert(key, &this->root);
			}
			
			/* Insert more than one value using intializer list */
			void insertValues(std::initializer_list<T> keys)
			{
				insertVals(keys, &this->root);
			}
			
			void traverseInOrder(std::function<void(const T&)> op = [](const T& val) -> void { std::cout << val << std::endl; }) const
			{
				traverseIn(this->root, op);
			}
			
			void traversePreOrder(std::function<void(const T&)> op = [](const T& val) -> void { std::cout << val << std::endl; }) const
			{
				traversePre(this->root, op);
			}
			
			void traversePostOrder(std::function<void(const T&)> op = [](const T& val) -> void { std::cout << val << std::endl; }) const
			{
				traversePost(this->root, op);
			}
			
			/* Search for key in tree, returns true if found */
			bool keySearch(T key) const
			{
				return search(key, this->root);
			}
			
			/* Get max depth of tree */
			int64_t depth() const
			{
				return dive(this->root);
			}
			
			/* Invert the tree, left = right, right = left */
			void invertTree() 
			{
				invert(this->root);
			}
			

		private:
			BSTNode* root = nullptr;
			
      
			/* Recurse and destroy every node, setting root to nullptr */
			void destroy(BSTNode* head)
			{
			  if (!head)
				return;

			  /* Destroy in post order way */
			  destroy (head->left);
			  destroy (head->right);
			  delete (head);
			}
			

			/* Insert a node with a value */
			void insert(T key, BSTNode** head) 
			{
				/* Base case */
				if (!(*head)) { *head  = new BSTNode(key); }
				else
				{	
					/* If the key is less than the nodes value go left */
					if(key < (*head)->val) insert(key, &(*head)->left);
					/* Otherwise go right */
					else insert(key , &(*head)->right);
				}
				
				return;
			}
			
			/* Insert many values at once */
			void insertVals(std::initializer_list<T> keys, BSTNode** head) 
			{
				for(const auto& item : keys)
					insert(item, head);
			}
			
			/* travers in order */
			void traverseIn(BSTNode* head, std::function<void(const T&)> op) const
			{
				if(head)
				{
					traverseIn(head->left, op);
					op(head->val);
					traverseIn(head->right, op);
				}
				
				return;
			}
			
			/* pre order traversal */
			void traversePre(BSTNode* head, std::function<void(const T&)> op) const
			{
				if(head)
				{
					op(head->val);
					traversePre(head->left, op);
					traversePre(head->right, op);
				}
				
				return;
			}
			
			/* post order traversal */
			void traversePost(BSTNode* head, std::function<void(const T&)> op) const
			{
				if(head)
				{
					traversePost(head->left, op);
					traversePost(head->right, op);
					op(head->val);
				}
				
				return;
			}
			
			/* search for a key, true if found */
			bool search(T key, BSTNode* head) const
			{
				if(head)
				{
					/* If the key is less than the nodes value go left */
					if(key < head->val) return search(key, head->left);
					/* Otherwise go right */
					else if (key > head->val) return search(key , head->right);
					/* Or we found it */
					else return true;
					
				}
				
				return false;
			}
			
			int64_t dive(BSTNode* head) const
			{
				if(head)
				{
					return 1 + std::max(dive(head->left), dive(head->right));
					
				}
				return 0;
			}

   
			/* Inverts a binary tree */
			void invert(BSTNode* head)
			{

				std::queue<BSTNode*> ptr;
        
				if(!root) return;
        
    				ptr.push(root);
			 	while(!ptr.empty())
			  	{
			   		BSTNode* temp = ptr.front();
			    		ptr.pop();

			    		std::swap(temp->left, temp->right);

			    		if(temp->left) ptr.push(temp->left);
			    		if(temp->right) ptr.push(temp->right);

			  	}
			}
	};
}


#endif
