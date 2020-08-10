class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> m;
        m["quot;"] = "\"";
        m["apos;"] = "\'";
        m["amp;"] = "&";
        m["gt;"] = ">";
        m["lt;"] = "<";
        m["frasl;"] = "/";
        for(int i=0; i<text.size(); i++){
            if(text[i] == '&'){
                int j = 6;
                for(; j>=3; j--){
                    if(i+j<text.size() && text[i+j]==';' &&m.count(text.substr(i+1,j))){
                        text = text.replace(i, j+1, m[text.substr(i+1,j)] );
                        //text =  text.substr(0,i) + m[text.substr(i+1,j)] +  text.substr(i+j+1);
                        break;
                    }         
                }
            }
        }
        return text;
    }
};