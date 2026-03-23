#include "print.hpp"

void print_mst(const Mst &my_mst){
    for(int i=0; i<my_mst.size(); i++)
        cout<<my_mst[i].first<<" "<<my_mst[i].second.first<<" "<<my_mst[i].second.second<<'\n';
}

