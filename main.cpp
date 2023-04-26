//
//  main.cpp
//  Polynomial
//
//  Created by 小雪糕 on 2023/4/26.
//

#include "Polynomial.h"
#include <vector>

void test_linklist();

int main() {
    vector<float> coef1 = {1, 2, 9, 3, 4, 9, 6, 31, 4, 17};
    vector<float> coef2 = {4, 1, 3, 0, 1, 5, 7, 0, 19, 0, 2, 0, 0, 99, 21, 0, 5};
    Polynomial p1(coef1), p2(coef2);

    cout << "多项式1：" << endl;
    p1.print_item();
    cout << endl;

    cout << "多项式2：" << endl;
    p2.print_item();
    cout << endl;

    Polynomial p_add = p1.add_op(p2);
    cout << "两式相加：" << endl;
    p_add.print_item();
    cout << endl;

    Polynomial p_sub = p1.sub_op(p2);
    cout << "两式相减：" << endl;
    p_sub.print_item();
    cout << endl;

    Polynomial p_mul = p1.mul_op(p2);
    cout << "两式相乘：" << endl;
    p_mul.print_item();
    cout << endl;

    return 0;
}

void test_linklist() {
    vector<int> array = {0, 2, 4, 6, 8};
    
    LinkList<int> linklist(array, 5);
    cout << "初始: ";
    linklist.print_all();
    
    linklist.insert_data(10, 1);
    linklist.insert_data(8, 6);
    cout << "添加: ";
    linklist.print_all();
    
    int data = linklist.drop_data(3);
    cout << "删除: " << '[' << data << "] ";
    linklist.print_all();
    
    data = linklist.get_data(1);
    cout << "获取: " << data << endl;
    
    vector<int> pos = linklist.get_pos(8);
    cout << "定位: " << '[';
    for (auto i : pos) cout << i << ' ';
    cout << ']' << endl;
    
    int len = linklist.get_length();
    cout << "长度: " << len << endl;
}

