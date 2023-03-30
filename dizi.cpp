#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <windows.h>
using namespace std;

void dizi(vector<int> initVals, int maxLimit, int &maxVal, vector<int> &usedVals, vector<int> &halfVals) {
    int n = initVals.size();
    maxVal = 0;
    for (int i = 1; i < pow(2, n); i++) {
        bitset<32> binaryVec(i);
        int tempSum = 0;
        for (int j = 0; j < n; j++) {
            if (binaryVec[j]) {
                tempSum += initVals[j];
            }
        }
        if (tempSum <= maxLimit && tempSum > maxVal) {
            maxVal = tempSum;
            usedVals.clear();
            halfVals.clear();
            for (int j = 0; j < n; j++) {
                if (binaryVec[j]) {
                    usedVals.push_back(initVals[j]);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (!binaryVec[j]) {
                int tempSum2 = tempSum + floor(initVals[j] / 2);
                if (tempSum2 <= maxLimit && tempSum2 > maxVal) {
                    maxVal = tempSum2;
                    usedVals.clear();
                    halfVals.clear();
                    for (int k = 0; k < n; k++) {
                        if (binaryVec[k]) {
                            usedVals.push_back(initVals[k]);
                        }
                    }
                    usedVals.push_back(initVals[j]);
                    halfVals.push_back(initVals[j]);
                }
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(65001);
        printf("伊洛纳手游装备计算器\n凑底子专用\n个人开发，免费开源，欢迎使用！\n禁止任何转手销售行为，否则后果自负！\n程序及源代码详见B站UP：双流壮汉 uid:61204526\n");
        cout << endl;
        for (int i = 0; i < 120; i++) { 
            cout << '-';
        }
        cout << endl << endl;
    while (true) {
        vector<int> initVals;
        cout << "输入准备用于凑底子的装备的数值，空格分割，以字母o结尾: ";
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
        cout << "输入你的底子装备的数值与可改造上限数值的差值的两倍: ";
        cin >> maxLimit;
        int maxVal;
        vector<int> usedVals;
        vector<int> halfVals;
        dizi(initVals, maxLimit, maxVal, usedVals, halfVals);
        cout << "最接近的值: " << maxVal << endl;
        cout << "使用过的装备数值: ";
        for (int val : usedVals) {
            cout << val << ' ';
        }
        cout << endl;
        cout << "需要先合到其他素材装备上的装备数值: ";
        for (int val : halfVals) {
            cout << val << ' ';
        }
        cout << endl;
        for (int i = 0; i < 120; i++) { 
            cout << '-';
        }
        cout << endl << endl;
    }
}