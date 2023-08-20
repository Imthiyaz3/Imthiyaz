#ifndef graph_h
#define graph_h
#define graph_nodes 64

struct graph_info
{
    unsigned short int nodes;
    unsigned short int rows;
    unsigned short int colums;
    unsigned short int edges;
};

struct edge_info
{
    unsigned short int source;
    unsigned short int destination;
    float edge_weight;
};

struct virtual_address
{
	unsigned short int *row;
	unsigned short int *colum;
    //unsigned short int row;
	//unsigned short int colum;
};

void intialize_graph_info(unsigned short int,unsigned short int,unsigned short int,unsigned short int);
float** allocate_memory(unsigned short int);
void copy_graph(float**,float(*)[graph_nodes],unsigned short int);
unsigned short int find_edges(float**,unsigned short int);
void intialize_edges(float** );
float** intialize_graph(char*,char*);
#endif
