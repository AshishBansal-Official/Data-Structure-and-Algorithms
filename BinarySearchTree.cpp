#include<iostream>
#define SPACE 10

class BinarySearchTree{
	struct Node {
		int data;
		Node* left;
		Node* right;
		
		Node() : data(0), left(nullptr), right(nullptr){}
		
		Node(int value) : data(value), left(nullptr), right(nullptr) {}
	};
	public:
	Node* root;
	BinarySearchTree() : root(nullptr) {}
	
	bool isTreeEmpty() {
		return root==nullptr;
	}
	
	void insertNodeIteratively(Node* node) {
		if(isTreeEmpty()) {
			root = node;
			std::cout<<"Value inserted at root node!!!"<<std::endl;
		} else {
			Node* temp = root;
			while(temp!=nullptr) {
				if(node->data <= temp->data && temp->left == nullptr) {
					temp->left = node;
					std::cout<<"Value added at left node"<<std::endl;
					return;
				} else if (node->data <= temp->data) {
					temp = temp->left;
				} else if(node->data > temp->data && temp->right == nullptr) {
					temp->right = node;
					std::cout<<"Value added at right node"<<std::endl;
					return;
				} else if (node->data > temp->data) {
					temp = temp->right;
				} else {
					temp = temp->right;
				}
			}
		}
	}
	
	Node* insertNodeRecursively(Node* root, Node* new_node) {
		if(root==nullptr) {
			root = new_node;
			std::cout<<"Insertion Successful!!!"<<std::endl;
			return root;
		} else if(new_node->data <= root->data) {
			root->left = insertNodeRecursively(root->left, new_node);
		} else if(new_node->data > root->data) {
			root->right = insertNodeRecursively(root->right, new_node);
		}
		return root;
	}
	
	void insertNode(int data) {
		Node* node = new Node(data);
		insertNodeIteratively(node);
//		root = insertNodeRecursively(root, node);
	}
	
	void print2DUtil(Node* r,int space) {
		if(r == nullptr) {
			return;
		}
		space += SPACE;
		print2DUtil(r->right, space);
		std::cout<<std::endl;
		for(int i = SPACE; i<space; i++) {
			std::cout<<" ";
		}
		std::cout<<r->data<<"\n";
		print2DUtil(r->left, space);
	}
	
	void print2D() {
		if(isTreeEmpty()){
			std::cout<<"Tree is empty!!!"<<std::endl;
		}
		print2DUtil(root, 5);
	}
	
	void preOrderTraversalUtil(Node* root) {
		if(root == nullptr) {
			return;
		} else {
			preOrderTraversalUtil(root->left);
			std::cout<<root->data<< ", ";
			preOrderTraversalUtil(root->right);
		}
	}
	
	void inOrderTraversalUtil(Node* root) {
		if(root == nullptr) {
			return;
		} else {
			std::cout<<root->data<<", ";
			inOrderTraversalUtil(root->left);
			inOrderTraversalUtil(root->right);
		}
	}
	
	void postOrderTraversalUtil(Node* root) {
		if(root == nullptr) {
			return;
		} else {
			postOrderTraversalUtil(root->left);
			postOrderTraversalUtil(root->right);
			std::cout<<root->data<<", ";
		}
	}
	
	void preOrderTraversal() {
		preOrderTraversalUtil(root);
		std::cout<<"\n";
	}
	
	void inOrderTraversal() {
		inOrderTraversalUtil(root);
		std::cout<<"\n";
	}
	
	void postOrderTraversal() {
		postOrderTraversalUtil(root);
		std::cout<<"\n";
	}
	
	void printGivenLevel(Node* root, int level) {
		if(root == nullptr) {
			return;
		} else if (level == 0) {
			std::cout << root->data << ", ";
		} else {
			printGivenLevel(root->left, level - 1);
			printGivenLevel(root->right, level - 1);
		}
	}
	
	void printLevelOrderBFS() {
		int h = height();
		for(int i = 0; i <= h; i++) {
			printGivenLevel(root, i);
		}
		std::cout<<std::endl;
	}
	
	void searchIteratively(int data) {
		if(isTreeEmpty()) {
			std::cout<<"Tree is Empty!!!"<<std::endl;
			return;
		} else {
			Node* temp = root;
			while(temp!=nullptr) {
				if(temp->data == data) {
					std::cout<<"Data Found!!!"<<std::endl;
					return;
				} else if(temp->data > data) {
					temp = temp->left;
				} else if(temp->data < data) {
					temp = temp->right;
				} else {
					temp = temp->right;
				}
			}
			std::cout<<"Data not found!!!"<<std::endl;
		}
	}
	
	Node* searchRecursivelyUtil(Node* root, int data) {
		if(root==nullptr || root->data == data) {
			return root;
		} else if (root->data < data) {
			searchRecursivelyUtil(root->right, data);
		} else {
			searchRecursivelyUtil(root->left, data);
		}
	}
	
	void searchRecursively(int data) {
		if(isTreeEmpty()) {
			std::cout<<"Tree is Empty!!!" <<std::endl;
		} else {
			Node* node = searchRecursivelyUtil(root, data);
			if(node) {
				std::cout<<"Data Found!!!"<<std::endl;
			} else {
				std::cout<<"Data not found!!!" <<std::endl;
			}
		}
	}
	
	int heightUtil(Node* root) {
		if(root == nullptr) {
			return -1;
		} else {
			int lHeight = heightUtil(root->left);
			int rHeight = heightUtil(root->right);
			
			if(lHeight > rHeight) {
				return lHeight + 1;
			} else return rHeight + 1;
		}
	}
	
	int height() {
		return heightUtil(root);
	}
	
	Node* minValueNode(Node* root) {
		Node* temp = root;
		while(temp->left != nullptr) {
			temp = temp->left;
		}
		return temp;
	}
	
	Node* deleteNodeUtil(Node* root, int data) {
		if (root == nullptr) {
			return nullptr;
		} else if (root->data > data) {
			root->left = deleteNodeUtil(root->left, data);
		} else if (root->data < data) {
			root->right = deleteNodeUtil(root->right, data);
		} else {
			if(root->left == nullptr && root->right == nullptr) {
				delete root;
				return nullptr;
			} else if (root->left == nullptr) {
				Node* temp = root->right;
				delete root;
				return temp;
			} else if (root->right == nullptr) {
				Node* temp = root->left;
				delete root;
				return temp;
			} else {
				Node* temp = minValueNode(root->right);
				root->data = temp->data;
				root->right = deleteNodeUtil(root->right, temp->data);
			}
		}
		return root;
	}
	
	void deleteNode(int data) {
		if(isTreeEmpty()) {
			std::cout<<"Tree is Empty!!!"<<std::endl;
			return;
		}
		deleteNodeUtil(root, data);
	}
};

int main() {
	BinarySearchTree bst;
	bst.insertNode(2);
	bst.insertNode(1);
	bst.insertNode(4);
	bst.insertNode(3);
	bst.print2D();
	bst.preOrderTraversal();
	bst.inOrderTraversal();
	bst.postOrderTraversal();
	bst.searchRecursively(1);
	std::cout<<"Height : "<<bst.height()<<std::endl;
	bst.printLevelOrderBFS();
	bst.deleteNode(5);
	bst.print2D();
	return 0;
}

//int main() {
//	BinarySearchTree obj;
//  	int option, val;
//
//  	do {
//    	std::cout << "What operation do you want to perform? " <<
//      			" Select Option number. Enter 0 to exit." << std::endl;
//	    std::cout << "1. Insert Node" << std::endl;
//	    std::cout << "2. Search Node" << std::endl;
//	    std::cout << "3. Delete Node" << std::endl;
//	    std::cout << "4. Print/Traversal BST values" << std::endl;
//	    std::cout << "5. Height of Tree" << std::endl;
//	    std::cout << "6. Clear Screen" << std::endl;
//	    std::cout << "0. Exit Program" << std::endl;
//
//    	std::cin >> option;
//    	//Node n1;
//    	
//    	switch (option) {
//    	case 0:
//      		break;
//	    case 1:
//	      	std::cout <<"INSERT"<<std::endl;
//		    std::cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
//		    std::cin >> val;
////		      new_node->value = val;
////		      obj.root= obj.insertRecursive(obj.root,new_node);
////		      //obj.insertNode(new_node);
//		    obj.insertNode(val);
//			std::cout<<std::endl;
//	    	break;
//	      
////	    case 2:
////	      cout << "SEARCH" << endl;
////	      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
////	      cin >> val;
////	      //new_node = obj.iterativeSearch(val);
////	      new_node = obj.recursiveSearch(obj.root, val);
////	      if (new_node != NULL) {
////	        cout << "Value found" << endl;
////	      } else {
////	        cout << "Value NOT found" << endl;
////	      }
////	      break;
////	    case 3:
////	      cout << "DELETE" << endl;
////	      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
////	      cin >> val;
////	      new_node = obj.iterativeSearch(val);
////	      if (new_node != NULL) {
////	        obj.deleteNode(obj.root, val);
////	        cout << "Value Deleted" << endl;
////	      } else {
////	        cout << "Value NOT found" << endl;
////	      }
////	      break;
//	    case 4:
//	      std::cout << "PRINT 2D: " << std::endl;
//	      obj.print2D(obj.root, 5);
//	      std::cout << std::endl;
//	      std::cout << "Print Level Order BFS: \n";
////	      obj.printLevelOrderBFS(obj.root);
////	      cout << endl;
////	      //	      cout <<"PRE-ORDER: ";
////	      //	      obj.printPreorder(obj.root);
////	      //	      cout<<endl;
////	      //	      cout <<"IN-ORDER: ";
////	      //	      obj.printInorder(obj.root);
////	      //	      cout<<endl;
////	      //	      cout <<"POST-ORDER: ";
////	      //	      obj.printPostorder(obj.root);
////	      break;
////	    case 5:
////	      cout << "TREE HEIGHT" << endl;
////	      cout << "Height : " << obj.height(obj.root) << endl;
////	      break;
//	    case 6:
//	      system("cls");
//	      break;
//	    default:
//	      std::cout << "Enter Proper Option number " << std::endl;
//	    }
//	
//	  } while (option != 0);
//
//  	return 0;
//}
