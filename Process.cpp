#include "Process.h"


int Process::getprocess_id()const {
    return process_id;
}
int Process::getarrival_time() const {
    return arrival_time;
}
float Process::getcpu_time() const {
    return cpu_time;
}
float Process::gettermination_time()const {
    return termination_time;
}
float Process::getwaiting_time() const {
    return waiting_time;
}

float Process::getturnaround_time() const {
    return turnaround_time;
}

float Process::getresponse_time() const {
    return response_time;
}
int Process::getio_requesttime() {
    return io_requesttime;
}
float Process::getio_duration() {
    return io_duration;
}
void Process::setprocess_id(int id) {
    process_id = id;
}
void Process::setarrival_time(float time) {
    arrival_time = time;
}
void Process::setresponse_time(float time) {
    response_time = time;
}
void Process::setcpu_time(float time) {
    cpu_time = time;
}
void Process::settermination_time(float time) {
    termination_time = time;
}
void Process::setwaiting_time(float time) {
    waiting_time = time;
}
void Process::setturnaround_time(float time) {
    turnaround_time = time;
}
void Process::setio_requesttime(int timestep) {
    io_requesttime = timestep;
}
void Process::setio_duration(float duration) {
    io_duration = duration;
}
