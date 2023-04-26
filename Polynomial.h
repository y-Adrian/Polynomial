//
//  Polynomial.h
//  Polynomial
//
//  Created by 小雪糕 on 2023/4/26.
//

#ifndef Polynomial_h
#define Polynomial_h

#include "LinkList.h"
#include <vector>
#include <map>
#include <string>

struct term {
    float coef;
    int expn;
};

class Polynomial {
private:
    int n = 0;       // 多项式阶数
    int length = 0;  // 多项式项数
    LinkList<term> *polynomial = NULL;
public:
    Polynomial(vector<term> &);
    Polynomial(vector<float> &);
    Polynomial add_op(Polynomial &);
    Polynomial sub_op(Polynomial &);
    Polynomial mul_op(Polynomial &);
//    Polynomial div_op(Polynomial &);
    void print_item();
};

Polynomial::Polynomial(vector<term> &vec_node) {
    n = int(vec_node.size()) - 1;
    polynomial = new LinkList<term>(vec_node, n + 1);
    for (int i = 0; i <= n; i++)
        if (polynomial->get_data(i + 1).coef) length++;
}

Polynomial::Polynomial(vector<float> &vec_coef) {
    n = int(vec_coef.size()) - 1;
    vector<term> vec;
    for (int i = 0; i <= n; i++) {
        if (vec_coef[i]) length++;
        term node;
        node.coef = vec_coef[i];
        node.expn = i;
        vec.push_back(node);
    }
    polynomial = new LinkList<term>(vec, n + 1);
}

Polynomial Polynomial::add_op(Polynomial &other) {
    vector<term> vec;
    for(int i = 0; i <= max(n, other.n); i++) {
        term node;
        if (i <= min(n, other.n))
            node.coef = this->polynomial->get_data(i + 1).coef + other.polynomial->get_data(i + 1).coef;
        else if (n == min(n, other.n))
            node.coef = other.polynomial->get_data(i + 1).coef;
        else
            node.coef = this->polynomial->get_data(i + 1).coef;
        node.expn = i;
        vec.push_back(node);
    }
    Polynomial res_polynomial(vec);
    return res_polynomial;
}

Polynomial Polynomial::sub_op(Polynomial &other) {
    vector<term> vec;
    for(int i = 0; i <= max(n, other.n); i++) {
        term node;
        if (i <= min(n, other.n))
            node.coef = this->polynomial->get_data(i + 1).coef - other.polynomial->get_data(i + 1).coef;
        else if (n == min(n, other.n))
            node.coef = -other.polynomial->get_data(i + 1).coef;
        else
            node.coef = this->polynomial->get_data(i + 1).coef;
        node.expn = i;
        vec.push_back(node);
    }
    Polynomial res_polynomial(vec);
    return res_polynomial;
}

Polynomial Polynomial::mul_op(Polynomial &other) {
    map<int, float> mp;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= other.n; j++) {
            float coef = this->polynomial->get_data(i + 1).coef * other.polynomial->get_data(j + 1).coef;
            int expn = this->polynomial->get_data(i + 1).expn + other.polynomial->get_data(j + 1).expn;
            mp[expn] += coef;
        }
    }
    vector<float> vec;
    for (int i = 0; i <= (--mp.end())->first; i++)
        vec.push_back((mp.find(i) == mp.end()) ? 0 : mp[i]);
    Polynomial res_polynomial(vec);
    return res_polynomial;
}

void Polynomial::print_item() {
    cout << "Polynomial = ";
    for (int i = 0; i <= n; i++) {
        float coef = polynomial->get_data(i + 1).coef;
        int expn = polynomial->get_data(i + 1).expn;    
        if (coef > 0)
            switch (expn) {
                case 0:
                    cout << coef << ' ';
                    break;

                case 1:
                    if (coef - 1) cout << '+' << ' ' << coef << "x" << ' ';
                    else cout << '+' << ' ' << "x" << ' ';
                    break;

                default:
                    if (coef - 1) cout << '+' << ' ' << coef << "x^" << expn << ' ';
                    else cout << '+' << ' ' << "x^" << expn << ' ';
                    break;
            }
        if (coef < 0)
            switch (expn) {
                case 0:
                    cout << coef << ' ';
                    break;

                case 1:
                    if (coef + 1) cout << '-' << ' ' << -coef << "x" << ' ';
                    else cout << '-' << ' ' << "x" << ' ';
                    break;

                default:
                    if (coef + 1) cout << '-' << ' ' << -coef << "x^" << expn << ' ';
                    else cout << '-' << ' ' << "x^" << expn << ' ';
                    break;
            }
        if (!coef && !expn && !n) cout << coef << ' ';
    }
    cout << endl;
}

#endif /* Polynomial_h */
