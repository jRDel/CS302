//This is the main driver for project 2, which tests the efficiency of performance of sorting algorithms. I chose to implement selection and merge sort. 

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include "SelectionSort.cpp"
#include "MergeSort.cpp"

using namespace std;
using namespace std::chrono;

void testSelection()
{
 //unsorted arrays for case 1
int smallArray[1000];
int mediumArray[10000];
int largeArray[100000];

//sorted arrays for case 2
int smallArraySorted[1000];
int mediumArraySorted[10000];
int largeArraySorted[100000];

//Populate the arrays with random numbers...
    srand(time(0)); //seeding the rand() function
    for(int i=0; i<1000; i++) //for smallArray
    {
        smallArray[i]= rand() % 1000000;
    }

    for(int i=0; i<10000; i++) //for mediumArray
    {
        mediumArray[i] = rand() % 1000000;
    }

    for(int i=0; i<100000; i++) //for largeArray
    {
        largeArray[i] = rand() % 1000000;
    }

int sorts = 0;
unsigned long int swapsSmall, swapsMedium, swapsLarge=0;
unsigned long int comparisonsSmall, comparisonsMedium, comparisonsLarge=0;

cout<<"Now testing the selection sort and taking the average of 10 sorts on an originally unsorted array..."<<endl;
SelectionSort<int> smallTest(smallArray, 1000);
SelectionSort<int> mediumTest(mediumArray, 10000);
SelectionSort<int> largeTest(largeArray, 100000);

std::chrono::time_point<std::chrono::system_clock> start, end;

start = std::chrono::system_clock::now();
while(sorts<10)
{
    smallTest.selectionSort(smallArray, 1000);
    swapsSmall=swapsSmall+smallTest.getSwaps();
    comparisonsSmall=comparisonsSmall+smallTest.getComparisons();   
    sorts++;
}
sorts=0;  
end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds1 = end-start;

start = std::chrono::system_clock::now();
while(sorts<10)
{
    mediumTest.selectionSort(mediumArray, 10000);
    swapsMedium=swapsMedium+mediumTest.getSwaps();
    comparisonsMedium=comparisonsMedium+mediumTest.getComparisons();
    sorts++;
}
sorts=0;  
end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds2 = end-start;

start = std::chrono::system_clock::now();
while(sorts<10)
{
    largeTest.selectionSort(largeArray, 100000);
    swapsLarge=swapsLarge+largeTest.getSwaps();
    comparisonsLarge=comparisonsLarge+largeTest.getComparisons();
    sorts++;
}
end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds3 = end-start;

swapsSmall=swapsSmall/10;
swapsMedium=swapsMedium/10;
swapsLarge=swapsLarge/10;

comparisonsSmall=comparisonsSmall/10;
comparisonsMedium=comparisonsMedium/10;
comparisonsLarge=comparisonsLarge/10;

elapsed_seconds1/=10;
elapsed_seconds2/=10;
elapsed_seconds3/=10;

cout<<"The average number of swaps for small array was: "<<swapsSmall<<endl;
cout<<"The average number of comparisons for small array was: "<<comparisonsSmall<<endl;
cout<<"The average time for the small array in seconds was: "<<elapsed_seconds1.count()<<endl;

cout<<"The average number of swaps for medium array was: "<<swapsMedium<<endl;
cout<<"The average number of comparisons for medium array was: "<<comparisonsMedium<<endl;
cout<<"The average time for the medium array in seconds was: "<<elapsed_seconds2.count()<<endl;

cout<<"The average number of swaps for large array was: "<<swapsLarge<<endl;
cout<<"The average number of comparisons for large array was: "<<comparisonsLarge<<endl;
cout<<"The average time for the large array in seconds was: "<<elapsed_seconds3.count()<<endl;
}

void testMerge(){
    //unsorted arrays for case 1
int smallArray[1000];
int mediumArray[10000];
int largeArray[100000];

//sorted arrays for case 2
int smallArraySorted[1000];
int mediumArraySorted[10000];
int largeArraySorted[100000];

//Populate the arrays with random numbers...
    srand(time(0)); //seeding the rand() function
    for(int i=0; i<1000; i++) //for smallArray
    {
        smallArray[i]= rand() % 1000000;
    }

    for(int i=0; i<10000; i++) //for mediumArray
    {
        mediumArray[i] = rand() % 1000000;
    }

    for(int i=0; i<100000; i++) //for largeArray
    {
        largeArray[i] = rand() % 1000000;
    }
    

int sorts = 0;
unsigned long int swapsSmall, swapsMedium, swapsLarge=0;
unsigned long int comparisonsSmall, comparisonsMedium, comparisonsLarge=0;

cout<<"Now testing the selection sort and taking the average of 10 sorts on an originally unsorted array..."<<endl;
MergeSort<int> smallTest(smallArray, 0, 1000);
MergeSort<int> mediumTest(mediumArray, 0, 10000);
MergeSort<int> largeTest(largeArray, 0, 100000);

std::chrono::time_point<std::chrono::system_clock> start, end;

start = std::chrono::system_clock::now();
while(sorts<10)
{
    smallTest.mergeSort(smallArray, 0, 1000);
    swapsSmall=swapsSmall+smallTest.getSwaps();
    comparisonsSmall=comparisonsSmall+smallTest.getComparisons();   
    sorts++;
}
sorts=0;  
end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds1 = end-start;

start = std::chrono::system_clock::now();
while(sorts<10)
{
    mediumTest.mergeSort(mediumArray, 0, 10000);
    swapsMedium=swapsMedium+mediumTest.getSwaps();
    comparisonsMedium=comparisonsMedium+mediumTest.getComparisons();
    sorts++;
}
sorts=0;  
end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds2 = end-start;

start = std::chrono::system_clock::now();
while(sorts<10)
{
    largeTest.mergeSort(largeArray, 0, 100000);
    swapsLarge=swapsLarge+largeTest.getSwaps();
    comparisonsLarge=comparisonsLarge+largeTest.getComparisons();
    sorts++;
}
end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds3 = end-start;

swapsSmall=swapsSmall/10;
swapsMedium=swapsMedium/10;
swapsLarge=swapsLarge/10;

comparisonsSmall/=10;
comparisonsMedium/=10;
comparisonsLarge/=10;

elapsed_seconds1/=10;
elapsed_seconds2/=10;
elapsed_seconds3/=10;

cout<<"The average number of swaps for small array was: "<<swapsSmall<<endl;
cout<<"The average number of comparisons for small array was: "<<comparisonsSmall<<endl;
cout<<"The average time for the small array in seconds was: "<<elapsed_seconds1.count()<<endl;

cout<<"The average number of swaps for medium array was: "<<swapsMedium<<endl;
cout<<"The average number of comparisons for medium array was: "<<comparisonsMedium<<endl;
cout<<"The average time for the medium array in seconds was: "<<elapsed_seconds2.count()<<endl;

cout<<"The average number of swaps for large array was: "<<swapsLarge<<endl;
cout<<"The average number of comparisons for large array was: "<<comparisonsLarge<<endl;
cout<<"The average time for the large array in seconds was: "<<elapsed_seconds3.count()<<endl;
}


int main(){

cout<<"Hello. This program tests the average swaps, comparisons, and computing time of running two different sorts on arrays of random numbers of size 1000, 10000, and 100000."<<endl;
cout<<"Please choose from the following options:"<<endl<<"(1) Test with Selection Sort"<<endl<<"(2) Test with Merge Sort"<<endl<<"(3) Exit the program"<<endl;

int option;
bool go=true;

while(go==true)
{

    cout<<"Option:";
    cin>>option;

    switch(option){
        case 1:
            testSelection();
            break;
        case 2:
            testMerge();
            break;
        case 3:
            go=false;
            break;
        default:
            cout<<"Please input a valid option."<<endl;
            break;
    }   

}





return 0;

}