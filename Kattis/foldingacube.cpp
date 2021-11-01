#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v(6, vector<char>(6, '.'));

int sizeRow(int i) {
   int size = 0;
   for (int j = 0; j < 6; j++) {
      if (v[i][j] == '#')
     size++;
   }
   return size;
}

int sizeCol(int i) {
   int size = 0;
   for (int j = 0; j < 6; j++) {
      if (v[j][i] == '#')
     size++;
   }
   return size;
}

int main() {
   for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
     char c;
     cin >> c;
     v[i][j] = c;
      }
   }
   
   int row = 0;
   int col = 0;
   bool rowHas = false;
   bool colHas = false;
   for (int i = 0; i < 6; i++) {
      rowHas = false;
      colHas = false;
      for (int j = 0; j < 6; j++) {
     if (v[i][j] == '#' && !rowHas) {
        rowHas = true;
        row++;
     }
     if (v[j][i] == '#' && !colHas) {
        colHas = true;
        col++;
     }
      }
   }
   
   bool ans = false;
   if (row == 4 && col == 3) {
      for (int i =1; i < 5; i++) {
     int left, middle, right;
     left = sizeCol(i-1);
     right = sizeCol(i+1);
     middle = sizeCol(i);
     if (left >= 1 && left <= middle && right >= 1 && right <= middle) {
        ans = true;
        break;
     }
      }
   }
   else if (row == 3 && col == 4) {
      for (int i =1; i < 5; i++) {
     int left, middle, right;
     left = sizeRow(i-1);
     right = sizeRow(i+1);
     middle = sizeRow(i);
     if (left >= 1 && left <= middle && right >= 1 && right <= middle) {
        ans = true;
        break;
     }
      }
   }
   else if (row == 5 && col == 2) {
      for(int i=1; i<5; i++) {
     int left, middle, right;
     left = sizeCol(i-1);
     middle = sizeCol(i);
     right = sizeCol(i+1);
     if((left == 3 && middle == 3) || (middle == 3 && right == 3)) {
        ans = true;
        break;
     }
      }
   }
   else if (row == 2 && col == 5) {
      for(int i=1; i<5; i++) {
     int left, middle, right;
     left = sizeRow(i-1);
     middle = sizeRow(i);
     right = sizeRow(i+1);
     if((left == 3 && middle == 3) || (middle == 3 && right == 3)) {
        ans = true;
        break;
     }
      }
   }
   
   if (ans)
      cout << "can fold" << endl;
   else
      cout << "cannot fold" << endl;
}