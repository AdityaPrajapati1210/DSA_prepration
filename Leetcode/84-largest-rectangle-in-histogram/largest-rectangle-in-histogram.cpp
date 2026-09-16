class Solution {
public:


    vector<int>nextSmaller(vector<int>heights){
        int n = heights.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1; i>=0; i--){
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >=  curr){
                st.pop();
            }

            ans[i] = (st.top() == -1) ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmaller(vector<int>heights){
        int n = heights.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=0; i < n; i++){
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >=  curr){
                st.pop();
            }

            ans[i] = (st.top() == -1) ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) return heights[0];
        vector<int>next = nextSmaller(heights);
        vector<int>prev = prevSmaller(heights);
        int maxArea = 0;

        for(int i=0;i < heights.size(); i++){
            int w = next[i] - prev[i] - 1;
            int h = heights[i];
            int area = w * h;
            maxArea = max(area , maxArea);
        }
        return maxArea;
    }
};