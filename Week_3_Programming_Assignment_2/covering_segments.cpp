#include<bits/stdc++.h>
using namespace std;

struct Segment {
    int start, end;
};
bool segmentComparator(Segment a , Segment b) {
  return a.end < b.end;
}
vector<int > optimal_points(vector<Segment> &segments) {
    vector<int > points;
    sort(segments.begin(), segments.end(), segmentComparator);
    int endIndex = segments[0].end;
    for (int i=1; i < segments.size(); i++) {
        if (segments[i].start > endIndex) {
            points.push_back(endIndex);
            endIndex = segments[i].end;
        }
        else {
            if (segments[i].end < endIndex)
            endIndex = segments[i].end;
        }
    }
    points.push_back(endIndex);
    return points;
}
int main() {
    int n;
    cin>>n;
    vector<Segment > segments(n);
    for(int i=0; i<segments.size(); i++) {
        cin>>segments[i].start>>segments[i].end;
    }
    vector<int > points = optimal_points(segments);
    cout<<points.size()<<endl;
    for(int i=0; i<points.size(); i++){
        cout<<points[i]<<" ";
    }
    return 0;
}
