/*
Sample Input 1:
1
2
Call function ‘knows(0, 1)’ // returns false
Call function ‘knows(1, 0)’ // returns true
Sample Output 1:
0
Explanation For Sample Input 1:
In the first test case, there are 2 people at the party. When we call function knows(0,1), it returns false. That means the person having id ‘0’ does not know a person having id ‘1'. Similarly, the person having id ‘1’  knows a person having id ‘0’ as knows(1,0) returns true. Thus a person having id ‘0’ is a celebrity because he is known to everyone at the party but doesn't know anyone.
Sample Input 2:
1
2
Call ‘knows(0, 1)’ // returns true
Call ‘knows(1, 0)’ // returns true
2
Call ‘knows(0, 1)’ // returns false
Call ‘knows(1, 0)’ // returns false
Sample Output 2:
-1
-1
Explanation For Sample Input 2:
In first test case, there are 2 people at the party. The person having id ‘0’  knows a person having id ‘1’. The person having id ‘1’  knows a person having id ‘0’. Thus there is no celebrity at the party, because both know each other. 
In second test case, there are 2 people at the party. The person having id ‘0’ does not knows a person having id ‘1’. The person having id ‘1’  also does not knows a person having id ‘0’. Thus there is no celebrity at the party, because both does not know each other. 
*/

#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	stack<int>s;

 	//first put all element inoto stack
	 for(int i=0;i<n;i++){
s.push(i);
	 }
	 //step2
	 //take out 2 element from stack check whether they know 
	 while(s.size()>1){
int element1=s.top();
s.pop();
int element2=s.top();
s.pop();
int ans= knows(element1,element2);
if(ans==1){
s.push(element2);
}
else{
	s.push(element1);
}
	 }
//step 3 now only one element left which might be celebrity so verify it
int celebrity=s.top();
//check rownumber which should be same as n
int rownumber=0;
for(int  i=0;i<n;i++){
	if(knows(celebrity,i)==0){
		rownumber++;
	}
}
//check for column which should be equal to n-1
int colnumber=0;
for(int i=0;i<n;i++){
if(knows(i,celebrity)==1){
	colnumber++;
}
}

if(rownumber==n&&colnumber==n-1){
	return celebrity;
}
else{
	return -1;
}
	
}