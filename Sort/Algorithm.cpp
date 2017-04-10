#include "Algorithm.h"

void printf_array(int a[], int size)
{
    for (int j = 0; j < size; j++)
    {
        printf("%d", a[j]);
        if (j != size)
        {
            printf(",");
        }
    }
}
/*
*   insert sort  asc
*/
void insert_sort(int a[],int size)
{
    int len = size;
    if(len < 2) {
        return;
    }
    for (int i = 0; i < len;i++) {
        int key = a[i];
        int pos = i;
        for (int k = i; k > 0;k-- )
        {
            if (a[k - 1] > key)
            {
                a[k] = a[k - 1];
                pos = k - 1;
            }
            else
            {
                break;
            }
        }
        a[pos] = key;
    }
    printf_array(a, size);
}


/*
*      bubble sort asc
*/
void bubble_sort(int a[], int size)
{
    for (int i = 0; i < size;i++)
    {
        for (int j = i ; j < size;j++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    printf_array(a, size);
}

/*
*  select sort 
*/
void select_sort(int a[], int size)
{
    
    for (int i = 0; i < size;i++)
    {
        int min = a[i];
        int pos = i;
        for (int j = i; j < size;j++)
        {
            if (a[j] < min)
            {
                pos = j;
                min = a[j];
            }
        }
        if (pos != i)
        {
            a[pos] = a[i];
            a[i] = min;
        }
    }
    printf_array(a, size);
}

void merge_array(int a[],int b[],int start,int mid,int end)
{
    int i = start;
    int j = mid +1;
    int k = start;
    while (i != mid + 1 && j != end + 1)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else {
            b[k++] = a[j++];
        }
    }

    while (i != mid+1)
    {
        b[k++] = a[i++];
    }
    while (j != end+1)
    {
        b[k++] = a[j++];
    }

    for (int p = start; p <= end;p++)
    {
        a[p] = b[p];
    }
}

void sort_part(int a[],int b[],int start,int end)
{
    int mid_index = 0;
    if (start < end)
    {
        mid_index = (start + end) / 2;
        sort_part(a,b,start,mid_index);
        sort_part(a,b,mid_index + 1 , end);
        merge_array(a,b,start,mid_index,end);
    }

}

void merge_sort(int a[], int size) {
    int*b = new int[size];
    sort_part(a, b, 0, size-1);
    printf_array(a, size);
    delete b;
}

void qsort(int a[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int key = a[low];
    int first = low;
    int last = high;
    while (first < last)
    {
        while (key > a[last] && first < last)
        {
            last--;
        }
        a[first] = a[last];

        while (first < last && a[first] > key)
        {
            first++;
        }
        a[last] = a[first];
    }
    a[last] = key;
    qsort(a, low, first -1);
    qsort(a, first + 1, high);
}

void quick_sort(int a[], int size){

    qsort(a, 0, size - 1);
    printf_array(a, size);
}