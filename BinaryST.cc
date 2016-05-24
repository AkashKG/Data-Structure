#include<iostream>
#include<malloc.h>
#include<queue>
using namespace std;

typedef struct NODE{
    int data;
    struct NODE *left, *right;
}*node;

node insertNode(node root, int val);
node deleteNode(node root, int val);
bool searchNode(node root, int val);
void traverse(node root);
void loTraverse(node root);

int main(){
    int opt;
    int val;
    node root = NULL;
    while(1){
            cout<<"[1] Insert\n[2] Delete\n[3] Search \n[4] Traverse\n[5] Level Order Traversal\n[6] Inorder\n\nOption: ";
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
