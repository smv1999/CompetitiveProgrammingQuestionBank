#include<stdio.h>
#define size 50
//Time Complexity :- O((nv)^2)
//Space Complexity :- O(nv)
struct vertex{
    int dist,par,processed;
}V[size];
int nv;
//relax method is used to assign the shortest value to the node.
void relax(int w[size][size],int u,int v){
    if(V[v].dist > V[u].dist + w[u][v]){
        V[v].dist = V[u].dist + w[u][v];
        V[v].par = u;
    }
}
//setting the source value to zero
void initializeSingleSource(int src){
    int i;
    for(i = 0; i < nv; i++){
       V[i].dist = 99999;
       V[i].par = -1;
       V[i].processed = 0;
    }
    V[src].dist = 0;
}

void dijkstra(int w[size][size],int src){
    int i,j,k,ver,dmin;
    initializeSingleSource(src);
    for(i = 0; i < nv; i++){
        dmin = 999999;
        for(k = 0; k < nv; k++){
            if(!V[k].processed && V[k].dist < dmin){
                dmin = V[k].dist;
                ver = k;
            }
           
        }
        
        for(j = 0; j < nv; j++){
            
            if(!V[j].processed && w[ver][j]){
                relax(w,ver,j);
               
            }
           
        }
        V[ver].processed = 1;
        
    }
}

void printPath(int src,int dest){
    if(dest == src){
        printf("\n%d", src);
        return;
    }
    printPath(src,V[dest].par);
    printf(" ------> %d",dest);

}
int main(){
    int i,j,src,dest;
    int w[size][size];
    printf("ENTER NO. OF VERTICES \n");
    scanf("%d",&nv);

    printf("\nENTER THE WEIGHT MATRIX \n");
    for(i = 0; i < nv; i++)
    {
        for(j = 0; j < nv; j++)
        {
            scanf("%d",&w[i][j]);
        }
    }
    printf("\nENTER THE SOURCE \n");
    scanf("%d",&src);
    dijkstra(w,src);
    do{
        printf("\nENTER THE DESTINATION (ENTER -1 TO QUIT) \n");
        scanf("%d",&dest);
        if(dest != -1 && dest < nv){
            printf("\nSHORTEST PATH WEIGHT = %d\n",V[dest].dist);
            printf("\nPATH %d to %d IS",src,dest);
            printPath(src,dest);
        }
    }while(dest != -1 && dest < nv);
    return 0;
}

