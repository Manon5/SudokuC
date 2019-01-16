void ecrireCand(Cand C[9][9])
{
    int a,i,j,k,l,comptb;
    for(a=0;a<9;a++)
    {
        if(a%3==0)
        { 
            for(i=0;i<82;i++)
            {
                printf("*");
            }
            printf("\n");
        }
        else
        {
            printf("*");
            for(i=0;i<3;i++)
            {
                for(j=0;j<26;j++)
                {
                    printf("-");
                }
                printf("*\n");
            }   
        }
        printf("*");
        for(k=0;k<9;k++)
        {
            printf(" ");
            comptb=6-C[a][k].nbc;
            for(l=0;l<comptb;l++)
            {
                printf(" ");
            }
            for(l=0;l<C[a][k].nbc;l++)
            {
                printf("%d",C[a][k].tab[l]);
            }
            printf(" ");
            if(k%3==2)
            {
                printf("*");
                if(k%8==8)
                  {
                  printf("\n");
                  }
            }
            else
            {
                printf("|");
            }
        
        }    
        
    }
    for(i=0;i<82;i++)
            {
                printf("*");
            }
            printf("\n");    
}
