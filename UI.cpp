//#include "UI.h"
//void UI::print(Processor* p[], int numprocessor, Queue<Process*> blk, Process* run[], Queue<Process*> trm, int timestep) {
//    cout << "current Timestep:" << timestep << endl;
//    cout << "-----------------   RDY processes __________" << endl;
//    for (int i = 0; i < numprocessor; i++) {
//        cout << "processor " << i + 1 << "  [" << p[i]->return_Type() << "]" << ": " << "RDY";
//        p[i]->printRDY();
//        cout << endl;
//    }
//    cout << "-----------------   BLK processes __________" << endl;
//    cout << blk.getCount() << " BLK: ";
//    blk.printQueue();
//    cout << endl;
//    cout << "-----------------   RUN processes __________" << endl;
//    cout << numprocessor << " RUN: ";
//    for (int i = 0; i < numprocessor; ++i) {
//        cout << p[i] << "(p" << i + 1 << "),  ";
//    }
//    cout << endl;
//    cout << "-----------------   TRM processes __________" << endl;
//    cout << trm.getCount() << " BLK: ";
//    trm.printQueue();
//    cout << endl;
//}