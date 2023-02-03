class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        vector<string> rows(numRows);
        bool moveDown = true;
        int rowIdx = 0;
        
        for (auto &ch : s) {
            rows[rowIdx] += ch;
            
            if (rowIdx == numRows - 1)
                moveDown = false;
            else if (rowIdx == 0)
                moveDown = true;

            rowIdx += (moveDown ? 1 : -1);
        }

        string ret = "";
        for (int i = 0; i < numRows; ++i)
            ret += rows[i];
        
        return ret;
    }
};
