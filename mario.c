#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int num; 
    
    do 
    {
        printf("Enter a positive integer: ");
        num = GetInt();
    } 
    while(num < 0 || num >23);

    int numHash = 2;
    

   
   for (int counter = 1; counter < num + 1; counter++)
    {
         
       
        int numSpace = num - counter; 
        int counter2 = 0; 
                
        while(numSpace > 0)
        {
            printf(" "); 
            numSpace = numSpace - 1;
        }
            
        while(counter2 < numHash){
            printf("#");
            counter2++;
        }

        numHash++;       
        
        printf("\n");        
    }
}   
