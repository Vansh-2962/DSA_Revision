#include<iostream>
#include<queue>
using namespace std;

class Tree{
    public:
        int data;
        Tree* left;
        Tree* right;
        Tree(int val){
            data = val;
            left = right = NULL;
        }
};

class BinaryTree{
    private:
        Tree* root;
    public:
        BinaryTree(){
            root = NULL;
        }

        Tree* getRoot(){
            return root;
        }

        void insert(int val){
            Tree* newNode = new Tree(val);

            if(root == NULL){
                root = newNode;
                return;
            }

            queue<Tree*> q;
            q.push(root);

            while(!q.empty()){
                Tree* front = q.front();
                q.pop();

                if(front -> left == NULL){
                    front -> left = newNode;
                    return;
                }else{
                    q.push(front->left);
                }

                if(front -> right == NULL){
                    front -> right = newNode;
                    return;
                }else{
                    q.push(front->right);
                }
            }
        }

        void inOrder(Tree* node){
            if(node == NULL) return;
            inOrder(node -> left);
            cout << node -> data << " ";
            inOrder(node -> right);
        }

        void preOrder(Tree* node){
            if(node == NULL) return;
            cout << node -> data << " ";
            preOrder(node -> left);
            preOrder(node -> right);
        }
        void postOrder(Tree* node){
            if(node == NULL) return;
            preOrder(node -> left);
            preOrder(node -> right);
            cout << node -> data << " ";
        }

        void levelOrder(){
            if(root == NULL) return;
            
            queue<Tree*> q;
            q.push(root);

            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();

                cout << temp -> data << " ";

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            cout << endl;
        }


        Tree* deleteNode(int val){
            if(root == NULL) return NULL;

            // if tree has 1 node
            if(root -> left == NULL && root -> right == NULL){
                if(root -> data == val) return NULL;
                else return root;
            }

            queue<Tree*> q;
            q.push(root);

            Tree* current;
            Tree* keyNode = NULL;

            while(!q.empty()){
                current = q.front();
                q.pop();
                
                // if current node is the key node
                if(current -> data == val) keyNode = current;
                if(current -> left) q.push(current -> left);
                if(current -> right) q.push(current -> right);
            }

            if(keyNode != NULL){
                int x = current -> data;
                keyNode -> data = x;
                deleteNode(current->data);
            }
           return root;
        }


        bool search(int val){
            if(root == NULL) return false;

            queue<Tree*> q;
            q.push(root);

            while(!q.empty()){
                Tree* temp = q.front();
                q.pop();

                if(temp -> data == val) return true;

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);

            }
            return false;
        }

        int height(Tree* node){
            if(node == NULL) return 0;
            return max(height(node -> left), height(node -> right)) + 1;
        }
};

int main(){
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    tree.levelOrder();
    tree.deleteNode(3);

    return 0;
}