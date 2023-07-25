#include<stdio.h>
#include<stdlib.h>
#include "rand_num.h"
struct Node 
{
    int num;
    struct Node *Left_child;
    struct Node *Right_child;
};
typedef struct Node *node;
node root = NULL, newnode;
node getnode( int data )
{
    newnode = (node)malloc(sizeof(node));

    newnode->num = data;
    newnode->Left_child = NULL;
    newnode->Right_child = NULL;
    //printf("%d\n", newnode->num);
    return newnode;
}
node insert_node( node root, int data )
{
    
    if( root == NULL )
    {
        node n = getnode( data );
        //printf("%d", n->num);
        return n;
    }

    if( root->num < data )
    {
        root->Right_child = insert_node( root->Right_child, data );
    }
    else if( root->num > data )
    {
        root->Left_child = insert_node( root->Left_child, data );
    }
    return root;

}
void inOrder( node root )
{
    FILE *file1 = fopen("in_order.txt", "a");

    if( root != NULL )
    {
        inOrder( root->Left_child );
        fprintf( file1, "%d ", root->num );
        printf("%d ", root->num );
        inOrder( root->Right_child );
    }   
    fclose( file1 );
}
void preOrder( node root )
{
    FILE *file2 = fopen("pre_order.txt", "a");
    if( root != NULL )
    {
        fprintf( file2, "%d ", root->num );
        printf("%d ", root->num );
        preOrder( root->Left_child );
        preOrder( root->Right_child );
    }
    fclose( file2 );
}
void postOrder( node root )
{
    FILE *file3 = fopen("post_order.txt", "a");
    if( root != NULL )
    {
        postOrder( root->Left_child );
        postOrder( root->Right_child );
        fprintf( file3, "%d ", root->num );
        printf("%d ", root->num );
    }
    fclose( file3 );
}
int main()
{
    int n;
    int k;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    uni_rand_num( n, n, 1);
    FILE *f = fopen("unique_input.txt", "r");

    
    

    for( int i = 0; i < n; i++ )
    {
        fscanf(f, "%d", &k);
        root = insert_node( root, k );
    }
    inOrder( root );
    printf("\n");
    // preOrder( root );
    // printf("\n");
    // postOrder( root );
    // printf("\n");
    fclose( f );
    
}
