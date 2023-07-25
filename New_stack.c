#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/**
 * Generates a file containing a list of random numbers within a specified range.
 *
 * @param None
 *
 * @returns None
 */
void random_numb()
{
    FILE *fileptr1;
    int range,upper,lower;

    printf("Enter the Range of the elements(max elements : upper : lower).\n");
    scanf("%d%d%d",&range,&upper,&lower);

    fileptr1 = fopen("input1.txt","w");

    srand(time(0));
    for( int i = 0 ; i < range ; i++ )
    {
        int num = ( ( rand() % ( upper - lower + 1) ) + lower );
        fprintf(fileptr1,"%d\n",num);
    }
    fclose(fileptr1);


}
/**
 * Pushes an element onto the stack and writes it to a file.
 *
 * @param elem The element to be pushed onto the stack.
 *
 * @returns None
 */
void PUSH(int elem)
{

    FILE *ptr12,*PTR13;

    ptr12 = fopen( "stack.txt","a" );
    PTR13 = fopen("PUSHED_elements.txt","a");

    fprintf(PTR13,"%d\n",elem);
    fprintf(ptr12,"%d\n",elem);
    fclose(PTR13);
    fclose(ptr12);

}
/**
 * Pops an element from the top of a stack stored in a file.
 *
 * @returns None
 *
 * This function reads the last element of the stack from a file named "stack.txt", removes it from the stack, and writes it to a file named "POPPED_elements.txt". The intermediate steps are stored in a file named "intermediate.txt". 
 */
void POP()
{
    FILE *PTR1,*PTR2,*PTR3,*PTR4;
    int k,loc,last;
    PTR1 = fopen("stack.txt","r+");
    PTR4 = fopen("POPPED_elements.txt","a");
    fseek(PTR1,-2,SEEK_END);


    PTR2 = fopen("intermediate.txt","w+");
    loc = (ftell(PTR1) / 3); 
    //printf("%d",loc);
    fseek(PTR1,0,SEEK_SET);
    for(int i = 0 ; i < loc ; i++)
    {
        fscanf(PTR1,"%d\n",&k);
        fprintf(PTR2,"%d\n",k);
    }
    fscanf(PTR1,"%d",&last);
    fprintf(PTR4,"%d\n",last);
    fclose(PTR4);
    fclose(PTR1);
    fclose(PTR2);
    PTR2 = fopen("intermediate.txt","r+");
    PTR3 = fopen("stack.txt","w+");
    for( int i = 0 ; i < loc ; i++)
    {
        fscanf(PTR2,"%d\n",&k);
        fprintf(PTR3,"%d\n",k);
    } 
    fclose(PTR3);
    
    
}
/**
 * Displays the contents of a stack stored in a file named "stack.txt".
 *
 * @returns None
 */
void display_stack()
{
    FILE *PTR_D;
    int LMNT;

    PTR_D = fopen("stack.txt","r+");

    do
    {
        fscanf(PTR_D,"%d",&LMNT);
        if(feof(PTR_D))
            break;
        printf("\n%d\n",LMNT);    
        
    }while(1);
    fclose(PTR_D);

}


/**
 * Main function that reads input from a file, performs operations based on user choice, and writes output to a file.
 *
 * @returns 0 on successful execution.
 */
int main()
{
    random_numb();
    int choice,elem;

    FILE *ptr13,*PTR2;
    int last;
    char push[] = "PUSH()";
    char pop[] = "POP()";
    ptr13 = fopen("input1.txt","r+");
    PTR2 = fopen("commandlog.txt","w+");
    

    while(1)
    {
        printf("Enter the operations number.\n 1)PUSH \n 2)POP \n 3)Display Stack\n 4)Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: fprintf(PTR2,"%s\n",push);
                    fscanf(ptr13,"%d",&elem);
                    PUSH(elem);
                    break;
            case 2: fprintf(PTR2 ,"%s\n",pop);
                    POP();
                    break;
            case 3: display_stack();
                    break;
           
            default:  exit(0);

        }
        

    }
    fclose(PTR2);
    fclose(ptr13);
    
}
