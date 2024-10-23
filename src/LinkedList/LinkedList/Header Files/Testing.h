#ifndef TESTING_H
#define TESTING_H

#include "List.h"
#include <chrono>
#include <fstream>
#include <string>

class Testing {
public:
    // Method to log time complexity data
    static void logResultsToExcel(const std::string& operationType, int listSize, int operationCount, double avgTimePerOp, double totalTime);

    // Methods to test insertion and deletion
    static void testInsertion(DoublyLinkedList& list, int maxElements, int step);
    static void testDeletion(DoublyLinkedList& list, int maxElements, int step);
};

#endif
