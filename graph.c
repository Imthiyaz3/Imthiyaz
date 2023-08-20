#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "predictive.h"
//#include "tgff_reader.h"
struct graph_info Gr;
struct edge_info *edges;



extern struct graph_info Gr;
extern struct edge_info *edges;
void intialize_graph_info(unsigned short int no_nodes,unsigned short int no_rows,unsigned short int no_colums,unsigned short int no_edges)
{
    Gr.nodes=no_nodes;
    Gr.rows=no_rows;
    Gr.colums=no_colums;
    Gr.edges=no_edges;
}

float** allocate_memory(unsigned short int no_nodes)
{

    unsigned short int node_index;
    float**graph;
    //printf("no_nodes %d\n",no_nodes);
    graph=(float **)malloc(no_nodes*sizeof(float*));
    for(node_index=0;node_index<no_nodes;node_index++)
        graph[node_index]=(float*)malloc(no_nodes*sizeof(float));

    return graph;
}

void copy_graph(float**graph,float temp_graph[graph_nodes][graph_nodes],unsigned short int no_nodes)
{
    unsigned short int node_index1,node_index2;
    //printf("why problem is here\n");
    for(node_index1=0;node_index1<no_nodes;node_index1++)
        for(node_index2=0;node_index2<no_nodes;node_index2++)
            graph[node_index1][node_index2]=temp_graph[node_index1][node_index2];
}
unsigned short int find_edges(float**graph,unsigned short int no_nodes)
{
    unsigned short int node_index1,node_index2,no_edges=0;
    for(node_index1=0;node_index1<no_nodes;node_index1++)
    {
        for(node_index2=node_index1+1;node_index2<no_nodes;node_index2++)
        {
            if (graph[node_index1][node_index2]!=0)
            {
                no_edges++;
            }
        }
     }
    return no_edges;
}
void intialize_edges(float**graph)
{


	unsigned short int node_index1,node_index2,no_edges,edge_index;

	//WRITE YOUR CODE HERE AND NO NEED TO DEFINE ANY VARIABLE.
	//=======================================================
	
	
	

}
float** intialize_graph(char* arg,char* name)
{
    float **graph;
    //struct edge_info*edges;
    //float temp_graph[graph_nodes][graph_nodes];
    unsigned short int no_nodes,no_rows,no_colums,no_edges,node_index,devider,node_index1,node_index2,edge_index;
    //printf("something is wrong\n");
    unsigned short choice=atoi(arg);
    if(choice==3)
    {
        no_nodes=8;
        no_rows=2;
        no_colums=4;
        devider=2;
        graph=allocate_memory(no_nodes);
    }
         //printf("something is still wrong\n");
        //intialize_graph_info(no_nodes,no_rows,no_colums);
        //copy_graph(graph,temp_graph1,no_nodes);
        //printf("something is still wrong\n");

       if(/*choice==2 || */choice==15)
    	{
        no_nodes=16;
        no_rows=4;
        no_colums=4;
        devider=2;
        graph=allocate_memory(no_nodes);
      }  
        //intialize_graph_info(no_nodes,no_rows,no_colums);
        //copy_graph(graph,temp_graph2,no_nodes);
       // break;
       if(choice==1 || choice ==5 || choice==6 ||choice==7 || choice ==8 ||choice==9 || choice==10 || choice==14 || choice==2 )
    	{
        no_nodes=12;
        no_rows=4;
        no_colums=3;
        devider=2;
        graph=allocate_memory(no_nodes);
        } 
        //intialize_graph_info(no_nodes,no_rows,no_colums);
        //copy_graph(graph,temp_graph3,no_nodes);

        if(choice==4)
    	{
        no_nodes=32;
        no_rows=4;
        no_colums=8;
        devider=2;
        graph=allocate_memory(no_nodes);
        }
                //intialize_graph_info(no_nodes,no_rows,no_colums);
        //printf("i cant believe it\n");
        //copy_graph(graph,temp_graph4,no_nodes);
        //printf("i still cant believe it\n");
        if(choice==12)
    	{
        no_nodes=24;
        no_rows=4;
        no_colums=6;
        devider=2;
        graph=allocate_memory(no_nodes);
        }
        if(choice==13)
    	{
        no_nodes=30;
        no_rows=5;
        no_colums=6;
        devider=2;
        graph=allocate_memory(no_nodes);
        }

         if(choice==17||choice==18||choice==19||choice==20||choice==21||choice==22||choice==23)
    	{
        no_nodes=64;
        no_rows=8;
        no_colums=8;
        devider=2;
        graph=allocate_memory(no_nodes);
        //graph=readgraph_tgff(name);
       }
	else if(choice==25 || choice ==26 || choice==27 || choice==28 || choice ==29 || choice ==30)
    {
        no_nodes=128;
        no_rows=8;
        no_colums=16;
        devider=2;
        graph=allocate_memory(no_nodes);
    }

    intialize_graph_info(no_nodes,no_rows,no_colums,0);
    read_graph(graph,arg);
    //make_undirected(graph,no_nodes,devider);
    for(node_index1=0;node_index1<no_nodes;node_index1++)
    {
       for(node_index2=node_index1+1;node_index2<no_nodes;node_index2++)
       {
          graph[node_index1][node_index2]=(graph[node_index1][node_index2]+graph[node_index2][node_index1])/devider;
          graph[node_index2][node_index1]=graph[node_index1][node_index2];
         // printf("%4.2f",graph[node_index1][node_index2]);
       }
    }
    //copy_graph(graph,temp_graph,no_nodes);
    no_edges=find_edges(graph,no_nodes);
    intialize_graph_info(no_nodes,no_rows,no_colums,no_edges);
    edges=(struct edge_info*)malloc(no_edges*sizeof(struct edge_info));
    intialize_edges(graph);
    /*
    for(edge_index=0; edge_index<no_edges;edge_index++)
    {
    	printf("\n%d -> %d = %f",edges[edge_index].source,edges[edge_index].destination,edges[edge_index].edge_weight);
    }
    */
    return graph;
    //return edges;
}
