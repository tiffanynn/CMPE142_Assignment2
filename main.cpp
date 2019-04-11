#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <ctime>
#include "Jobs.hpp"
using namespace std;
/*
need to output:
start time, finish time, total time elapsed, response time
*/
void FIFO(Jobs *jobsArry, int numberOfJobs);
void SJF(Jobs *jobsArry, int numberOfJobs);
void BJF(Jobs *jobsArry, int numberOfJobs);
void STCF(Jobs *jobsArry, int numberOfJobs);
void RR(Jobs *jobsArry, int numberOfJobs);
int findNumJobs();
int main() {
	int numberOfJobsFound = 0;
	ifstream in_stream;
	in_stream.open("jobs.dat");

	numberOfJobsFound = findNumJobs();

	Jobs *jobsArry = new Jobs[numberOfJobsFound];

	for(int i = 0; i < numberOfJobsFound; i++)
	{
		in_stream >> jobsArry[i];
//		cout << jobsArry[i];
	}
	FIFO(jobsArry, numberOfJobsFound);

	return 0;
}
//*NOTE: this FIFO function also sorts the array of jobs in increasing order of arrival times
void FIFO(Jobs *jobsArry, int numberOfJobs){//no preemption
	int i, j, k, a, min;
	Jobs temp;
	int currentTimeStamp = 0;//time stamp starts at zero

	//sorting the jobs array by increasing order of arrival times using selection sort (for simplicity)
    for (i = 0; i < (numberOfJobs - 1); i++)
    {
        min = i;
        for (j = i + 1; j < numberOfJobs; j++){
        	if (jobsArry[j].getArrival() < jobsArry[min].getArrival()){
        		min = j;
        	}
        }
        temp = jobsArry[min];
        jobsArry[min] = jobsArry[i];
        jobsArry[i] = temp;
    }

}
void SJF(Jobs *jobsArry, int numberOfJobs){
	//no preemption

}
void BJF(Jobs *jobsArry, int numberOfJobs){//no preemption

}
void STCF(Jobs *jobsArry, int numberOfJobs){}
void RR(Jobs *jobsArry, int numberOfJobs){}
int findNumJobs()
{
	int numberOfJobsFound = 0, counter = 0;
	int next;
	ifstream in_stream;
	in_stream.open("jobs.dat");
	in_stream >> next;

	while(!in_stream.eof())
	{
		if((counter % 3) == 0)
		{
			numberOfJobsFound++;
		}
		in_stream >> next;
		counter++;
	}
	in_stream.close();
	return numberOfJobsFound;
}