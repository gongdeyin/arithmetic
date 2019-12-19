//
//  arithmetic_sort.h
//  arithmeticDemo
//
//  Created by Any on 2019/12/12.
//  Copyright © 2019 龚德银. All rights reserved.
//

#ifndef arithmetic_sort_h
#define arithmetic_sort_h

#include <stdio.h>
#endif /* arithmetic_sort_h */

/*
* 冒泡排序，核心点在于，把最大或者最小数，朝一个方向运动，此为冒泡，时间复杂度为N的二次方
*/
void bubbleSort(int *data, int count) {
    if(count <= 1) {
        return;
    }

    for(int loopIndex = 0; loopIndex < count; loopIndex ++){ //外层循环控制来回循环此次
        for (int dataIndex = 0; dataIndex < count - loopIndex - 1;dataIndex ++) {//做每个数的对比，进行冒泡
            if (data[dataIndex] < data[dataIndex + 1]) {
                int tmp = data[dataIndex];
                data[dataIndex] = data[dataIndex + 1];
                data[dataIndex + 1] = tmp;
            }
        }
    }
}

/*
* 插入排序算法时间复杂度跟冒泡排序是一样的，而且，实现起来比冒泡排序更为复杂，难点在于扫描有序数组以及对数组平移各自的索引范围确定，时间复杂度为N的二次方
*/
void insertSort(int *data,int length) {
    if (length <= 1)
    {
        return;
    }

    for (int dataIndex = 1; dataIndex < length; dataIndex++) //取数组元素无序数据
    {
        for (int  sequenceIndex = 0; sequenceIndex < dataIndex; sequenceIndex++) //扫描数组有序部分，找到插入位置
        {
            if (data[dataIndex] < data[sequenceIndex])
            {
                int insertData = data[dataIndex];
                for (int i = dataIndex; i > sequenceIndex; i--) //有插入项，对数组数据进行右平移一位，这里虽然有一个循环但是，算一个平均复杂度，遍历次数为1，因此总体复杂度还是N的二次方
                {
                    data[i] = data[i - 1];
                }
                data[sequenceIndex] = insertData;
                break;
            }
        }
    }
}

/*
* 插入排序算法更高效的写法，可读性差了点
*/
void insertSort2(int *data,int length) {
    if (length <= 1)
    {
        return;
    }

    for (int dataIndex = 1; dataIndex < length; dataIndex++)
    {
        int value = data[dataIndex];
        int j = dataIndex - 1;

        for (; j >= 0;j--) //1.把对比和移动数据合并一步 2.数组的有序部分因为从小到大有序，因此只需移动大于对比数后面部分；
        {
            if (data[j] > value)
            {
                data[j+1] = data[j];
            } else
            {
                break;
            }
        }
        data[j+1] = value;
    }
}

/*
*选择排序，故名，数组被划分后有序和无序两个部分，每次扫描无序部分的最大或者最小值，放到有序部分中；
*对比冒泡和插入排序，选择排序在扫描数组次数跟冒泡和插入算法一致，但是，少了冒泡排序的多次交换数据和插入排序的数据移动，因此，效率略高。
*/
void selectionSort(int *data,int length) {
    if (length <= 1)
    {
        return;
    }

    for (int dataIndex = 0; dataIndex < length; dataIndex++)
    {
        int minData = data[dataIndex];
        int minDataIndex = 0;
        bool canSwitch = false;
        for (int startIndex = dataIndex; startIndex < length; startIndex++)
        {
            if (data[startIndex] < minData)
            {
                minData = data[startIndex];
                minDataIndex = startIndex;
                canSwitch = true;
            }
        }

        if (canSwitch)
        {
            int tmp = data[dataIndex];
            data[dataIndex] = minData;
            data[minDataIndex] = tmp;
        }
    }
}








