#include <vector>
#include <fstream>
#include <map>
#include <deque>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

ifstream fin("house.in");
//ofstream cout("house.out");

const long long INF = (long long)1.1e18;
const double PI = acos(-1.0);
const double E = exp(1.0);
const double EPS = 1e-6;

struct line {
    double a, b, c;
    line(double x = 0, double y = 0, double z = 0) {
        a = x;
        b = y;
        c = z;
    }
};

bool comp(line l1, line l2) {
    return (l1.c < l2.c - EPS);
}

vector<line> l, ox, oy;

int main() {
    int n;
    double x1, y1, x2, y2;
    fin >> n;
    l.resize(n);
    for (int i = 0; i < n; ++i) {
        fin >> x1 >> y1 >> x2 >> y2;
        l[i].a = y2 - y1;
        l[i].b = x1 - x2;
        l[i].c = y1 * (x2 - x1) - x1 * (y2 - y1);
        if (abs(l[i].a) < EPS) {
            ox.push_back(l[i]);
        } else if (abs(l[i].b) < EPS) {
            oy.push_back(l[i]);
        }
    }
  //  cout << "OK" << '\n';
    sort(ox.begin(), ox.end(), comp);
    sort(oy.begin(), oy.end(), comp);
    sort(l.begin(), l.end(), comp);
   // cout << "OK" << '\n';
    int m = ox.size();
    int k = oy.size();
   /* for (int i = 0; i < m; ++i) {
		cout << ox[i].a << " " << ox[i].b << " " << ox[i].c << '\n';
    }
	for (int i = 0; i < k; ++i) {
		cout << oy[i].a << " " << oy[i].b << " " << oy[i].c << '\n';
    }*/
    double x = 0.0, y = 0.0;
 //cout << m << " " << k << '\n';
    if (m > 0 || k > 0) {
     /*   if (m > 0) {
            if (m % 2 == 1) {
                x = -ox[m / 2].c / ox[m / 2].b;
            } else {
                x = -(ox[m / 2].c + ox[m / 2 - 1].c) / ox[m / 2].b;
            }
        }
        if (k > 0) {
            if (k % 2 == 1) {
                y = -oy[k / 2].c / oy[k / 2].a;
            } else {
                y = -(oy[k / 2].c + oy[k / 2 - 1].c) / oy[k / 2].a;
            }
        }*/
     //   cout << "OK" << '\n';
     //   cout << m << " " ;//<< ox[m / 2].b << '\n';
		if (m > 0) {
			y = -(ox[0].c + ox[m - 1].c) / (2.0 * ox[m / 2].b);
		}
	//	cout << "OK" << '\n';
		if (k > 0) {
			x = -(oy[0].c + oy[k - 1].c) / (2.0 * oy[k / 2].a);
		}
    } else {
        x = 0;
     /*   if (n % 2 == 1) {
            x = -ox[m / 2].c / ox[m / 2].b;
        } else {
            x = -(ox[m / 2].c + ox[m / 2 - 1].c) / ox[m / 2].b;
        }
	*/	y = -(ox[0].c + ox[m - 1].c) / (2.0 * ox[m / 2].b);
    }
    cout << fixed;
    cout.precision(6);
    cout << x << " " << y << '\n';
    return 0;
}
