//#include "QueueFIFO.h"
//
//template<typename T>
//class QueueIterator {
//private:
//    QueueFIFO &queue;
//    int currentIndex;
//public:
//     QueueIterator(QueueFIFO& queue) : queue(queue), currentIndex(0) {};
//    void start() {
//        currentIndex = queue.get_head() % (queue.getSize()+1);
//    }
//
//    void next() {
//        currentIndex++ % (queue.getSize()+1);
//    }
//
////    bool finish() {
////        return currentIndex % queue.getSize() == queue.get_tail() % queue.getSize();
//    }
//
//    int getValue() {
//        return queue.getElement(queue.getHead % (queue.length()));
//
//    }
//};