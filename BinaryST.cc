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
int sumTree(node);
queue <int>  qForB;
node BToBST(node);
void traverse(node root);
void preorder(node root);
void postorder(node root);
void loTraverse(node root);
void inorderStack(node root);
void optInorder(node root);
bool isBST(node root, int , int);
void kthSmallestElement(node root, int k);
void getDataOfKthNode(node root, int pos);
int getDiameter(node);
int height(node root);
void leftView(node root, int);
node lowestCommonAncestor(node,int, int);
int max(int, int);
int max(int,int,int);
int count = 0;
int maxLevel = 0;
int main(){
    int opt;
    int val;
    node root = NULL, lca;
    while(1){
            cout<<"[1] Insert\n[2] Delete\n[3] Search \n[4] Inorder Traversal\n[5] Level Order Traversal\n[6] PreOrder\n[7] Postorder\n[8] Inorder without recursion\n[9] If BST\n[10] Insert error val\n[11] Kth Smallest Element in BST\n[12] Data at K distance from root.\n[13] Diameter of the Tree.\n[14] Traversal without recursion and stack.\n[15] Sum Tree\n\n[16] Lowest Common Ancestor\n[17] Left View\n[18] B-Tree to BST\n[19] Bottom View\n\nOption: ";
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
                case 12:cin>>val;
                        count=0;
                        getDataOfKthNode(root, val);
                        break;
                case 13:val = getDiameter(root);
                        cout<<"\nDiameter is: "<<val;
                        break;
                case 14:cout<<endl;
                        optInorder(root);
                        break;
                case 15: root->data = sumTree(root->left)+sumTree(root->right);
                        break;
                case 16:int val1, val2;
                        cout<<"\nEnter: value [1], value [2]:";
                        cin>>val1>>val2;
                        lca = lowestCommonAncestor(root, val1, val2);
                        cout<<"\n"<<lca->data<<endl;
                        break;
                case 17:cout<<endl;
                        maxLevel=-1;
                        leftView(root, 0);
                        cout<<endl;
                        break;
                case 18:cout<<endl;
                        root=BToBST(root);
                        cout<<endl;
                        break;
            }
    }
    return 0;
}

int max(int a, int b){
    return a>b?a:b;
}

int max(int a, int b, int c){
    return a>b?(a>c?a:c):(b>c?b:c);
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
        qForB.push(current->data);
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

void getDataOfKthNode(node root, int pos){
    if(root == NULL)
        return;
    if(pos == 0){
        cout<<root->data<<" ";
    }
    getDataOfKthNode(root->left,pos-1);
    getDataOfKthNode(root->right, pos-1);
}

int height(node root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int getDiameter(node root){
    if(root == NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);

    int lDiameter = getDiameter(root->left);
    int rDiameter = getDiameter(root->right);
    return max(lheight+rheight+1, max(lDiameter,rDiameter));
}

void optInorder(node root){
  /*  if(root == NULL)
        return;

    node current = root, prev = NULL;
    while(current){
        if(!current->left){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            prev = current->left;
            while

        }
    }*/
}

int sumTree(node root){
    int temp=root->data;
    if(root->left == NULL||root->right==NULL){
        root->data = 0;
        return temp;
    }
    temp=root->data;
    root->data = sumTree(root->left) + sumTree(root->right);
    return root->data + temp;
}

node lowestCommonAncestor(node root, int val1, int val2){
    if(root==NULL){
        return NULL;
    }
    if(val1<root->data && val2< root->data){
        return lowestCommonAncestor(root->left,val1,val2);
    }
    else if(val1>root->data && val2>root->data){
        return lowestCommonAncestor(root->right,val1,val2);
    }
    return root;
}

void leftView(node root, int level){
    if(root == NULL){
        return;
    }
    if(level>maxLevel){
        maxLevel=level;
        cout<<root->data<< " ";
    }
    leftView(root->left,level+1);
    leftView(root->right,level+1);
}

node BToBST(node root){
    inorderStack(root);
    node temp=root, prev;
    root=NULL;
    while(!qForB.empty()){
        root=insertNode(root, qForB.front());
        qForB.pop();
    }
    return root;
}
