#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int februaryDays(int year) {
    return 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
int monthDays(int month, int year) {
    if (month == 2) return februaryDays(year);
    if ((month <= 7 && month % 2 == 1) 
    || (month > 7 && month % 2 == 0)) return 31;
    else return 30;
}

class Date {
    int day, month, year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    bool isValid() {
        return day <= monthDays(month, year);
    }
    bool operator<(Date& d) {
        if (year != d.year) return year < d.year;
        if (month != d.month) return month < d.month;
        return day < d.day;
    }
    bool operator>(Date& d) {
        if (year != d.year) return year > d.year;
        if (month != d.month) return month > d.month;
        return day > d.day;
    }
    Date minimum(Date& d1, Date& d2) {
        return d1 < d2 ? d1: d2;
    }
    Date maximum(Date& d1, Date& d2) {
        return d1 > d2 ? d1: d2;
    }
    // return days
    int operator-(Date d) {
        // firstly, count years
        int sum = 0;
        Date now(day, month, year);
        Date minDate = minimum(d, now), maxDate = maximum(d, now);
        for (int y = minDate.year + 1; y < maxDate.year; y++) {
            sum += (februaryDays(y) == 29) ? 366 : 365;
        }
        // now, count months
        if (minDate.year != maxDate.year) {
            // count for the first month
            // sum += monthDays(minDate.month, minDate.year) - minDate.day;
            for (int firstMonth = minDate.month + 1; firstMonth <= 12; firstMonth++) {
                sum += monthDays(firstMonth, minDate.year);
            }
            for (int secondMonth = 1; secondMonth < maxDate.month; secondMonth++) {
                sum += monthDays(secondMonth, maxDate.year);
            }
        }
        else {
            for (int m = minDate.month + 1; m < maxDate.month; m++) {
                monthDays(m, minDate.year);
            }
        }
        if (minDate.year == maxDate.year && minDate.month == maxDate.month)
            return sum + maxDate.day - minDate.day;
        else 
            return sum + monthDays(minDate.month, minDate.year) - minDate.day + maxDate.day;
        // now, count days
    }
};

bool cmp(Date& a, Date& b) {
    return a < b;
}

int problemB() {
    int d1, m1, y1, d2, m2, y2, d3, m3, y3;
    cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2 >> d3 >> m3 >> y3;
    
    Date a(d1, m1, y1);
    Date b(d2, m2, y2);
    Date c(d3, m3, y3);

    vector<Date> v = {a, b, c};
    
    if(!a.isValid() || !b.isValid() || !c.isValid()) {
        cout << "Invalid Input" << endl; 
        return 0;
    }
 
    // define your comparator function globally
    sort(v.begin(), v.end(), cmp); 
    
    // overload the - operator for this to work
    cout << v[2] - v[0] << endl;
    return 0;
}

int main() {
    // freopen("i.txt", "r", stdin);
    problemB();
}