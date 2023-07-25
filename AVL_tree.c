#include<stdio.h>
#include<stdlib.h>

struct Node{
    
    int data;
    struct Node* right;
    struct Node* left;
    int height;

};

typedef struct Node* node;
node root=NULL, newnode;
node getnode( int data ){

    newnode = (node)malloc(sizeof(struct Node));
    if(newnode == NULL){

        printf("Failed to allocate!\n");
        exit(1);
    }

    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

int height( node root ){

    int lh, rh;

    if( root == NULL )
        return 0;
    
    if( root->left == NULL )
        lh = 0;
    else 
        lh = 1 + root->left->height;

    if( root->right == NULL )
        rh = 0;
    else 
        rh = 1 + root->right->height;
    
    if( lh > rh )
        return(lh);
    return(rh);
}
node rotate_left( node root ){

    node right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;

    root->height = height(root);
    right_child->height = height(right_child);
    return right_child;
    

}
node rotate_right( node root ){

    node left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;

    root->height  = height(root);
    left_child->height = height(left_child);
    return left_child;
}
int balance_factor( node root ){

    int lh, rh;

    if( root == NULL)
        return 0;
    
    if( root->right == NULL )
        rh = 0;
    else
        rh = 1 + root->right->height;
    
    if( root->left == NULL )
        lh = 0;
    else 
        lh = 1 + root->left->height;
    
    return lh-rh;
}
node insert_node( node root, int data ){

    if( root == NULL ){

        node temp = getnode(data);        
        root = temp;
    }
    else if( data > root->data ){

        root->right = insert_node( root->right, data );

    }
    else if( data < root->data ){

        root->left = insert_node( root->left, data );
    }

    root->height = height(root);

    if( balance_factor( root ) == 2 ){

        if( data < root->left->data )
           root = rotate_right( root );
        else{

            root->left = rotate_left( root->left );
            root = rotate_right( root );
        }
    }
    if( balance_factor( root ) == -2 ){
        
        if( data > root->right->key )
            root = rotate_left( root );
        else{

            root->right = rotate_right( root->right );
            root = rotate_left( root );
        }
    }
    if( balance_factor( root ) == 2 ){

        if( data < root->left->key )
            root = rotate_right( root );
        else{
            
            root->left = rotate_left( root->left );
            root = rotate_right( root );
        }
    }

    
    
    return root;
}
void inOrder( node root ){

    if( root != NULL)
    {
        inOrder( root->left );
        printf("%d->%d\n",root->data,root->height);
        inOrder( root->right );
    }
}
void preOrder( node root ){

    if( root != NULL)
    {
        printf("%d->%d\n",root->data,root->height);
        preOrder( root->left );
        preOrder( root->right );
    }
    
}
void postOrder( node root ){

    if( root != NULL)
    {
        postOrder( root->left );
        postOrder( root->right );
        printf("%d->%d\n",root->data,root->height);
    }
}
int main(){

    int num[] = {5,6,8,3,2,4,7};
    int size_arr = sizeof(num)/sizeof(num[0]);
   int i;
   

    for( i = 0 ; i < size_arr ; i++ ){

        root = insert_node( root, num[i] );
        
    }
    
    
    inOrder( root );
    printf("\n");
    preOrder( root );
    printf("\n");
    postOrder( root );

}
