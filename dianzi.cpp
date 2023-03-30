#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <windows.h>
using namespace std;

void dianzi(vector<int> initVals, int maxLimit, int &maxVal, vector<int> &usedVals, vector<int> &order) {
    int n = initVals.size();
    maxVal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> tempInitVals = {initVals[i], initVals[j]};
            vector<int> tempOrder = {i + 1, j + 1};
            int newVal = initVals[i] + floor(initVals[j] / 2);
            if (newVal <= maxLimit && newVal > maxVal) {
                maxVal = newVal;
                usedVals = {initVals[i], initVals[j]};
                order = tempOrder;
            }
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    tempInitVals.push_back(initVals[k]);
                    tempOrder.push_back(k + 1);
                    newVal += floor(initVals[k] / 2);
                    if (newVal <= maxLimit && newVal > maxVal) {
                        maxVal = newVal;
                        usedVals = {initVals[i], initVals[j], initVals[k]};
                        order = tempOrder;
                    }
                }
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(65001);
    printf("伊洛纳手游装备计算器\n凑垫子专用\n个人开发，免费开源，欢迎使用！\n禁止任何转手销售行为，否则后果自负！\n程序及源代码详见B站UP：双流壮汉 uid:61204526\n");
        cout << endl;
        for (int i = 0; i < 120; i++) { 
            cout << '-';
        }
        cout << endl << endl;
    while (true) {
        vector<int> initVals;
        cout << "输入用作材料的装备的数值，空格分割，以字母o结尾: ";
        string input;
        while (cin >> input) {
            if (input == "o" || input == "O") {
                break;
            }
            initVals.push_back(stoi(input));
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int maxLimit;
        cout << "输入最大数值限制: ";
        cin >> maxLimit;
        int maxVal;
        vector<int> usedVals;
        vector<int> order;
        dianzi(initVals, maxLimit, maxVal, usedVals, order);
        cout << "最接近的值: " << maxVal << endl;
        cout << "使用过的装备对应的数值: ";
        for (int val : usedVals) {
            cout << val << ' ';
        }
        cout << endl;
        cout << "合成顺序: ";
        for (int val : order) {
            cout << val << ' ';
        }
        cout << endl;
         for (int i = 0; i < 120; i++) { 
            cout << '-';
        }
        cout << endl << endl;
    }
}