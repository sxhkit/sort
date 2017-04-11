// Sort.cpp : 定义控制台应用程序的入口点。
//

#include <tchar.h>
#include "Algorithm.h"

int _tmain(int argc, _TCHAR* argv[])
{
    int a[] = { 2, 5, 3, 9, 7, 12, 8,6 };
    int len = sizeof(a) / sizeof(int);
    //insert_sort(a,sizeof(a) / sizeof(int));

    //bubble_sort(a, len);
    //select_sort(a, len);
    //merge_sort(a, len);
    //quick_sort(a, len);
    heap_sort(a, len);
	return 0;
}
