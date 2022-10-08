#include<iostream>
#include<iomanip>
using namespace std;
class Node
{
public:
    int data;
    int height;
    Node* parent;
    Node* left;
    Node* right;

    Node(int val,Node* p,Node* l,Node* r)
    {
        data=val;
        height=1;
        parent=p;
        left=l;
        right=r;
    }
};
class Avl_tree
{
private:
    Node* root;
    void rotate(Node* par,Node* ch)
    {
        if(par==root)
        {
            if(ch==par->left)
            {
                par->left=ch->right;
                if(ch->right!=NULL)
                {
                    ch->right->parent=par;
                }
                ch->right=par;
                par->parent=ch;

                root=ch;
                root->parent=NULL;
            }
            else
            {
                par->right=ch->left;
                if(ch->left!=NULL)
                {
                    ch->left->parent=par;
                }
                ch->left=par;
                par->parent=ch;

                root=ch;
                root->parent=NULL;
            }
        }
        else
        {
            if(par==par->parent->left)
            {
                par->parent->left=ch;
                ch->parent=par->parent;
            }
            else
            {
                par->parent->right=ch;
                ch->parent=par->parent;
            }
            if(ch==par->left)
            {
                par->left=ch->right;
                if(ch->right!=NULL)
                {
                    ch->right->parent=par;
                }
                ch->right=par;
                par->parent=ch;
            }
            else
            {
                par->right=ch->left;
                if(ch->left!=NULL)
                {
                    ch->left->parent=par;
                }
                ch->left=par;
                par->parent=ch;
            }
        }
    }
    int avl_tree_find_max_child_height(Node* temp)
    {
        Node* left_child=temp->left;
        Node* right_child=temp->right;
        int h;
        if(left_child==NULL && right_child==NULL)
        {
            h=0;
        }
        else if(left_child!=NULL && right_child==NULL)
        {
            h=left_child->height;
        }
        else if(left_child==NULL && right_child!=NULL)
        {
            h=right_child->height;
        }
        else
        {
            h=(left_child->height>right_child->height)?left_child->height:right_child->height;
        }
        return h;
    }
    int avl_tree_child_height_difference(Node* temp)
    {
        Node* left_child=temp->left;
        Node* right_child=temp->right;
        int h_diff;
        if(left_child==NULL && right_child==NULL)
        {
            h_diff=0;
        }
        else if(left_child!=NULL && right_child==NULL)
        {
            h_diff=left_child->height;
        }
        else if(left_child==NULL && right_child!=NULL)
        {
            h_diff=right_child->height;
        }
        else
        {
            h_diff=left_child->height-right_child->height;
            if(h_diff<0)
            {
                h_diff*=(-1);
            }
        }
        return h_diff;
    }
    Node* avl_tree_find_max_height_child(Node* temp)
    {
        Node* left_child=temp->left;
        Node* right_child=temp->right;
        if(left_child==NULL && right_child==NULL)
        {
            return NULL;
        }
        else if(left_child!=NULL && right_child==NULL)
        {
            return left_child;
        }
        else if(left_child==NULL && right_child!=NULL)
        {
            return right_child;
        }
        else
        {
            return (left_child->height > right_child->height)?left_child:right_child;
        }
    }
    void avl_tree_height_manager(Node* temp)
    {
        while(temp!=NULL)
        {
            int h=avl_tree_find_max_child_height(temp);
            if(h==temp->height)
            {
                temp->height=temp->height+1;
            }
            int h_diff=avl_tree_child_height_difference(temp);
            if(h_diff > 1)
            {
                Node* grand_par=temp;
                Node* par=avl_tree_find_max_height_child(grand_par);
                Node* ch=avl_tree_find_max_height_child(par);
                if((par==grand_par->left && ch==par->left) || (par==grand_par->right && ch==par->right))
                {
                    rotate(grand_par,par);
                }
                else
                {
                    rotate(par,ch);
                    rotate(grand_par,ch);
                }
                grand_par->height=(avl_tree_find_max_child_height(grand_par))+1;
                par->height=(avl_tree_find_max_child_height(par))+1;
                ch->height=(avl_tree_find_max_child_height(ch))+1;
            }
            else
            {
                temp=temp->parent;
            }
        }
    }
    void avl_tree_insert_node(Node* temp,int val)
    {
        if(val < temp->data)
        {
            if(temp->left==NULL)
            {
                temp->left=new Node(val,temp,NULL,NULL);
                avl_tree_height_manager(temp);
            }
            else
            {
                avl_tree_insert_node(temp->left,val);
            }
        }
        else
        {
            if(temp->right==NULL)
            {
                temp->right=new Node(val,temp,NULL,NULL);
                avl_tree_height_manager(temp);
            }
            else
            {
                avl_tree_insert_node(temp->right,val);
            }
        }
    }
    Node* avl_tree_find_min(Node* temp)
    {
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp;
    }
    Node* avl_tree_find_node(Node* temp,int val)
    {
        while(temp!=NULL)
        {
            if(val < temp->data)
            {
                temp=temp->left;
            }
            else if(val > temp->data)
            {
                temp=temp->right;
            }
            else
            {
                break;
            }
        }
        return temp;
    }
    void avl_tree_delete_node(Node* temp)
    {
        if(temp->left==NULL && temp->right==NULL)
        {
            if(temp==root)
            {
                delete temp;
                root=NULL;
            }
            else if(temp==temp->parent->left)
            {
                Node* par=temp->parent;
                temp->parent->left=NULL;
                delete temp;
                avl_tree_height_manager(par);
            }
            else
            {
                Node* par=temp->parent;
                temp->parent->right=NULL;
                delete temp;
                avl_tree_height_manager(par);
            }
        }
        else if(temp->left!=NULL && temp->right==NULL)
        {
            if(temp==root)
            {
                root=temp->left;
                root->parent=NULL;
                delete temp;
            }
            else if(temp==temp->parent->left)
            {
                temp->parent->left=temp->left;
                temp->left->parent=temp->parent;
                Node* par=temp->parent;
                delete temp;
                avl_tree_height_manager(par);
            }
            else
            {
                temp->parent->right=temp->left;
                temp->left->parent=temp->parent;
                Node* par=temp->parent;
                delete temp;
                avl_tree_height_manager(par);
            }
        }
        else if(temp->left==NULL && temp->right!=NULL)
        {
            if(temp==root)
            {
                root=temp->right;
                root->parent=NULL;
                delete temp;
            }
            else if(temp==temp->parent->left)
            {
                temp->parent->left=temp->right;
                temp->right->parent=temp->parent;
                Node* par=temp->parent;
                delete temp;
                avl_tree_height_manager(par);
            }
            else
            {
                temp->parent->right=temp->right;
                temp->right->parent=temp->parent;
                Node* par=temp->parent;
                delete temp;
                avl_tree_height_manager(par);
            }
        }
        else
        {
            Node* temp_min=avl_tree_find_min(temp->right);
            temp->data=temp_min->data;
            avl_tree_delete_node(temp_min);
        }
    }
    void avl_tree_show_data(Node* temp)
    {
        if(temp!=NULL)
        {
            avl_tree_show_data(temp->left);
            cout<<setw(5)<<temp->data<<setw(5)<<temp->height<<endl;
            avl_tree_show_data(temp->right);
        }
    }
public:
    Avl_tree()
    {
        root=NULL;
    }
    void insert_node(int val)
    {
        if(root==NULL)
        {
            root=new Node(val,NULL,NULL,NULL);
        }
        else
        {
            avl_tree_insert_node(root,val);
        }
    }
    void delete_node(int val)
    {
        if(root==NULL)
        {
            cout<<"No data is present in the tree"<<endl;
        }
        else
        {
            Node* temp=avl_tree_find_node(root,val);
            if(temp!=NULL)
            {
                cout<<temp->data<<" is deleted"<<endl;
                avl_tree_delete_node(temp);
            }
            else
            {
                cout<<"No such data is present"<<endl;
            }
        }
    }
    void show_data()
    {
        if(root==NULL)
        {
            cout<<"No data is present"<<endl;
        }
        else
        {
            cout<<"In-order walk"<<endl;
            cout<<"  Data"<<"  Height"<<endl;
            avl_tree_show_data(root);
        }
        
    }
    void show_root_data()
    {
        if(root==NULL)
        {
            cout<<"No data is present"<<endl;
        }
        else
        {
            cout<<"Showing root data"<<endl;
            cout<<"  Data"<<"  Height"<<endl;
            cout<<setw(5)<<root->data<<setw(5)<<root->height<<endl;
        }
        
    }
};
int main()
{
    Avl_tree obj;

    obj.insert_node(50);
    obj.insert_node(62);
    obj.insert_node(63);
    obj.insert_node(100);
    obj.insert_node(10);
    obj.insert_node(95);
    obj.insert_node(45);
    obj.insert_node(75);
    obj.insert_node(40);
    obj.insert_node(115);
    obj.insert_node(42);
    obj.insert_node(41);

    obj.show_data();
    obj.show_root_data();

    obj.delete_node(50);
    obj.show_data();
    obj.show_root_data();
    return 0;
}