class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_set<char>myset;
        for (const auto&c:ransomNote) {
            myset.insert(c);
        }
        auto it=myset.begin();
        while (it != myset.end()) {
            if (count(ransomNote.begin(),ransomNote.end(),*it) > count(magazine.begin(),magazine.end(),*it)) {
                return false;
            }
            ++it;
        }
        return true;
    }
};
