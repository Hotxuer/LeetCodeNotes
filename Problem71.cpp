//
// Created by mac on 2020/7/16.
//

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stringList;
        string temp;
        path = path+"/";
        for (int i=1; i<path.size(); i++) {
            if (path[i]=='/') {
                if (temp==".." && stringList.size()>0)
                    stringList.pop_back();
                else if (temp!= ".." && temp!= "." && temp.size()>0)
                    stringList.push_back(temp);
                temp = "";
            } else {
                temp.push_back(path[i]);
            }
        }
        // 最后没有/截断：所以更巧妙的方法是在path后手动加入/
//        if (temp.size()>0) {
//            if (temp==".." && stringList.size()>0)
//                stringList.pop_back();
//            else if (temp!= ".." && temp!= "." && temp.size()>0)
//                stringList.push_back(temp);
//        }

        string result("");
        for (int i=0; i<stringList.size(); i++) {
            cout<<stringList[i]<<endl;
            result = result+"/"+stringList[i];
        }
        return result.size()>0 ? result : "/";

    }
};

// 精简写法
class Solution2 {
public:
    string simplifyPath(string path) {
        string temp;
        string result;
        vector<string> stringList;
        stringstream pathStream(path);
        while (getline(pathStream, temp, '/')) {
            if (temp==".." && stringList.size()>0)
                stringList.pop_back();
            if (temp!=".." && temp!="." && temp.size()>0)
                stringList.push_back(temp);
        }
        for (string s:stringList) {
            result = result+"/"+s;
        }
        return result.size()>0 ? result : "/";
    }
};