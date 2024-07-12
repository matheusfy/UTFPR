#include <stdio.h>
#include <stdlib.h>

int fat(int a){
   int y,cont,x;
   if(a=1)
      return  y; // retorna zero pois o fatorial será impresso na tela
   else{
      y=a;
      if(cont>=0){
         a=x;
         x=a*(y-1);
         printf("%d ",x);
         cont++;
         return fat(y--);
      }
   }
}

 main(){
   int r=3;
   int y;
   y = fat(r);
   printf("%d\n",y);
   system("pause");
}
