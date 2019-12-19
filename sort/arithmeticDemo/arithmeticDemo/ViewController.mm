//
//  ViewController.m
//  arithmeticDemo
//
//  Created by Any on 2019/12/12.
//  Copyright © 2019 龚德银. All rights reserved.
//

#import "ViewController.h"
#include "arithmetic_sort.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    int a[18] = {4,2,1,6,10,9,7,13,11,3,5,16,12,8,14,15,16,15};
//    bubbleSort(a, 16);
//    insertSort2(a, 18);
    selectionSort(a, 18);
    NSLog(@"ok!");
}
@end
