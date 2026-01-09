#include <vector>
using namespace std;







struct Teemo_Attacking {
public:
    struct Interval {int start, end; };
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        std::vector<int> starts, ends;
        for(auto& t : timeSeries) {
            starts.push_back(t);
            ends.push_back(t + duration - 1);
        }

        std::vector<Interval> merged_intervals;

        for(int i = 1; i < starts.size(); i++) {
            auto& prev_start = starts[i-1];
            auto& prev_end = ends[i-1];
            auto& cur_start = starts[i];
            auto& cur_end = ends[i];

            if(prev_end < cur_start) {
                merged_intervals.push_back({prev_start, prev_end});
                continue;
            }

            // prev_end >= cur_start

            starts[i] = prev_start;
            ends[i] = cur_end;
        }

        merged_intervals.push_back({starts.back(), ends.back()});

        int res {0};

        for(auto& interval : merged_intervals) {
            res += interval.end - interval.start + 1;
        }

        return res;
    }
};
