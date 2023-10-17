


# include<stack>
bool isBalanced(string expression) 
{
    // Write your code here
//creation of stack
stack<int>s;
for(int i=0;i<expression.length();i++){
char c=expression[i];
//stack ke andar dalo
if(c=='('||c=='{'||c=='['){
    s.push(c);
}
else{
  if (!s.empty()) {
    // compare top element of stack with upcoming closer but stack should not
    // empty
    char topele = s.top();
    if (c == ')' && topele == '(' || c == '}' && topele == '{' ||
        c == ']' && topele == '[') {
      s.pop();
    } 
    else {
      return false;
    }
  } 

}

}
if(s.empty()){
    return true;
} else {
  return false;
}
}