#include<stdio.h>
#define size 50
struct vertex{
    int dist,par,processed;
}V[size];
int nv;
//relax method is used to assign the shortest value to the node.
void relax(int w[size][size],int u,int v){
    //printf("RELAX %d  %d\n",u,v);
    if(V[v].dist > V[u].dist + w[u][v]){
        V[v].dist = V[u].dist + w[u][v];
        V[v].par = u;
    }
}

void initializeSingleSource(int src){
    int i;
    for(i = 0; i < nv; i++){
        //printf("HERE ");
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
        //printf("HERE ");
        for(k = 0; k < nv; k++){
            if(!V[k].processed && V[k].dist < dmin){
                dmin = V[k].dist;
                ver = k;
            }
           // printf("K LOOP %d %d %d %d \n",k,ver,V[k].processed,V[k].dist);
        }
        //printf("BETWEEN K AND J LOOP\n");
        for(j = 0; j < nv; j++){
            //printf("j = %d V[j].processed = %d w[ver][j] = %d ",j,V[j].processed,w[ver][j]);
            if(!V[j].processed && w[ver][j]){
                relax(w,ver,j);
               // printf("J LOOP %d \n",ver);
            }
           // printf("J LOOP END\n");
        }
        V[ver].processed = 1;
        //printf("I LOOP %d \n",V[ver].processed);
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
//    int w[5][5] = {{0,10,0,5,0},
//                {0,0,1,2,0},
//                {0,0,0,0,4},
//                {0,3,9,0,2},
//                {7,0,6,0,0}};
//    printf("-------- THE WEIGHT MATRIX --------\n");
//    for(i = 0; i < nv; i++)
//    {
//        for(j = 0; j < nv; j++)
//        {
//            printf("w[%d][%d] = %d ",i,j,&w[i][j]);
//        }
//        printf("\n");
//    }
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

