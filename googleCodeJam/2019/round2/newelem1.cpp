#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

void solve(int testCase) {
    std::vector<std::pair<int, int>> in;
    int n;
    std::cin >> n;
    in.resize(n);
    for(int i = 0; i< n;i++) {
        std::cin >> in[i].first >> in[i].second;
    }
    
    std::set<std::pair<int, int>> thresholds;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::pair<int, int> ratio(std::make_pair(in[i].first - in[j].first, in[i].second - in[j].second));
            if((ratio.first < 0 &&  ratio.second> 0) || (ratio.first > 0 &&  ratio.second< 0)) {
                int d = std::__gcd(ratio.first, ratio.second);
                if(d < 0) d = -d;
                ratio.first /= d;
                ratio.second /= d;
                if(ratio.first < 0) { 
                    // - + and + - are counted ad + - always
                    ratio.first = -ratio.first;
                    ratio.second = -ratio.second;
                }
                thresholds.insert(ratio);
            }
        }
    }
    std::cout << "Case #" << testCase << ": " << thresholds.size() + 1 << std::endl;
    
}


int main() {
    int t;
    std::cin >> t;
    
    for(int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}

