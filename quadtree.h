#ifndef quadtree_h
#define quadtree_h

struct point
{
    int x;
    int y;
    point(int xi, int yi)
    {
        x = xi;
        y = yi;
    }
    point()
    {
        x=0;
        y=0;
    }
};

struct node
{
    point stamp;
    int data;
    node(point st, int dat)
    {
        stamp = st;
        data = dat;
    }
    node()
    {
        data = 0;
    }
};

class quadtree
{
    point bottomleft;
    point topright;
    node *n;
    quadtree *toplefttree;
    quadtree *bottomlefttree;
    quadtree *toprighttree;
    quadtree *bottomrighttree;
    public:
        quadtree() ;
        quadtree(point botLeft, point topRight) ;
        void insert(node*);
        node *search(point);
        bool inrange(point);
};


#endif //quadtree_h