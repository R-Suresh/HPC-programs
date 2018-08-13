#include<iostream>
#include<omp.h>
#include<vector>
using namespace std;

// matrix multiplication 
// cant use static allocation during threads

// first we write normall matrix multiplication
int main()
{
 // static allocation
 //int a[10][10],b[10][10],c[10][10];
 //dynamic allocation
 
 vector<double> results;
 int **a  = new int*[1000];

 for (int i=0;i<1000;++i)
   a[i]=new int [1000];

 int **b  = new int*[1000];

 for (int i=0;i<1000;++i)
   b[i]=new int [1000];

 int **c  = new int*[1000];

 for (int i=0;i<1000;++i)
   c[i]=new int [1000];

 for(int iter=1;iter<5;++iter)
{
 int n=250*iter;
 // get size of matrix
 // cin>>n;

 //populate matrix
 srand((unsigned)time(0));
 
 // check correctness of program first
 // populate matrix with 1 first
 // matrix a 
 
 for(int i=0;i<n;++i)
   for(int j=0;j<n;++j)
     {
      a[i][j]=1;
     }

 // matrix b
  
 for(int i=0;i<n;++i)
   for(int j=0;j<n;++j)
     {
      b[i][j]=1;
     }

 // multiplication
 // for parallel execution

double start=omp_get_wtime(),end;


// have to set threads here
omp_set_num_threads(8);
int i,j,k;
#pragma omp parallel for private(j,k)
//#pragma omp parallel for 

 for( i=0;i<n;++i)
  for( j=0;j<n;++j)
   {c[i][j]=0;
    for( k=0;k<n;++k)
     c[i][j]+=a[i][k]*b[k][j];
   }

end=omp_get_wtime();

 // print matrix c
 
 for(int i=0;i<n;++i)
   {for(int j=0;j<n;++j)
     {
      cout<<c[i][j]<<"  ";
     }
    cout<<endl;
   }

 //cout<<"\nThe execution time was "<<end-start<<endl;
  results.push_back(end-start);
}
 for( double d : results)
 cout<<d<<endl;
 return 0;
}
