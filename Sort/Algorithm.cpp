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
    printf("\n");
}
/******************************************************************************************/
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


/******************************************************************************************/
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

/******************************************************************************************/
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

/******************************************************************************************/
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

/******************************************************************************************/
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

/******************************************************************************************/
void modify_heap(int a[], int i, int size)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && a[i] < a[left])
    {
        largest = left;
    }

    if (right <  size && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int max = a[largest];
        a[largest] = a[i];
        a[i] = max;
        modify_heap(a, largest, size);
    }
}

void build_max_heap(int a[], int size)
{
    for (int i = size / 2 - 1; i >= 0;i--)
    {
        modify_heap(a, i, size);
    }
}

void hsort(int a[],int size )
{
    build_max_heap(a, size);
    for (int i = size - 1; i >= 0;--i)
    {
        int largest = a[0];
        a[0] = a[i];
        a[i] = largest;
        modify_heap(a, 0, i);
        printf_array(a, size);
    }
}

void heap_sort(int a[], int size)
{
    hsort(a, size);
    printf_array(a, size);
}

/******************************************************************************************/
void counting_sort(int a[], int size) {
    int k = 20;          
    int * c = new int[k]; //  k = max( a[])  本案例中最大为12 所以20 足够了
    int * b = new int[size];
    for (int i = 0; i < k;i++) {
        c[i] = 0;
    }

    for (int j = 0; j < size;j++)
    {
        c[a[j]] = c[a[j]] + 1;
    }

    for (int q = 1; q < k;q++)
    {
        c[q] = c[q] + c[q - 1];
    }

    for (int p = size - 1; p >= 0;p--)
    {
        b[c[a[p]] - 1] = a[p];
        c[a[p]] = c[a[p]] - 1; // 此目的为了如果存在重复的同样能够以此排列
    }
    for (int t = 0; t < size;t++)
    {
        a[t] = b[t];
    }
    delete[]b;
    delete[]c;
    printf_array(a, size);
}

/******************************************************************************************/
int getIndex(int num, int pos)
{
    int index = 0;
    if (pos > 1)
    {
        int t = num / ((pos - 1) * 10);
        index = t % 10;
    }
    else {
        index = num % 10;
    }
    return index;
}

void getresult(int *arr[],int a[],int size)
{
    int k = 0;
    for (int i = 0; i < 10;i++)
    {
        for (int j = 0; j < arr[11][i];j++)
        {
            a[k++] = *(arr[i] + j);
        }
    }
}

int  getLoopTimes(int a[], int size)
{
    int max = a[0];
    for (int i = 1; i < size;i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    int loop = 1;
    while (max /10)
    {
        loop++;
        max = max / 10;
    }
    return loop;
}

/*
* 基数排序 asc 
*/
void radix_sort(int a[], int size)
{
    int **arr;
    arr = new int *[11];

    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
    }
    int index = 1;
    arr[11][0] = 0;
    int loop = getLoopTimes(a, size);
    while (loop-- > 0)
    {
        for (int k = 0; k < size;k++)
        {
            arr[11][k] = { 0 };
        }
        for (int i = 0; i < size;i++)
        {
            int pos = getIndex(a[i], index);
            *(arr[pos] + arr[11][pos] )= a[i];
            arr[11][pos] ++;
        }
        index++;
        getresult(arr, a,size);
    }
    printf_array(a, size);
}
