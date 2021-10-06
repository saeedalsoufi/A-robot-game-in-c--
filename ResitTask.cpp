#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Visits.h"
using namespace std;

// a function to read from a text file and add to a vector of visits.
void filereader(string g, vector<Visits>& x) {
    int entrytime;
    int exittime;
    string name;
    ifstream f(g);

    while (f >> entrytime >> exittime >> name) {
        x.push_back(Visits(entrytime, exittime, name));
    }
}

// a function to read from a text file and add to a vector of times.
void timessreader(string g, vector<int>& v) {
    ifstream k(g);
    int i;

    while (k >> i) {
        //  cout << i << '\n';
        v.push_back(i);
    }

}
// a function to check how many peeople were present at every time in the vector and output it to console.
void precense(vector<int>& t, vector<Visits> s) {
    int counter;
    vector<Visits> pr;
    for (int i : t) {
        counter = 0;
        for (auto& v : s) {
            if (i >= v.getEntryTime() && i <= v.getExitTime()) {
                counter++;
                pr.push_back(v);
            }
        }
        cout << "There were " << counter << " people present at time " << i << ":" << '\n';
        for (auto& v : pr)
            cout << "  " << v.getName() << "(entered at " << v.getEntryTime() << ", left at " << v.getExitTime() << ")" << '\n';
        pr.clear();
    }

}

// a function to check the amount time with the highest amount of people present at a given time.
int maxtime(vector<Visits>& v) {
    int maxtime = 0;
    for (auto& v : v) {
        if (v.getExitTime() > maxtime)
            maxtime = v.getExitTime();
    }
    return maxtime;
}

// a function to sort the visits alphabeticaaly by first name.
 bool sorts(Visits v, Visits x) {
     return v.getName() < x.getName();
}

 // a function to check and output the time with the highest precesnce.
void precensecounter(vector<int>& t, vector<Visits>& s) {
    int counter = 0;
    int max = 0;
    int maxt = 0;
    for (int i = 0; i <= maxtime(s) ; i++) {
        for (auto& v : s) {
            if (i >= v.getEntryTime() && i <= v.getExitTime()) {
                counter++;
            }
            if (counter > max) {
                max = counter;
                maxt = i;
            }
        }
        counter = 0;
    }
    cout << "There were " << max << " people present at time " << maxt << '\n';
}

// a function to check how long each person was present for.
void peoplecounter(vector<int>& t, vector<Visits>& s) {
  
    for (auto& v : s) {
        cout << v.getName() << " " << (v.getExitTime() - v.getEntryTime()) << '\n';
    }
    
}


int main() {
    vector <Visits> data;
    vector<int> time;
    filereader("visits.txt", data);
    timessreader("times.txt", time);
    sort(data.begin(), data.end(), sorts);
    precense(time, data);
    cout << " -----------------------PART B----------------------" << '\n';
    precensecounter(time, data);
    cout << " -----------------------PART C----------------------" << '\n';
    peoplecounter(time, data);
    return 0;
}