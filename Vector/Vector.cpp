// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;
class Vector 
{
private:
    int* arr = nullptr;
    int size = 0;
public :
    Vector(int size) : size(size)
    {
        if (size < 0)
        {
            size = 1;
        }
        arr = new int[size] {};

    }
    ~Vector() {
        delete[] arr;
        arr = nullptr;
    }
    int GetSize()
    {
        return size;
    }
    int Get(int idx)
    {
        assert(0 <= idx && idx < size);
        return arr[idx];
    }
    void set(int idx, int val) 
    {
        /*if (0 <= idx && idx < size)
        {
            return;
        }*/
        arr[idx] = val;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
            std::cout << "\n";
        }
    }
    int find(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                return i;
            }
        }
        return -1;

    }
    int GetFront()
    {
        return arr[0];
    }
    int GetBack()
    {
        return arr[size -1];
    }
    int PushBack(int value)
    {
        ++size;
        int* arr2 = new int[size] {};        
        /*for (int i = 0; i < size ; i++)
        {
            if (i == size -1)
            {
                arr2[i] = value;
                break;
            }
            arr2[i] = arr[i];
        }*/
        int* temp = arr;
        arr = arr2;
        delete[] temp;        
        return 0;
    }
    int PushFront(int value)
    {
        ++size;
        int* arr2 = new int[size] {};
        for (int i = 1; i < size ; i++)
        {            
            arr2[i] = arr[i - 1];
            cout << arr2[i] << "\n";
        }
        arr2[0] = value;
        int* temp = arr;
        arr = arr2;
        delete[] temp;
        return 0;
    }
};

int main()
{
    Vector v(10);
    for (int i = 0; i < 10; i++)
    {
        v.set(i, i);
    }
    v.PushBack(21);
    v.PushBack(22);
    v.PushBack(23);
    v.print();
    cout << v.GetBack() << " " << v.GetFront();
   /* int n = 4;
    Vector v(n);*/
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
