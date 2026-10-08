class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need, have;

        // What does t require?
        for (char c : t) {
            need[c]++;
        }

        int l = 0;
        int formed = 0;

        int minLen = INT_MAX;
        int minL = 0;

        for (int r = 0; r < s.size(); r++) {

            char c = s[r];
            have[c]++;

            // Did adding this character complete a requirement?
            if (need.find(c) != need.end() &&
                have[c] == need[c]) {
                formed++;
            }

            // Window is valid
            while (formed == need.size()) {

                // Update answer
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minL = l;
                }

                // Remove s[l]
                char leftChar = s[l];
                have[leftChar]--;

                // Did removing it break a requirement?
                if (need.find(leftChar) != need.end() &&
                    have[leftChar] < need[leftChar]) {
                    formed--;
                }

                l++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(minL, minLen);
    }
};// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int n = s.size(), m = t.size();
//         if (m > n) return "";

//         vector<int> mp(128, 0);
//         for (char c : t) mp[c]++;

//         int l = 0, in = 0;
//         int mini = INT_MAX, leftpos = 0;

//         for (int r = 0; r < n; r++) {
//             if (mp[s[r]] > 0) in++;     // count only if still needed
//             mp[s[r]]--;                  // may go negative = surplus

//             while (in == m) {            // window valid -> shrink
//                 if (r - l + 1 < mini) {
//                     mini = r - l + 1;
//                     leftpos = l;
//                 }
//                 mp[s[l]]++;
//                 if (mp[s[l]] > 0) in--;  // lost a needed char
//                 l++;
//             }
//         }
//         return mini == INT_MAX ? "" : s.substr(leftpos, mini);
//     }
// };