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
    
    
    for (int counter = 0; counter < num; counter++)
    {
        int numSpace = num - numHash;
         
        printf("%d",numSpace);
        
        for (int count2 = 0; count2 < numSpace; count2++)
        {
            int i = 0; 
            
            while(i <= numSpace){
                //printf(" ");
                printf("%d",i);
                i++;
            }
            printf("%d",count2);
            count2++;
            
            for (int count3 = 0; count3 <numHash; count3++)
            {
                int k = 0; 
                
                while(k<numHash){
                    //printf("#");
                    printf("%d",k);
                    k++;
                }
                
                printf("%d",count3);
                count3++;
            }
            printf("\n");
        }

        numHash++;
    }
}
