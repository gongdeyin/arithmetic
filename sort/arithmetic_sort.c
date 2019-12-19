//
//  arithmetic_sort.c
//  arithmeticDemo
//
//  Created by Any on 2019/12/12.
//  Copyright © 2019 龚德银. All rights reserved.
//

#include "arithmetic_sort.h"

// void bubbleSort(int *data, int count) {
//    if(count <= 1) {
//        return;
//    }
//
//    for(int loopIndex = 0; loopIndex < count; loopIndex ++){ //外层循环控制来回循环此次
//        for (int dataIndex = 0; dataIndex < count;dataIndex ++) {//做每个数的对比，进行冒泡
//            if(dataIndex < count - 1) break;
//            int preData = data[dataIndex];
//            int nextData = data[dataIndex+1];
//            if (preData < nextData){
//                data[dataIndex] = nextData;
//                data[dataIndex + 1] = preData;
//            }
//        }
//    }
//}
