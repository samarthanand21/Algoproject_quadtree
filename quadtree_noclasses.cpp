#include<bits/stdc++.h>
#include "quadtree.h"
#include "quadtree.cpp"

using namespace std ;

int main() 
{ 
cout<<"Enter the Bottom left and Top Right coordinates of the entire space ";
point bootl,topr ;cin>>bootl.x>>bootl.y>>topr.x>>topr.y;

quadtree center(bootl, topr); 

cout<<"Enter The number of points you want to store ?";
long long int size;
cin>>size;
int f=0;
node entry[size];
while(size--)
{
    int x,y,d;
    cin>>x>>y>>d;
    entry[f].stamp=point(x,y);
    entry[f].data=d;
    center.insert(&entry[f]); 
    f++;
}
cout<<"Enter the co ordinates you want to search ? ";
clock_t start, end; 
start = clock();  
long long int  x_co , y_co ; 
cin >> x_co >> y_co ; 
cout<<"  "<<center.search(point(x_co,y_co))->data<<endl;
end = clock(); 
double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
return 0; 
}