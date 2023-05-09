#pragma once
#include <iostream>
using namespace std;
class Process
{
private:
    int process_id;
    float arrival_time;
    float response_time;
    float cpu_time;
    float termination_time;
    float turnaround_time;
    float waiting_time;
    int io_requesttime;
    float io_duration;
public:


    int getprocess_id()const;
    int getarrival_time() const;
    float getresponse_time() const;
    float getwaiting_time() const;
    float getturnaround_time() const;
    float getcpu_time() const;
    float gettermination_time()const;
    int getio_requesttime();
    float getio_duration();

    void setwaiting_time(float time);
    void setturnaround_time(float time);
    void setprocess_id(int id);
    void setarrival_time(float time);
    void setresponse_time(float time);
    void setcpu_time(float time);
    void settermination_time(float time);
    void setio_requesttime(int timestep);
    void setio_duration(float duration);
    friend ostream& operator<<(ostream& output, Process P) {
        output << "Process is:  " << P.getprocess_id() << endl;
        return output;
    }
};