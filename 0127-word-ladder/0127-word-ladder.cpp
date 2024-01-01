class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            //return steps once we find target word
            if(word == endWord) return steps;
            for(int i=0; i<word.length(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(s.find(word) != s.end()){
                        s.erase(word);
                        q.push({word, steps+1});
                    }
                }
                //replace the character with orginal char otherwise 'z' will occupy that place
                word[i] = original;
            }
        }
        return 0;
    }
};