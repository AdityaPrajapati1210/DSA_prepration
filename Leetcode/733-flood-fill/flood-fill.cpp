class Solution {
public: 
    void helper(vector<vector<int>>& image, int sr, int sc, int color, int endRow,int endCol,int oc){
        image[sr][sc] = color;

        if(sr-1 >=0 && image[sr-1][sc] == oc){
            helper(image,sr-1,sc,color,endRow,endCol,oc);
        }
        if(sc-1 >= 0 && image[sr][sc-1] == oc){
            helper(image,sr,sc-1,color,endRow,endCol,oc);
        }
        if(sr+1 < endRow && image[sr+1][sc] == oc){
            helper(image,sr+1,sc,color,endRow,endCol,oc);  
        }
        if(sc+1 < endCol && image[sr][sc+1] == oc){
            helper(image,sr,sc+1,color,endRow,endCol,oc);  
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int endRow = image.size();
        int endCol = image[0].size();
        int oc = image[sr][sc];
        if(oc == color){
            return image;
        }

        helper(image,sr,sc,color,endRow,endCol,oc);

        return image;
    }
};