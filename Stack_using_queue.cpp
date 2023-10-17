/*
Sample Input 1:
6
1 13
1 47
4
5
2
3
Sample Output 1:
2
false
47
13
Explanation Of The Sample Input 1:
Here we have six queries in total.

Query 1: Integer 1 represents the push function. Hence we push element ‘13’ onto the stack.

Query 2: Integer 1 represents the push function. Hence we push element ‘47’ onto the stack.

Query 3: Integer 4 represents the size function. Hence we print the size of the stack that is 2.

Query 4: Integer 5 represents the isEmpty function. Hence here, we print false because the stack is not empty.

Query 5: Integer 2 represents the pop function. The stack contains element ‘47’ at the top. We remove/pop ‘47’ from the stack and print ‘47’ on the new line.

Query 6: Integer 3 represents the top function. Because we have element ‘13’ at the top of the stack, we print ‘13’ on the new line.
Constraints:
1 <= Q <= 1000
1 <= query type <= 5
-10^9 <= data <= 10^9 and data != -1

Where 'Q' is the total number of queries being performed on the stack and data represents the integer pushed into the stack. 

Time Limit: 1 second
*/

# include<bits/stdc++.h>
class Stack {
	// Define the data members.
     //two queue
        queue<int>q1;
        queue<int>q2;
        int size;

   public:
    Stack() {
       size=0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {

        return size;
    }

    bool isEmpty() {
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int element) {
        //as operation in push are same in queue and stack
        q1.push(element);
        //update size
        size++;

    }

    int pop() {
        //first check if element is empty or not
        if(q1.empty()){
            return -1;
        }

        //first move all element from q1 to q2 except last
        int n=q1.size();
        while(n>1){
            int ele=q1.front();
            q2.push(ele);
            q1.pop();
            n--;
        }
int value=q1.front();
//pop element from q1
q1.pop();
//check again either it is empty or not
size--;

//now again move element from q2 to q1;
while(q2.empty()==false){
    int ele=q2.front();
    q2.pop();
    q1.push(ele);

}
//now return store value of q1
return value;



    }

    int top() {
        // Implement the top() function.
if(q1.empty()){
    return -1;
}
else{
    //return back element of q1
    return q1.back();
}


    }
};