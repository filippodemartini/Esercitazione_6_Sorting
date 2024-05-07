#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include "SortingAlgorithm.hpp"

using namespace SortLibrary;
using namespace std::chrono;

double AVGTimeBS(vector<double>& v, const unsigned int & n)
{
    vector<double> time;
    double avg_time = 0;
    time.reserve(n);


    for(unsigned int it = 0; it < n; it++)
    {
        steady_clock::time_point start = steady_clock::now();

        BubbleSort(v);

        steady_clock::time_point end = steady_clock::now();

        double duration = duration_cast<nanoseconds>(end - start).count();
        time.push_back(duration);
    }

    for(unsigned int it = 0; it < time.size(); it++)
        avg_time += time[it];

    avg_time = avg_time / time.size();

    return avg_time;

}

double AVGTimeMS(vector<double>& v, const unsigned int & n)
{
    vector<double> time;
    double avg_time = 0;
    time.reserve(n);

    for(unsigned int it = 0; it < n; it++)
    {
        steady_clock::time_point start = steady_clock::now();

        MergeSort(v);

        steady_clock::time_point end = std::chrono::steady_clock::now();

        double duration = duration_cast<nanoseconds>(end - start).count();
        time.push_back(duration);
    }

    for(unsigned int it = 0; it < time.size(); it++)
        avg_time += time[it];

    avg_time = avg_time / time.size();

    return avg_time;
}


int main(int argc, char ** argv)
{
    unsigned int n = 10;
    unsigned int n1=200;
    unsigned int dim = stoi(argv[1]);
    vector<double> v(dim);

    // ********************************CASE 1: sorted vectors with n=10**************************************************************
     cout << "CASE 1: sorted vectors with n =10" << endl;

    iota(v.begin(),v.end(), 0);

    cout << "The average time using BubbleSort in nanoseconds is: " << AVGTimeBS(v, n) << " ns" << endl;

    cout << "The average time using MergeSort in nanoseconds is: " << AVGTimeMS(v, n) << " ns" << endl;

    // ********************************CASE 2: sorted vectors with n=100**************************************************************
    cout << "CASE 2: sorted vectors with n =200" << endl;

    iota(v.begin(),v.end(), 0);

    cout << "The average time using BubbleSort in nanoseconds is:  " << AVGTimeBS(v, n1) << " ns" << endl;

    cout << "The average time using MergeSort in nanoseconds is:" << AVGTimeMS(v, n1) <<" ns" << endl;

    // *******************************CASE 3: random vectors with n =10***********************************************
    cout << "CASE 3: random vectors with n=10" << endl;

    for(unsigned int  i = 0; i < dim; i++)
    {
        v[i] = rand() % 1000;
    }

    cout << "The average time using BubbleSort in nanoseconds is:  " << AVGTimeBS(v, n) << "ns" << endl;

    cout << "The average time using MergeSort in nanoseconds is: " << AVGTimeMS(v, n) << "ns" << endl;

    // *******************************CASE 4: random vectors with n =100***********************************************
    cout << "CASE 4: random vectors with n=200" << endl;

    for(unsigned int  i = 0; i < dim; i++)
    {
        v[i] = rand() % 1000;
    }

    cout << "The average time using BubbleSort in nanoseconds is:  " << AVGTimeBS(v, n1) << "ns" << endl;

    cout << "The average time using MergeSort in nanoseconds is: " << AVGTimeMS(v, n1) << "ns" << endl;

    return 0;
}

