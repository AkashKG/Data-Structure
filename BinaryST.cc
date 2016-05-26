#include<iostream>
#include<malloc.h>
#include<queue>
#include<stack>
using namespace std;

typedef struct NODE{
    int data;
    struct NODE *left, *right;
}*node;

node insertNode(node root, int val);
node insertNodeError(node root, int val);
node deleteNode(node root, int val);
bool searchNode(node root, int val);
void traverse(node root);
void preorder(node root);
void postorder(node root);
void loTraverse(node root);
void inorderStack(node root);
bool isBST(node root, int , int);
void kthSmallestElement(node root, int k);

int count = 0;

int main(){
    int opt;
    int val;
    node root = NULL;
    while(1){
            cout<<"[1] Insert\n[2] Delete\n[3] Search \n[4] Inorder Traversal\n[5] Level Order Traversal\n[6] PreOrder\n[7] Postorder\n[8] Inorder without recursion\n[9] If BST\n[10] Insert error val\n[11] Kth Smallest Element in BST\n\nOption: ";
            cin>>opt;
            switch(opt){
                case 1: cin>>val;
                        root = insertNode(root, val);
                        break;
                case 2: cin>>val;
                        root = deleteNode(root, val);
                        break;
                case 3: cin>>val;
                        searchNode(root, val)?cout<<"\nPresent\n":cout<<"\nNot Present\n";
                        break;
                case 4: cout<<endl;
                        traverse(root);
                        cout<<endl;
                        break;
                case 5: cout<<endl;
                   // node temp = root;
                        loTraverse(root);
                        cout<<endl;
                        break;
                case 6: cout<<endl;
                        preorder(root);
                        cout<<endl;
                        break;
                case 7: cout<<endl;
                        postorder(root);
                        cout<<endl;
                        break;
                case 8: cout<<endl;
                        inorderStack(root);
                        cout<<endl;
                        break;
                case 9: cout<<endl;
                        if(root!=NULL)
                        if(isBST(root, -999, 999))
                            cout<<"BST\n";
                        else
                            cout<<"NOT BST";
                        break;
                case 10:cin>>val;
                        root = insertNodeError(root, val);
                        break;
                case 11:cin>>val;
                        count=0;
                        kthSmallestElement(root, val);
                        break;
            }
    }
    return 0;
}

node insertNode(node root, int data){
    if(root == NULL){
        node newnode = (node)malloc(sizeof(struct NODE));
        newnode->data = data;
        root = newnode;
        root->left = root->right = NULL;
        return root;
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else root->right = insertNode(root->right, data);
    return root;
}
node insertNodeError(node root, int data){
    if(root == NULL){
        node newnode = (node)malloc(sizeof(struct NODE));
        newnode->data = data;
        root = newnode;
        root->left = root->right = NULL;
        return root;
    }
    if(data > root->data){
        root->left = insertNode(root->left, data);
    }
    else root->right = insertNode(root->right, data);
    return root;
}

node getMinValueNode(node root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

void traverse(node root){
    if(root==NULL){
        return;
    }
        traverse(root->left);
        cout<<root->data<< " ";
        traverse(root->right);
}

void preorder(node root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node root){
    if(root == NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

node deleteNode(node root, int data){
    if(root == NULL){
        cout<<"Not There!!";
        return NULL;
    }
    if(root->data < data){
        root->right = deleteNode(root->right, data);
    }
    else if( root->data > data){
        root->left = deleteNode(root->left, data);
    }
    else if(root->data == data){
        if(root->left == NULL){
            node temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if(root->right == NULL){
            node temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        node temp = getMinValueNode(root->right);
        root->data = temp ->data;
        root->right=deleteNode(root->right, root->data);
        return root;
    }

}
bool searchNode(node root, int data){
    if(root==NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    if(data < root->data){
        return searchNode(root->left, data);
    }
    else
        return searchNode(root->right, data);
    return false;
}

void loTraverse(node root){
    queue <node> q;
    if(root == NULL){
        return;
    }
    q.push(root);
    while(!q.empty()){
        node temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}

void inorderStack(node root){
    if(root == NULL)
        return;
    stack <node> s;
    node current = root;
    while(!s.empty()||current!=NULL){
        if(current!=NULL)
            s.push(current);
        cout<<"\n\t\tEntered while loop!";
        while(current!=NULL){
            current = current->left;
            cout<<"\n\t\tPushed into stack";
            if(current!=NULL)
            s.push(current);
        }
        current = s.top();
        cout<<"\n"<<current->data<<"\n";
        cout<<"\n\t\tPopped Top";
        s.pop();
        current=current->right;
    }

}

bool isBST(node root, int minVal, int maxVal){
    if(root == NULL){
        return true;
    }
    if(root->data < minVal || root->data > maxVal)
        return false;
    return isBST(root->left, minVal, root->data - 1) && isBST(root->right, root->data+1, maxVal);

}
void kthSmallestElement(node root, int k){
    if(root == NULL){
        return ;
    }
    kthSmallestElement(root->left, k);
    count++;
    if(count == k){
        cout<<"\nThe asked smallest element is: "<<root->data<<endl;
        return;
    }
    if(root->right!=NULL){
        kthSmallestElement(root->right, k);
    }
}
