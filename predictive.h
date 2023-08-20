#ifndef predictive_h
#define predictive_h

void short_edges(void);
void display_edges(void);
void copy_arrays(unsigned short*,unsigned short*);
void intialize_array(unsigned short* );
float get_communicatio_of_node(unsigned short ,float**);
unsigned short get_maximum_outgoing_edge_maped_node(unsigned short* ,struct edge_info );
unsigned short int hop_count(unsigned short ,unsigned short );
unsigned short find_min_comm_pos(unsigned short *,unsigned short ,unsigned short *,float**,unsigned short int*,unsigned short *,unsigned short*);
unsigned short predict_best_pos(unsigned short *,unsigned short*,float**,unsigned short,unsigned short ,unsigned short,unsigned short*,unsigned short*,unsigned short*,float*,unsigned short* );
void display_mapping(unsigned short*);
void display_min_pos(unsigned short *,unsigned short );
unsigned short * map_graph(float**,unsigned short );
void display_data(float**);
float cost(unsigned short*,float**);
void read_graph(float**,char*);
void print_address(unsigned short*,char*);

#endif
