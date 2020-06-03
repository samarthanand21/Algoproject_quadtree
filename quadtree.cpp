#include<bits/stdc++.h>
#include "quadtree.h"
using namespace std ;

quadtree::quadtree()
{
    bottomleft = point(0, 0); 
    topright = point(0, 0); 
    n = NULL; 
    toplefttree  = NULL; 
    toprighttree = NULL; 
    bottomlefttree  = NULL; 
    bottomrighttree = NULL; 
}
quadtree::quadtree(point botLeft, point topRight)
{
    n = NULL;
    toplefttree = NULL;
    bottomlefttree = NULL;
    toprighttree = NULL;
    bottomrighttree = NULL;
    bottomleft = botLeft;
    topright = topRight;
}
void quadtree::insert(node* Node)
{
    if(!inrange(Node->stamp))   // Check whether the given node can be stored in the quadtree;
    return ;
    
    if(Node == NULL)
    return ;
    
    if(topright.x - bottomleft.x <= 1 && topright.y - bottomleft.y <= 1) // This area cannot be further subdivided, hence it is the place to insert;
    {
        if(n == NULL)
        n = Node;
        return ;
    }
    
     if ((bottomleft.x + topright.x) / 2 >= Node->stamp.x)
     {
         if ((bottomleft.y + topright.y) / 2 <= Node->stamp.y)  // Node goes to top left tree;
         {
             if(toplefttree == NULL) 
             toplefttree = new quadtree( 
                    point(bottomleft.x, (bottomleft.y + topright.y)/2), 
                    point((bottomleft.x + topright.x)/2, topright.y)); 
             toplefttree->insert(Node);
         }
         else
         {
             if(bottomlefttree == NULL)   // Node goes to bottom left tree;
             bottomlefttree = new quadtree(
                    point(bottomleft.x, bottomleft.y),
                    point((bottomleft.x + topright.x)/2, (bottomleft.y + topright.y)/2));
             bottomlefttree->insert(Node);        
         }
     }
     else
     {
         if ((bottomleft.y + topright.y) / 2 <= Node->stamp.y) // Node goes to top right tree;
         {
             if(toprighttree == NULL)
             toprighttree = new quadtree(
                    point((bottomleft.x + topright.x)/2, (bottomleft.y + topright.y)/2),
                    point(topright.x, topright.y));
             toprighttree->insert(Node);        
         }
         else
         {
             if(bottomrighttree == NULL)   // Node goes to bottom right tree;
             bottomrighttree = new quadtree(
                    point((bottomleft.x + topright.x)/2, bottomleft.y),
                    point(topright.x, (bottomleft.y + topright.y)/2));
             bottomrighttree->insert(Node);        
         }
     }
}

node *quadtree::search(point p)
{
    if(n!= NULL)  // We are at quad of unit area and this is our node which we searched;
    return n;
    
    if(!inrange(p))   // The current quadtree cannot contain the searched node;
    return NULL;
    
    if ((bottomleft.x + topright.x) / 2 >= p.x) 
    { 
        if ((bottomleft.y + topright.y) / 2 <= p.y)   // Search in top left tree;
        { 
            if (toplefttree == NULL) 
                return NULL; 
            return toplefttree->search(p); 
        } 
  
        else
        { 
            if (bottomlefttree == NULL)   // Search in bottom left tree;
                return NULL; 
            return bottomlefttree->search(p); 
        } 
    } 
    else
    {
        if ((bottomleft.y + topright.y) / 2 <= p.y)    // Search in top right tree;
        { 
            if (toprighttree == NULL) 
                return NULL; 
            return toprighttree->search(p); 
        } 
  
        else
        { 
            if (bottomrighttree == NULL)     // Search in bottom right tree;
                return NULL; 
            return bottomrighttree->search(p); 
        } 
    }
};

bool quadtree::inrange(point p) // Function to check whether the point lies within the boundary of the quadtree;
{
    return(p.x >= bottomleft.x && p.y >= bottomleft.y &&
           p.x <= topright.x && p.y <= topright.y);
}