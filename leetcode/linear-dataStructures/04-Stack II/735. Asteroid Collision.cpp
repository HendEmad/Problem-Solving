class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> myStack;
        for(int i=0;i<asteroids.size();i++){
            if(i==0 || myStack.empty() || asteroids[i]>0){
                myStack.push(asteroids[i]);
                continue;
            }

            //IF negative asteroid
            int flag=0;
            while(!myStack.empty() && myStack.top()>0){
                if(abs(asteroids[i]) == abs(myStack.top())){
                    myStack.pop();
                    flag=1;
                    break;
                }else if(abs(asteroids[i]) > abs(myStack.top())){
                    myStack.pop();
                }else{
                    flag=1;
                    break;  //If negative asteroid is smaller
                }
            }
            if(flag==0){
                myStack.push(asteroids[i]);
            }
        }

        vector<int> ans(myStack.size(),0);
        for(int i=myStack.size()-1;i>=0;i--){
            ans[i]=myStack.top();
            myStack.pop();

        }
        return ans;
    }
};