#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <math.h>
#include "graph.h"
#include "predictive.h"
using namespace std;
extern	struct graph_info Gr;
extern struct edge_info *edges;
//extern struct virtual_address address;
struct virtual_address address;
//unsigned short cores;

void read_graph(float**G,char* data)
{

    unsigned short nodes,row=0,colum=0;
    char*buff,*arg;
    char*file_name;
    fstream fp;
    buff=new char [5];
    arg=new char [5];
    file_name=new char [150];
   
    Gr.edges=0;    
    strcpy(file_name,"./Apps/Graph");
    strcat(file_name,data);
    strcat(file_name,".txt");
    fp.open(file_name,ios::in);
    
    //WRITE YOU CODE HERE NO NEED TO DEFINE ANY VARIABLE.
    //===================================================
    while(!fp.eof())
    {
      fp.getline(buff,5);
      nodes = atoi(buff);
      Gr.nodes = nodes;

      for(row=0;row<nodes;row++)
      {
        for(colum=0;colum<nodes;colum++)
        {
          fp.getline(arg,5);
          G[row][colum] = atof(arg);
          if(row!= colum)
          {
            Gr.edges++;
          }
          }
        }
    }
    //===================================================
    Gr.edges=Gr.edges/2;
}

void short_edges(void)
{

    unsigned short edge_index,edge_index2;
    struct edge_info temp;
     //WRITE YOU CODE HERE NO NEED TO DEFINE ANY VARIABLE.
    //===================================================
    
    
    
    
    
}
void display_edges(void)
{
    unsigned short edge_index2;
    for(edge_index2=0;edge_index2<Gr.edges;edge_index2++)
    {
        cout<<edges[edge_index2].source<<" ---> "<<edges[edge_index2].destination<<" = "<<edges[edge_index2].edge_weight<<endl;
    }
}
void intialize_array(unsigned short* array)
{
    unsigned short index;
    for(index=0;index<Gr.nodes;index++)
    {
        array[index]=0;
    }
}

float get_communicatio_of_node(unsigned short node,float**G)
{
    unsigned short node_index;
    float comm=0;
    for(node_index=0;node_index<Gr.nodes;node_index++)
    {
        comm=comm+G[node][node_index];
    }
    return comm;
}
unsigned short get_maximum_outgoing_edge_maped_node(unsigned short* core_mapping_flag,struct edge_info edge)
{
    if(core_mapping_flag[edge.source] & core_mapping_flag[edge.destination])
        return 0;
    else if(core_mapping_flag[edge.source])
        return 1;
    else if(core_mapping_flag[edge.destination])
        return 2;
    else
        return 0;


}
unsigned short int hop_count(unsigned short node1,unsigned short node2)
{

    unsigned short no_hops;
     //WRITE YOU CODE HERE NO NEED TO DEFINE ANY VARIABLE.
    //===================================================
    
    
    
    //===================================================
    return no_hops;
}
void intialize_mapping_var(unsigned short* map)
{
    unsigned short index;
    for(index=0;index<Gr.nodes;index++)
        map[index]=9999;
}
unsigned short find_min_comm_pos(unsigned short *core_mapping_flag,unsigned short node,unsigned short *pos,float**G,unsigned short int*router_mapping_flag,unsigned short *mapping,unsigned short*inv_map)
{

    unsigned short node_indexl,node_index2,count=0,index;
    float *comm_pos,min_comm=99999999, comm=0.0;
    comm_pos=new float [Gr.nodes];
    
    for(node_index2=0;node_index2<Gr.nodes;node_index2++)
        comm_pos[node_index2]=99999999;
    
    
     //WRITE YOU CODE HERE NO NEED TO DEFINE ANY VARIABLE.
    //===================================================
    
    
    
    
    
    //===================================================
    return count;
}

void copy_arrays(unsigned short*source,unsigned short *destination)
{
    unsigned short index=0;
    for(index=0;index<Gr.nodes;index++)
    {
        destination[index]=source[index];
    }
}
float cost(unsigned short*map,float**G)
{
    unsigned short index1,index2;
    float cost=0;
    
     //WRITE YOU CODE HERE NO NEED TO DEFINE ANY VARIABLE.
    //===================================================
    
    
    
    
    
    
    //===================================================
    return cost;
}
unsigned short predict_best_pos(unsigned short *mapping,unsigned short*pos,float**G,unsigned short pos_count,unsigned short node,unsigned short mapping_count,unsigned short* core_mapping_flag,unsigned short*router_mapping_flag,unsigned short*best_map,float*bestcost,unsigned short* inv_map)
{

    unsigned short count=0,temp_map_count=mapping_count,edge_index,find_node=0,temp_node,index;
    unsigned short* temp_pos,*temp_map,*temp_core_map_flag,*temp_router_map_flag,*temp_inv_map;
    float min_cost=999999,comm_cost;
    unsigned short best_pos;
    temp_pos=new unsigned short[Gr.nodes];
    temp_map=new unsigned short[Gr.nodes];
    temp_core_map_flag=new unsigned short[Gr.nodes];
    temp_router_map_flag=new unsigned short [Gr.nodes];
    temp_inv_map=new unsigned short[Gr.nodes];
    intialize_mapping_var(temp_map);
    intialize_mapping_var(temp_inv_map);
    intialize_array(temp_core_map_flag);
    intialize_array(temp_pos);
    intialize_array(temp_router_map_flag);
   // cout<<"intialize done"<<endl;
    while(count<pos_count)
    {
     //WRITE YOU CODE HERE NO NEED TO DEFINE ANY VARIABLE.
    //===================================================
    
    
    
    
    
    
    //===================================================
    }//3rd while() ends here
    //cout<<"best position"<<pos[best_pos]<<endl;
    return best_pos;
}

void display_mapping(unsigned short*mapping)
{
    unsigned short row_index,colum_index;
    for(row_index=0;row_index<Gr.rows;row_index++)
    {
        for(colum_index=0;colum_index<Gr.colums;colum_index++)
        {
            cout<<mapping[row_index*Gr.colums+colum_index]<<"\t";
        }
        cout<<endl;
    }
}
void display_min_pos(unsigned short *pos,unsigned short pos_count)
{
    unsigned short index;
    cout<<"positions"<<endl;
    for(index=0;index<pos_count;index++)
       cout <<pos[index]<<"\t";
       cout<<endl;
}
unsigned short * map_graph(float**G,unsigned short router_id)
{

    unsigned short mapping_count=0,edge_index=0,temp_node1,temp_node2,index;
    unsigned short *router_mapping_flag,*core_mapping_flag,find_node=0,pos_count=0;
    unsigned short *mapping,*pos,best_pos=0;
    unsigned short* best_map;
    unsigned short *inv_map;
    unsigned short buff=0;
    float comm_cost=0,*bestcost,bc;
    router_mapping_flag=new unsigned short [Gr.nodes];
    core_mapping_flag=new unsigned short [Gr.nodes];
    pos=new unsigned short [Gr.nodes];
    mapping=new unsigned short [Gr.nodes];
    best_map=new unsigned short [Gr.nodes];
    inv_map=new unsigned short [Gr.nodes];
    bc=999999;
    bestcost=&bc;
    intialize_array(router_mapping_flag);
    intialize_mapping_var(mapping);
    intialize_array(core_mapping_flag);
    
    temp_node1=edges[0].destination;
    temp_node2=edges[0].source;

    if(get_communicatio_of_node(temp_node1,G)>get_communicatio_of_node(temp_node2,G))
    {
        mapping[router_id]=temp_node1;
        core_mapping_flag[temp_node1]=1;
        inv_map[temp_node1]=router_id;
    }
    else
    {
        mapping[router_id]=temp_node2;
        core_mapping_flag[temp_node2]=1;
        inv_map[temp_node2]=router_id;
    }
    router_mapping_flag[router_id]=1;
    mapping_count++;
    
    while(mapping_count<Gr.nodes)
    {
        find_node=0;
        edge_index=0;
        //WRITE YOU CODE HERE NO NEED TO DEFINE ANY VARIABLE.
       //===================================================
       
       
       
       
       
       //===================================================
    }
   
    return mapping;

}

void display_data(float**G)
{
        unsigned short index,index2;
        for(index=0;index<Gr.nodes;index++)
        {
            for(index2=0;index2<Gr.nodes;index2++)
            {
                cout<<G[index][index2]<<"\t";
            }
            cout<<endl;
        }
}


void intialize_virtual_add(void)
{
    unsigned short row_index,colum_index;
    //address=(struct virtual_address*)malloc(sizeof(struct virtual_address)*Gr.nodes);
    address.row=(unsigned short int *)malloc(sizeof(unsigned short int)*Gr.nodes);
    address.colum=(unsigned short int *)malloc(sizeof(unsigned short int)*Gr.nodes);
    for(row_index=0;row_index<Gr.rows;row_index++)
    {
        for(colum_index=0;colum_index<Gr.colums;colum_index++)
        {
            //address[row_index*Gr.colums+colum_index].row_add=row_index;
            //address[row_index*Gr.colums+colum_index].colum_add=colum_index;
            /*address[row_index*Gr.colums+colum_index].row=row_index;
            address[row_index*Gr.colums+colum_index].colum=colum_index;*/
            address.row[row_index*Gr.colums+colum_index]=row_index;
            address.colum[row_index*Gr.colums+colum_index]=colum_index;
            // cout<<"Core No= "<<row_index*Gr.colums+colum_index<<"row = "<<address.row[row_index*Gr.colums+colum_index]<<" Col= "<<address.colum[row_index*Gr.colums+colum_index]<<endl;
            //cout<<address[row_index*Gr.colums+colum_index].row_add<<address[row_index*Gr.colums+colum_index].colum_add<<"\t";
        }
        //cout<<endl;
    }
    //cout<<"intialized ok ok";
}

int main(int argc,char*argv[])
{
    float**G;
    unsigned short index1,index2;
    float best_cost=999999,temp_cost;
    unsigned short* mapping,*best_map;
   
   
    G = intialize_graph(argv[1], argv[1]);
    intialize_virtual_add(); 
    cout<<"step 2 done"<<endl;
   
    best_map=new unsigned short [Gr.nodes];
    mapping=new unsigned short [Gr.nodes];
    for(index1=0;index1<Gr.rows;index1++)
    {
    	
    	for(index2=0;index2<Gr.colums;index2++)
    	{       
    	      
    		mapping=map_graph(G,index1*Gr.colums+index2);
    		display_mapping(mapping);
    		temp_cost=cost(mapping,G);
    		cout<<"Mapping Cost= "<<temp_cost<<endl;
    		if(temp_cost<best_cost)
    		{
    			best_cost=temp_cost;
    			copy_arrays(mapping,best_map);
    		}
    	}
    		
    }
   // display_data(G);
   cout<<"************** Final mapping best of all ****************"<<endl;
   cout<<"communication cost (hops*Bandwidth) = "<<best_cost<<endl;
   display_mapping(mapping);
   return 0;
}

