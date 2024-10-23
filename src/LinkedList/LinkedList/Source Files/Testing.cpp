#include "Testing.h"
#include <iostream>
#include <iomanip>

// Logging results to Excel
void Testing::logResultsToExcel(const std::string& operationType, int listSize, int operationCount, double avgTimePerOp, double totalTime) {
    std::ofstream file;
    file.open("test_results.csv", std::ios_base::app); // Appending to the file
    if (file.is_open()) {
        file << operationType << "," << listSize << "," << operationCount << "," << std::fixed << std::setprecision(4)
            << avgTimePerOp << "," << totalTime << "\n";
    }
    file.close();
}

// Test for insertion
void Testing::testInsertion(DoublyLinkedList& list, int maxElements, int step) {
    for (int size = 100; size <= maxElements; size += 100) {
        list = DoublyLinkedList(); // Reset the list for each size
        int operationCount = 0;
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 1; i <= size; i++) {
            list.Add(i);
            operationCount++;
            if (operationCount % step == 0) {
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> elapsed = end - start;
                double avgTimePerOp = elapsed.count() / operationCount;
                Testing::logResultsToExcel("Insertion", size, operationCount, avgTimePerOp, elapsed.count());
            }
        }
    }
}

// Test for deletion
void Testing::testDeletion(DoublyLinkedList& list, int maxElements, int step) {
    for (int size = 100; size <= maxElements; size += 100) {
        list = DoublyLinkedList(); // Reset the list and fill it up
        for (int i = 1; i <= size; i++) {
            list.Add(i);
        }

        int operationCount = 0;
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 1; i <= size; i++) {
            list.Remove(i);
            operationCount++;
            if (operationCount % step == 0) {
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> elapsed = end - start;
                double avgTimePerOp = elapsed.count() / operationCount;
                Testing::logResultsToExcel("Deletion", size, operationCount, avgTimePerOp, elapsed.count());
            }
        }
    }
}
