#include <bits/stdc++.h> 
  
using namespace std; 
struct process { 
    int processno; 
    int AT; 
    int BT; 
    int BTbackup; 
    int WT; 
    int TAT; 
    int CT; 
}; 
  
struct process p[3]; 
  
int totaltime = 0; 
int prefinaltotal = 0; 
  
bool compare(process p1, process p2) 
{ 
    // compare the Arrival time of two processes 
    return p1.AT < p2.AT; 
} 

int findlargest(int at) 
{ 
    int max = 0, i; 
    for (i = 0; i < 3; i++) { 
        if (p[i].AT <= at) { 
            if (p[i].BT > p[max].BT) 
                max = i; 
            /*else if(p[i].BT = p[max].BT){
            	if(p[0].processno > p[1].processno&&p[0].processno > p[2].processno){
            	 max=0;
            }
            if(p[1].processno > p[2].processno&&p[1].processno > p[0].processno){
            	 max=1;
            }
            if(p[2].processno > p[1].processno&&p[2].processno > p[1].processno){
            	 max=2;
            }
            }*/
			
        } 
    } 
   
    // returning the index of the process having the largest BT 
    return max;

} 
  
// function to find the completion time of each process 
int findCT() 
{ 
  
    int index; 
    int flag = 0; 
    int i = p[0].AT; 
    while (1) { 
        if (i <= 3) { 
            index = findlargest(i); 
        } 
  
        else
            index = findlargest(3); 
        cout << "Student eating at time " << totaltime+1 
             << " is: P" << index + 1 << "\t"; 
  
        p[index].BT -= 1; 
        totaltime += 1; 
        i++; 
  
        if (p[index].BT == 0) { 
            p[index].CT = totaltime; 
            cout << " Process P" << p[index].processno  
                 << " is completed at " << totaltime; 
        } 
        cout << endl; 
  
        // loop termination condition 
        if (totaltime == prefinaltotal) 
            break; 
    } 
} 
  
int main() 
{ 
  
    int i; 
  
  
    // initializing the process number 
        p[0].processno = 2132;
        p[1].processno = 2102;
        p[2].processno = 2453;

 
  
    // cout<<"arrival time of 3 processes : "; 
    for (i = 0; i < 3; i++) // taking AT 
    { 
        p[i].AT = 0; 
    } 
    for(int i=0;i<=1;i++)
	{
	
    // cout<<" Burst time of 3 processes : "; 
        p[i].BT=2*(i+1);
        p[i].BTbackup = p[i].BT; 
        prefinaltotal += p[i].BT; 
    }
       for(int i=2;i<3;i++)
	{
	
    // cout<<" Burst time of 3 processes : "; 
        p[i].BT=2*(i+2);
        p[i].BTbackup = p[i].BT; 
        prefinaltotal += p[i].BT; 
    }
    // displaying the process before executing 
    cout << "PNo\tAT\tBT\n"; 
  
    for (i = 0; i < 3; i++) { 
        cout << p[i].processno << "\t"; 
        cout << p[i].AT << "\t"; 
        cout << p[i].BT << "\t"; 
        cout << endl; 
    } 
    cout << endl; 
  
    // soritng process according to Arrival Time 
    sort(p, p + 3, compare); 
  
    // calculating initial time when execution starts 
    totaltime += p[0].AT; 
  
    // calculating to terminate loop 
    prefinaltotal += p[0].AT; 
    findCT(); 
    int totalWT = 0; 
    int totalTAT = 0; 
    for (i = 0; i < 3; i++) { 
        // since, TAT = CT - AT 
        p[i].TAT = p[i].CT - p[i].AT; 
        p[i].WT = p[i].TAT - p[i].BTbackup; 
  
        // finding total waiting time 
        totalWT += p[i].WT; 
  
        // finding total turn around time 
        totalTAT += p[i].TAT; 
    } 
  
    cout << "After execution of all processes ... \n"; 
  
    // after all process executes 
    cout << "PNo\tAT\tBT\tCT\tTAT\tWT\n"; 
  
    for (i = 0; i < 3; i++) { 
        cout << p[i].processno << "\t"; 
        cout << p[i].AT << "\t"; 
        cout << p[i].BTbackup << "\t"; 
        cout << p[i].CT << "\t"; 
        cout << p[i].TAT << "\t"; 
        cout << p[i].WT << "\t"; 
        cout << endl; 
    } 
  
    cout << endl; 
    cout << "Total TAT = " << totalTAT << endl; 
    cout << "Average TAT = " << totalTAT / 3.0 << endl; 
    cout << "Total WT = " << totalWT << endl; 
    cout << "Average WT = " << totalWT / 3.0 << endl; 
    return 0; 
} 
