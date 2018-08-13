#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
 omp_set_num_threads(10);
 cout<<"\nNumber of processes"<<omp_get_num_procs()<<endl;
 #pragma omp parallel
{
 cout<<omp_get_num_threads()<<endl;
 cout<<"Hello world"<<(omp_get_thread_num())<<endl;
 
}return 0;
}
