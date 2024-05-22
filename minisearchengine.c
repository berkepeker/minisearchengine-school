#include <ctype.h> 
#include<stdlib.h> 
#include<stdio.h> 
#include <string.h>
int rec_search(char array[][100], int maxi,char array1[]);
int main() { 
	char list[1000][100],ignoreList[1000][100];     
    int a,checker=0,e,u,j,b,c,z,n=1;
    int number[e];
    int checker1 = 0;
    int max = a;
    int max1 = j;
    int y=0;
    char word[20],word1[20],filename[20],txt[100]=".txt",x[100]="documents/",search[20]; 
      
      printf("enter a file name to read: ");
      scanf("%s",&filename);
       
      FILE *i;

      i=fopen("ignoreList.txt","r");

      j=0;
        while(!feof(i)){ 
          
            fscanf(i,"%s",word1); 
            strcpy(ignoreList[j],word1);
            
            j++;
      }
      fclose(i);
        FILE *file;
        
        if((file=fopen(strcat(strcat(x,filename),txt),"r")) == NULL){ 
        printf("Input File Not Found!\n"); 
        system("pause");
        return 0;
        } 
        a=0;
        while(!feof(file)){ 
          
            fscanf(file,"%s",word); 
            strcpy(list[a],word);

           
            a++;
        } 
        
    fclose(file); 
    max = a;
    max1 = j;

    FILE *wrd;
    wrd = fopen("words.txt","w");    

    for(e=0;e<=max;e++){
        checker=0;
        for(u=0;u<=max;u++){
            z = strcmp(list[e],list[u]);
            if(z==0)
            checker1++;
            
        }
        number[e] = checker1;
        checker1=0;
        
        z=0;
        for(u=0;u<=max1;u++){
            z = strcmp(list[e],ignoreList[u]);
            if(z==0)
            checker = 1;
        }
        if(checker==0){
        
        if(e>=1){
        for(u=e-1;u>=0;u--){

            n = strcmp(list[e],list[u]);
            if(n==0){
            checker1 = 1;
            }


        }
        }
        
        if(checker1 != 1){
        printf("%s,%d\n",list[e],number[e]);
        fprintf(wrd,"%s\n",list[e]);
        y++;
        


        }
         
        }
    







    }
    fclose(wrd);

char newlist[1000][100],word2[25];


wrd = fopen("words.txt","r");
e=0;
while(!feof(wrd)){
    fscanf(wrd,"%s",word2);
    strcpy(newlist[e],word2);
    e++;
}



char temp[100];
for(e = 0 ; e <= y ; e++){
    
    
    for(u = e+1 ; u <= y ; u++){
         if( strcmp(newlist[e],newlist[u]) > 0 ){
            strcpy(temp,newlist[e]);
            strcpy(newlist[e],newlist[u]);
            strcpy(newlist[u],temp);
         }

    }
    
    
    
        
    }
         






   
   
   




do{
   
printf("(0 for exit)    Enter a search string:");
scanf("%s",search);  

if(strcmp(search,"0") == 0 ){
    printf("--end--\n");
    
}else{
    rec_search(newlist,y,search);
}
    

    
    

    
}while(strcmp(search,"0") != 0 );






system("pause");





}


int rec_search(char array[][100], int n,char array1[]){
    int i,up,low,a=0;
     a = n;
    
    if(a>=0){
    a--;
    
    i = strcmp(array[n],array1);
       
    if( i==0 ){
    printf("The word - %s - Exists in file.\n",array1);
    
    }
    else if( i > 0)
    rec_search(array,n - 1 ,array1);
    else if( i < 0)
    rec_search(array,n - 1 ,array1);
   
    
    } else{
        printf("The word is not in the file.\n");
        
    }
    

    
    
    
    
    
                             
       
   
    
    
    

}
