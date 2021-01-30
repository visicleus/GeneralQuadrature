#include "stdlib.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>


/*
 * Rearranges nodes and weights according to significane
 * index s associated with each node in ascending order
 * 
 * Inputs: 
 * double *s: array of significance indices
 * double *x: array of nodes and weights
 * double *w: array of weights
 * int k: number of nodes and weights
 * int dim: dimension of nodes
 * Outputs: 
 * No outputs, reorders s, x and w
 */




void InsertionSortCentered(double *s,double *x,double *w,int k, int dim, int *nodeIndex) {
  
  int i,j,l;
  double index_s;
  double index_w;
  double *index_x=malloc(dim*sizeof(double));
  int *index_nodes=malloc(2*sizeof(int));
  
  for(i=0;i<k;i++) {
    index_s=s[i];
    for(l=0; l<dim;l++) {
      index_x[l]=x[i*dim+l];
    }
    index_nodes[0]=nodeIndex[2*i];
    index_nodes[1]=nodeIndex[2*i+1];
    index_w=w[i];
    j=i;
    
    while((j>0)&&(s[j-1]>index_s)) {      
    s[j]=s[j-1];
    w[j]=w[j-1];
    nodeIndex[2*j]=nodeIndex[2*j-2];
    nodeIndex[2*j+1]=nodeIndex[2*j-1];
    for(l=0; l<dim;l++) { 
      x[dim*j+l]=x[dim*(j-1)+l];
    }
      j--;
    } 
    s[j]=index_s;
    w[j]=index_w; 
    nodeIndex[2*j]=index_nodes[0];
    nodeIndex[2*j+1]=index_nodes[1];
          
    for(l=0; l<dim;l++) {
      x[j*dim+l]=index_x[l];
    }   
  }//end loops
  
free(index_x);
free(index_nodes);

}//end Insertion sort   



